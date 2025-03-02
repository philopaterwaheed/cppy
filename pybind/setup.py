from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        "module_name",
        ["module_making.cpp"],
        include_dirs=[pybind11.get_include()],
        language="c++",
    ),
]

setup(
    name="module_name",
    ext_modules=ext_modules,
)
