// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "impeller/renderer/context.h"
#include "impeller/renderer/render_pass.h"
#include "impeller/renderer/render_target.h"

namespace impeller {

class InlinePassContext {
 public:
  struct RenderPassResult {
    std::shared_ptr<RenderPass> pass;
    std::shared_ptr<Texture> backdrop_texture;
  };

  InlinePassContext(std::shared_ptr<Context> context,
                    RenderTarget render_target,
                    uint32_t pass_texture_reads);
  ~InlinePassContext();

  bool IsValid() const;
  bool IsActive() const;
  std::shared_ptr<Texture> GetTexture();
  bool EndPass();
  const RenderTarget& GetRenderTarget() const;
  uint32_t GetPassCount() const;

  RenderPassResult GetRenderPass(uint32_t pass_depth);

 private:
  std::shared_ptr<Context> context_;
  RenderTarget render_target_;
  std::shared_ptr<CommandBuffer> command_buffer_;
  std::shared_ptr<RenderPass> pass_;
  uint32_t pass_count_ = 0;
  uint32_t total_pass_reads_ = 0;

  FML_DISALLOW_COPY_AND_ASSIGN(InlinePassContext);
};

}  // namespace impeller
