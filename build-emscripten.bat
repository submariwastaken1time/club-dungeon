cmake "-DCMAKE_TOOLCHAIN_FILE=E:/club-dungeon/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=E:/club-dungeon/emsdk-main/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake" "-DVCPKG_TARGET_TRIPLET=wasm32-emscripten" E:/club-dungeon -G Ninja -B E:/club-dungeon/build-emscripten
cmake --build E:/club-dungeon/build-emscripten
