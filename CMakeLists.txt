cmake_minimum_required(VERSION 3.17)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

# set the project name
project(starfield)

# add the executable
add_executable(starfield "main.cpp" 
    "theforge/Common_3/Application/UI/UI.cpp"
    "theforge/Common_3/Game/Scripting/LuaSystem.cpp"
    "theforge/Common_3/OS/CPUConfig.cpp"
    "theforge/Common_3/OS/ThirdParty/OpenSource/cpu_features/src/impl_x86_windows.c"
    "theforge/Common_3/OS/Windows/WindowsBase.cpp"
    "theforge/Common_3/OS/Windows/WindowsFileSystem.cpp"
    "theforge/Common_3/OS/Windows/WindowsLog.c"
    "theforge/Common_3/OS/Windows/WindowsStackTraceDump.cpp"
    "theforge/Common_3/OS/Windows/WindowsThread.c"
    "theforge/Common_3/OS/Windows/WindowsTime.c"
    "theforge/Common_3/OS/Windows/WindowsToolsFileSystem.cpp"
    "theforge/Common_3/OS/Windows/WindowsWindow.cpp"
    "theforge/Common_3/Utilities/FileSystem/FileSystem.cpp"
    "theforge/Common_3/Utilities/Log/Log.c"
    "theforge/Common_3/Utilities/ThirdParty/OpenSource/FluidStudios/MemoryManager/mmgr.c"
    "theforge/Common_3/Utilities/Timer.c"
    "theforge/Common_3/Application/Fonts/FontSystem.cpp"
)

find_path(VULKAN_HEADERS_INCLUDE_DIRS "vk_video/vulkan_video_codec_h264std.h")

target_compile_features(starfield PRIVATE cxx_std_20)
set_property(TARGET starfield PROPERTY CXX_STANDARD 20)
set_property(TARGET starfield PROPERTY CXX_STANDARD_REQUIRED ON)

if (MSVC)
    set_property(TARGET starfield PROPERTY WIN32_EXECUTABLE ON)
    target_compile_options(starfield PRIVATE /Zc:__cplusplus)
endif ()

target_include_directories(starfield PRIVATE 
    "theforge/Common_3/OS/Interfaces" 
    "theforge/Common_3/Application/Interfaces"
    ${VULKAN_HEADERS_INCLUDE_DIRS}
)

# target_link_libraries(starfield PRIVATE)