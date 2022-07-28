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

bool Window::Launch() const {
  if (!IsValid()) {
    return false;
  }
  playground_->SetupWindow(PlaygroundBackend::kMetal);
  auto result = playground_->OpenPlaygroundHere(
      [](RenderPass& pass) -> bool { return true; });
  playground_->TeardownWindow();
  return result;
}

}  // namespace disco
}  // namespace impeller
