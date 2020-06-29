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
set(VENDOR_DIR "${CMAKE_SOURCE_DIR}/src/vendor")

add_subdirectory(${GLFW_SOURCE_DIR})
add_subdirectory(${GLM_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DDEBUG")

file(GLOB MAIN_SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_HEADER_FILES ${HEADER_DIR}/*.h)
file(GLOB VENDOR_FOLDER ${VENDOR_DIR}/*)

# TODO: how to iterate over folders
# foreach(VAR ${VENDOR_FOLDER})
#     file(GLOB VENDOR_HEADER_FILES ${VENDOR_DIR}/${VAR}/*.h)
#     file(GLOB VENDOR_SOURCE_FILES ${VENDOR_DIR}/${VAR}/*.cpp)
# endforeach(VAR ${VENDOR_FOLDER})

set(VENDOR_FOLDERS 
    "imgui"
    "stb_image"
)

foreach(VAR ${VENDOR_FOLDERS})
    file(GLOB VENDOR_HEADER_FILES ${VENDOR_DIR}/${VAR}/*.h)
    file(GLOB VENDOR_SOURCE_FILES ${VENDOR_DIR}/${VAR}/*.cpp)
endforeach(VAR ${VENDOR_FOLDERS})

set(SOURCE_FILES 
    ${MAIN_SRC_FILES} 
    ${MAIN_HEADER_FILES}
    ${VENOR_HEADER_FILES}
    ${VENDOR_SOURCE_FILES}
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

list (APPEND OTHER_FLAGS
#  "-Wno-int-to-void-pointer-cast"
    "-DDEBUG"
)

# OPENGL FLAGS
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

include_directories(
    ${GLAD_SOURCE_DIR}/include
    ${GLM_SOURCE_DIR}

    ${HEADER_DIR}
    ${VENDOR_DIR}
)

# TODO: move this to seperate cmake modules
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
