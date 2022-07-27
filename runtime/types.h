// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "flutter/fml/build_config.h"

#ifdef __cplusplus
#define DISCO_EXTERN_C_BEGIN extern "C" {
#define DISCO_EXTERN_C_END }
#else  // __cplusplus
#define DISCO_EXTERN_C_BEGIN
#define DISCO_EXTERN_C_END
#endif  // __cplusplus

#if FML_OS_WIN
#define DISCO_FFI_VISIBILITY __declspec(dllexport)
#else  // FML_OS_WIN
#define DISCO_FFI_VISIBILITY __attribute__((visibility("default")))
#endif  // FML_OS_WIN
