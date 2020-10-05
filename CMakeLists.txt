cmake_minimum_required(VERSION 3.5)

project(mast2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

find_package(KF5Crash)

find_package(KF5Su)

set(TS_FILES mast2_ru_RU.ts)

add_executable(mast2
  src/main.cpp
  src/mast2.cpp
  src/mast2.h
  src/fsutils.h
  src/secutils.h
  ${TS_FILES}
)

target_link_libraries(mast2 PRIVATE Qt5::Widgets KF5::Crash KF5::Su)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
