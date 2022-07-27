// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "disco/shell/window.h"

#include "impeller/base/validation.h"

namespace impeller {
namespace disco {

class DiscoPlayground : public Playground {
 public:
  DiscoPlayground() = default;

  ~DiscoPlayground() = default;

  void TestBody() override {}

 private:
  FML_DISALLOW_COPY_AND_ASSIGN(DiscoPlayground);
};

Window::Window() {
  auto playground = std::make_unique<DiscoPlayground>();
  if (!playground) {
    VALIDATION_LOG << "Could not create playground.";
    return;
  }
  playground->SetUp();
  is_valid_ = true;
}

Window::~Window() = default;

bool Window::IsValid() const {
  return is_valid_;
}

}  // namespace disco
}  // namespace impeller
