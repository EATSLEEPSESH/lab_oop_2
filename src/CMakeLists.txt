add_library(twelve_lib STATIC
        twelve.cpp
)

target_include_directories(twelve_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(labs_OOP_2 main.cpp)

target_link_libraries(labs_OOP_2 PRIVATE twelve_lib)