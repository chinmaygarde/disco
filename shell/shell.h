// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "disco/runtime/runtime.h"
#include "disco/shell/switches.h"
#include "flutter/fml/macros.h"

namespace disco {

class Shell {
 public:
  explicit Shell(Switches switches);

  ~Shell();

  bool IsValid() const;

 private:
  std::unique_ptr<Runtime> runtime_;
  bool is_valid_ = false;

  FML_DISALLOW_COPY_AND_ASSIGN(Shell);
};

}  // namespace disco
