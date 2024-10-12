cmake_minimum_required(VERSION 3.14)
project(Qualité) # Remplacer par le nom de votre projet : par exemple qualite-dev-s2-prenom-nom

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  kataTDD_test
  ./Tp6/kataTDD_test.cpp
)
target_link_libraries(
  kataTDD_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(kataTDD_test)
