/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Fabio Massaioli
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef __NODAL_PASSES_CYCLE_DETECTION_H__
#define __NODAL_PASSES_CYCLE_DETECTION_H__

#include "depth_first_search.h"

#include <functional>

namespace nodal
{

namespace detail
{

  using cd_callback =
    std::function<void(graph_link const&, graph const&)>;

  class cd_visitor : public boost::default_dfs_visitor
  {
  public:
    cd_visitor(cd_callback const& callback) : back_edge(callback) {}

    cd_callback back_edge;
  };

} /* namespace detail */

class cycle_detection_pass :
  public depth_first_search_pass<detail::cd_visitor>
{
public:
  cycle_detection_pass(detail::cd_callback const& callback)
    : depth_first_search_pass<detail::cd_visitor>(callback)
    {}
};

} /* namespace nodal */

#endif /* __NODAL_PASSES_CYCLE_DETECTION_H__ */
