Steps to reproduce

cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build
cmake --build build
cd build
./repro.out
