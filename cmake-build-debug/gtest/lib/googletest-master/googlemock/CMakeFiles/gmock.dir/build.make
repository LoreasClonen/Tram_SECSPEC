# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /opt/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/uauser/CLionProjects/Tram_SecSpec_4_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug

# Include any dependencies generated for this target.
include gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make
gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o: ../gtest/lib/googletest-master/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o"
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o -c /home/uauser/CLionProjects/Tram_SecSpec_4_5/gtest/lib/googletest-master/googletest/src/gtest-all.cc

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i"
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uauser/CLionProjects/Tram_SecSpec_4_5/gtest/lib/googletest-master/googletest/src/gtest-all.cc > CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.i

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s"
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uauser/CLionProjects/Tram_SecSpec_4_5/gtest/lib/googletest-master/googletest/src/gtest-all.cc -o CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.s

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires:

.PHONY : gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build.make gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build
.PHONY : gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.provides.build: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o


gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/flags.make
gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../gtest/lib/googletest-master/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /home/uauser/CLionProjects/Tram_SecSpec_4_5/gtest/lib/googletest-master/googlemock/src/gmock-all.cc

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uauser/CLionProjects/Tram_SecSpec_4_5/gtest/lib/googletest-master/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uauser/CLionProjects/Tram_SecSpec_4_5/gtest/lib/googletest-master/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires:

.PHONY : gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build.make gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build
.PHONY : gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.provides.build: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o


# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

gtest/lib/googletest-master/googlemock/libgmock.a: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o
gtest/lib/googletest-master/googlemock/libgmock.a: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
gtest/lib/googletest-master/googlemock/libgmock.a: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build.make
gtest/lib/googletest-master/googlemock/libgmock.a: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgmock.a"
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build: gtest/lib/googletest-master/googlemock/libgmock.a

.PHONY : gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/build

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/requires: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/__/googletest/src/gtest-all.cc.o.requires
gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/requires: gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o.requires

.PHONY : gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/requires

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/clean:
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/clean

gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/depend:
	cd /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uauser/CLionProjects/Tram_SecSpec_4_5 /home/uauser/CLionProjects/Tram_SecSpec_4_5/gtest/lib/googletest-master/googlemock /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock /home/uauser/CLionProjects/Tram_SecSpec_4_5/cmake-build-debug/gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gtest/lib/googletest-master/googlemock/CMakeFiles/gmock.dir/depend

