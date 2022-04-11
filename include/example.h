// Copyright (c) 2022 Lukas Koestler. All rights reserved.

#ifndef RAYTRACING_EXAMPLE_H
#define RAYTRACING_EXAMPLE_H

#include "types.h"
#include <torch/torch.h>

namespace raytracing {

/* Compute out = a+b */
// We will always give the output as arguments because then we do not have to deal with memory allocation
void add(torch::Tensor a, torch::Tensor b, torch::Tensor out);

} // namespace raytracing

#endif //RAYTRACING_EXAMPLE_H
