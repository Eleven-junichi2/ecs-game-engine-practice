cmake_minimum_required(VERSION 3.24)
project(ecs-game-engine-practice LANGUAGES C CXX)

add_executable(ecs-game-engine-practice main.cpp)
add_executable(Vec2_test tests/Vec2_test.cpp)
add_executable(entity_test tests/entity_test.cpp)

target_include_directories(ecs-game-engine-practice PRIVATE include)
target_include_directories(Vec2_test PRIVATE include)
target_include_directories(entity_test PRIVATE include)

enable_testing()

add_test(NAME Vec2_test COMMAND Vec2_test)
add_test(NAME entity_test COMMAND entity_test)
