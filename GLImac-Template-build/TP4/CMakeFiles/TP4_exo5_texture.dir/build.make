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
include TP4/CMakeFiles/TP4_exo5_texture.dir/depend.make

# Include the progress variables for this target.
include TP4/CMakeFiles/TP4_exo5_texture.dir/progress.make

# Include the compile flags for this target's objects.
include TP4/CMakeFiles/TP4_exo5_texture.dir/flags.make

TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o: TP4/CMakeFiles/TP4_exo5_texture.dir/flags.make
TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o: /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP4/exo5_texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o"
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP4 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o -c /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP4/exo5_texture.cpp

TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.i"
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP4/exo5_texture.cpp > CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.i

TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.s"
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP4/exo5_texture.cpp -o CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.s

TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o.requires:

.PHONY : TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o.requires

TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o.provides: TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o.requires
	$(MAKE) -f TP4/CMakeFiles/TP4_exo5_texture.dir/build.make TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o.provides.build
.PHONY : TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o.provides

TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o.provides.build: TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o


# Object files for target TP4_exo5_texture
TP4_exo5_texture_OBJECTS = \
"CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o"

# External object files for target TP4_exo5_texture
TP4_exo5_texture_EXTERNAL_OBJECTS =

TP4/TP4_exo5_texture: TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o
TP4/TP4_exo5_texture: TP4/CMakeFiles/TP4_exo5_texture.dir/build.make
TP4/TP4_exo5_texture: glimac/libglimac.a
TP4/TP4_exo5_texture: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP4/TP4_exo5_texture: /usr/lib/x86_64-linux-gnu/libSDL.so
TP4/TP4_exo5_texture: /usr/lib/x86_64-linux-gnu/libGL.so
TP4/TP4_exo5_texture: /usr/lib/x86_64-linux-gnu/libGLU.so
TP4/TP4_exo5_texture: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP4/TP4_exo5_texture: TP4/CMakeFiles/TP4_exo5_texture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP4_exo5_texture"
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP4 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP4_exo5_texture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP4/CMakeFiles/TP4_exo5_texture.dir/build: TP4/TP4_exo5_texture

.PHONY : TP4/CMakeFiles/TP4_exo5_texture.dir/build

TP4/CMakeFiles/TP4_exo5_texture.dir/requires: TP4/CMakeFiles/TP4_exo5_texture.dir/exo5_texture.cpp.o.requires

.PHONY : TP4/CMakeFiles/TP4_exo5_texture.dir/requires

TP4/CMakeFiles/TP4_exo5_texture.dir/clean:
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP4 && $(CMAKE_COMMAND) -P CMakeFiles/TP4_exo5_texture.dir/cmake_clean.cmake
.PHONY : TP4/CMakeFiles/TP4_exo5_texture.dir/clean

TP4/CMakeFiles/TP4_exo5_texture.dir/depend:
	cd /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template/TP4 /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP4 /home/olivier/Documents/IMAC_s3_opengl/GLImac-Template-build/TP4/CMakeFiles/TP4_exo5_texture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP4/CMakeFiles/TP4_exo5_texture.dir/depend

