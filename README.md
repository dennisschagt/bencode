Bencode
=======
Bencode is a library for parsing bencoded text. The bencode encoding is specified in the [BitTorrent specification](https://wiki.theory.org/BitTorrentSpecification#Bencoding).

### Compiling
Bencode can be build with CMake. CMake can be downloaded from [cmake.org](http://www.cmake.org/download/) but is also available in most package managers. To build in a directory called `build`, navigate to the root of the repository and execute the following commands:
```
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
```

Here `..` is the path to the directory containing the root `CMakeLists.txt` file, relative to the build directory. `"Unix Makefiles"` specifies the makefile generator that should be used, in this case the generator for Unix and Cygwin. You can replace it by other generators, e.g. `"MinGW Makefiles"`. More of these generators can be found on the [CMake wiki](http://www.cmake.org/Wiki/CMake_Generator_Specific_Information#Makefile_generators).
