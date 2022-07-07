// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "disco/runtime/runtime.h"

#include "embedder.h"

#include "flutter/fml/logging.h"
#include "impeller/base/validation.h"

namespace disco {

struct Runtime::EngineHandle {
  explicit EngineHandle(FLUTTER_API_SYMBOL(FlutterEngine) engine)
      : engine_(engine) {}

  ~EngineHandle() {
    if (::FlutterEngineShutdown(engine_) != kSuccess) {
      FML_LOG(ERROR) << "Could not shut down the Flutter Engine in runtime.";
    }
  }

 private:
  FLUTTER_API_SYMBOL(FlutterEngine) engine_;
};

Runtime::Runtime(const std::string& assets_path,
                 const std::string& icu_data_path) {
  FlutterRendererConfig null_renderer = {};
  null_renderer.type = kSoftware;
  null_renderer.software.struct_size = sizeof(FlutterSoftwareRendererConfig);
  null_renderer.software.surface_present_callback = [](auto, auto, auto, auto) {
    // This indicates the Flutter runtime in Disco is trying to render. Shut it
    // down.
    FML_CHECK(false) << "Null renderer cannot render.";
    return false;
  };

  FlutterProjectArgs project = {};
  project.struct_size = sizeof(FlutterProjectArgs);
  project.assets_path = assets_path.c_str();
  project.icu_data_path = icu_data_path.c_str();

  FLUTTER_API_SYMBOL(FlutterEngine) engine = {};
  auto result = ::FlutterEngineRun(FLUTTER_ENGINE_VERSION,  // version
                                   &null_renderer,          // renderer
                                   &project,                // project
                                   this,                    // user data
                                   &engine  // out variable on success
  );
  if (result != kSuccess) {
    VALIDATION_LOG << "Could not launch the Flutter engine in the runtime.";
    return;
  }
  engine_ = std::make_unique<EngineHandle>(engine);
  is_valid_ = true;
}

Runtime::~Runtime() = default;

bool Runtime::IsValid() const {
  return is_valid_;
}

}  // namespace disco
