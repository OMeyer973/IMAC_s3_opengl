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
CMAKE_SOURCE_DIR = /home/nicolass/Bureau/OPENGL/GLImac-Template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nicolass/Bureau/OPENGL/GLImac-Template

# Include any dependencies generated for this target.
include TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/depend.make

# Include the progress variables for this target.
include TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/progress.make

# Include the compile flags for this target's objects.
include TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/flags.make

TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o: TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/flags.make
TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o: TP1/exo6_quad_IBO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nicolass/Bureau/OPENGL/GLImac-Template/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o"
	cd /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o -c /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1/exo6_quad_IBO.cpp

TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.i"
	cd /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1/exo6_quad_IBO.cpp > CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.i

TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.s"
	cd /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1/exo6_quad_IBO.cpp -o CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.s

TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o.requires:

.PHONY : TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o.requires

TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o.provides: TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o.requires
	$(MAKE) -f TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/build.make TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o.provides.build
.PHONY : TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o.provides

TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o.provides.build: TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o


# Object files for target TP1_exo6_quad_IBO
TP1_exo6_quad_IBO_OBJECTS = \
"CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o"

# External object files for target TP1_exo6_quad_IBO
TP1_exo6_quad_IBO_EXTERNAL_OBJECTS =

TP1/TP1_exo6_quad_IBO: TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o
TP1/TP1_exo6_quad_IBO: TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/build.make
TP1/TP1_exo6_quad_IBO: glimac/libglimac.a
TP1/TP1_exo6_quad_IBO: /usr/lib/x86_64-linux-gnu/libSDLmain.a
TP1/TP1_exo6_quad_IBO: /usr/lib/x86_64-linux-gnu/libSDL.so
TP1/TP1_exo6_quad_IBO: /usr/lib/x86_64-linux-gnu/libGL.so
TP1/TP1_exo6_quad_IBO: /usr/lib/x86_64-linux-gnu/libGLU.so
TP1/TP1_exo6_quad_IBO: /usr/lib/x86_64-linux-gnu/libGLEW.so
TP1/TP1_exo6_quad_IBO: TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nicolass/Bureau/OPENGL/GLImac-Template/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TP1_exo6_quad_IBO"
	cd /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP1_exo6_quad_IBO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/build: TP1/TP1_exo6_quad_IBO

.PHONY : TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/build

TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/requires: TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/exo6_quad_IBO.cpp.o.requires

.PHONY : TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/requires

TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/clean:
	cd /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1 && $(CMAKE_COMMAND) -P CMakeFiles/TP1_exo6_quad_IBO.dir/cmake_clean.cmake
.PHONY : TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/clean

TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/depend:
	cd /home/nicolass/Bureau/OPENGL/GLImac-Template && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nicolass/Bureau/OPENGL/GLImac-Template /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1 /home/nicolass/Bureau/OPENGL/GLImac-Template /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1 /home/nicolass/Bureau/OPENGL/GLImac-Template/TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : TP1/CMakeFiles/TP1_exo6_quad_IBO.dir/depend

