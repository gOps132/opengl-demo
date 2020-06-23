cmake_minimum_required(VERSION 3.8)
project(learn-opengl C CXX)
set(CMAKE_CXX_STANDARD 14)

set(GLFW_SOURCE_DIR "lib/glfw")
set(GLAD_SOURCE_DIR "lib/glad")

add_subdirectory(
    ${GLFW_SOURCE_DIR}
)

# TODO: set working directory on the root of the project

# TODO: REMOVE DEBUG FLAG LATER 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DDEBUG")
set(SOURCE_FILES
    src/main.cpp

    src/Renderer.cpp
    header/Renderer.hpp

    src/Shader.cpp
    header/Shader.hpp

    src/VertexBuffer.cpp
    header/VertexBuffer.hpp

    src/IndexBuffer.cpp
    header/IndexBuffer.hpp
    
    src/VertexArray.cpp
    header/VertexArray.hpp

    header/VertexBufferLayout.hpp

    src/ErrorManager.cpp
    header/ErrorManager.hpp
)

list (APPEND OTHER_FLAGS
#  "-Wno-int-to-void-pointer-cast"
    "-DDEBUG"
)

if (APPLE)
    list (APPEND EXTRA_LIBS
        "-framework OpenGL"
    )

elseif(WIN32)
    list (APPEND EXTA_LIBS
        "-lgu32 -lopengl32")
    set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -mwindows")
else()
    list(APPEND EXTRA_LIBS
        "-lGL -lGLU -lX11")
endif()


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories(
    ${GLAD_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/header
)

add_library(glad STATIC
  ${GLAD_SOURCE_DIR}/src/glad.c
  ${GLAD_SOURCE_DIR}/include
)

target_link_libraries(
    ${PROJECT_NAME} 
    ${EXTRA_LIBS}
    ${OTHER_FLAGS}
    glad
    glfw 
)
