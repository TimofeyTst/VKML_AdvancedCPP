cmake_minimum_required(VERSION 3.15)
project(CommandParser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES "src/*.cpp")

# add_custom_target(run COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXECUTABLE} 'echo million | cat static/text.txt | cat static/zarplata.txt')
# MakeFile удобнее, так как там я мог make run сразу запускать файл с переданной строкой

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME})


# Автоматический запуск тестов после сборки
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
)
