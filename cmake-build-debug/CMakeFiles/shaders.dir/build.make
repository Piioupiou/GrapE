# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\pierr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\pierr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pierr\CLionProjects\GrapE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug

# Utility rule file for Shaders.

# Include any custom commands dependencies for this target.
include CMakeFiles\Shaders.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\Shaders.dir\progress.make

CMakeFiles\Shaders: ..\shaders\basic_shader.frag.spv
CMakeFiles\Shaders: ..\shaders\basic_shader.vert.spv

..\shaders\basic_shader.frag.spv: ..\shaders\basic_shader.frag
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../shaders/basic_shader.frag.spv"
	C:\Users\pierr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E make_directory C:/Users/pierr/CLionProjects/GrapE/shaders/
	C:\VulkanSDK\1.2.189.2\Bin\glslangValidator.exe -V C:/Users/pierr/CLionProjects/GrapE/shaders/basic_shader.frag -o C:/Users/pierr/CLionProjects/GrapE/shaders/basic_shader.frag.spv

..\shaders\basic_shader.vert.spv: ..\shaders\basic_shader.vert
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating ../shaders/basic_shader.vert.spv"
	C:\Users\pierr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E make_directory C:/Users/pierr/CLionProjects/GrapE/shaders/
	C:\VulkanSDK\1.2.189.2\Bin\glslangValidator.exe -V C:/Users/pierr/CLionProjects/GrapE/shaders/basic_shader.vert -o C:/Users/pierr/CLionProjects/GrapE/shaders/basic_shader.vert.spv

Shaders: CMakeFiles\Shaders
Shaders: ..\shaders\basic_shader.frag.spv
Shaders: ..\shaders\basic_shader.vert.spv
Shaders: CMakeFiles\Shaders.dir\build.make
.PHONY : Shaders

# Rule to build all files generated by this target.
CMakeFiles\Shaders.dir\build: Shaders
.PHONY : CMakeFiles\Shaders.dir\build

CMakeFiles\Shaders.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Shaders.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Shaders.dir\clean

CMakeFiles\Shaders.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\pierr\CLionProjects\GrapE C:\Users\pierr\CLionProjects\GrapE C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles\shaders.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Shaders.dir\depend

