import 'file:/Users/chinmaygarde/VersionControlled/engine/src/out/host_debug_unopt/gen/flutter/impeller/disco/runtime/disco.dart' as disco;
import 'dart:ffi';

class Context implements Finalizable {
  Pointer<disco.DiscoContext> context;
  Context.create()
    : context = disco.DiscoContextCreate() {
      assert(context.address != 0);
      var finalizer = NativeFinalizer(disco.DiscoContextDestroyFNPTR.cast());
      finalizer.attach(this, context.cast());
    }
}
