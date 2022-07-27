// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <memory>

#include "flutter/fml/macros.h"
#include "impeller/playground/playground.h"

namespace impeller {
namespace disco {

class Window {
 public:
  Window();

  ~Window();

  bool IsValid() const;

 private:
  std::unique_ptr<Playground> playground_;
  bool is_valid_ = false;

  FML_DISALLOW_COPY_AND_ASSIGN(Window);
};

}  // namespace disco
}  // namespace impeller
