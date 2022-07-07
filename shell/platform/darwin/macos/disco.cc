// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/fml/command_line.h"

namespace disco {

bool Main(const fml::CommandLine& command_line) {
  return false;
}

}  // namespace disco

int main(int argc, char const* argv[]) {
  return disco::Main(fml::CommandLineFromArgcArgv(argc, argv)) ? EXIT_SUCCESS
                                                               : EXIT_FAILURE;
}
