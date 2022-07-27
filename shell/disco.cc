// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#define FML_USED_ON_EMBEDDER

#include "disco/shell/shell.h"
#include "flutter/fml/command_line.h"
#include "flutter/fml/logging.h"
#include "flutter/fml/message_loop.h"
#include "flutter/fml/paths.h"
#include "flutter/testing/testing.h"

namespace disco {

bool Main(const fml::CommandLine& command_line) {
  Switches switches;
  switches.assets_path = flutter::testing::GetFixturesPath();
  switches.icu_path = fml::paths::JoinPaths(
      {std::string{flutter::testing::GetFixturesPath()}, "icudtl.dat"});

  auto shell = std::make_unique<Shell>(switches);

  if (!shell->IsValid()) {
    FML_LOG(ERROR) << "Could not create shell.";
    return false;
  }

  fml::MessageLoop::GetCurrent().Run();

  return true;
}

}  // namespace disco

int main(int argc, char const* argv[]) {
  return disco::Main(fml::CommandLineFromArgcArgv(argc, argv)) ? EXIT_SUCCESS
                                                               : EXIT_FAILURE;
}
