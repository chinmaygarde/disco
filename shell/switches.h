// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <optional>
#include <string>

#include "flutter/fml/command_line.h"
#include "flutter/fml/macros.h"

namespace disco {

struct Switches {
  std::string assets_path;
  std::string icu_path;
};

}  // namespace disco
