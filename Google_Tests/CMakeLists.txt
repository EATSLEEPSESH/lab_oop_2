add_subdirectory(lib)

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

add_executable(tw_tests twelve_tests.cpp)
target_link_libraries(tw_tests
        PRIVATE
        twelve_lib
        gtest
        gtest_main
)
target_include_directories(tw_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(NAME twelveTests COMMAND tw_tests)