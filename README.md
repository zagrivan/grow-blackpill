# build

## open container with vpn

-dependencies 
    Launch VS Code Quick Open (Ctrl+P), paste the following command, and press enter. 
    ```
    ext install ms-vscode-remote.remote-containers
    ```

Ctrl+Shift+P 
Enter
```
>Dev Containers: Reopen in Container
```

## build elf
```
mkdir -p build

cd build

cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_TOOLCHAIN_FILE=/workspaces/blackpill/cmake/gcc-arm-none-eabi.cmake -S /workspaces/blackpill -B /workspaces/blackpill/build

make -j $(nproc)
```

