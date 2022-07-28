// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "disco/shell/disco_playground.h"

namespace impeller {
namespace disco {

DiscoPlayground::DiscoPlayground() = default;

DiscoPlayground::~DiscoPlayground() = default;

// |Playground|
std::unique_ptr<fml::Mapping> DiscoPlayground::OpenAssetAsMapping(
    std::string asset_name) const {
  FML_UNREACHABLE();
  return nullptr;
}

// |Playground|
std::string DiscoPlayground::GetWindowTitle() const {
  return "Disco Runner (Press ESC or 'q' to quit)";
}

}  // namespace disco
}  // namespace impeller
