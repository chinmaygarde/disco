import 'file:/Users/chinmaygarde/VersionControlled/engine/src/out/host_debug_unopt/gen/flutter/impeller/disco/runtime/disco.dart' as disco;
import 'dart:ffi';

class Context implements Finalizable {
  Pointer<disco.DiscoContext> context;

  Context.global()
    : context = disco.DiscoGetContext();

  // void setFinalizer() {
  //   Pointer<NativeFinalizerFunction> function = disco.DiscoContextReleaseCFNPTR;
  //   var finalizer = NativeFinalizer(function);
  //   finalizer.attach(this, context.cast());
  // }
}
