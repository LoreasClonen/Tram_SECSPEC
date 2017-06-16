cmake_minimum_required(VERSION 3.5.1)
project(Tram_Netwerk)

set(CMAKE_CXX_STANDARD 11)

set(RELEASE_SOURCE_FILES src/main.cpp src/Station src/System src/Tram src/Parser/Parser.cpp src/DesignByContract
        src/tinystr src/tinyxml src/tinyxml/tinyxmlerror.cpp src/tinyxml/tinyxmlparser.cpp src/Parser/Parser.h src/Passagier/Passagier.cpp src/Passagier/Passagier.h
        src/Metrostation src/Halte src/Spoor/Spoor.cpp src/Spoor/Spoor.h src/Tram/Albatros.cpp src/Tram/Albatros.h src/Tram/PCC.cpp)

set(DEBUG_SOURCE_FILES Tests/SystemTests.cpp src/System/System.cpp src/Station src/System src/Tram src/Parser/Parser.cpp src/DesignByContract
        src/tinystr src/tinyxml src/tinyxml/tinyxmlerror.cpp src/tinyxml/tinyxmlparser.cpp src/Parser/Parser.h Tests/TestUtils.cpp Tests/TestUtils.h
        src/Passagier/Passagier.cpp src/Passagier/Passagier.h src/Spoor/Spoor.cpp src/Spoor/Spoor.h
        Tests/SystemDomainTests.cpp Tests/SystemInputTests.cpp Tests/SystemOutputTests.cpp)

add_executable(Tram_Netwerk ${RELEASE_SOURCE_FILES})

add_executable(Tram_Netwerk_debug ${DEBUG_SOURCE_FILES})

add_subdirectory(gtest/lib/googletest-master)
include_directories(gtest/lib/googletest-master/googlemock/include)
link_directories(gtest/lib)
target_link_libraries(Tram_Netwerk gtest gtest_main)
target_link_libraries(Tram_Netwerk_debug gtest)


