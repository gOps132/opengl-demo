#
#   Made by Epilan Gian Cedrick G.
#

cmake_minimum_required(VERSION 3.8)
project(opengl_demo C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)
add_subdirectory(lib/glad)

# add_subdirectory(lib/imgui)
add_subdirectory(lib/imgui-test)

set(OPENGL_DEMO_SOURCE_FILES
    src/ErrorManager.cpp
    src/IndexBuffer.cpp
    src/main.cpp
    src/Renderer.cpp  
    src/Shader.cpp
    src/Texture.cpp
    src/VertexArray.cpp
    src/VertexBuffer.cpp
    
    src/test/Test.cpp
    src/test/TestClearColor.cpp
    src/test/TestTexture2d.cpp

    src/ImguiBuild.cpp
)

add_executable(opengl_demo ${OPENGL_DEMO_SOURCE_FILES})

set_target_properties(opengl_demo PROPERTIES 
    LINKER_LANGUAGE CXX

    SOVERSION   ${PROJECT_VERSION_MAJOR}
    VERSION     ${PROJECT_VERSION}

    LIBRARY_OUTPUT_DIRECTORY        "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
    ARCHIVE_OUTPUT_DIRECTORY        "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
    RUNTIME_OUTPUT_DIRECTORY        "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
)


if (APPLE)
    list (APPEND EXTRA_LIBS
        "-framework OpenGL"
    )
elseif(WIN32)
    list (APPEND EXTRA_LIBS
        "-lgu32 -lopengl32")
    set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -mwindows")
else()
    list(APPEND EXTRA_LIBS
        "-lGL -lGLU -lX11")
endif()

target_include_directories(opengl_demo
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/vendor
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/src/include
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/src/tests
)

target_link_libraries(opengl_demo
    ${EXTRA_LIBS}
    -lstdc++
    # imgui
    imgui-test
    glad
    glfw 
    glm
)