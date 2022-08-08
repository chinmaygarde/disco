import 'dart:ffi';

import 'file:/Users/chinmaygarde/VersionControlled/engine/src/out/host_debug_unopt/gen/flutter/impeller/disco/runtime/disco.dart'
    as disco;

void initializeBindings() {
  disco.AttachNativeBindings(DynamicLibrary.process());
}
