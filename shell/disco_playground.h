// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "flutter/fml/macros.h"
#include "impeller/playground/playground.h"

namespace impeller {
namespace disco {

class DiscoPlayground : public Playground {
 public:
  DiscoPlayground();

  ~DiscoPlayground();

  // |Playground|
  std::unique_ptr<fml::Mapping> OpenAssetAsMapping(
      std::string asset_name) const override;

  // |Playground|
  std::string GetWindowTitle() const override;

 private:
  FML_DISALLOW_COPY_AND_ASSIGN(DiscoPlayground);
};

}  // namespace disco
}  // namespace impeller
