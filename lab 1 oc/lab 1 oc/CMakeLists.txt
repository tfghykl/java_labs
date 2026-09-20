cmake_minimum_required(VERSION 3.10)
project(Lab1_WinAPI)

add_executable(Creator Creator.cpp)
add_executable(Reporter Reporter.cpp)
add_executable(Main Main.cpp)

add_custom_command(
    TARGET Main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Creator> $<TARGET_FILE_DIR:Main>
)
add_custom_command(
    TARGET Main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Reporter> $<TARGET_FILE_DIR:Main>
)