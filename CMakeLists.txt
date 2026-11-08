# CMakeList.txt : CMake project for 5S Lab1 Calculator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Calculator LANGUAGES CXX)


add_executable (CMakeTarget "source/Calculator.cpp" "source/Calc.cpp" "source/Function.cpp" "source/Operation.cpp"  "source/Term.cpp" "source/PluginLoader.cpp")

target_include_directories(CMakeTarget PRIVATE header)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory(plugins)
