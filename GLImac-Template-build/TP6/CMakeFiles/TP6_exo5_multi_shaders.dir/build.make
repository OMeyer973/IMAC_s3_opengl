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
CMAKE_SOURCE_DIR = /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build

# Include any dependencies generated for this target.
include TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/depend.make

# Include the progress variables for this target.
include TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/progress.make

# Include the compile flags for this target's objects.
include TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/flags.make

TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o: TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/flags.make
TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o: /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP6/exo5_multi_shaders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o"
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP6 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o -c /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP6/exo5_multi_shaders.cpp

TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.i"
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP6 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP6/exo5_multi_shaders.cpp > CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.i

TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.s"
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP6 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP6/exo5_multi_shaders.cpp -o CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.s

TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o.requires:

.PHONY : TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o.requires

TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o.provides: TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o.requires
	$(MAKE) -f TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/build.make TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o.provides.build
.PHONY : TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o.provides

TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o.provides.build: TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o


# Object files for target TP6_exo5_multi_shaders
TP6_exo5_multi_shaders_OBJECTS = \
"CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o"

# External object files for target TP6_exo5_multi_shaders
TP6_exo5_multi_shaders_EXTERNAL_OBJECTS =

TP6/TP6_exo5_multi_shaders: TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o
TP6/TP6_exo5_multi_shaders: TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/build.make
TP6/TP6_exo5_multi_shaders: glimac/libglimac.a
TP6/TP6_exo5_multi_shaders: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP6/TP6_exo5_multi_shaders: /usr/lib/x86_64-linux-gnu/libSDL.so
TP6/TP6_exo5_multi_shaders: /usr/lib/x86_64-linux-gnu/libGL.so
TP6/TP6_exo5_multi_shaders: /usr/lib/x86_64-linux-gnu/libGLU.so
TP6/TP6_exo5_multi_shaders: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP6/TP6_exo5_multi_shaders: TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP6_exo5_multi_shaders"
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP6 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP6_exo5_multi_shaders.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/build: TP6/TP6_exo5_multi_shaders

.PHONY : TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/build

TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/requires: TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/exo5_multi_shaders.cpp.o.requires

.PHONY : TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/requires

TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/clean:
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP6 && $(CMAKE_COMMAND) -P CMakeFiles/TP6_exo5_multi_shaders.dir/cmake_clean.cmake
.PHONY : TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/clean

TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/depend:
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP6 /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP6 /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP6/CMakeFiles/TP6_exo5_multi_shaders.dir/depend
