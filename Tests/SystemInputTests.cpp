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
              << "</naam>" << endl
              << "\t</station>" << endl
              << "</SYSTEM>";
    inputFile.close();

    bool importResult = parser.XmlParser("testInput/testInput1.xml");

    EXPECT_TRUE(importResult);
}

TEST_F(SystemInputTests, ProperlyParsed) {
    parser.XmlParser("testInput/testInput2.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "Circuit is not valid.");
}

// Station Class Tests
TEST_F(SystemInputTests, EmptyStationName) {
    parser.XmlParser("testInput/StationsNaam.xml");
    string error = "FAULT IN STATION NAME: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}


// Track Class Tests
TEST_F(SystemInputTests, EmptyPrevStation){
    parser.XmlParser("testInput/VorigStation.xml");
    string error = "FAULT IN PREVIOUS STATION: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptyNextStation){
    parser.XmlParser("testInput/VolgendStation.xml");
    string error = "FAULT IN NEXT STATION: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptyStationTrack){
    parser.XmlParser("testInput/StationSpoor.xml");
    string error = "FAULT IN STATION TRACK NUMBER: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, NegativeStationTrack){
    parser.XmlParser("testInput/N_StationSpoor.xml");
    string error = "FAULT IN STATION TRACK NUMBER: NEGATIVE";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, L_StationTrack){
    parser.XmlParser("testInput/L_StationSpoor.xml");
    string error = "FAULT IN STATION TRACK NUMBER: NOT AN INTEGER";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

// Tram Class Tests
TEST_F(SystemInputTests, EmptyLineNr){
    parser.XmlParser("testInput/TramLijnNr.xml");
    string error = "FAULT IN TRAM LINE NUMBER: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, NegativeLineNr){
 parser.XmlParser("testInput/N_TramLijnNr.xml");
    string error = "FAULT IN TRAM LINE NUMBER: NEGATIVE";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, L_LineNr){
    parser.XmlParser("testInput/L_TramLijnNr.xml");
    string error = "FAULT IN TRAM LINE NUMBER: NOT AN INTEGER";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptySeats){
    parser.XmlParser("testInput/TramZitplaatsen.xml");
    string error = "FAULT IN TRAM SEATS: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, NegativeSeats){
    parser.XmlParser("testInput/N_TramZitplaatsen.xml");
    string error = "FAULT IN TRAM SEATS: NEGATIVE";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, L_Seats){
    parser.XmlParser("testInput/L_TramZitplaatsen.xml");
    string error = "FAULT IN TRAM SEATS: NOT AN INTEGER";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptySpeed){
    parser.XmlParser("testInput/TramSnelheid.xml");
    string error = "FAULT IN TRAM SPEED: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, NegativeSpeed){
    parser.XmlParser("testInput/N_TramSnelheid.xml");
    string error = "FAULT IN TRAM SPEED: NEGATIVE";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, L_Speed){
    parser.XmlParser("testInput/L_TramSnelheid.xml");
    string error = "FAULT IN TRAM SPEED: NOT AN INTEGER";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptyStartingStation){
    parser.XmlParser("testInput/BeginStationTram.xml");
    string error = "FAULT IN TRAM STARTING STATION: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptyTramType){
    parser.XmlParser("testInput/TramType.xml");
    string error = "FAULT IN TRAM TYPE: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, IncorrectTramType){
    parser.XmlParser("testInput/I_TramType.xml");
    string error = "FAULT IN TRAM TYPE: INCORRECT TYPE";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptyVehicleNr){
    parser.XmlParser("testInput/VoertuigNr.xml");
    string error = "FAULT IN TRAM VEHICLE NUMBER: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, NegativeVehicleNr){
    parser.XmlParser("testInput/N_VoertuigNr.xml");
    string error = "FAULT IN TRAM VEHICLE NUMBER: NEGATIVE";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, L_VehicleNr){
    parser.XmlParser("testInput/L_VoertuigNr.xml");
    string error = "FAULT IN TRAM VEHICLE NUMBER: NOT AN INTEGER";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

// Passenger Class Tests
TEST_F(SystemInputTests, EmptyPassengerName){
    parser.XmlParser("testInput/PassagiersNaam.xml");
    string error = "FAULT IN PASSENGER NAME: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptyPassengerStartingStation){
    parser.XmlParser("testInput/PassagierBeginStation.xml");
    string error = "FAULT IN PASSENGER STARTING STATION: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptyPassengerEndingStation){
    parser.XmlParser("testInput/PassagierEindStation.xml");
    string error = "FAULT IN PASSENGER END STATION: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, EmptyPassengerAmount){
    parser.XmlParser("testInput/PassagiersAantal.xml");
    string error = "FAULT IN PASSENGER AMOUNT: EMPTY";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, NegativePassengerAmount){
    parser.XmlParser("testInput/N_PassagiersAantal.xml");
    string error = "FAULT IN PASSENGER AMOUNT: NEGATIVE";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, L_PassengerAmount){
    parser.XmlParser("testInput/L_PassagiersAantal.xml");
    string error = "FAULT IN PASSENGER AMOUNT: NOT AN INTEGER";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}

TEST_F(SystemInputTests, MultipleErrors){
    parser.XmlParser("testInput/MultipleErrors.xml");
    string error = "\nFAULT IN STATION NAME: EMPTY";
    error += "\nFAULT IN NEXT STATION: EMPTY";
    error += "\nFAULT IN STATION TYPE: INCORRECT TYPE";
    error += "\nFAULT IN TRAM SEATS: NOT AN INTEGER";
    error += "\nFAULT IN TRAM SPEED: NEGATIVE";
    error += "\nFAULT IN TRAM STARTING STATION: EMPTY";
    error += "\nFAULT IN TRAM VEHICLE NUMBER: EMPTY";
    error += "\nFAULT IN PASSENGER STARTING STATION: EMPTY";
    error += "\nFAULT IN PASSENGER AMOUNT: NOT AN INTEGER\n";
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), error);
}