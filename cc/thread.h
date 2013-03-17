// Copyright 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_THREAD_H_
#define CC_THREAD_H_

#include "base/callback.h"
#include "base/basictypes.h"
#include "cc/cc_export.h"

namespace cc {

// Thread provides basic infrastructure for messaging with the compositor in a
// platform-neutral way.
class CC_EXPORT Thread {
 public:
  virtual ~Thread() {}

  // Executes the callback on context's thread asynchronously.
  virtual void PostTask(base::Closure cb) = 0;

  // Executes the task after the specified delay.
  virtual void PostDelayedTask(base::Closure cb, long long delay_ms) = 0;

  virtual bool BelongsToCurrentThread() const = 0;
};

}  // namespace cc

#endif  // CC_THREAD_H_
