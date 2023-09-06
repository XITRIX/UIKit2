set(UIKIT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(EXTERN_PATH ${UIKIT_PATH}/extern)

set(UIKIT_SRC)
set(UIKIT_SOURCE)
set(UIKIT_INCLUDE)
set(UIKIT_PLATFORM_LIBS)

# Add BGFX
add_subdirectory(${EXTERN_PATH}/bgfx.cmake EXCLUDE_FROM_ALL)

# Add SDL
set(SDL_SHARED OFF)
set(SDL_STATIC ON)
add_subdirectory(${EXTERN_PATH}/SDL EXCLUDE_FROM_ALL)
find_package(SDL2 REQUIRED SDL2-static SDL2main)

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
add_library(UIKit STATIC ${UIKIT_SRC})
set_property(TARGET UIKit PROPERTY CXX_STANDARD 17)

target_include_directories(UIKit PUBLIC
        ${SDL2_INCLUDE_DIRS}
        ${UIKIT_INCLUDE}
        )

target_link_libraries(UIKit
        bgfx
        SDL2::SDL2-static
        SDL2::SDL2main
        ${UIKIT_PLATFORM_LIBS})