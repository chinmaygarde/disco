// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "disco/shell/window.h"

#include "impeller/base/validation.h"

namespace impeller {
namespace disco {

Window::Window() : playground_(std::make_unique<DiscoPlayground>()) {
  if (!playground_->is_enabled()) {
    VALIDATION_LOG << "Playgrounds are not enabled.";
    return;
  }
  is_valid_ = true;
}

Window::~Window() = default;

bool Window::IsValid() const {
  return is_valid_;
}

}  // namespace disco
}  // namespace impeller
