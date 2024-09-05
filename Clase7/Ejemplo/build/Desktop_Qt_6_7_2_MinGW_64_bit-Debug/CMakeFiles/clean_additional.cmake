# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Ejemplo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ejemplo_autogen.dir\\ParseCache.txt"
  "Ejemplo_autogen"
  )
endif()
