# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 2.6)

project ("Step6")

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 5)
 
# does this system provide the log and exp functions?
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# does this system provide the log and exp functions?
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# should we use our own math functions
option(USE_MYMATH 
  "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/Step6config.h.in"
  "${PROJECT_BINARY_DIR}/Step6config.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# add the executable
add_executable (Step6 "Step6.cpp" "Step6.h")
target_link_libraries (Step6  ${EXTRA_LIBS})

# add the install targets
install (TARGETS Step6 DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/Step5Config.h"        
         DESTINATION include)


include(CTest)

#define a macro to simplify adding tests
macro (do_test arg result)
  add_test (TutorialComp${arg} Step6  ${arg})
  set_tests_properties (TutorialComp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro (do_test)
 
# do a bunch of result based tests
#do_test (4 "4 is 2")
#do_test (9 "9 is 3")
#do_test (5 "5 is 2.236")
#do_test (7 "7 is 2.645")
#do_test (25 "25 is 5")
#do_test (-25 "-25 is 0")
#do_test (0.0001 "0.0001 is 0.01")

# does the application run
 add_test (TutorialRuns Step6 25)
# does it sqrt of 25
 add_test (TutorialComp25 Step6 25)
 set_tests_properties (TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
# does it handle negative numbers
 add_test (TutorialNegative Step6 -25)
 set_tests_properties (TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")
# does it handle small numbers
 add_test (TutorialSmall Step6 0.0001)
 set_tests_properties (TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.md")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)