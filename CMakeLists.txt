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

include_directories(
    ${CMAKE_SOURCE_DIR}/include/
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/Container
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/Substance
)

add_library(virtual-labs STATIC 
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Entity.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/EntityManager.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/IComponent.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/PhysicsComponent.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/Sprite2DComponent.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/Physics/HeatSource.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/Physics/Room.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/Physics/Substance/Substance.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/Physics/Substance/Liquid.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/Physics/Substance/Metal.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/Physics/Container/Beaker.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/Physics/Container/Calorimeter.cpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Components/Physics/Container/Container.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Entity.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/EntityManager.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/IComponent.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/PhysicsComponent.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Sprite2DComponent.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/HeatSource.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/Room.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/Substance/Substance.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/Substance/Liquid.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/Substance/Metal.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/Container/Beaker.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/Container/Calorimeter.hpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Components/Physics/Container/Container.hpp
)
target_link_libraries(virtual-labs PRIVATE sfml-graphics sfml-window sfml-system)

add_executable(main src/__main.cpp)
target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)

add_executable(test_substance test/__test_substance.cpp)
target_link_libraries(test_substance PRIVATE virtual-labs)

add_executable(test_container test/__test_container.cpp)
target_link_libraries(test_container PRIVATE virtual-labs)

add_executable(test_sprites test/__test_sprites.cpp)
target_link_libraries(test_sprites PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

add_executable(test_entity test/__test_sprites.cpp)
target_link_libraries(test_entity PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

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
add_test(
    NAME test_entity
    COMMAND $<TARGET_FILE:test_entity>
)

add_custom_target(
    load_assets
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rm -R ${CMAKE_BINARY_DIR}/assets
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
    VERBATIM
)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM
    )
endif()