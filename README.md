### Building with CMake
Generate Makefile: `PS C:\Algorithms\build> cmake .. -G "MinGW Makefiles"`.
Use `cmake --help` to see other generator flags

Then use make: `PS C:\Algorithms\build> make`

For some reason it cannot compile google test (maybe try setting cxx version after including google test or/and change to lower cmake version?). Because of that comment out google test in main `CMakeLists.txt`

Also note that when compiling from CLion `.exe` doesn't work from command line