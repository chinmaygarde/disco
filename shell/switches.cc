// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "disco/shell/switches.h"

#include <sstream>

#include "impeller/base/validation.h"

namespace disco {

constexpr const char* kAssetsFlagKey = "assets";
constexpr const char* kICUFlagKey = "icu";

std::optional<Switches> Switches::FromCommandLine(
    const fml::CommandLine& command_line) {
  if (!command_line.HasOption(kAssetsFlagKey)) {
    VALIDATION_LOG << "Assets not specified.";
    return std::nullopt;
  }

  if (!command_line.HasOption(kICUFlagKey)) {
    VALIDATION_LOG << "ICU data not specified.";
    return std::nullopt;
  }

  Switches switches;
  switches.assets_path =
      command_line.GetOptionValueWithDefault(kAssetsFlagKey, "");
  switches.icu_path = command_line.GetOptionValueWithDefault(kICUFlagKey, "");

  return std::move(switches);
}

std::string Switches::GetUsage() {
  std::stringstream stream;
  stream << R"~(
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
                                 _ _
                              __| (_)___  ___ ___
                             / _` | / __|/ __/ _ \
                            | (_| | \__ \ (_| (_) |
                             \__,_|_|___/\___\___/
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

Valid Usage:
)~";
  stream << "\t--" << kAssetsFlagKey << " [Required] The assets path."
         << std::endl;
  stream << "\t--" << kICUFlagKey << " [Required] The ICU data path."
         << std::endl;
  return stream.str();
}

}  // namespace disco
