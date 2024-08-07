// Copyright (c) 2024 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "paddle/pir/include/dialect/shape/utils/shape_analysis.h"

namespace paddle::dialect {
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(AffineGrid)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(All)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Amax)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Amin)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Any)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Argmax)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Argmin)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(AsComplex)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(AsReal)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Assign)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Assign_)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(AllReduce)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(AllReduce_)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(Barrier)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(BipartiteMatch)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Cast)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Cast_)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Cholesky)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(ClipByNorm)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(ClipByNormSr)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Cummax)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Cummin)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Cumprod)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Cumprod_)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Cumsum)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Cumsum_)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(ChannelShuffle)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(Crop)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(DecodeJpeg)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Diag)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(DiagEmbed)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Diagonal)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(DistributeFpnProposals)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Eigh)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Eigvalsh)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(FractionalMaxPool2D)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(FractionalMaxPool3D)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(FakeChannelWiseQuantizeAbsMax)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(FftC2c)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(FftC2r)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(FftR2c)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(FillDiagonal)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(FillDiagonal_)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Flatten)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Flatten_)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(GumbelSoftmax)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(IdentityLoss)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(IdentityLoss_)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Kthvalue)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(LpPool2d)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Logcumsumexp)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Logsumexp)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Max)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Maxout)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Min)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(MeanAll)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(MatrixPower)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(MatrixRank)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(MaxPool2DWithIndex)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(MaxPool3DWithIndex)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(Multinomial)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(Nanmedian)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(Norm)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Nonzero)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Numel)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(P_Norm)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(PartialSum)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Pad)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Pad3d)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Pool2d)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Prod)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(RepeatInterleave)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Reshape)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Reshape_)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Shape)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(ShapeSr)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Slice)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Split)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(SplitWithNum)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Squeeze)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Squeeze_)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Sum)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(SetValueWithTensor)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(Trace)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Tile)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Topk)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(TopkV1)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Transpose)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Transpose_)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Unbind)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Unique)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(UniqueConsecutive)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Unsqueeze)
OP_DECLARE_INFER_SYMBOLIC_SHAPE(Unsqueeze_)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(Unfold)
// OP_DECLARE_INFER_SYMBOLIC_SHAPE(Unstack)

}  // namespace paddle::dialect
