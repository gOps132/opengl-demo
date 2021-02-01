set(TARGET glad)

add_library(${TARGET} STATIC
	src/glad.c
	include/glad/glad.h
	include/KHR/khrplatform.h
)

target_include_directories(${TARGET}
	PUBLIC "src"
	PUBLIC "include"
)