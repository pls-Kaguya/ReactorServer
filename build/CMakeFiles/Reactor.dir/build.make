# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/huiye/C++Project/ReactorServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huiye/C++Project/ReactorServer/build

# Include any dependencies generated for this target.
include CMakeFiles/Reactor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Reactor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Reactor.dir/flags.make

CMakeFiles/Reactor.dir/src/InetAddress.cpp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/src/InetAddress.cpp.o: ../src/InetAddress.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huiye/C++Project/ReactorServer/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reactor.dir/src/InetAddress.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/src/InetAddress.cpp.o -c /home/huiye/C++Project/ReactorServer/src/InetAddress.cpp

CMakeFiles/Reactor.dir/src/InetAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/src/InetAddress.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huiye/C++Project/ReactorServer/src/InetAddress.cpp > CMakeFiles/Reactor.dir/src/InetAddress.cpp.i

CMakeFiles/Reactor.dir/src/InetAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/src/InetAddress.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huiye/C++Project/ReactorServer/src/InetAddress.cpp -o CMakeFiles/Reactor.dir/src/InetAddress.cpp.s

CMakeFiles/Reactor.dir/src/InetAddress.cpp.o.requires:
.PHONY : CMakeFiles/Reactor.dir/src/InetAddress.cpp.o.requires

CMakeFiles/Reactor.dir/src/InetAddress.cpp.o.provides: CMakeFiles/Reactor.dir/src/InetAddress.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/src/InetAddress.cpp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/src/InetAddress.cpp.o.provides

CMakeFiles/Reactor.dir/src/InetAddress.cpp.o.provides.build: CMakeFiles/Reactor.dir/src/InetAddress.cpp.o

CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o: ../src/TcpEpoll.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huiye/C++Project/ReactorServer/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o -c /home/huiye/C++Project/ReactorServer/src/TcpEpoll.cpp

CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huiye/C++Project/ReactorServer/src/TcpEpoll.cpp > CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.i

CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huiye/C++Project/ReactorServer/src/TcpEpoll.cpp -o CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.s

CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o.requires:
.PHONY : CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o.requires

CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o.provides: CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o.provides

CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o.provides.build: CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o

CMakeFiles/Reactor.dir/src/Socket.cpp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/src/Socket.cpp.o: ../src/Socket.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huiye/C++Project/ReactorServer/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reactor.dir/src/Socket.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/src/Socket.cpp.o -c /home/huiye/C++Project/ReactorServer/src/Socket.cpp

CMakeFiles/Reactor.dir/src/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/src/Socket.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huiye/C++Project/ReactorServer/src/Socket.cpp > CMakeFiles/Reactor.dir/src/Socket.cpp.i

CMakeFiles/Reactor.dir/src/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/src/Socket.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huiye/C++Project/ReactorServer/src/Socket.cpp -o CMakeFiles/Reactor.dir/src/Socket.cpp.s

CMakeFiles/Reactor.dir/src/Socket.cpp.o.requires:
.PHONY : CMakeFiles/Reactor.dir/src/Socket.cpp.o.requires

CMakeFiles/Reactor.dir/src/Socket.cpp.o.provides: CMakeFiles/Reactor.dir/src/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/src/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/src/Socket.cpp.o.provides

CMakeFiles/Reactor.dir/src/Socket.cpp.o.provides.build: CMakeFiles/Reactor.dir/src/Socket.cpp.o

CMakeFiles/Reactor.dir/src/Epoll.cpp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/src/Epoll.cpp.o: ../src/Epoll.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huiye/C++Project/ReactorServer/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reactor.dir/src/Epoll.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/src/Epoll.cpp.o -c /home/huiye/C++Project/ReactorServer/src/Epoll.cpp

CMakeFiles/Reactor.dir/src/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/src/Epoll.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huiye/C++Project/ReactorServer/src/Epoll.cpp > CMakeFiles/Reactor.dir/src/Epoll.cpp.i

CMakeFiles/Reactor.dir/src/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/src/Epoll.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huiye/C++Project/ReactorServer/src/Epoll.cpp -o CMakeFiles/Reactor.dir/src/Epoll.cpp.s

CMakeFiles/Reactor.dir/src/Epoll.cpp.o.requires:
.PHONY : CMakeFiles/Reactor.dir/src/Epoll.cpp.o.requires

CMakeFiles/Reactor.dir/src/Epoll.cpp.o.provides: CMakeFiles/Reactor.dir/src/Epoll.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/src/Epoll.cpp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/src/Epoll.cpp.o.provides

CMakeFiles/Reactor.dir/src/Epoll.cpp.o.provides.build: CMakeFiles/Reactor.dir/src/Epoll.cpp.o

CMakeFiles/Reactor.dir/src/Channel.cpp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/src/Channel.cpp.o: ../src/Channel.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huiye/C++Project/ReactorServer/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reactor.dir/src/Channel.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/src/Channel.cpp.o -c /home/huiye/C++Project/ReactorServer/src/Channel.cpp

CMakeFiles/Reactor.dir/src/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/src/Channel.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huiye/C++Project/ReactorServer/src/Channel.cpp > CMakeFiles/Reactor.dir/src/Channel.cpp.i

CMakeFiles/Reactor.dir/src/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/src/Channel.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huiye/C++Project/ReactorServer/src/Channel.cpp -o CMakeFiles/Reactor.dir/src/Channel.cpp.s

CMakeFiles/Reactor.dir/src/Channel.cpp.o.requires:
.PHONY : CMakeFiles/Reactor.dir/src/Channel.cpp.o.requires

CMakeFiles/Reactor.dir/src/Channel.cpp.o.provides: CMakeFiles/Reactor.dir/src/Channel.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/src/Channel.cpp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/src/Channel.cpp.o.provides

CMakeFiles/Reactor.dir/src/Channel.cpp.o.provides.build: CMakeFiles/Reactor.dir/src/Channel.cpp.o

CMakeFiles/Reactor.dir/src/TcpServer.cpp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/src/TcpServer.cpp.o: ../src/TcpServer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huiye/C++Project/ReactorServer/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reactor.dir/src/TcpServer.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/src/TcpServer.cpp.o -c /home/huiye/C++Project/ReactorServer/src/TcpServer.cpp

CMakeFiles/Reactor.dir/src/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/src/TcpServer.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huiye/C++Project/ReactorServer/src/TcpServer.cpp > CMakeFiles/Reactor.dir/src/TcpServer.cpp.i

CMakeFiles/Reactor.dir/src/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/src/TcpServer.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huiye/C++Project/ReactorServer/src/TcpServer.cpp -o CMakeFiles/Reactor.dir/src/TcpServer.cpp.s

CMakeFiles/Reactor.dir/src/TcpServer.cpp.o.requires:
.PHONY : CMakeFiles/Reactor.dir/src/TcpServer.cpp.o.requires

CMakeFiles/Reactor.dir/src/TcpServer.cpp.o.provides: CMakeFiles/Reactor.dir/src/TcpServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/src/TcpServer.cpp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/src/TcpServer.cpp.o.provides

CMakeFiles/Reactor.dir/src/TcpServer.cpp.o.provides.build: CMakeFiles/Reactor.dir/src/TcpServer.cpp.o

CMakeFiles/Reactor.dir/src/EventLoop.cpp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/src/EventLoop.cpp.o: ../src/EventLoop.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huiye/C++Project/ReactorServer/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reactor.dir/src/EventLoop.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/src/EventLoop.cpp.o -c /home/huiye/C++Project/ReactorServer/src/EventLoop.cpp

CMakeFiles/Reactor.dir/src/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/src/EventLoop.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huiye/C++Project/ReactorServer/src/EventLoop.cpp > CMakeFiles/Reactor.dir/src/EventLoop.cpp.i

CMakeFiles/Reactor.dir/src/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/src/EventLoop.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huiye/C++Project/ReactorServer/src/EventLoop.cpp -o CMakeFiles/Reactor.dir/src/EventLoop.cpp.s

CMakeFiles/Reactor.dir/src/EventLoop.cpp.o.requires:
.PHONY : CMakeFiles/Reactor.dir/src/EventLoop.cpp.o.requires

CMakeFiles/Reactor.dir/src/EventLoop.cpp.o.provides: CMakeFiles/Reactor.dir/src/EventLoop.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/src/EventLoop.cpp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/src/EventLoop.cpp.o.provides

CMakeFiles/Reactor.dir/src/EventLoop.cpp.o.provides.build: CMakeFiles/Reactor.dir/src/EventLoop.cpp.o

CMakeFiles/Reactor.dir/src/Acceptor.cpp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/src/Acceptor.cpp.o: ../src/Acceptor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huiye/C++Project/ReactorServer/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reactor.dir/src/Acceptor.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/src/Acceptor.cpp.o -c /home/huiye/C++Project/ReactorServer/src/Acceptor.cpp

CMakeFiles/Reactor.dir/src/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/src/Acceptor.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huiye/C++Project/ReactorServer/src/Acceptor.cpp > CMakeFiles/Reactor.dir/src/Acceptor.cpp.i

CMakeFiles/Reactor.dir/src/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/src/Acceptor.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huiye/C++Project/ReactorServer/src/Acceptor.cpp -o CMakeFiles/Reactor.dir/src/Acceptor.cpp.s

CMakeFiles/Reactor.dir/src/Acceptor.cpp.o.requires:
.PHONY : CMakeFiles/Reactor.dir/src/Acceptor.cpp.o.requires

CMakeFiles/Reactor.dir/src/Acceptor.cpp.o.provides: CMakeFiles/Reactor.dir/src/Acceptor.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/src/Acceptor.cpp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/src/Acceptor.cpp.o.provides

CMakeFiles/Reactor.dir/src/Acceptor.cpp.o.provides.build: CMakeFiles/Reactor.dir/src/Acceptor.cpp.o

CMakeFiles/Reactor.dir/src/Connection.cpp.o: CMakeFiles/Reactor.dir/flags.make
CMakeFiles/Reactor.dir/src/Connection.cpp.o: ../src/Connection.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/huiye/C++Project/ReactorServer/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Reactor.dir/src/Connection.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Reactor.dir/src/Connection.cpp.o -c /home/huiye/C++Project/ReactorServer/src/Connection.cpp

CMakeFiles/Reactor.dir/src/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reactor.dir/src/Connection.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/huiye/C++Project/ReactorServer/src/Connection.cpp > CMakeFiles/Reactor.dir/src/Connection.cpp.i

CMakeFiles/Reactor.dir/src/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reactor.dir/src/Connection.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/huiye/C++Project/ReactorServer/src/Connection.cpp -o CMakeFiles/Reactor.dir/src/Connection.cpp.s

CMakeFiles/Reactor.dir/src/Connection.cpp.o.requires:
.PHONY : CMakeFiles/Reactor.dir/src/Connection.cpp.o.requires

CMakeFiles/Reactor.dir/src/Connection.cpp.o.provides: CMakeFiles/Reactor.dir/src/Connection.cpp.o.requires
	$(MAKE) -f CMakeFiles/Reactor.dir/build.make CMakeFiles/Reactor.dir/src/Connection.cpp.o.provides.build
.PHONY : CMakeFiles/Reactor.dir/src/Connection.cpp.o.provides

CMakeFiles/Reactor.dir/src/Connection.cpp.o.provides.build: CMakeFiles/Reactor.dir/src/Connection.cpp.o

# Object files for target Reactor
Reactor_OBJECTS = \
"CMakeFiles/Reactor.dir/src/InetAddress.cpp.o" \
"CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o" \
"CMakeFiles/Reactor.dir/src/Socket.cpp.o" \
"CMakeFiles/Reactor.dir/src/Epoll.cpp.o" \
"CMakeFiles/Reactor.dir/src/Channel.cpp.o" \
"CMakeFiles/Reactor.dir/src/TcpServer.cpp.o" \
"CMakeFiles/Reactor.dir/src/EventLoop.cpp.o" \
"CMakeFiles/Reactor.dir/src/Acceptor.cpp.o" \
"CMakeFiles/Reactor.dir/src/Connection.cpp.o"

# External object files for target Reactor
Reactor_EXTERNAL_OBJECTS =

../bin/Reactor: CMakeFiles/Reactor.dir/src/InetAddress.cpp.o
../bin/Reactor: CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o
../bin/Reactor: CMakeFiles/Reactor.dir/src/Socket.cpp.o
../bin/Reactor: CMakeFiles/Reactor.dir/src/Epoll.cpp.o
../bin/Reactor: CMakeFiles/Reactor.dir/src/Channel.cpp.o
../bin/Reactor: CMakeFiles/Reactor.dir/src/TcpServer.cpp.o
../bin/Reactor: CMakeFiles/Reactor.dir/src/EventLoop.cpp.o
../bin/Reactor: CMakeFiles/Reactor.dir/src/Acceptor.cpp.o
../bin/Reactor: CMakeFiles/Reactor.dir/src/Connection.cpp.o
../bin/Reactor: CMakeFiles/Reactor.dir/build.make
../bin/Reactor: CMakeFiles/Reactor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/Reactor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Reactor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Reactor.dir/build: ../bin/Reactor
.PHONY : CMakeFiles/Reactor.dir/build

CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/src/InetAddress.cpp.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/src/TcpEpoll.cpp.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/src/Socket.cpp.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/src/Epoll.cpp.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/src/Channel.cpp.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/src/TcpServer.cpp.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/src/EventLoop.cpp.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/src/Acceptor.cpp.o.requires
CMakeFiles/Reactor.dir/requires: CMakeFiles/Reactor.dir/src/Connection.cpp.o.requires
.PHONY : CMakeFiles/Reactor.dir/requires

CMakeFiles/Reactor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Reactor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Reactor.dir/clean

CMakeFiles/Reactor.dir/depend:
	cd /home/huiye/C++Project/ReactorServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huiye/C++Project/ReactorServer /home/huiye/C++Project/ReactorServer /home/huiye/C++Project/ReactorServer/build /home/huiye/C++Project/ReactorServer/build /home/huiye/C++Project/ReactorServer/build/CMakeFiles/Reactor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Reactor.dir/depend

