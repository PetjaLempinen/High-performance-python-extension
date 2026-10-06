import os
import sys
import subprocess
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

class CMakeExtension(Extension):
    def __init__(self, name, sourcedir=""):
        super().__init__(name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)

class CMakeBuild(build_ext):
    def run(self):
        try:
            subprocess.check_output(["cmake", "--version"])
        except OSError:
            raise RuntimeError("CMake must be installed to build the following extensions: " + ", ".join(e.name for e in self.extensions))

        for ext in self.extensions:
            extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
            cmake_args = [
                f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={extdir}",
                f"-DPYTHON_EXECUTABLE={sys.executable}",
            ]
            
            cfg = "Debug" if self.debug else "Release"
            build_args = ["--config", cfg]

            if not os.path.exists(self.build_temp):
                os.makedirs(self.build_temp)

            subprocess.check_call(["cmake", ext.sourcedir] + cmake_args, cwd=self.build_temp)
            subprocess.check_call(["cmake", "--build", "."] + build_args, cwd=self.build_temp)

setup(
    name="pathfinder_ext",
    version="0.1.0",
    author="Petja Lempinen",
    description="High-performance C++ A* pathfinder extension",
    ext_modules=[CMakeExtension("pathfinder_ext")],
    packages=[],
    cmdclass={"build_ext": CMakeBuild},
    zip_safe=False,
)