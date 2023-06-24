cmake_minimum_required(VERSION 3.21)
project(CMakeSFMLProject LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG v1.89.5)
FetchContent_MakeAvailable(imgui)

FetchContent_Declare(imgui-sfml
  GIT_REPOSITORY https://github.com/SFML/imgui-sfml
  GIT_TAG master)

set(IMGUI_DIR ${imgui_SOURCE_DIR})
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_SFML_IMGUI_DEMO ON)

FetchContent_MakeAvailable(imgui-sfml)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
#link_directories(external/lib)

file(GLOB COMMON "src/handler/*.cpp" "src/util/*.cpp")

file(GLOB TETRIS "src/tetris/main.cpp" "src/tetris/**/*.cpp" "src/tetris/**/**/*.cpp")

file(GLOB PLAYGROUND "src/playground/main.cpp" "src/playground/**/*.cpp" "src/playground/**/**/*.cpp")
#file(GLOB PLAYGROUND "src/playground/**/*.cpp")

add_executable(Tetris ${TETRIS} ${COMMON})

add_executable(Playground ${PLAYGROUND})

#target_link_libraries(Tetris dwmapi)
target_link_libraries(Tetris PRIVATE sfml-graphics dwmapi)
target_compile_features(Tetris PRIVATE cxx_std_17)

target_link_libraries(Playground PRIVATE sfml-graphics ImGui-SFML::ImGui-SFML)
target_compile_features(Playground PRIVATE cxx_std_17)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Tetris> $<TARGET_FILE_DIR:Tetris> COMMAND_EXPAND_LISTS)
endif()

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Playground POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Playground> $<TARGET_FILE_DIR:Playground> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Tetris Playground)

