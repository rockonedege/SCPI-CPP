# This script is tested with vcpkg.
## For Linux
### cmake ../src/ -G  "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=/home/ttan/repo/public/vcpkg/scripts/buildsystems/vcpkg.cmake
### cmake --build . --config Release 
## For Windows
### cmake ../src/ -G  "Visual Studio 16 2019" -A Win64 -DCMAKE_TOOLCHAIN_FILE=F:/vcpkg/scripts/buildsystems/vcpkg.cmake  -DVCPKG_TARGET_TRIPLET=x64-windows  // dynamic
### cmake ../src/ -G  "Visual Studio 16 2019" -A Win64 -DCMAKE_TOOLCHAIN_FILE=F:/vcpkg/scripts/buildsystems/vcpkg.cmake  -DVCPKG_TARGET_TRIPLET=x64-windows-static  // static
### cmake --build . --config Release --target install 

cmake_minimum_required(VERSION 3.13.0)

project(onsemi)

# Configuring
set(LOCAL_CMAKE_SCRIPTS ${CMAKE_HOME_DIRECTORY}/cmake)
include (${LOCAL_CMAKE_SCRIPTS}/my_routine.cmake)   

system_info()
include_boost()

find_package(pybind11 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

enable_testing()

if(Boost_FOUND)
    # logging lib
    add_library(logging  ./logging/cpp/logging.cpp)
    target_include_directories(logging PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(logging PRIVATE ${Boost_LIBRARIES} fmt::fmt)
    
    create_lib_and_unitest(options  logging)
    create_lib_and_unitest(commands  logging)
    create_lib_and_unitest(serialport logging)
 
    # pybind
    pybind11_add_module(example ./pybind/cpp/pyscpi2.cpp)

    add_executable(channel-demo ./logging/cpp/channel-demo.cpp)
    target_include_directories(channel-demo PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(channel-demo PRIVATE logging ${Boost_LIBRARIES})    

    # simulator
    add_executable(simulator ./app/cpp/simulator.cpp)
    target_include_directories(simulator PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(simulator PRIVATE logging ${Boost_LIBRARIES} 
                                        fmt::fmt)
    
    # hipot main program
    add_executable(hipot ./app/cpp/main.cpp ./app/cpp/example.cpp)
    target_include_directories(hipot PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(hipot PRIVATE 
                        logging 
                        options 
                        commands
                        serialport 
                        ${Boost_LIBRARIES} 
                        fmt::fmt)                            

    install(TARGETS hipot simulator 
            PUBLIC_HEADER
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/release)

    add_custom_target(run
            COMMAND ./release/hipot
            DEPENDS install 
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        )
endif()
