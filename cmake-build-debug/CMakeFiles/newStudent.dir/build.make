# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Paulius\CLionProjects\newStudent

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Paulius\CLionProjects\newStudent\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\newStudent.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\newStudent.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\newStudent.dir\flags.make

CMakeFiles\newStudent.dir\main.cpp.obj: CMakeFiles\newStudent.dir\flags.make
CMakeFiles\newStudent.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Paulius\CLionProjects\newStudent\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/newStudent.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\newStudent.dir\main.cpp.obj /FdCMakeFiles\newStudent.dir\ /FS -c C:\Users\Paulius\CLionProjects\newStudent\main.cpp
<<

CMakeFiles\newStudent.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/newStudent.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\newStudent.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Paulius\CLionProjects\newStudent\main.cpp
<<

CMakeFiles\newStudent.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/newStudent.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\newStudent.dir\main.cpp.s /c C:\Users\Paulius\CLionProjects\newStudent\main.cpp
<<

CMakeFiles\newStudent.dir\main.cpp.obj.requires:

.PHONY : CMakeFiles\newStudent.dir\main.cpp.obj.requires

CMakeFiles\newStudent.dir\main.cpp.obj.provides: CMakeFiles\newStudent.dir\main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\newStudent.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\newStudent.dir\main.cpp.obj.provides.build
.PHONY : CMakeFiles\newStudent.dir\main.cpp.obj.provides

CMakeFiles\newStudent.dir\main.cpp.obj.provides.build: CMakeFiles\newStudent.dir\main.cpp.obj


# Object files for target newStudent
newStudent_OBJECTS = \
"CMakeFiles\newStudent.dir\main.cpp.obj"

# External object files for target newStudent
newStudent_EXTERNAL_OBJECTS =

newStudent.exe: CMakeFiles\newStudent.dir\main.cpp.obj
newStudent.exe: CMakeFiles\newStudent.dir\build.make
newStudent.exe: CMakeFiles\newStudent.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Paulius\CLionProjects\newStudent\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable newStudent.exe"
	"C:\Program Files\JetBrains\CLion 2018.1.3\bin\cmake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\newStudent.dir --manifests  -- C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\newStudent.dir\objects1.rsp @<<
 /out:newStudent.exe /implib:newStudent.lib /pdb:C:\Users\Paulius\CLionProjects\newStudent\cmake-build-debug\newStudent.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\newStudent.dir\build: newStudent.exe

.PHONY : CMakeFiles\newStudent.dir\build

CMakeFiles\newStudent.dir\requires: CMakeFiles\newStudent.dir\main.cpp.obj.requires

.PHONY : CMakeFiles\newStudent.dir\requires

CMakeFiles\newStudent.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\newStudent.dir\cmake_clean.cmake
.PHONY : CMakeFiles\newStudent.dir\clean

CMakeFiles\newStudent.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Paulius\CLionProjects\newStudent C:\Users\Paulius\CLionProjects\newStudent C:\Users\Paulius\CLionProjects\newStudent\cmake-build-debug C:\Users\Paulius\CLionProjects\newStudent\cmake-build-debug C:\Users\Paulius\CLionProjects\newStudent\cmake-build-debug\CMakeFiles\newStudent.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\newStudent.dir\depend

