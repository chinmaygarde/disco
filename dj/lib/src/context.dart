import 'file:/Users/chinmaygarde/VersionControlled/engine/src/out/host_debug_unopt/gen/flutter/impeller/disco/runtime/disco.dart' as disco;
import 'dart:ffi';

class Context implements Finalizable {
  Pointer<disco.DiscoContext> context;

  Context.global()
    : context = disco.DiscoContextCreate() {
      // assert(context.address != 0);
      var dylib = DynamicLibrary.process();
      var functionPointer = dylib.lookup<NativeFunction<disco.DiscoContextDestroyCType>>("EPOXY_BIND_DiscoContextDestroy");
      var finalizer = NativeFinalizer(functionPointer.cast());
      finalizer.attach(this, context.cast());
    }
}
