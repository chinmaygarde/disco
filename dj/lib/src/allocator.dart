import 'dart:ffi';

import 'file:/Users/chinmaygarde/VersionControlled/engine/src/out/host_debug_unopt/gen/flutter/impeller/disco/runtime/disco.dart'
    as disco;

class Allocator {
  Pointer<disco.DiscoAllocator> ptr;

  Allocator(this.ptr);
}
