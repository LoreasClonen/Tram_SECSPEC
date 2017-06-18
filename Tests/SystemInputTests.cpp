#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

#include "TestUtils.h"
#include "../src/Parser/Parser.h"

class SystemInputTests: public ::testing::Test {
protected:
    friend class Parser;

    Parser parser;
};

TEST_F(SystemInputTests, InputFileTests) {
    ASSERT_TRUE(DirectoryExists("testInput"));

    ofstream inputFile;

    inputFile.open("testInput/testInput1.xml");
    inputFile << "<SYSTEM>" << endl
              << "\t<station>" << endl
              << "\t\t<naam>" << "A" << endl
              << "\t\t</naam>" << endl
              << "\t</station>" << endl
              << "</SYSTEM>";
    inputFile.close();

    bool importResult = parser.XmlParser("testInput/testInput1.xml");

    EXPECT_FALSE(importResult);
}

TEST_F(SystemInputTests, ProperlyParsed) {
    parser.XmlParser("testInput/testInput2.xml");

    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Circuit is not valid.");
}

// Station Class Tests
TEST_F(SystemInputTests, EmptyStationName){
    parser.XmlParser("testInput/StationsNaam.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

// Track Class Tests
TEST_F(SystemInputTests, EmptyPrevStation){
    parser.XmlParser("testInput/VorigStation.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptyNextStation){
    parser.XmlParser("testInput/VolgendStation.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptyStationTrack){
    parser.XmlParser("testInput/StationSpoor.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, NegativeStationTrack){
    parser.XmlParser("testInput/N_StationSpoor.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, L_StationTrack){
    parser.XmlParser("testInput/L_StationSpoor.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

// Tram Class Tests
TEST_F(SystemInputTests, EmptyLineNr){
    parser.XmlParser("testInput/TramLijnNr.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, NegativeLineNr){
    parser.XmlParser("testInput/N_TramLijnNr.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, L_LineNr){
    parser.XmlParser("testInput/L_TramLijnNr.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptySeats){
    parser.XmlParser("testInput/TramZitplaatsen.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, NegativeSeats){
    parser.XmlParser("testInput/N_TramZitplaatsen.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, L_Seats){
    parser.XmlParser("testInput/L_TramZitplaatsen.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptySpeed){
    parser.XmlParser("testInput/TramSnelheid.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, NegativeSpeed){
    parser.XmlParser("testInput/N_TramSnelheid.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, L_Speed){
    parser.XmlParser("testInput/L_TramSnelheid.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptyStartingStation){
    parser.XmlParser("testInput/BeginStationTram.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptyTramType){
    parser.XmlParser("testInput/TramType.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptyVehicleNr){
    parser.XmlParser("testInput/VoertuigNr.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, NegativeVehicleNr){
    parser.XmlParser("testInput/N_VoertuigNr.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, L_VehicleNr){
    parser.XmlParser("testInput/L_VoertuigNr.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

// Passenger Class Tests
TEST_F(SystemInputTests, EmptyPassengerName){
    parser.XmlParser("testInput/PassagiersNaam.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptyPassengerStartingStation){
    parser.XmlParser("testInput/PassagierBeginStation.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptyPassengerEndingStation){
    parser.XmlParser("testInput/PassagierEindStation.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptyPassengerAmount){
    parser.XmlParser("testInput/PassagiersAantal.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, NegativePassengerAmount){
    parser.XmlParser("testInput/N_PassagiersAantal.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, L_PassengerAmount){
    parser.XmlParser("testInput/L_PassagiersAantal.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}