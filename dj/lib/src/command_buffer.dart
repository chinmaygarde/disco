import 'file:/Users/chinmaygarde/VersionControlled/engine/src/out/host_debug_unopt/gen/flutter/impeller/disco/runtime/disco.dart';
import 'dart:ffi';

class CommandBuffer implements Finalizable {
  Pointer<DiscoCommandBuffer> ptr;

  CommandBuffer(this.ptr) {
    var finalizer = NativeFinalizer(DiscoCommandBufferDestroyFNPTR.cast());
    finalizer.attach(this, ptr.cast());
  }
}
