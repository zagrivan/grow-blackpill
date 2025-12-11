# build

open container with vpn

```
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_TOOLCHAIN_FILE=/workspaces/blackpill/cmake/gcc-arm-none-eabi.cmake -S /workspaces/blackpill -B /workspaces/blackpill/build
```