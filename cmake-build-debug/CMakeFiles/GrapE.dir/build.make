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

# Include any dependencies generated for this target.
include CMakeFiles\GrapE.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\GrapE.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\GrapE.dir\flags.make

CMakeFiles\GrapE.dir\main.cpp.obj: CMakeFiles\GrapE.dir\flags.make
CMakeFiles\GrapE.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GrapE.dir/main.cpp.obj"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GrapE.dir\main.cpp.obj /FdCMakeFiles\GrapE.dir\ /FS -c C:\Users\pierr\CLionProjects\GrapE\main.cpp
<<

CMakeFiles\GrapE.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrapE.dir/main.cpp.i"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe > CMakeFiles\GrapE.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pierr\CLionProjects\GrapE\main.cpp
<<

CMakeFiles\GrapE.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrapE.dir/main.cpp.s"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GrapE.dir\main.cpp.s /c C:\Users\pierr\CLionProjects\GrapE\main.cpp
<<

CMakeFiles\GrapE.dir\grp_window.cpp.obj: CMakeFiles\GrapE.dir\flags.make
CMakeFiles\GrapE.dir\grp_window.cpp.obj: ..\grp_window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GrapE.dir/grp_window.cpp.obj"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GrapE.dir\grp_window.cpp.obj /FdCMakeFiles\GrapE.dir\ /FS -c C:\Users\pierr\CLionProjects\GrapE\grp_window.cpp
<<

CMakeFiles\GrapE.dir\grp_window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrapE.dir/grp_window.cpp.i"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe > CMakeFiles\GrapE.dir\grp_window.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pierr\CLionProjects\GrapE\grp_window.cpp
<<

CMakeFiles\GrapE.dir\grp_window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrapE.dir/grp_window.cpp.s"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GrapE.dir\grp_window.cpp.s /c C:\Users\pierr\CLionProjects\GrapE\grp_window.cpp
<<

CMakeFiles\GrapE.dir\App.cpp.obj: CMakeFiles\GrapE.dir\flags.make
CMakeFiles\GrapE.dir\App.cpp.obj: ..\App.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GrapE.dir/App.cpp.obj"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GrapE.dir\App.cpp.obj /FdCMakeFiles\GrapE.dir\ /FS -c C:\Users\pierr\CLionProjects\GrapE\App.cpp
<<

CMakeFiles\GrapE.dir\App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrapE.dir/App.cpp.i"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe > CMakeFiles\GrapE.dir\App.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pierr\CLionProjects\GrapE\App.cpp
<<

CMakeFiles\GrapE.dir\App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrapE.dir/App.cpp.s"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GrapE.dir\App.cpp.s /c C:\Users\pierr\CLionProjects\GrapE\App.cpp
<<

CMakeFiles\GrapE.dir\grp_pipeline.cpp.obj: CMakeFiles\GrapE.dir\flags.make
CMakeFiles\GrapE.dir\grp_pipeline.cpp.obj: ..\grp_pipeline.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GrapE.dir/grp_pipeline.cpp.obj"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GrapE.dir\grp_pipeline.cpp.obj /FdCMakeFiles\GrapE.dir\ /FS -c C:\Users\pierr\CLionProjects\GrapE\grp_pipeline.cpp
<<

CMakeFiles\GrapE.dir\grp_pipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrapE.dir/grp_pipeline.cpp.i"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe > CMakeFiles\GrapE.dir\grp_pipeline.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pierr\CLionProjects\GrapE\grp_pipeline.cpp
<<

CMakeFiles\GrapE.dir\grp_pipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrapE.dir/grp_pipeline.cpp.s"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GrapE.dir\grp_pipeline.cpp.s /c C:\Users\pierr\CLionProjects\GrapE\grp_pipeline.cpp
<<

CMakeFiles\GrapE.dir\grp_device.cpp.obj: CMakeFiles\GrapE.dir\flags.make
CMakeFiles\GrapE.dir\grp_device.cpp.obj: ..\grp_device.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GrapE.dir/grp_device.cpp.obj"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GrapE.dir\grp_device.cpp.obj /FdCMakeFiles\GrapE.dir\ /FS -c C:\Users\pierr\CLionProjects\GrapE\grp_device.cpp
<<

CMakeFiles\GrapE.dir\grp_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrapE.dir/grp_device.cpp.i"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe > CMakeFiles\GrapE.dir\grp_device.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pierr\CLionProjects\GrapE\grp_device.cpp
<<

CMakeFiles\GrapE.dir\grp_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrapE.dir/grp_device.cpp.s"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GrapE.dir\grp_device.cpp.s /c C:\Users\pierr\CLionProjects\GrapE\grp_device.cpp
<<

CMakeFiles\GrapE.dir\grp_swap_chain.cpp.obj: CMakeFiles\GrapE.dir\flags.make
CMakeFiles\GrapE.dir\grp_swap_chain.cpp.obj: ..\grp_swap_chain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GrapE.dir/grp_swap_chain.cpp.obj"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GrapE.dir\grp_swap_chain.cpp.obj /FdCMakeFiles\GrapE.dir\ /FS -c C:\Users\pierr\CLionProjects\GrapE\grp_swap_chain.cpp
<<

CMakeFiles\GrapE.dir\grp_swap_chain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrapE.dir/grp_swap_chain.cpp.i"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe > CMakeFiles\GrapE.dir\grp_swap_chain.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pierr\CLionProjects\GrapE\grp_swap_chain.cpp
<<

CMakeFiles\GrapE.dir\grp_swap_chain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrapE.dir/grp_swap_chain.cpp.s"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GrapE.dir\grp_swap_chain.cpp.s /c C:\Users\pierr\CLionProjects\GrapE\grp_swap_chain.cpp
<<

CMakeFiles\GrapE.dir\grp_model.cpp.obj: CMakeFiles\GrapE.dir\flags.make
CMakeFiles\GrapE.dir\grp_model.cpp.obj: ..\grp_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GrapE.dir/grp_model.cpp.obj"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\GrapE.dir\grp_model.cpp.obj /FdCMakeFiles\GrapE.dir\ /FS -c C:\Users\pierr\CLionProjects\GrapE\grp_model.cpp
<<

CMakeFiles\GrapE.dir\grp_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrapE.dir/grp_model.cpp.i"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe > CMakeFiles\GrapE.dir\grp_model.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pierr\CLionProjects\GrapE\grp_model.cpp
<<

CMakeFiles\GrapE.dir\grp_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrapE.dir/grp_model.cpp.s"
	C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\GrapE.dir\grp_model.cpp.s /c C:\Users\pierr\CLionProjects\GrapE\grp_model.cpp
<<

# Object files for target GrapE
GrapE_OBJECTS = \
"CMakeFiles\GrapE.dir\main.cpp.obj" \
"CMakeFiles\GrapE.dir\grp_window.cpp.obj" \
"CMakeFiles\GrapE.dir\App.cpp.obj" \
"CMakeFiles\GrapE.dir\grp_pipeline.cpp.obj" \
"CMakeFiles\GrapE.dir\grp_device.cpp.obj" \
"CMakeFiles\GrapE.dir\grp_swap_chain.cpp.obj" \
"CMakeFiles\GrapE.dir\grp_model.cpp.obj"

# External object files for target GrapE
GrapE_EXTERNAL_OBJECTS =

GrapE.exe: CMakeFiles\GrapE.dir\main.cpp.obj
GrapE.exe: CMakeFiles\GrapE.dir\grp_window.cpp.obj
GrapE.exe: CMakeFiles\GrapE.dir\App.cpp.obj
GrapE.exe: CMakeFiles\GrapE.dir\grp_pipeline.cpp.obj
GrapE.exe: CMakeFiles\GrapE.dir\grp_device.cpp.obj
GrapE.exe: CMakeFiles\GrapE.dir\grp_swap_chain.cpp.obj
GrapE.exe: CMakeFiles\GrapE.dir\grp_model.cpp.obj
GrapE.exe: CMakeFiles\GrapE.dir\build.make
GrapE.exe: C:\VulkanSDK\1.2.189.2\Lib\vulkan-1.lib
GrapE.exe: C:\Libraries\glfw-3.3.4.bin.WIN64\lib-vc2019\glfw3.lib
GrapE.exe: CMakeFiles\GrapE.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable GrapE.exe"
	C:\Users\pierr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\GrapE.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\mt.exe --manifests -- C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1430~1.307\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\GrapE.dir\objects1.rsp @<<
 /out:GrapE.exe /implib:GrapE.lib /pdb:C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\GrapE.pdb /version:0.0 /machine:x64 /debug /INCREMENTAL /subsystem:console  C:\VulkanSDK\1.2.189.2\Lib\vulkan-1.lib C:\Libraries\glfw-3.3.4.bin.WIN64\lib-vc2019\glfw3.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	C:\Users\pierr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E make_directory C:/Users/pierr/CLionProjects/GrapE/cmake-build-debug/shaders/
	C:\Users\pierr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E copy_directory C:/Users/pierr/CLionProjects/GrapE/shaders C:/Users/pierr/CLionProjects/GrapE/cmake-build-debug/shaders

# Rule to build all files generated by this target.
CMakeFiles\GrapE.dir\build: GrapE.exe
.PHONY : CMakeFiles\GrapE.dir\build

CMakeFiles\GrapE.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GrapE.dir\cmake_clean.cmake
.PHONY : CMakeFiles\GrapE.dir\clean

CMakeFiles\GrapE.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\pierr\CLionProjects\GrapE C:\Users\pierr\CLionProjects\GrapE C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug C:\Users\pierr\CLionProjects\GrapE\cmake-build-debug\CMakeFiles\GrapE.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\GrapE.dir\depend
