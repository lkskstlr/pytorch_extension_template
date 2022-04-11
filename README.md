# PyTorch C++ Extension Template

This is a template that shows how to integrate PyTorch with C++. PyTorch has an excellent [tutorial](https://pytorch.org/tutorials/advanced/cpp_extension.html) with [code](https://github.com/pytorch/extension-cpp).

## Installation
Install PyTorch and LibTorch from the [webpage](https://pytorch.org/get-started/locally/). I recommend using a relatively new
version at the beginning of the project and then avoid upgrading. If a new feature becomes available and would be very beneficial
an upgrade is necessary. We will for now use the CPU only version because it makes installing & building much easier.

```shell script
# Create Conda env
conda create -n t-cpu python=3.10
conda activate t1.11

# Install pytorch
pip install torch torchvision torchaudio --extra-index-url https://download.pytorch.org/whl/cpu

# Download libtorch
cd thirdparty/libtorch && wget https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-1.11.0%2Bcpu.zip
unzip libtorch-cxx11-abi-shared-with-deps-1.11.0+cpu.zip
```

## Build Cpp Test
This is a **cmake project**, hence errors can be googled for and looking for cmake-related articles. It should be worked on
with a IDE that supports cmake. It is **crucial** that you have full IDE support without any problems! This includes at
least autocomplete and running a visual debugger with stepping functionality and debug symbols.

```shell script
mkdir build && cd build

# This is very handy to get a clean build
cd .. && rm -rf build && mkdir build && cd build

cmake .. -DPython_ROOT_DIR=/usr/wiss/koestlel/miniconda3/envs/t-cpu -DCMAKE_BUILD_TYPE=Debug # Use Release if it needs to be fast. The difference can be huge!
make -j
```
The `-DPython_ROOT_DIR=/usr/wiss/koestlel/miniconda3/envs/t-cpu` tells cmake where to look for python. The cmake output
**must** contain this line `Found Python: /usr/wiss/koestlel/miniconda3/envs/t-cpu/include/python3.10 (found version "3.10.4") found components: Development Development.Module Development.Embed`
with the path from the correct conda environment. You can get this path by `conda activate t-cpu && echo $CONDA_PREFIX`.
You also have to set this appropriately in your IDE.

## Use from Python
```shell script
conda activate t-cpu

# install
pip install -e .

# only if not done before
pip install jupyterlab

jupyter lab  # and then open notebooks/00-Test.ipynb
```