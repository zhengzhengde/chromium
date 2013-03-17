// Copyright 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_THREAD_IMPL_H_
#define CC_THREAD_IMPL_H_

#include "base/callback.h"
#include "base/memory/scoped_ptr.h"
#include "base/message_loop_proxy.h"
#include "cc/cc_export.h"
#include "cc/thread.h"

namespace cc {

// Implements cc::Thread in terms of base::MessageLoopProxy.
class CC_EXPORT ThreadImpl : public Thread {
 public:
  // Creates a ThreadImpl wrapping the current thread.
  static scoped_ptr<cc::Thread> CreateForCurrentThread();

  // Creates a Thread wrapping a non-current thread.
  static scoped_ptr<cc::Thread> CreateForDifferentThread(
      scoped_refptr<base::MessageLoopProxy> thread);

  virtual ~ThreadImpl();

  // Thread implementation
  virtual void PostTask(base::Closure cb) OVERRIDE;
  virtual void PostDelayedTask(base::Closure cb, long long delay_ms) OVERRIDE;
  virtual bool BelongsToCurrentThread() const OVERRIDE;

 private:
  explicit ThreadImpl(scoped_refptr<base::MessageLoopProxy> thread);

  scoped_refptr<base::MessageLoopProxy> thread_;

  DISALLOW_COPY_AND_ASSIGN(ThreadImpl);
};

}  // namespace cc

#endif  // CC_THREAD_IMPL_H_
