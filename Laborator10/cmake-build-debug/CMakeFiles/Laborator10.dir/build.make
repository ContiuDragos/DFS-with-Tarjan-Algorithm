# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = "D:\C_lion\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\C_lion\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\pb de c\AF\Laborator10"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\pb de c\AF\Laborator10\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Laborator10.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Laborator10.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Laborator10.dir\flags.make

CMakeFiles\Laborator10.dir\main.cpp.obj: CMakeFiles\Laborator10.dir\flags.make
CMakeFiles\Laborator10.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\pb de c\AF\Laborator10\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Laborator10.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Laborator10.dir\main.cpp.obj /FdCMakeFiles\Laborator10.dir\ /FS -c "D:\pb de c\AF\Laborator10\main.cpp"
<<

CMakeFiles\Laborator10.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Laborator10.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\Laborator10.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\pb de c\AF\Laborator10\main.cpp"
<<

CMakeFiles\Laborator10.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Laborator10.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Laborator10.dir\main.cpp.s /c "D:\pb de c\AF\Laborator10\main.cpp"
<<

# Object files for target Laborator10
Laborator10_OBJECTS = \
"CMakeFiles\Laborator10.dir\main.cpp.obj"

# External object files for target Laborator10
Laborator10_EXTERNAL_OBJECTS =

Laborator10.exe: CMakeFiles\Laborator10.dir\main.cpp.obj
Laborator10.exe: CMakeFiles\Laborator10.dir\build.make
Laborator10.exe: CMakeFiles\Laborator10.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\pb de c\AF\Laborator10\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Laborator10.exe"
	"D:\C_lion\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Laborator10.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Laborator10.dir\objects1.rsp @<<
 /out:Laborator10.exe /implib:Laborator10.lib /pdb:"D:\pb de c\AF\Laborator10\cmake-build-debug\Laborator10.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Laborator10.dir\build: Laborator10.exe

.PHONY : CMakeFiles\Laborator10.dir\build

CMakeFiles\Laborator10.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Laborator10.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Laborator10.dir\clean

CMakeFiles\Laborator10.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\pb de c\AF\Laborator10" "D:\pb de c\AF\Laborator10" "D:\pb de c\AF\Laborator10\cmake-build-debug" "D:\pb de c\AF\Laborator10\cmake-build-debug" "D:\pb de c\AF\Laborator10\cmake-build-debug\CMakeFiles\Laborator10.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Laborator10.dir\depend

