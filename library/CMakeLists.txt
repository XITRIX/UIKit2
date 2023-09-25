set(UIKIT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(EXTERN_PATH ${UIKIT_PATH}/extern)

set(UIKIT_SRC src/Video.cpp)
set(UIKIT_SOURCE)
set(UIKIT_INCLUDE)
set(UIKIT_PLATFORM_LIBS)
set(UIKIT_PLATFORM_OPTION)

# Add BGFX
add_subdirectory(${EXTERN_PATH}/bgfx.cmake EXCLUDE_FROM_ALL)
list(APPEND UIKIT_INCLUDE ${EXTERN_PATH}/bgfx.cmake/bx/include)

# Add SDL
set(SDL_SHARED OFF)
set(SDL_STATIC ON)

# Add GLFW
#add_subdirectory(${EXTERN_PATH}/glfw EXCLUDE_FROM_ALL)
#list(APPEND UIKIT_INCLUDE ${EXTERN_PATH}/glfw/include)
#list(APPEND CMAKE_SYSTEM_PREFIX_PATH /opt/homebrew/lib)

# Set UIKit's Includes
list(APPEND UIKIT_INCLUDE
        ${UIKIT_PATH}/include
        )

# Set UIKit's Sources
list(APPEND UIKIT_SOURCE
        ${UIKIT_PATH}/src
        )

# Apply UIKit's Sources
foreach (lib ${UIKIT_SOURCE})
    file(GLOB_RECURSE TEMP_SRC "${lib}/*.cpp" "${lib}/*.c")
    list(APPEND UIKIT_SRC ${TEMP_SRC})
endforeach (lib)

# Setup UIKit

if (PLATFORM_DESKTOP)
    add_subdirectory(${EXTERN_PATH}/SDL EXCLUDE_FROM_ALL)
    find_library(SDL2 NAMES SDL2 SDL2-static SDL2main)
    list(APPEND UIKIT_PLATFORM_LIBS SDL2-static SDL2main bgfx)
elseif (PLATFORM_IOS)
    add_subdirectory(${EXTERN_PATH}/SDL EXCLUDE_FROM_ALL)
    find_library(SDL2 NAMES SDL2-static SDL2main)
    list(APPEND UIKIT_PLATFORM_LIBS SDL2-static SDL2main bgfx)
elseif (PLATFORM_SWITCH)
    list(APPEND UIKIT_SRC ${UIKIT_PATH}/src/platform/switch/switch_wrapper.c)
    list(APPEND UIKIT_PLATFORM_LIBS SDL2 bgfx pthread GLESv2 EGL glapi drm_nouveau c nx m)
    find_package(PkgConfig REQUIRED)
endif ()

add_library(UIKit STATIC ${UIKIT_SRC})
set_property(TARGET UIKit PROPERTY CXX_STANDARD 17)

list(APPEND UIKIT_INCLUDE ${EXTERN_PATH}/include)
target_include_directories(UIKit PUBLIC
        ${EXTERN_PATH}/SDL/include
        ${EXTERN_PATH}/SDL/include/SDL2
        ${UIKIT_INCLUDE}
        )

target_link_libraries(UIKit
        ${UIKIT_PLATFORM_LIBS}

        )

target_compile_options(UIKit PUBLIC
        ${UIKIT_PLATFORM_OPTION})