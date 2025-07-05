cmake_minimum_required(VERSION 3.20)

project(GameJam LANGUAGES C)


if (CMAKE_BUILD_TYPE STREQUAL "Release")
    file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/build/Release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/Release)
else()
    message(STATUS "chegou aqui")

    file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/build/Debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/Debug)
endif()

add_executable(gamejam  src/main.c src/estruturas/array_dinamico.c)
add_executable(
        testes
        # arquivo principal dos testes
        src/testes/testes.c
        # arquivos de testes
        src/testes/testes_array_dinamico.c
        src/testes/testes_entidade.c
        #dependencias
        src/estruturas/array_dinamico.c
        src/entidade/gerenciador_entidades.c
)

if (WIN32)
    target_include_directories(gamejam PRIVATE  "vendor/windows/include/")
    target_link_libraries(gamejam PRIVATE ${CMAKE_SOURCE_DIR}/vendor/windows/lib/libraylib.a m)
    target_include_directories(testes PRIVATE  "vendor/windows/include/")
    target_link_libraries(testes PRIVATE ${CMAKE_SOURCE_DIR}/vendor/windows/lib/libraylib.a m)
elseif (UNIX)
    target_include_directories(gamejam PRIVATE "vendor/linux/include/")
    target_link_libraries(gamejam PRIVATE ${CMAKE_SOURCE_DIR}/vendor/linux/lib/libraylib.a m)
    target_include_directories(testes PRIVATE "vendor/linux/include/")
    target_link_libraries(testes PRIVATE ${CMAKE_SOURCE_DIR}/vendor/linux/lib/libraylib.a m)
endif()
