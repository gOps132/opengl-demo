# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/giancedrickepilan/dev/native/opengl-demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/learn-opengl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learn-opengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learn-opengl.dir/flags.make

CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.o: ../src/ErrorManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/ErrorManager.cpp

CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/ErrorManager.cpp > CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.i

CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/ErrorManager.cpp -o CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.s

CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.o: ../src/IndexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/IndexBuffer.cpp

CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/IndexBuffer.cpp > CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.i

CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/IndexBuffer.cpp -o CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.s

CMakeFiles/learn-opengl.dir/src/Renderer.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/Renderer.cpp.o: ../src/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/learn-opengl.dir/src/Renderer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/Renderer.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/Renderer.cpp

CMakeFiles/learn-opengl.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/Renderer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/Renderer.cpp > CMakeFiles/learn-opengl.dir/src/Renderer.cpp.i

CMakeFiles/learn-opengl.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/Renderer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/Renderer.cpp -o CMakeFiles/learn-opengl.dir/src/Renderer.cpp.s

CMakeFiles/learn-opengl.dir/src/Shader.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/Shader.cpp.o: ../src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/learn-opengl.dir/src/Shader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/Shader.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/Shader.cpp

CMakeFiles/learn-opengl.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/Shader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/Shader.cpp > CMakeFiles/learn-opengl.dir/src/Shader.cpp.i

CMakeFiles/learn-opengl.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/Shader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/Shader.cpp -o CMakeFiles/learn-opengl.dir/src/Shader.cpp.s

CMakeFiles/learn-opengl.dir/src/Texture.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/Texture.cpp.o: ../src/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/learn-opengl.dir/src/Texture.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/Texture.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/Texture.cpp

CMakeFiles/learn-opengl.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/Texture.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/Texture.cpp > CMakeFiles/learn-opengl.dir/src/Texture.cpp.i

CMakeFiles/learn-opengl.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/Texture.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/Texture.cpp -o CMakeFiles/learn-opengl.dir/src/Texture.cpp.s

CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.o: ../src/VertexArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/VertexArray.cpp

CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/VertexArray.cpp > CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.i

CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/VertexArray.cpp -o CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.s

CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.o: ../src/VertexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/VertexBuffer.cpp

CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/VertexBuffer.cpp > CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.i

CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/VertexBuffer.cpp -o CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.s

CMakeFiles/learn-opengl.dir/src/main.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/learn-opengl.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/main.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/main.cpp

CMakeFiles/learn-opengl.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/main.cpp > CMakeFiles/learn-opengl.dir/src/main.cpp.i

CMakeFiles/learn-opengl.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/main.cpp -o CMakeFiles/learn-opengl.dir/src/main.cpp.s

CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.o: ../src/vendor/stb_image/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/stb_image/stb_image.cpp

CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/stb_image/stb_image.cpp > CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.i

CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/stb_image/stb_image.cpp -o CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.s

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.o: ../src/vendor/imgui/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui.cpp

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui.cpp > CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.i

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui.cpp -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.s

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.o: ../src/vendor/imgui/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_demo.cpp

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_demo.cpp > CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.i

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_demo.cpp -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.s

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.o: ../src/vendor/imgui/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_draw.cpp

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_draw.cpp > CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.i

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_draw.cpp -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.s

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o: ../src/vendor/imgui/imgui_impl_glfw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_impl_glfw.cpp

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_impl_glfw.cpp > CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.i

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_impl_glfw.cpp -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.s

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o: ../src/vendor/imgui/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_impl_opengl3.cpp

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_impl_opengl3.cpp > CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.i

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.s

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.o: ../src/vendor/imgui/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_widgets.cpp

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_widgets.cpp > CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.i

CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/vendor/imgui/imgui_widgets.cpp -o CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.s

CMakeFiles/learn-opengl.dir/src/test/Test.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/test/Test.cpp.o: ../src/test/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/learn-opengl.dir/src/test/Test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/test/Test.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/test/Test.cpp

CMakeFiles/learn-opengl.dir/src/test/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/test/Test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/test/Test.cpp > CMakeFiles/learn-opengl.dir/src/test/Test.cpp.i

CMakeFiles/learn-opengl.dir/src/test/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/test/Test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/test/Test.cpp -o CMakeFiles/learn-opengl.dir/src/test/Test.cpp.s

CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.o: ../src/test/TestClearColor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/test/TestClearColor.cpp

CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/test/TestClearColor.cpp > CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.i

CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/test/TestClearColor.cpp -o CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.s

CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.o: CMakeFiles/learn-opengl.dir/flags.make
CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.o: ../src/test/TestTexture2d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.o -c /Users/giancedrickepilan/dev/native/opengl-demo/src/test/TestTexture2d.cpp

CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/giancedrickepilan/dev/native/opengl-demo/src/test/TestTexture2d.cpp > CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.i

CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/giancedrickepilan/dev/native/opengl-demo/src/test/TestTexture2d.cpp -o CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.s

# Object files for target learn-opengl
learn__opengl_OBJECTS = \
"CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/Renderer.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/Shader.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/Texture.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/main.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/test/Test.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.o" \
"CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.o"

# External object files for target learn-opengl
learn__opengl_EXTERNAL_OBJECTS =

learn-opengl: CMakeFiles/learn-opengl.dir/src/ErrorManager.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/IndexBuffer.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/Renderer.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/Shader.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/Texture.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/VertexArray.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/VertexBuffer.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/main.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/vendor/stb_image/stb_image.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_demo.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_draw.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_glfw.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_impl_opengl3.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/vendor/imgui/imgui_widgets.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/test/Test.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/test/TestClearColor.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/src/test/TestTexture2d.cpp.o
learn-opengl: CMakeFiles/learn-opengl.dir/build.make
learn-opengl: libglad.a
learn-opengl: lib/glfw/src/libglfw3.a
learn-opengl: CMakeFiles/learn-opengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable learn-opengl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learn-opengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learn-opengl.dir/build: learn-opengl

.PHONY : CMakeFiles/learn-opengl.dir/build

CMakeFiles/learn-opengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learn-opengl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learn-opengl.dir/clean

CMakeFiles/learn-opengl.dir/depend:
	cd /Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/giancedrickepilan/dev/native/opengl-demo /Users/giancedrickepilan/dev/native/opengl-demo /Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug /Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug /Users/giancedrickepilan/dev/native/opengl-demo/cmake-build-debug/CMakeFiles/learn-opengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learn-opengl.dir/depend

