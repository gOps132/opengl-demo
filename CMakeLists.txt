#
#   Made by Epilan Gian Cedrick G.
#  
# TODO: REMOVE DEBUG FLAG LATER 
# TODO: use function that iterates of over .cpp & .h / .hpp files in certain directories in source files
# TODO: maybe find another way to add flags in cmake
# TODO: abstract other libraries with cmake files
#

cmake_minimum_required(VERSION 3.8)
project(learn-opengl C CXX)
set(CMAKE_CXX_STANDARD 14)


set(GLFW_SOURCE_DIR "${CMAKE_SOURCE_DIR}/lib/glfw")
set(GLAD_SOURCE_DIR "${CMAKE_SOURCE_DIR}/lib/glad")
set(GLM_SOURCE_DIR "${CMAKE_SOURCE_DIR}/lib/glm")

set(HEADER_DIR "${CMAKE_SOURCE_DIR}/src/header")
set(NOT_MY_HEADER_DIR "${CMAKE_SOURCE_DIR}/src/vendor")

add_subdirectory(${GLFW_SOURCE_DIR})
add_subdirectory(${GLM_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DDEBUG")
set(SOURCE_FILES
    src/main.cpp

    src/Renderer.cpp
    ${HEADER_DIR}/Renderer.h

    src/Shader.cpp
    ${HEADER_DIR}/Shader.h

    src/VertexBuffer.cpp
    ${HEADER_DIR}/VertexBuffer.h

    src/IndexBuffer.cpp
    ${HEADER_DIR}/IndexBuffer.h
    
    src/VertexArray.cpp
    ${HEADER_DIR}/VertexArray.h

    ${HEADER_DIR}/VertexBufferLayout.h

    src/ErrorManager.cpp
    ${HEADER_DIR}/ErrorManager.h

    ${NOT_MY_HEADER_DIR}/stb_image/stb_image.cpp
    ${NOT_MY_HEADER_DIR}/stb_image/stb_image.h

    src/Texture.cpp
    ${HEADER_DIR}/Texture.h
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
    ${GLM_SOURCE_DIR}

    ${HEADER_DIR}
    ${NOT_MY_HEADER_DIR}
)

# making glad library here because COMFORT
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
    glm
)
