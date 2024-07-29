/* Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#include "glog/logging.h"
#include "gtest/gtest.h"
#include "paddle/phi/core/dense_tensor.h"
#include "paddle/phi/core/sparse_coo_tensor.h"
#include "test/cpp/phi/core/allocator.h"

namespace phi {
namespace tests {

TEST(sparse_coo_tensor, construct) {
  phi::CPUPlace cpu;
  auto dense_dims = common::make_ddim({3, 3});
  std::vector<float> non_zero_data = {1.0, 2.0, 3.0};
  std::vector<int64_t> indices_data = {0, 1, 2, 0, 2, 1};
  auto fancy_allocator = std::unique_ptr<Allocator>(new FancyAllocator);
  auto* alloc = fancy_allocator.get();
  auto indices_dims =
      common::make_ddim({2, static_cast<int>(non_zero_data.size())});
  DenseTensorMeta indices_meta(DataType::INT64, indices_dims, DataLayout::NCHW);
  DenseTensor indices(alloc, indices_meta);
  memcpy(indices.mutable_data<int64_t>(cpu),
         &indices_data[0],
         indices_data.size() * sizeof(int64_t));

  auto elements_dims =
      common::make_ddim({static_cast<int>(non_zero_data.size())});
  DenseTensorMeta elements_meta(
      DataType::FLOAT32, elements_dims, DataLayout::NCHW);
  DenseTensor elements(alloc, elements_meta);

  memcpy(elements.mutable_data<float>(cpu),
         &non_zero_data[0],
         non_zero_data.size() * sizeof(float));

  SparseCooTensor sparse(indices, elements, dense_dims);

  PADDLE_ENFORCE_EQ(
      sparse.initialized(),
      true,
      phi::errors::Fatal("`sparse.initialized()` should be true"));
  PADDLE_ENFORCE_EQ(
      sparse.initialized(),
      true,
      phi::errors::Fatal("`sparse.initialized()` should be true"));
  PADDLE_ENFORCE_EQ(
      sparse.nnz(),
      static_cast<int64_t>(non_zero_data.size()),
      phi::errors::Fatal("`sparse.nnz()` is %lld and "
                         "`static_cast<int64_t>(non_zero_data.size())` is "
                         "%lld, they should equal to each other",
                         sparse.nnz(),
                         static_cast<int64_t>(non_zero_data.size())));
  PADDLE_ENFORCE_EQ(
      sparse.numel(),
      9,
      phi::errors::Fatal("`sparse.numel()` is %d, but should be 9"));
  PADDLE_ENFORCE_EQ(sparse.dims(),
                    dense_dims,
                    phi::errors::Fatal("`sparse.dims()` is %d, but `dense_dim` "
                                       "is %d, they should equal to each other",
                                       sparse.dims(),
                                       dense_dims));
  PADDLE_ENFORCE_EQ(sparse.dtype(),
                    DataType::FLOAT32,
                    phi::errors::Fatal("`sparse.dtype()` is No.%d in DataType, "
                                       "and should be No.d --DataType::FLOAT32",
                                       sparse.dtype(),
                                       DataType::FLOAT32));
  PADDLE_ENFORCE_EQ(sparse.place(),
                    phi::CPUPlace(),
                    phi::errors::Fatal("Variable `sparse` should on CPU!"));
}

TEST(sparse_coo_tensor, other_function) {
  auto fancy_allocator = std::unique_ptr<Allocator>(new FancyAllocator);
  auto* alloc = fancy_allocator.get();
  auto dense_dims = common::make_ddim({4, 4});
  const int non_zero_num = 2;
  auto indices_dims = common::make_ddim({2, non_zero_num});
  DenseTensorMeta indices_meta(DataType::INT64, indices_dims, DataLayout::NCHW);
  DenseTensor indices(alloc, indices_meta);

  auto elements_dims = common::make_ddim({non_zero_num});
  DenseTensorMeta elements_meta(
      DataType::FLOAT32, elements_dims, DataLayout::NCHW);
  DenseTensor elements(alloc, elements_meta);

  SparseCooTensor coo(indices, elements, dense_dims);
  PADDLE_ENFORCE_EQ(
      coo.initialized(),
      true,
      phi::errors::Fatal("SparseCooTensor variable `coo` is not initialized"));
  PADDLE_ENFORCE_EQ(
      coo.dims(),
      dense_dims,
      phi::errors::Fatal("`coo.dims()` is not equal to dense_dims"));

  // Test Resize
  auto dense_dims_3d = common::make_ddim({2, 4, 4});
  coo.Resize(dense_dims_3d, 1, 3);
  PADDLE_ENFORCE_EQ(
      coo.nnz(),
      3,
      phi::errors::Fatal("`coo.nnz()` is %d, but should be 3", coo.nnz()));

  // Test shallow_copy
  SparseCooTensor coo2(coo);
  PADDLE_ENFORCE_EQ(
      coo.dims(),
      coo2.dims(),
      phi::errors::Fatal("`coo.dims()` is not equal to `coo2.dims()`, "
                         "something wrong with shallow copy assignment"));

  // Test shallow_copy_assignment
  SparseCooTensor coo3 = coo2;
  CHECK(coo3.dims() == coo2.dims());
  PADDLE_ENFORCE_EQ(
      coo3.dims(),
      coo2.dims(),
      phi::errors::Fatal("`coo3.dims()` is not equal to `coo2.dims()`, "
                         "something wrong with shallow copy assignment"));
}

}  // namespace tests
}  // namespace phi
