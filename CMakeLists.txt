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
)

set(VIRTUAL_LABS_SRC
    ${CMAKE_SOURCE_DIR}/src/Beaker.cpp
    ${CMAKE_SOURCE_DIR}/include/Beaker.hpp
    # ${CMAKE_SOURCE_DIR}/src/Button.cpp
    # ${CMAKE_SOURCE_DIR}/include/Button.hpp
    ${CMAKE_SOURCE_DIR}/src/Calorimeter.cpp
    ${CMAKE_SOURCE_DIR}/include/Calorimeter.hpp
    # ${CMAKE_SOURCE_DIR}/src/Clickable.cpp
    # ${CMAKE_SOURCE_DIR}/include/Clickable.hpp
    ${CMAKE_SOURCE_DIR}/src/Container.cpp
    ${CMAKE_SOURCE_DIR}/include/Container.hpp
    # ${CMAKE_SOURCE_DIR}/src/Entity.cpp
    # ${CMAKE_SOURCE_DIR}/include/Entity.hpp
    # ${CMAKE_SOURCE_DIR}/src/EntityManager.cpp
    # ${CMAKE_SOURCE_DIR}/include/EntityManager.hpp
    ${CMAKE_SOURCE_DIR}/src/HeatPlate.cpp
    ${CMAKE_SOURCE_DIR}/include/HeatPlate.hpp
    # ${CMAKE_SOURCE_DIR}/src/IComponent.cpp
    # ${CMAKE_SOURCE_DIR}/include/IComponent.hpp
    ${CMAKE_SOURCE_DIR}/src/Laboratory.cpp
    ${CMAKE_SOURCE_DIR}/include/Laboratory.hpp
    ${CMAKE_SOURCE_DIR}/src/Liquid.cpp
    ${CMAKE_SOURCE_DIR}/include/Liquid.hpp
    ${CMAKE_SOURCE_DIR}/src/Metal.cpp
    ${CMAKE_SOURCE_DIR}/include/Metal.hpp
    # ${CMAKE_SOURCE_DIR}/src/PhysicsComponent.cpp
    # ${CMAKE_SOURCE_DIR}/include/PhysicsComponent.hpp
    # ${CMAKE_SOURCE_DIR}/src/PhysicsManager.cpp
    # ${CMAKE_SOURCE_DIR}/include/PhysicsManager.hpp
    # ${CMAKE_SOURCE_DIR}/src/Renderable.cpp
    # ${CMAKE_SOURCE_DIR}/include/Renderable.hpp
    # ${CMAKE_SOURCE_DIR}/src/RenderableComponent.cpp
    # ${CMAKE_SOURCE_DIR}/include/RenderableComponent.hpp
    # ${CMAKE_SOURCE_DIR}/src/Renderer.cpp
    # ${CMAKE_SOURCE_DIR}/include/Renderer.hpp
    ${CMAKE_SOURCE_DIR}/src/Scale.cpp
    ${CMAKE_SOURCE_DIR}/include/Scale.hpp
    ${CMAKE_SOURCE_DIR}/src/Substance.cpp
    ${CMAKE_SOURCE_DIR}/include/Substance.hpp
)

add_library(virtual-labs STATIC ${VIRTUAL_LABS_SRC})

target_link_libraries(virtual-labs PRIVATE sfml-graphics sfml-window sfml-system)

add_executable(main test/__main.cpp)
target_link_libraries(main PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

# add_executable(test_substance test/__test_substance.cpp)
# target_link_libraries(test_substance PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

# add_executable(test_container test/__test_container.cpp)
# target_link_libraries(test_container PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

# add_executable(test_renderable test/__test_renderable.cpp)
# target_link_libraries(test_renderable PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

# add_executable(test_entity test/__test_sprites.cpp)
# target_link_libraries(test_entity PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

enable_testing()

# add_test(
#     NAME test_substance
#     COMMAND $<TARGET_FILE:test_substance>
# )
# add_test(
#     NAME test_container
#     COMMAND $<TARGET_FILE:test_container>
# )
# add_test(
#     NAME test_renderable
#     COMMAND $<TARGET_FILE:test_renderable>
# )
# add_test(
#     NAME test_entity
#     COMMAND $<TARGET_FILE:test_entity>
# )

add_custom_command(
    TARGET main
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rm -R ${CMAKE_BINARY_DIR}/assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
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