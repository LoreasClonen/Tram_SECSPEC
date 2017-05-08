cmake_minimum_required(VERSION 3.5.1)
project(Tram_Netwerk)

set(CMAKE_CXX_STANDARD 11)

set(RELEASE_SOURCE_FILES src/main.cpp src/Station src/System src/Tram src/Parser.cpp src/DesignByContract
        src/tinystr src/tinyxml src/tinyxmlerror.cpp src/tinyxmlparser.cpp src/Parser.h src/Passagier.cpp src/Passagier.h src/Spoor.cpp src/Spoor.h )

set(DEBUG_SOURCE_FILES Tests/SystemTests.cpp src/System.cpp src/Station src/System src/Tram src/Parser.cpp src/DesignByContract
        src/tinystr src/tinyxml src/tinyxmlerror.cpp src/tinyxmlparser.cpp src/Parser.h Tests/TestUtils.cpp Tests/TestUtils.h
        src/Passagier.cpp src/Passagier.h src/Spoor.cpp src/Spoor.h
        Tests/SystemDomainTests.cpp Tests/SystemInputTests.cpp Tests/SystemOutputTests.cpp)

add_executable(Tram_Netwerk ${RELEASE_SOURCE_FILES})

add_executable(Tram_Netwerk_debug ${DEBUG_SOURCE_FILES})

add_subdirectory(gtest/lib/googletest-master)
include_directories(gtest/lib/googletest-master/googlemock/include)
link_directories(gtest/lib)
target_link_libraries(Tram_Netwerk gtest gtest_main)
target_link_libraries(Tram_Netwerk_debug gtest)


