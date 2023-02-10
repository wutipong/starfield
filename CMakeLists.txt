cmake_minimum_required(VERSION 3.17)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file")

# set the project name
project(starfield)

# add the executable
add_executable(starfield "main.cpp"
        "theforge/Common_3/Application/CameraController.cpp"
        "theforge/Common_3/Application/Fonts/FontSystem.cpp"
        "theforge/Common_3/Application/Fonts/stbtt.cpp"
        "theforge/Common_3/Application/InputSystem.cpp"
        "theforge/Common_3/Application/Profiler/GpuProfiler.cpp"
        "theforge/Common_3/Application/Profiler/ProfilerBase.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/gainput.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputAllocator.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputDeltaState.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputDevice.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputManager.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputMap.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputInputState.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/GainputMapFilters.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/GainputHID.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/GainputHIDWhitelist.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS4Controller.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/hid/hidparsers/HIDParserPS5Controller.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/keyboard/GainputInputDeviceKeyboard.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/mouse/GainputInputDeviceMouse.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/pad/GainputInputDevicePad.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/gainput/touch/GainputInputDeviceTouch.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source/hidapi/windows/hid.c"
        "theforge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_demo.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_draw.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_tables.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui_widgets.cpp"
        "theforge/Common_3/Application/ThirdParty/OpenSource/imgui/imgui.cpp"
        "theforge/Common_3/Application/UI/UI.cpp"
        "theforge/Common_3/Game/Scripting/LuaManager.cpp"
        "theforge/Common_3/Game/Scripting/LuaSystem.cpp"
        "theforge/Common_3/Graphics/CommonShaderReflection.cpp"
        "theforge/Common_3/Graphics/DependencyTracking.cpp"
        "theforge/Common_3/Graphics/Direct3D11/Direct3D11.cpp"
        "theforge/Common_3/Graphics/Direct3D11/Direct3D11Raytracing.cpp"
        "theforge/Common_3/Graphics/Direct3D11/Direct3D11ShaderReflection.cpp"
        "theforge/Common_3/Graphics/Direct3D12/Direct3D12.cpp"
        "theforge/Common_3/Graphics/Direct3D12/Direct3D12Hooks.cpp"
        "theforge/Common_3/Graphics/Direct3D12/Direct3D12Raytracing.cpp"
        "theforge/Common_3/Graphics/Direct3D12/Direct3D12ShaderReflection.cpp"
        "theforge/Common_3/Graphics/GPUConfig.cpp"
        "theforge/Common_3/Graphics/Graphics.cpp"
        "theforge/Common_3/Graphics/Vulkan/Vulkan.cpp"
        "theforge/Common_3/Graphics/Vulkan/VulkanRaytracing.cpp"
        "theforge/Common_3/Graphics/Vulkan/VulkanShaderReflection.cpp"
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
        "theforge/Common_3/OS/WindowSystem/WindowSystem.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ResourceLoader.cpp"
        "theforge/Common_3/Utilities/FileSystem/FileSystem.cpp"
        "theforge/Common_3/Utilities/Log/Log.c"
        "theforge/Common_3/Utilities/Math/StbDs.c"
        "theforge/Common_3/Utilities/MemoryTracking/MemoryTracking.c"
        "theforge/Common_3/Utilities/ThirdParty/OpenSource/bstrlib/bstrlib.c"
        "theforge/Common_3/Utilities/Timer.c"
        "theforge/Common_3/Utilities/Math/Algorithms.c"
        "theforge/Common_3/Game/Scripting/LuaManagerImpl.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/SpirvTools.cpp"
        "theforge/Common_3/Utilities/FileSystem/SystemRun.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/allocator.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/clusterizer.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/indexcodec.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/indexgenerator.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/overdrawanalyzer.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/overdrawoptimizer.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/simplifier.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/spatialorder.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/stripifier.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/vcacheanalyzer.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/vcacheoptimizer.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/vertexcodec.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/vertexfilter.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/vfetchanalyzer.cpp"
        "theforge/Common_3/Resources/ResourceLoader/ThirdParty/OpenSource/meshoptimizer/src/vfetchoptimizer.cpp"
        "theforge/Common_3/Utilities/ThirdParty/OpenSource/basis_universal/transcoder/basisu_transcoder.cpp"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lapi.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lauxlib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lbaselib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lbitlib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lcode.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lcorolib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lctype.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldblib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldebug.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldo.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ldump.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lfunc.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lgc.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/linit.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/liolib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/llex.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lmathlib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lmem.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/loadlib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lobject.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lopcodes.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/loslib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lparser.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lstate.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lstring.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lstrlib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ltable.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ltablib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/ltm.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lundump.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lutf8lib.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lvm.c"
        "theforge/Common_3/Game/ThirdParty/OpenSource/lua-5.3.5/src/lzio.c"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cfg.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cpp.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cross_parsed_ir.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cross_util.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_cross.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_glsl.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_hlsl.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_msl.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_parser.cpp"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/SPIRV_Cross/spirv_reflect.cpp"
        )

find_package(Vulkan REQUIRED)

target_compile_features(starfield PRIVATE cxx_std_20)
set_property(TARGET starfield PROPERTY CXX_STANDARD 20)
set_property(TARGET starfield PROPERTY CXX_STANDARD_REQUIRED ON)

if (MSVC)
    # set_property(TARGET starfield PROPERTY WIN32_EXECUTABLE ON)
    target_compile_options(starfield PRIVATE /Zc:__cplusplus)
endif ()

target_include_directories(starfield PRIVATE
        "theforge/Common_3/OS/Interfaces"
        "theforge/Common_3/Application/Interfaces"
        "theforge/Common_3/Utilities/Interfaces"
        "theforge/Common_3/Graphics/Interfaces"
        "theforge/Common_3/Resources/ResourceLoader/Interfaces"
        "theforge/Common_3/Application/ThirdParty/OpenSource/gainput/lib/source"
        ${VULKAN_HEADERS_INCLUDE_DIRS}
        )

target_link_directories(starfield PRIVATE
        "theforge/Common_3/OS/ThirdParty/OpenSource/winpixeventruntime/bin"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/ags/ags_lib/lib"
        "theforge/Common_3/Graphics/ThirdParty/OpenSource/nvapi/amd64"
        )

target_link_libraries(starfield PRIVATE XInput Vulkan::Vulkan WinPixEventRuntime amd_ags_x64 nvapi64)

file(COPY
        "${CMAKE_CURRENT_SOURCE_DIR}/theforge/Common_3/OS/ThirdParty/OpenSource/winpixeventruntime/bin/WinPixEventRuntime.dll"
        DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

file(COPY
        "${CMAKE_CURRENT_SOURCE_DIR}/theforge/Common_3/Graphics/ThirdParty/OpenSource/ags/ags_lib/lib/amd_ags_x64.dll"
        DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

file(COPY
        "${CMAKE_CURRENT_SOURCE_DIR}/theforge/Examples_3/Unit_Tests/UnitTestResources/GPUCfg/gpu.cfg"
        DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/GPUCfg")
