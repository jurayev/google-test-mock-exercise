add_subdirectory(lib/googlemock)
enable_testing()

add_executable(runAllTests
               TriangleTests.cpp
               HailstoneTests.cpp
               AwardsTests.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests simpleLibrary)

add_test(NAME AllTests COMMAND runAllTests)

