// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/fml/command_line.h"

namespace impeller {

bool Main(const fml::CommandLine& command_line) {
  return false;
}

}  // namespace impeller

int main(int argc, char const* argv[]) {
  return impeller::Main(fml::CommandLineFromArgcArgv(argc, argv));
}
