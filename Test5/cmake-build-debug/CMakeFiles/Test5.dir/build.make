# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\loghd\CLionProjects\Test5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\loghd\CLionProjects\Test5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Test5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test5.dir/flags.make

CMakeFiles/Test5.dir/main.cpp.obj: CMakeFiles/Test5.dir/flags.make
CMakeFiles/Test5.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loghd\CLionProjects\Test5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test5.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Test5.dir\main.cpp.obj -c C:\Users\loghd\CLionProjects\Test5\main.cpp

CMakeFiles/Test5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test5.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\loghd\CLionProjects\Test5\main.cpp > CMakeFiles\Test5.dir\main.cpp.i

CMakeFiles/Test5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test5.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\loghd\CLionProjects\Test5\main.cpp -o CMakeFiles\Test5.dir\main.cpp.s

# Object files for target Test5
Test5_OBJECTS = \
"CMakeFiles/Test5.dir/main.cpp.obj"

# External object files for target Test5
Test5_EXTERNAL_OBJECTS =

Test5.exe: CMakeFiles/Test5.dir/main.cpp.obj
Test5.exe: CMakeFiles/Test5.dir/build.make
Test5.exe: CMakeFiles/Test5.dir/linklibs.rsp
Test5.exe: CMakeFiles/Test5.dir/objects1.rsp
Test5.exe: CMakeFiles/Test5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\loghd\CLionProjects\Test5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Test5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test5.dir/build: Test5.exe

.PHONY : CMakeFiles/Test5.dir/build

CMakeFiles/Test5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Test5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Test5.dir/clean

CMakeFiles/Test5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\loghd\CLionProjects\Test5 C:\Users\loghd\CLionProjects\Test5 C:\Users\loghd\CLionProjects\Test5\cmake-build-debug C:\Users\loghd\CLionProjects\Test5\cmake-build-debug C:\Users\loghd\CLionProjects\Test5\cmake-build-debug\CMakeFiles\Test5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test5.dir/depend

