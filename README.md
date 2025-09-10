# SimpleDeviceModule

**SimpleDeviceModule** is an example module demonstrating how to build and test a simple device module using the **openDAQ framework**.  
This repository can serve as a template for building other modules integrated with openDAQ.

---

## Prerequisites

- **CMake** (>= 3.25)  
- **Git**  
- **C++ compiler** (Visual Studio on Windows, GCC/Clang on Linux/macOS)  
- Optional: **openDAQ framework** installed locally or available via versioned checkout  

---

## Building the Project

There are two main ways to provide the openDAQ framework:

1. **Using a local openDAQ installation**  
  - Install the openDAQ package on your machine.  
  - Set the environment variable `OPENDAQ_ROOT` to the path containing the binaries.
  - Then CMake will automatically detect the binaries during configuration.

```bash
export OPENDAQ_ROOT=/path/to/opendaq

cmake -S . -B build/output \
  -G "Ninja" \
  -DEXAMPLE_MODULE_ENABLE_TESTS=ON \
  -DSIMPLE_DEVICE_MODULE_OPENDAQ_SDK_VER=3.20.4
```

2. **Using a specific openDAQ version via CMake**  
  - Pass the desired version using the `SIMPLE_DEVICE_MODULE_OPENDAQ_SDK_VER`.
  - CMake will perform a checkout of the openDAQ repository at the specified tag and build the minimal set of binaries needed to build the module and run tests.

```bash
cmake -S . -B build/output \
  -G "Ninja" \
  -DEXAMPLE_MODULE_ENABLE_TESTS=ON \
  -DSIMPLE_DEVICE_MODULE_OPENDAQ_SDK_VER=3.20.4
```

---

### Example: Build Module

```bash
cmake --build build/output --config Release
```

#### Note: 
- The flag `EXAMPLE_MODULE_ENABLE_TESTS=ON` is required if you want to build the module tests for subsequent execution.
- Building the module without `EXAMPLE_MODULE_ENABLE_TESTS=ON` will skip test compilation.
- Providing either `OPENDAQ_ROOT` or `SIMPLE_DEVICE_MODULE_OPENDAQ_SDK_VER` is mandatory for the module to find the required binaries.

### Running Tests
Once the build is complete:
```bash
ctest --test-dir build/output --output-on-failure -C Release -V
```
