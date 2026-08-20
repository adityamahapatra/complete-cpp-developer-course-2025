cmake_minimum_required(VERSION 3.20)
project(CppDeveloperCourse LANGUAGES CXX)

# ---------------------------------------------------------------------------
# Global build settings
# ---------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)   # gnu++20, matching the existing VS Code config

# Export compile_commands.json so IntelliSense resolves every include path
# (including the vendored fmt headers).
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Every built executable lands in <repo>/bin, matching the existing $BIN
# workflow (e.g. $BIN/percentages).
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Professional, strict warning policy: every warning is treated as an error.
if(MSVC)
  add_compile_options(/W4 /permissive- /WX)
else()
  add_compile_options(-Wall -Wextra -Werror -g)
endif()

# ---------------------------------------------------------------------------
# fmt — used by some exercises (e.g. section_2/Percentages/percentages.cpp)
# Prefer a system install; otherwise fetch a pinned release automatically.
# ---------------------------------------------------------------------------
include(FetchContent)
find_package(fmt QUIET)
if(NOT fmt_FOUND)
  message(STATUS "fmt not found on the system - fetching a pinned release")
  set(FMT_DOC OFF CACHE BOOL "" FORCE)
  set(FMT_TEST OFF CACHE BOOL "" FORCE)
  set(FMT_INSTALL OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG        11.0.2
    GIT_SHALLOW    TRUE
  )
  FetchContent_MakeAvailable(fmt)
endif()

# ---------------------------------------------------------------------------
# Project auto-discovery
#
# Every directory under section_*/ that contains at least one .cpp file
# becomes its own executable target, named after that directory. Directories
# whose name starts with an underscore (e.g. _supplemental,
# _for-proj12-2-files) are treated as working files and are skipped.
# ---------------------------------------------------------------------------
file(GLOB_RECURSE _all_cpp CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/section_*/*.cpp")

set(_project_dirs "")
foreach(_cpp IN LISTS _all_cpp)
  get_filename_component(_dir "${_cpp}" DIRECTORY)

  # Skip directories that contain an underscore-prefixed path component.
  set(_skip FALSE)
  string(REPLACE "/" ";" _parts "${_dir}")
  foreach(_part IN LISTS _parts)
    if(_part MATCHES "^_")
      set(_skip TRUE)
    endif()
  endforeach()
  if(_skip)
    continue()
  endif()

  list(APPEND _project_dirs "${_dir}")
endforeach()
list(REMOVE_DUPLICATES _project_dirs)

# Build one executable from a project directory.
#
# A few folders contain BOTH the original main.cpp and a reworked file that
# also defines main() (e.g. Percentages: main.cpp + percentages.cpp, and
# SunnyWarm: main.cpp + SunnyWarm.cpp). In that case we prefer the reworked
# file(s) and drop main.cpp to avoid a duplicate-symbol link error - this
# matches the workflow where $BIN/percentages and $BIN/SunnyWarm are built.
function(add_course_executable _name _dir)
  file(GLOB _sources CONFIGURE_DEPENDS "${_dir}/*.cpp")
  set(_with_main "")
  set(_without_main "")
  foreach(_src IN LISTS _sources)
    file(READ "${_src}" _content)
    if(_content MATCHES "[^A-Za-z0-9_]main[ \t\r\n]*\\(")
      list(APPEND _with_main "${_src}")
    else()
      list(APPEND _without_main "${_src}")
    endif()
  endforeach()

  list(LENGTH _with_main _main_count)
  if(_main_count GREATER 1)
    # More than one file defines main(): keep the reworked files, drop main.cpp.
    set(_final "${_with_main}")
    list(FILTER _final EXCLUDE REGEX "/main\\.cpp$")
  else()
    set(_final "${_sources}")
  endif()

  add_executable("${_name}" ${_final})
  target_link_libraries("${_name}" PRIVATE fmt::fmt)
endfunction()

foreach(_dir IN LISTS _project_dirs)
  get_filename_component(_name "${_dir}" NAME)
  message(STATUS "Adding project: ${_name}  (${_dir})")
  add_course_executable("${_name}" "${_dir}")
endforeach()
