cmake_minimum_required(VERSION 3.28)
project(heroes-of-anarchy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Пути к SFML
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML-3.0.0")
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

# Include директории
include_directories(
        "${SFML_ROOT}/include"
        "${CMAKE_SOURCE_DIR}/include"
)

# Исходные файлы
set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB
        src/Object.cpp
        src/Entity.cpp
        src/Player.cpp
        src/Item.cpp
        src/Engine.cpp
)

# Создание библиотеки и исполняемого файла
add_library(lib STATIC ${SOURCE_LIB})
add_executable(${PROJECT_NAME} ${SOURCE_EXE})

# Поиск SFML
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

# Подключение SFML
target_link_libraries(${PROJECT_NAME} PRIVATE
        lib
        SFML::Graphics
        SFML::Window
        SFML::System
)

# Для Windows: копирование DLL
if(WIN32)
    file(GLOB SFML_DLLS "${SFML_ROOT}/bin/*.dll")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SFML_DLLS}
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()