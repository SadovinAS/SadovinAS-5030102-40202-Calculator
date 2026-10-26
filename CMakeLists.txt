# CMakeList.txt : CMake project for 5S Lab1 Calculator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Calculator")

# Add source to this project's executable.
add_executable (CMakeTarget "5S Lab1 Calculator.cpp" "5S Lab1 Calculator.h" "Calc.cpp"  "Calc.h" "Function.cpp" "Function.h" "Term.h" "Operation.h" "PluginLoader.h" "Operation.cpp"  "Term.cpp" "PluginLoader.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory(plugins)
