cmake_minimum_required(VERSION 3.2)

project(diceroll-cpp)

set(PROJECT_SRCS
  src/roll_node.cpp
  src/distribution.cpp
  src/add_node.cpp
  src/dice_expr.cpp
  src/integer_node.cpp
  src/util.cpp)

set(PROJECT_INCLUDES
  include/expression_node.hpp
  include/roll_node.hpp
  include/distribution.hpp
  include/add_node.hpp
  include/dice_expr.hpp
  include/integer_node.hpp
  include/util.hpp)

set(PROJECT_TEST_SRCS
  test/main.cpp
  test/test_roll_node.cpp
  test/test_distribution.cpp
  test/test_add_node.cpp
  test/test_dice_expr.cpp
  test/test_integer_node.cpp
  test/test_util.cpp)

source_group(test_sources FILES ${PROJECT_TEST_SRCS})
source_group(lib_sources FILES ${PROJECT_SRCS})

add_library(diceroll_cpp ${PROJECT_SRCS} ${PROJECT_INCLUDES})

target_include_directories(diceroll_cpp PUBLIC include/)

add_executable(catch_tests ${PROJECT_SRCS} 
  ${PROJECT_INCLUDES}
  ${PROJECT_TEST_SRCS})

target_include_directories(catch_tests PRIVATE lib)
target_include_directories(catch_tests PRIVATE include/)

set_property(TARGET catch_tests PROPERTY CXX_STANDARD 14)
set_property(TARGET diceroll_cpp PROPERTY CXX_STANDARD 14)

