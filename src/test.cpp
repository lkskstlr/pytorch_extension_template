// Copyright (c) 2022 Lukas Koestler. All rights reserved.

#include "example.h"
#include <iostream>


int main(int argc, char **argv) {
  // Could also pass as args
  constexpr int N = 100;
  constexpr int M = 20;
  constexpr uint64_t seed = 0;
  constexpr RAY_F eps = 1e-6;

  // options. we will use double=float64 for now
  // this is slower but we don't have accuracy problems
  auto opt = torch::TensorOptions().dtype(torch::kFloat64).layout(torch::kStrided).device(torch::kCPU);

  // make data
  torch::manual_seed(seed);
  auto a = torch::rand({N, M}, opt);
  auto b = torch::rand({N, M}, opt);
  auto out = torch::empty({N, M}, opt);
//  auto out = torch::empty_like(a);  // the _like functions are also very useful
  auto out_ref = a + b;

  // Call our function
  raytracing::add(a, b, out);
  auto error = torch::mean(torch::square(out - out_ref)).item().toDouble();

  // Display Error
  std::cout << "Error: " << error << std::endl;

  if (error < eps)
    return EXIT_SUCCESS;
  return EXIT_FAILURE;
}