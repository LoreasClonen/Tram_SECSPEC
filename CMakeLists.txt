cmake_minimum_required(VERSION 3.5.1)
project(Tram_Netwerk)

set(CMAKE_CXX_STANDARD 11)

set(RELEASE_SOURCE_FILES src/main.cpp src/System/System src/Station/Station src/Parser/Parser src/DesignByContract
        src/tinyxml/tinystr src/tinyxml/tinyxml src/tinyxml/tinyxmlerror src/tinyxml/tinyxmlparser src/Tram/PCC
        src/Passagier/Passagier src/Spoor/Spoor src/Station/Metrostation src/Station/Halte src/Tram/Tram src/Tram/Albatros)

set(DEBUG_SOURCE_FILES Tests/SystemTests.cpp src/System/System src/Station/Station src/Parser/Parser src/DesignByContract
        src/tinyxml/tinystr src/tinyxml/tinyxml src/tinyxml/tinyxmlerror src/tinyxml/tinyxmlparser Tests/TestUtils
        src/Passagier/Passagier src/Spoor/Spoor src/Station/Metrostation src/Station/Halte src/Tram/Tram src/Tram/Albatros
        src/Tram/PCC Tests/SystemDomainTests.cpp Tests/SystemInputTests.cpp Tests/SystemOutputTests.cpp)

add_executable(Tram_Netwerk ${RELEASE_SOURCE_FILES})

add_executable(Tram_Netwerk_debug ${DEBUG_SOURCE_FILES})

add_subdirectory(gtest/lib/googletest-master)
include_directories(gtest/lib/googletest-master/googlemock/include)
link_directories(gtest/lib)
target_link_libraries(Tram_Netwerk gtest gtest_main)
target_link_libraries(Tram_Netwerk_debug gtest)

