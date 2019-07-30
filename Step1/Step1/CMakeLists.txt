# CMakeList.txt: проект CMake для Step1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 2.6)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/Step1config.h.in"
  "${PROJECT_BINARY_DIR}/Step1config.h"
  )

#configure_file (
#  "${PROJECT_SOURCE_DIR}/Step1config.h.in"
#  "${PROJECT_SOURCE_DIR}/Step1config.h"
#  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Step1 "Step1.cpp" "Step1.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
