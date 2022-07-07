// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "disco/shell/shell.h"
#include "flutter/fml/command_line.h"
#include "flutter/fml/logging.h"

namespace disco {

bool Main(const fml::CommandLine& command_line) {
  auto switches = Switches::FromCommandLine(command_line);
  if (!switches.has_value()) {
    FML_LOG(ERROR) << "Invalid usage.";
    FML_LOG(ERROR) << Switches::GetUsage();
    return false;
  }

  auto shell = std::make_unique<Shell>(switches.value());

  if (!shell->IsValid()) {
    FML_LOG(ERROR) << "Could not create shell.";
    return false;
  }

  return true;
}

}  // namespace disco

int main(int argc, char const* argv[]) {
  return disco::Main(fml::CommandLineFromArgcArgv(argc, argv)) ? EXIT_SUCCESS
                                                               : EXIT_FAILURE;
}
