#
#   Made by Epilan Gian Cedrick G.
#

cmake_minimum_required(VERSION 3.14)
project(opengl-demo C CXX)
set(CMAKE_CXX_STANDARD 17)

set(WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)
add_subdirectory(lib/glad)
add_subdirectory(lib/imgui)
add_subdirectory(lib/spdlog)

set(OPENGL_DEMO_SOURCE_FILES
    src/ErrorManager.cpp
    src/IndexBuffer.cpp
    src/main.cpp
    src/Renderer.cpp  
    src/Shader.cpp
    src/Texture.cpp
    src/VertexArray.cpp
    src/VertexBuffer.cpp
    src/Test.cpp
    src/Log.cpp

    test/test_clear_color/TestClearColor.cpp
    test/test_texture_2d/TestTexture2d.cpp

    src/ImguiBuild.cpp
)

add_executable(opengl-demo ${OPENGL_DEMO_SOURCE_FILES})

set_target_properties(opengl-demo PROPERTIES 
    LINKER_LANGUAGE CXX

    SOVERSION   ${PROJECT_VERSION_MAJOR}
    VERSION     ${PROJECT_VERSION}

    LIBRARY_OUTPUT_DIRECTORY        "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
    ARCHIVE_OUTPUT_DIRECTORY        "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
    RUNTIME_OUTPUT_DIRECTORY        "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"

    WORKING_DIRECTORY   ${CMAKE_CURRENT_SOURCE_DIR}
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

target_include_directories(opengl-demo
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/vendor
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(opengl-demo
    ${EXTRA_LIBS}
    imgui-test
    glad
    glfw 
    glm
    spdlog
)   