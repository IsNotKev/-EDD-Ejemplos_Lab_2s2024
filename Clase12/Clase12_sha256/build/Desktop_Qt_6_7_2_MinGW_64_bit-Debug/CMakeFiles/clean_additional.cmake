# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Clase12_sha256_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Clase12_sha256_autogen.dir\\ParseCache.txt"
  "Clase12_sha256_autogen"
  )
endif()
