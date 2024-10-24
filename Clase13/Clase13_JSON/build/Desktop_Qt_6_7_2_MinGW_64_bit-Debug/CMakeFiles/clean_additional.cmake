# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Clase13_JSON_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Clase13_JSON_autogen.dir\\ParseCache.txt"
  "Clase13_JSON_autogen"
  )
endif()
