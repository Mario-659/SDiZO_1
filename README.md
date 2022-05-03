# Struktury Danych i Złożoność Obliczeniowa
The purpose of this college project was to measure efficiency of adding, removing and finding values in implemented data structures.

Structures:

- Array (allocated dynamically)
- Doubly Linked List
- Heap (maximum type)
- Binary Search Tree

## Building with CMake
Generate Makefile: `PS C:\Algorithms\build> cmake .. -G "MinGW Makefiles"`. Use `cmake --help` to see other generator flags

Then use make: `PS C:\Algorithms\build> make`

Google test and tst_perf might not be compiled with some compilers. Because of that it is commented out in CMakeLists.txt. Also note that when compiling from CLion .exe might not work from command line