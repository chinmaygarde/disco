// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "disco/runtime/runtime.h"
#include "flutter/fml/command_line.h"
#include "flutter/fml/logging.h"

namespace disco {

bool Main(const fml::CommandLine& command_line) {
  constexpr const char* kAssetsFlagKey = "assets";
  constexpr const char* kICUFlagKey = "icu";

  if (!command_line.HasOption(kAssetsFlagKey)) {
    FML_LOG(ERROR) << "Assets not specified.";
    return false;
  }

  if (!command_line.HasOption(kICUFlagKey)) {
    FML_LOG(ERROR) << "ICU data not specified.";
    return false;
  }

  auto runtime = std::make_unique<Runtime>(
      command_line.GetOptionValueWithDefault(kAssetsFlagKey, ""),
      command_line.GetOptionValueWithDefault(kICUFlagKey, ""));
  if (!runtime->IsValid()) {
    FML_LOG(ERROR) << "Could not create Disco runtime.";
    return false;
  }

  return true;
}

}  // namespace disco

int main(int argc, char const* argv[]) {
  return disco::Main(fml::CommandLineFromArgcArgv(argc, argv)) ? EXIT_SUCCESS
                                                               : EXIT_FAILURE;
}
