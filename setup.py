from os.path import join, dirname, realpath
from setuptools import setup
from torch.utils.cpp_extension import BuildExtension, CppExtension

include_dir = realpath(join(dirname(__file__), "include"))
src_dir = join(dirname(__file__), "src")

setup(
    name='raytracing_cpp',
    ext_modules=[
        CppExtension(
            name='raytracing_cpp',
            sources=[join(src_dir, 'raytracing.cpp'), join(src_dir, 'example.cpp')],
            include_dirs=[include_dir],
            # Comment out the following line to get a debug build
            extra_compile_args={'cxx': ['-O3', '-DNDEBUG']},
        )
    ],
    cmdclass={
        'build_ext': BuildExtension
    },
)
