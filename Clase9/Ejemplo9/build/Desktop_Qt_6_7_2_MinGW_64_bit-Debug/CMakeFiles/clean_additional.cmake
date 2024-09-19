# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Ejemplo9_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ejemplo9_autogen.dir\\ParseCache.txt"
  "Ejemplo9_autogen"
  )
endif()
