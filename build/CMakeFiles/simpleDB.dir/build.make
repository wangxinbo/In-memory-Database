# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/xinbowang/Documents/Docs for Xcode/simpleDB"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build"

# Include any dependencies generated for this target.
include CMakeFiles/simpleDB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simpleDB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simpleDB.dir/flags.make

CMakeFiles/simpleDB.dir/main.cpp.o: CMakeFiles/simpleDB.dir/flags.make
CMakeFiles/simpleDB.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simpleDB.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpleDB.dir/main.cpp.o -c "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/main.cpp"

CMakeFiles/simpleDB.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleDB.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/main.cpp" > CMakeFiles/simpleDB.dir/main.cpp.i

CMakeFiles/simpleDB.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleDB.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/main.cpp" -o CMakeFiles/simpleDB.dir/main.cpp.s

CMakeFiles/simpleDB.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/simpleDB.dir/main.cpp.o.requires

CMakeFiles/simpleDB.dir/main.cpp.o.provides: CMakeFiles/simpleDB.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/simpleDB.dir/build.make CMakeFiles/simpleDB.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/simpleDB.dir/main.cpp.o.provides

CMakeFiles/simpleDB.dir/main.cpp.o.provides.build: CMakeFiles/simpleDB.dir/main.cpp.o


CMakeFiles/simpleDB.dir/src/Database.cpp.o: CMakeFiles/simpleDB.dir/flags.make
CMakeFiles/simpleDB.dir/src/Database.cpp.o: ../src/Database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/simpleDB.dir/src/Database.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpleDB.dir/src/Database.cpp.o -c "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Database.cpp"

CMakeFiles/simpleDB.dir/src/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleDB.dir/src/Database.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Database.cpp" > CMakeFiles/simpleDB.dir/src/Database.cpp.i

CMakeFiles/simpleDB.dir/src/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleDB.dir/src/Database.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Database.cpp" -o CMakeFiles/simpleDB.dir/src/Database.cpp.s

CMakeFiles/simpleDB.dir/src/Database.cpp.o.requires:

.PHONY : CMakeFiles/simpleDB.dir/src/Database.cpp.o.requires

CMakeFiles/simpleDB.dir/src/Database.cpp.o.provides: CMakeFiles/simpleDB.dir/src/Database.cpp.o.requires
	$(MAKE) -f CMakeFiles/simpleDB.dir/build.make CMakeFiles/simpleDB.dir/src/Database.cpp.o.provides.build
.PHONY : CMakeFiles/simpleDB.dir/src/Database.cpp.o.provides

CMakeFiles/simpleDB.dir/src/Database.cpp.o.provides.build: CMakeFiles/simpleDB.dir/src/Database.cpp.o


CMakeFiles/simpleDB.dir/src/Command.cpp.o: CMakeFiles/simpleDB.dir/flags.make
CMakeFiles/simpleDB.dir/src/Command.cpp.o: ../src/Command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/simpleDB.dir/src/Command.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpleDB.dir/src/Command.cpp.o -c "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Command.cpp"

CMakeFiles/simpleDB.dir/src/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleDB.dir/src/Command.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Command.cpp" > CMakeFiles/simpleDB.dir/src/Command.cpp.i

CMakeFiles/simpleDB.dir/src/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleDB.dir/src/Command.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Command.cpp" -o CMakeFiles/simpleDB.dir/src/Command.cpp.s

CMakeFiles/simpleDB.dir/src/Command.cpp.o.requires:

.PHONY : CMakeFiles/simpleDB.dir/src/Command.cpp.o.requires

CMakeFiles/simpleDB.dir/src/Command.cpp.o.provides: CMakeFiles/simpleDB.dir/src/Command.cpp.o.requires
	$(MAKE) -f CMakeFiles/simpleDB.dir/build.make CMakeFiles/simpleDB.dir/src/Command.cpp.o.provides.build
.PHONY : CMakeFiles/simpleDB.dir/src/Command.cpp.o.provides

CMakeFiles/simpleDB.dir/src/Command.cpp.o.provides.build: CMakeFiles/simpleDB.dir/src/Command.cpp.o


CMakeFiles/simpleDB.dir/src/Printer.cpp.o: CMakeFiles/simpleDB.dir/flags.make
CMakeFiles/simpleDB.dir/src/Printer.cpp.o: ../src/Printer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/simpleDB.dir/src/Printer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpleDB.dir/src/Printer.cpp.o -c "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Printer.cpp"

CMakeFiles/simpleDB.dir/src/Printer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleDB.dir/src/Printer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Printer.cpp" > CMakeFiles/simpleDB.dir/src/Printer.cpp.i

CMakeFiles/simpleDB.dir/src/Printer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleDB.dir/src/Printer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Printer.cpp" -o CMakeFiles/simpleDB.dir/src/Printer.cpp.s

CMakeFiles/simpleDB.dir/src/Printer.cpp.o.requires:

.PHONY : CMakeFiles/simpleDB.dir/src/Printer.cpp.o.requires

CMakeFiles/simpleDB.dir/src/Printer.cpp.o.provides: CMakeFiles/simpleDB.dir/src/Printer.cpp.o.requires
	$(MAKE) -f CMakeFiles/simpleDB.dir/build.make CMakeFiles/simpleDB.dir/src/Printer.cpp.o.provides.build
.PHONY : CMakeFiles/simpleDB.dir/src/Printer.cpp.o.provides

CMakeFiles/simpleDB.dir/src/Printer.cpp.o.provides.build: CMakeFiles/simpleDB.dir/src/Printer.cpp.o


CMakeFiles/simpleDB.dir/src/Reader.cpp.o: CMakeFiles/simpleDB.dir/flags.make
CMakeFiles/simpleDB.dir/src/Reader.cpp.o: ../src/Reader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/simpleDB.dir/src/Reader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpleDB.dir/src/Reader.cpp.o -c "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Reader.cpp"

CMakeFiles/simpleDB.dir/src/Reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleDB.dir/src/Reader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Reader.cpp" > CMakeFiles/simpleDB.dir/src/Reader.cpp.i

CMakeFiles/simpleDB.dir/src/Reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleDB.dir/src/Reader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Reader.cpp" -o CMakeFiles/simpleDB.dir/src/Reader.cpp.s

CMakeFiles/simpleDB.dir/src/Reader.cpp.o.requires:

.PHONY : CMakeFiles/simpleDB.dir/src/Reader.cpp.o.requires

CMakeFiles/simpleDB.dir/src/Reader.cpp.o.provides: CMakeFiles/simpleDB.dir/src/Reader.cpp.o.requires
	$(MAKE) -f CMakeFiles/simpleDB.dir/build.make CMakeFiles/simpleDB.dir/src/Reader.cpp.o.provides.build
.PHONY : CMakeFiles/simpleDB.dir/src/Reader.cpp.o.provides

CMakeFiles/simpleDB.dir/src/Reader.cpp.o.provides.build: CMakeFiles/simpleDB.dir/src/Reader.cpp.o


CMakeFiles/simpleDB.dir/src/Transaction.cpp.o: CMakeFiles/simpleDB.dir/flags.make
CMakeFiles/simpleDB.dir/src/Transaction.cpp.o: ../src/Transaction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/simpleDB.dir/src/Transaction.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpleDB.dir/src/Transaction.cpp.o -c "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Transaction.cpp"

CMakeFiles/simpleDB.dir/src/Transaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleDB.dir/src/Transaction.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Transaction.cpp" > CMakeFiles/simpleDB.dir/src/Transaction.cpp.i

CMakeFiles/simpleDB.dir/src/Transaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleDB.dir/src/Transaction.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/src/Transaction.cpp" -o CMakeFiles/simpleDB.dir/src/Transaction.cpp.s

CMakeFiles/simpleDB.dir/src/Transaction.cpp.o.requires:

.PHONY : CMakeFiles/simpleDB.dir/src/Transaction.cpp.o.requires

CMakeFiles/simpleDB.dir/src/Transaction.cpp.o.provides: CMakeFiles/simpleDB.dir/src/Transaction.cpp.o.requires
	$(MAKE) -f CMakeFiles/simpleDB.dir/build.make CMakeFiles/simpleDB.dir/src/Transaction.cpp.o.provides.build
.PHONY : CMakeFiles/simpleDB.dir/src/Transaction.cpp.o.provides

CMakeFiles/simpleDB.dir/src/Transaction.cpp.o.provides.build: CMakeFiles/simpleDB.dir/src/Transaction.cpp.o


# Object files for target simpleDB
simpleDB_OBJECTS = \
"CMakeFiles/simpleDB.dir/main.cpp.o" \
"CMakeFiles/simpleDB.dir/src/Database.cpp.o" \
"CMakeFiles/simpleDB.dir/src/Command.cpp.o" \
"CMakeFiles/simpleDB.dir/src/Printer.cpp.o" \
"CMakeFiles/simpleDB.dir/src/Reader.cpp.o" \
"CMakeFiles/simpleDB.dir/src/Transaction.cpp.o"

# External object files for target simpleDB
simpleDB_EXTERNAL_OBJECTS =

../bin/simpleDB: CMakeFiles/simpleDB.dir/main.cpp.o
../bin/simpleDB: CMakeFiles/simpleDB.dir/src/Database.cpp.o
../bin/simpleDB: CMakeFiles/simpleDB.dir/src/Command.cpp.o
../bin/simpleDB: CMakeFiles/simpleDB.dir/src/Printer.cpp.o
../bin/simpleDB: CMakeFiles/simpleDB.dir/src/Reader.cpp.o
../bin/simpleDB: CMakeFiles/simpleDB.dir/src/Transaction.cpp.o
../bin/simpleDB: CMakeFiles/simpleDB.dir/build.make
../bin/simpleDB: CMakeFiles/simpleDB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../bin/simpleDB"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simpleDB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simpleDB.dir/build: ../bin/simpleDB

.PHONY : CMakeFiles/simpleDB.dir/build

CMakeFiles/simpleDB.dir/requires: CMakeFiles/simpleDB.dir/main.cpp.o.requires
CMakeFiles/simpleDB.dir/requires: CMakeFiles/simpleDB.dir/src/Database.cpp.o.requires
CMakeFiles/simpleDB.dir/requires: CMakeFiles/simpleDB.dir/src/Command.cpp.o.requires
CMakeFiles/simpleDB.dir/requires: CMakeFiles/simpleDB.dir/src/Printer.cpp.o.requires
CMakeFiles/simpleDB.dir/requires: CMakeFiles/simpleDB.dir/src/Reader.cpp.o.requires
CMakeFiles/simpleDB.dir/requires: CMakeFiles/simpleDB.dir/src/Transaction.cpp.o.requires

.PHONY : CMakeFiles/simpleDB.dir/requires

CMakeFiles/simpleDB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simpleDB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simpleDB.dir/clean

CMakeFiles/simpleDB.dir/depend:
	cd "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/xinbowang/Documents/Docs for Xcode/simpleDB" "/Users/xinbowang/Documents/Docs for Xcode/simpleDB" "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build" "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build" "/Users/xinbowang/Documents/Docs for Xcode/simpleDB/build/CMakeFiles/simpleDB.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/simpleDB.dir/depend

