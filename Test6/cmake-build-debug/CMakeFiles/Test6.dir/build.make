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
CMAKE_SOURCE_DIR = C:\Users\loghd\CLionProjects\Test6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\loghd\CLionProjects\Test6\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Test6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test6.dir/flags.make

CMakeFiles/Test6.dir/main.cpp.obj: CMakeFiles/Test6.dir/flags.make
CMakeFiles/Test6.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\loghd\CLionProjects\Test6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test6.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Test6.dir\main.cpp.obj -c C:\Users\loghd\CLionProjects\Test6\main.cpp

CMakeFiles/Test6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test6.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\loghd\CLionProjects\Test6\main.cpp > CMakeFiles\Test6.dir\main.cpp.i

CMakeFiles/Test6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test6.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\loghd\CLionProjects\Test6\main.cpp -o CMakeFiles\Test6.dir\main.cpp.s

# Object files for target Test6
Test6_OBJECTS = \
"CMakeFiles/Test6.dir/main.cpp.obj"

# External object files for target Test6
Test6_EXTERNAL_OBJECTS =

Test6.exe: CMakeFiles/Test6.dir/main.cpp.obj
Test6.exe: CMakeFiles/Test6.dir/build.make
Test6.exe: CMakeFiles/Test6.dir/linklibs.rsp
Test6.exe: CMakeFiles/Test6.dir/objects1.rsp
Test6.exe: CMakeFiles/Test6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\loghd\CLionProjects\Test6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Test6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test6.dir/build: Test6.exe

.PHONY : CMakeFiles/Test6.dir/build

CMakeFiles/Test6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Test6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Test6.dir/clean

CMakeFiles/Test6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\loghd\CLionProjects\Test6 C:\Users\loghd\CLionProjects\Test6 C:\Users\loghd\CLionProjects\Test6\cmake-build-debug C:\Users\loghd\CLionProjects\Test6\cmake-build-debug C:\Users\loghd\CLionProjects\Test6\cmake-build-debug\CMakeFiles\Test6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test6.dir/depend

