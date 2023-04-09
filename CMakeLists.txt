cmake_minimum_required(VERSION 3.21)
project(CMakeSFMLProject LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(include)

file(GLOB TETRIS "src/tetris/main.cpp" "src/tetris/**/*.cpp" "src/tetris/**/**/*.cpp")

add_executable(Tetris ${TETRIS})

target_link_libraries(Tetris PRIVATE sfml-graphics)
target_compile_features(Tetris PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Tetris> $<TARGET_FILE_DIR:Tetris> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Tetris)
