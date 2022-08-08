import 'file:/Users/chinmaygarde/VersionControlled/engine/src/out/host_debug_unopt/gen/flutter/impeller/disco/runtime/disco.dart';
import 'dart:ffi';
import 'shader_library.dart';
import 'sampler_library.dart';
import 'command_buffer.dart';
import 'allocator.dart';

class Context implements Finalizable {
  late Pointer<DiscoContext> ptr;

  Context.create() {
    ptr = DiscoContextCreate();
    var finalizer = NativeFinalizer(DiscoContextDestroyFNPTR.cast());
    finalizer.attach(this, ptr.cast());
  }

  CommandBuffer createRenderCommandBuffer()
    => CommandBuffer(DiscoContextCreateRenderCommandBuffer(ptr));
}
