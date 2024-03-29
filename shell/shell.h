// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "disco/runtime/runtime.h"
#include "disco/shell/switches.h"
#include "disco/shell/window.h"
#include "flutter/fml/macros.h"

namespace impeller {
namespace disco {

class Shell {
 public:
  explicit Shell(const Switches& switches);

  ~Shell();

  bool IsValid() const;

  bool Launch();

 private:
  std::unique_ptr<Runtime> runtime_;
  std::unique_ptr<Window> window_;
  bool is_valid_ = false;

  FML_DISALLOW_COPY_AND_ASSIGN(Shell);
};

}  // namespace disco
}  // namespace impeller
