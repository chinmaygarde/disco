// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "impeller/disco/shell/shell.h"

#include "impeller/base/validation.h"

namespace disco {

Shell::Shell(Switches switches)
    : runtime_(
          std::make_unique<Runtime>(switches.assets_path, switches.icu_path)) {
  if (!runtime_->IsValid()) {
    VALIDATION_LOG << "Could not create Disco runtime.";
    return;
  }
  is_valid_ = true;
}

Shell::~Shell() = default;

bool Shell::IsValid() const {
  return is_valid_;
}

}  // namespace disco
