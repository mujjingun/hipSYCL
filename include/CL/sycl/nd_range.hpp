/*
 * This file is part of SYCU, a SYCL implementation based CUDA/HIP
 *
 * Copyright (c) 2018 Aksel Alpay
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef SYCU_ND_RANGE_HPP
#define SYCU_ND_RANGE_HPP

#include "range.hpp"
#include "id.hpp"

namespace cl {
namespace sycl {

template<int dimensions = 1>
struct nd_range
{

  __host__ __device__
  nd_range(range<dimensions> globalSize,
           range<dimensions> localSize,
           id<dimensions> offset = id<dimensions>())
    : _global_range{globalSize},
      _local_range{localSize},
      _num_groups{globalSize / localSize},
      _offset{offset}
  {}

  __host__ __device__
  range<dimensions> get_global() const
  { return _global_range; }

  __host__ __device__
  range<dimensions> get_local() const
  { return _local_range; }

  __host__ __device__
  range<dimensions> get_group() const
  { return _num_groups; }

  __host__ __device__
  id<dimensions> get_offset() const
  { return _offset; }

private:
  range<dimensions> _global_range;
  range<dimensions> _local_range;
  range<dimensions> _num_groups;
  id<dimensions> _offset;
};


}
}

#endif