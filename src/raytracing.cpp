// Copyright (c) 2022 Lukas Koestler. All rights reserved.

#include <torch/extension.h>
#include "example.h"

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def("add", &raytracing::add, "Add two double tensors");
}
