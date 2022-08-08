// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from disco.epoxy
#include "disco/runtime/disco.h"

#include "flutter/fml/logging.h"

namespace disco {

DiscoContext* DiscoContextCreate() {
  FML_LOG(ERROR) << __FUNCTION__;
  return nullptr;
}

void DiscoContextDestroy(DiscoContext* context) {
  FML_LOG(ERROR) << __FUNCTION__;
}

DiscoResult DiscoLaunchApplication(DiscoContext* context) {
  if (!context) {
    return DiscoResult::kFailure;
  }
  return DiscoResult::kSuccess;
}

}  // namespace disco
