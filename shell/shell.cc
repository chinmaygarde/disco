// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "impeller/disco/shell/shell.h"

#include "flutter/fml/logging.h"
#include "impeller/base/validation.h"

namespace impeller {
namespace disco {

Shell::Shell(const Switches& switches) {
  auto runtime =
      std::make_unique<Runtime>(switches.assets_path, switches.icu_path);
  if (!runtime->IsValid()) {
    VALIDATION_LOG << "Could not create Disco runtime.";
    return;
  }

  auto window = std::make_unique<Window>();
  if (!window->IsValid()) {
    VALIDATION_LOG << "Could not create window.";
    return;
  }

  runtime_ = std::move(runtime);
  window_ = std::move(window);

  is_valid_ = true;
}

bool Shell::Launch() {
  if (!IsValid()) {
    return false;
  }
  return window_->Launch();
}

Shell::~Shell() {
  FML_LOG(ERROR) << "Shutting down the shell.";
}

bool Shell::IsValid() const {
  return is_valid_;
}

}  // namespace disco
}  // namespace impeller
