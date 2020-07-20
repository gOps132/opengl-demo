#
#   Made by Epilan Gian Cedrick G.
#  
# TODO: REMOVE DEBUG FLAG LATER 
# TODO: use function that iterates of over .cpp & .h / .hpp files in certain directories in source files
# TODO: maybe find another way to add flags in cmake
# TODO: abstract other libraries with cmake modules
#

cmake_minimum_required(VERSION 3.8)
project(learn-opengl C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)
add_subdirectory(lib/glad)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# this is not good but im tired
file(GLOB VENDOR_HEADERS src/vendor/*/*.h)
file(GLOB VENDOR_SOURCES src/vendor/*/*.cpp)

set(SOURCE_FILES
    src/ErrorManager.cpp
    src/IndexBuffer.cpp
    src/main.cpp
    src/Renderer.cpp  
    src/Shader.cpp
    src/Texture.cpp
    src/VertexArray.cpp
    src/VertexBuffer.cpp
    
    src/header/ErrorManager.h
    src/header/IndexBuffer.h
    src/header/Renderer.h  
    src/header/Shader.h
    src/header/Texture.h
    src/header/VertexArray.h
    src/header/VertexBuffer.h
    src/header/VertexBufferLayout.h

    src/test/Test.cpp
    src/test/Test.h
    src/test/TestClearColor.cpp
    src/test/TestClearColor.h    
    src/test/TestTexture2d.cpp
    src/test/TestTexture2d.h

    ${VENDOR_HEADERS}
    ${VENDOR_SOURCES}
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

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

include_directories(
    src/header
    src/vendor
    src/test
)

target_link_libraries(${PROJECT_NAME} 
    ${EXTRA_LIBS}
    glad
    glfw 
    glm
)
