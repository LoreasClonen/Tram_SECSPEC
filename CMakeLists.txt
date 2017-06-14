cmake_minimum_required(VERSION 3.5.1)
project(Tram_Netwerk)

set(CMAKE_CXX_STANDARD 11)

set(RELEASE_SOURCE_FILES src/main.cpp src/Parser/Parser src/System/System src/Spoor/Spoor src/Passagier/Passagier src/Station/Station src/Station/Halte
        src/Station/Metrostation src/Tram/Tram src/Tram/Albatros src/Tram/PCC src/tinyxml/tinystr src/tinyxml/tinyxml
        src/tinyxml/tinyxmlerror src/tinyxml/tinyxmlparser src/DesignByContract)

set(DEBUG_SOURCE_FILES Tests/SystemTests Tests/SystemDomainTests Tests/SystemInputTests Tests/SystemOutputTests Tests/TestUtils
        src/Parser/Parser src/System/System src/Spoor/Spoor src/Passagier/Passagier src/Station/Station src/Station/Halte
        src/Station/Metrostation src/Tram/Tram src/Tram/Albatros src/Tram/PCC src/tinyxml/tinystr src/tinyxml/tinyxml
        src/tinyxml/tinyxmlerror src/tinyxml/tinyxmlparser src/DesignByContract)

add_executable(Tram_Netwerk ${RELEASE_SOURCE_FILES})

add_executable(Tram_Netwerk_debug ${DEBUG_SOURCE_FILES})

add_subdirectory(gtest/lib/googletest-master)
include_directories(gtest/lib/googletest-master/googlemock/include)
link_directories(gtest/lib)
target_link_libraries(Tram_Netwerk gtest gtest_main)
target_link_libraries(Tram_Netwerk_debug gtest)

