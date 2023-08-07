# Install script for directory: /home/dustin/code/snes9x/external/glslang/SPIRV

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/x86_64-linux-gnu" TYPE STATIC_LIBRARY FILES "/home/dustin/code/snes9x/gtk/build/glslang/SPIRV/libSPVRemapper.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/x86_64-linux-gnu" TYPE STATIC_LIBRARY FILES "/home/dustin/code/snes9x/gtk/build/glslang/SPIRV/libSPIRV.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/x86_64-linux-gnu/cmake" TYPE FILE FILES "/home/dustin/code/snes9x/gtk/build/glslang/SPIRV/SPVRemapperTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/x86_64-linux-gnu/cmake" TYPE FILE FILES "/home/dustin/code/snes9x/gtk/build/glslang/SPIRV/SPIRVTargets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/glslang/SPIRV" TYPE FILE FILES
    "/home/dustin/code/snes9x/external/glslang/SPIRV/bitutils.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/spirv.hpp"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/GLSL.std.450.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/GLSL.ext.EXT.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/GLSL.ext.KHR.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/GlslangToSpv.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/hex_float.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/Logger.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/SpvBuilder.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/spvIR.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/doc.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/SpvTools.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/disassemble.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/GLSL.ext.AMD.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/GLSL.ext.NV.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/GLSL.ext.ARM.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/NonSemanticDebugPrintf.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/NonSemanticShaderDebugInfo100.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/SPVRemapper.h"
    "/home/dustin/code/snes9x/external/glslang/SPIRV/doc.h"
    )
endif()

