cmake_minimum_required(VERSION 3.24)
project(GUI_Calculator_CPlusPlus)
include(FindPkgConfig)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

# ------------------ wxWidgets ------------------
set(wxWidgets_USE_STATIC 1)
set(wxBUILD_SHARED OFF)
FetchContent_Declare(
        wxWidgets
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.4/wxWidgets-3.2.4.tar.bz2
)
FetchContent_GetProperties(wxWidgets)
FetchContent_MakeAvailable(wxWidgets)

add_executable(App
        src/BasicMath.cpp
        src/BasicMath.h
        src/GUI.cpp
        src/GUI.h
        src/Main.cpp
        src/Main.h)
target_include_directories(App PRIVATE ${wxWidgets_SOURCE_DIR}/include)
target_link_libraries(App PRIVATE wx::base wx::core)


