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
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Entities
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Core
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Container
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Substance
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/UI
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Event
)

set(VL_PHYSICS_MANAGER_SRC
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/PhysicsManager.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/PhysicsManager.hpp
)

set(VL_CORE_SRC
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/Core/Laboratory.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Core/Laboratory.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/Core/HeatPlate.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Core/HeatPlate.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/Core/Scale.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Core/Scale.hpp
)

set(VL_SUBSTANCE_SRC
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/Substance/Substance.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Substance/Substance.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/Substance/Liquid.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Substance/Liquid.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/Substance/Metal.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Substance/Metal.hpp
)

set(VL_CONTAINER_SRC
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/Container/Container.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Container/Container.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/Container/Beaker.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Container/Beaker.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Physics/Container/Calorimeter.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Physics/Container/Calorimeter.hpp
)

set(VL_UI_SRC
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/UI/Renderable.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/UI/Renderable.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/UI/Renderer.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/UI/Renderer.hpp
)

set(VL_EVENT_SRC
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Event/Clickable.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Event/Clickable.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Event/Button.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Event/Button.hpp
)

set(VL_ENTITY_SRC
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Entities/Entity.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Entities/Entity.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Entities/EntityManager.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Entities/EntityManager.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Entities/IComponent.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Entities/IComponent.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Entities/PhysicsComponent.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Entities/PhysicsComponent.hpp
    ${CMAKE_SOURCE_DIR}/src/VirtualLabs/Entities/RenderComponent.cpp
    ${CMAKE_SOURCE_DIR}/include/VirtualLabs/Entities/RenderComponent.hpp
)

add_library(virtual-labs STATIC 
    ${VL_PHYSICS_MANAGER_SRC}
    ${VL_CORE_SRC}
    ${VL_SUBSTANCE_SRC}
    ${VL_CONTAINER_SRC}
    ${VL_UI_SRC}
)

target_link_libraries(virtual-labs PRIVATE sfml-graphics sfml-window sfml-system)

add_executable(main src/__main.cpp)
target_link_libraries(main PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

# add_executable(test_substance test/__test_substance.cpp)
# target_link_libraries(test_substance PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

# add_executable(test_container test/__test_container.cpp)
# target_link_libraries(test_container PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

add_executable(test_renderable test/__test_renderable.cpp)
target_link_libraries(test_renderable PRIVATE virtual-labs sfml-graphics sfml-window sfml-system)

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
add_test(
    NAME test_renderable
    COMMAND $<TARGET_FILE:test_renderable>
)
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