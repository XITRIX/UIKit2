# toolchain
include(${CMAKE_CURRENT_SOURCE_DIR}/library/cmake/toolchain.cmake)

# Target starts
cmake_minimum_required(VERSION 3.25)
project(BgfxTest)

set(APP_PATH ${CMAKE_CURRENT_SOURCE_DIR}/demo)

set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_ALTER "0")
set(VERSION_BUILD "0")
set(PACKAGE_NAME "ru.xitrix.bgfxtest")
set(PROJECT_AUTHOR "XITRIX")
set(PROJECT_ICON ${CMAKE_CURRENT_SOURCE_DIR}/resources/img/demo_icon.jpg)
set(PROJECT_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources)

add_libromfs(${PROJECT_NAME} ${PROJECT_RESOURCES})

set(CMAKE_CXX_STANDARD 20)
set(BX_CONFIG_DEBUG ON)

add_executable(BgfxTest demo/main.cpp)

if (PLATFORM_IOS)
    ios_bundle(
            "${APP_PATH}/ios/tvos/Splash.storyboard"
            "${APP_PATH}/ios/iphoneos/Splash.storyboard"
            "${APP_PATH}/ios/Images.xcassets"
            "${APP_PATH}/ios/iOSBundleInfo.plist.in"
            "BGFX_Test"
            "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_ALTER}")
elseif (PLATFORM_SWITCH)
    add_custom_target(${PROJECT_NAME}.nro DEPENDS ${PROJECT_NAME}
        COMMAND ${NX_NACPTOOL_EXE} --create "${PROJECT_NAME}" "${PROJECT_AUTHOR}" "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_ALTER}" ${PROJECT_NAME}.nacp --titleid=${PROJECT_TITLEID}
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_RESOURCES} ${CMAKE_BINARY_DIR}/resources
#        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/resources/font
        COMMAND ${NX_ELF2NRO_EXE} ${PROJECT_NAME}.elf ${PROJECT_NAME}.nro --icon=${PROJECT_ICON} --nacp=${PROJECT_NAME}.nacp --romfsdir=${CMAKE_BINARY_DIR}/resources
    )
endif ()

add_subdirectory(library)
target_link_libraries(${PROJECT_NAME} PRIVATE UIKit)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)