# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Learning\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Learning\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Dmitry\CLionProjects\K1C_exam_task

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Dmitry\CLionProjects\K1C_exam_task\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/K1C_exam_task.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/K1C_exam_task.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/K1C_exam_task.dir/flags.make

CMakeFiles/K1C_exam_task.dir/main.cpp.obj: CMakeFiles/K1C_exam_task.dir/flags.make
CMakeFiles/K1C_exam_task.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Dmitry\CLionProjects\K1C_exam_task\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/K1C_exam_task.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\K1C_exam_task.dir\main.cpp.obj -c C:\Users\Dmitry\CLionProjects\K1C_exam_task\main.cpp

CMakeFiles/K1C_exam_task.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/K1C_exam_task.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Dmitry\CLionProjects\K1C_exam_task\main.cpp > CMakeFiles\K1C_exam_task.dir\main.cpp.i

CMakeFiles/K1C_exam_task.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/K1C_exam_task.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Dmitry\CLionProjects\K1C_exam_task\main.cpp -o CMakeFiles\K1C_exam_task.dir\main.cpp.s

# Object files for target K1C_exam_task
K1C_exam_task_OBJECTS = \
"CMakeFiles/K1C_exam_task.dir/main.cpp.obj"

# External object files for target K1C_exam_task
K1C_exam_task_EXTERNAL_OBJECTS =

K1C_exam_task.exe: CMakeFiles/K1C_exam_task.dir/main.cpp.obj
K1C_exam_task.exe: CMakeFiles/K1C_exam_task.dir/build.make
K1C_exam_task.exe: CMakeFiles/K1C_exam_task.dir/linklibs.rsp
K1C_exam_task.exe: CMakeFiles/K1C_exam_task.dir/objects1.rsp
K1C_exam_task.exe: CMakeFiles/K1C_exam_task.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Dmitry\CLionProjects\K1C_exam_task\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable K1C_exam_task.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\K1C_exam_task.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/K1C_exam_task.dir/build: K1C_exam_task.exe

.PHONY : CMakeFiles/K1C_exam_task.dir/build

CMakeFiles/K1C_exam_task.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\K1C_exam_task.dir\cmake_clean.cmake
.PHONY : CMakeFiles/K1C_exam_task.dir/clean

CMakeFiles/K1C_exam_task.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Dmitry\CLionProjects\K1C_exam_task C:\Users\Dmitry\CLionProjects\K1C_exam_task C:\Users\Dmitry\CLionProjects\K1C_exam_task\cmake-build-debug C:\Users\Dmitry\CLionProjects\K1C_exam_task\cmake-build-debug C:\Users\Dmitry\CLionProjects\K1C_exam_task\cmake-build-debug\CMakeFiles\K1C_exam_task.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/K1C_exam_task.dir/depend

