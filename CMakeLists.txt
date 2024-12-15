cmake_minimum_required(VERSION 3.10.0)
project(VirtualLabs_SpecificHeat VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(include/)

add_executable(main src/__main.cpp)
target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)

add_executable(test_substance test/__test_substance.cpp 
               src/Substance.cpp
               src/Liquid.cpp
               src/Metal.cpp)

add_executable(test_container test/__test_container.cpp
               src/Substance.cpp
               src/Liquid.cpp
               src/Metal.cpp
               src/Container.cpp)

add_executable(test_sprites test/__test_sprites.cpp
               src/IComponent.cpp
               src/Sprite2DComponent.cpp)
target_link_libraries(test_sprites PRIVATE sfml-graphics sfml-window sfml-system)

enable_testing()

add_test(
    NAME test_substance
    COMMAND $<TARGET_FILE:test_substance>
)
add_test(
    NAME test_container
    COMMAND $<TARGET_FILE:test_container>
)
add_test(
    NAME test_sprites
    COMMAND $<TARGET_FILE:test_sprites>
)


if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()