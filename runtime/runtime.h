// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <memory>

#include "flutter/fml/macros.h"

namespace impeller {
namespace disco {

class Runtime {
 public:
  Runtime(const std::string& assets_path, const std::string& icu_data_path);

  ~Runtime();

  bool IsValid() const;

 private:
  struct EngineHandle;
  std::unique_ptr<EngineHandle> engine_;
  bool is_valid_ = false;

  FML_DISALLOW_COPY_AND_ASSIGN(Runtime);
};

}  // namespace disco
}  // namespace impeller
