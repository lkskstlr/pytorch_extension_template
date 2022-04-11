// Copyright (c) 2022 Lukas Koestler. All rights reserved.

#include "example.h"

// Make functions that are called often (> 1000 times or so) inline for speed
// You would not need to make this little code it's own function, it's just an example.
inline RAY_F add_elements(RAY_F a, RAY_F b) { return a + b; };

// I think we do not have to pass torch::Tensor by const ref, because
// (a) the pytorch example code doesn't and
// (b) the size is only 8 bytes
void raytracing::add(torch::Tensor a, torch::Tensor b, torch::Tensor out) {
  // See: https://pytorch.org/cppdocs/notes/tensor_basics.html

  auto a_a = a.accessor<RAY_F, 2>(); // can access elements quickly
  auto b_a = b.accessor<RAY_F, 2>(); // can access elements quickly
  auto out_a = out.accessor<RAY_F, 2>(); // can access elements

  #ifndef NDEBUG
  // This code will not run if compiled with DCMAKE_BUILD_TYPE=Release
  #endif

  for (int i = 0; i < a_a.size(0); i++) {
    for (int j = 0; j < a_a.size(1); j++) {
      out_a[i][j] = add_elements(a_a[i][j], b_a[i][j]);
    }
  }
}