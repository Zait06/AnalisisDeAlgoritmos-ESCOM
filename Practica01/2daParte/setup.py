from distutils.core import setup
from Cython.Build import cythonize

setup(ext_modules = cythonize('algoritmos00.pyx'))

# python3 setup.py build_ext --inplace