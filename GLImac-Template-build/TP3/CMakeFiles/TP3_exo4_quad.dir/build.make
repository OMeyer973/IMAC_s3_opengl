# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/olivier/Documents/openGL/GLImac-Template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/olivier/Documents/openGL/GLImac-Template-build

# Include any dependencies generated for this target.
include TP3/CMakeFiles/TP3_exo4_quad.dir/depend.make

# Include the progress variables for this target.
include TP3/CMakeFiles/TP3_exo4_quad.dir/progress.make

# Include the compile flags for this target's objects.
include TP3/CMakeFiles/TP3_exo4_quad.dir/flags.make

TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o: TP3/CMakeFiles/TP3_exo4_quad.dir/flags.make
TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o: /home/olivier/Documents/openGL/GLImac-Template/TP3/exo4_quad.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olivier/Documents/openGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o"
	cd /home/olivier/Documents/openGL/GLImac-Template-build/TP3 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o -c /home/olivier/Documents/openGL/GLImac-Template/TP3/exo4_quad.cpp

TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.i"
	cd /home/olivier/Documents/openGL/GLImac-Template-build/TP3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olivier/Documents/openGL/GLImac-Template/TP3/exo4_quad.cpp > CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.i

TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.s"
	cd /home/olivier/Documents/openGL/GLImac-Template-build/TP3 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olivier/Documents/openGL/GLImac-Template/TP3/exo4_quad.cpp -o CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.s

TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o.requires:

.PHONY : TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o.requires

TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o.provides: TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o.requires
	$(MAKE) -f TP3/CMakeFiles/TP3_exo4_quad.dir/build.make TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o.provides.build
.PHONY : TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o.provides

TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o.provides.build: TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o


# Object files for target TP3_exo4_quad
TP3_exo4_quad_OBJECTS = \
"CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o"

# External object files for target TP3_exo4_quad
TP3_exo4_quad_EXTERNAL_OBJECTS =

TP3/TP3_exo4_quad: TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o
TP3/TP3_exo4_quad: TP3/CMakeFiles/TP3_exo4_quad.dir/build.make
TP3/TP3_exo4_quad: glimac/libglimac.a
TP3/TP3_exo4_quad: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP3/TP3_exo4_quad: /usr/lib/x86_64-linux-gnu/libSDL.so
TP3/TP3_exo4_quad: /usr/lib/x86_64-linux-gnu/libGL.so
TP3/TP3_exo4_quad: /usr/lib/x86_64-linux-gnu/libGLU.so
TP3/TP3_exo4_quad: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP3/TP3_exo4_quad: TP3/CMakeFiles/TP3_exo4_quad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olivier/Documents/openGL/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP3_exo4_quad"
	cd /home/olivier/Documents/openGL/GLImac-Template-build/TP3 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP3_exo4_quad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP3/CMakeFiles/TP3_exo4_quad.dir/build: TP3/TP3_exo4_quad

.PHONY : TP3/CMakeFiles/TP3_exo4_quad.dir/build

TP3/CMakeFiles/TP3_exo4_quad.dir/requires: TP3/CMakeFiles/TP3_exo4_quad.dir/exo4_quad.cpp.o.requires

.PHONY : TP3/CMakeFiles/TP3_exo4_quad.dir/requires

TP3/CMakeFiles/TP3_exo4_quad.dir/clean:
	cd /home/olivier/Documents/openGL/GLImac-Template-build/TP3 && $(CMAKE_COMMAND) -P CMakeFiles/TP3_exo4_quad.dir/cmake_clean.cmake
.PHONY : TP3/CMakeFiles/TP3_exo4_quad.dir/clean

TP3/CMakeFiles/TP3_exo4_quad.dir/depend:
	cd /home/olivier/Documents/openGL/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olivier/Documents/openGL/GLImac-Template /home/olivier/Documents/openGL/GLImac-Template/TP3 /home/olivier/Documents/openGL/GLImac-Template-build /home/olivier/Documents/openGL/GLImac-Template-build/TP3 /home/olivier/Documents/openGL/GLImac-Template-build/TP3/CMakeFiles/TP3_exo4_quad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP3/CMakeFiles/TP3_exo4_quad.dir/depend

