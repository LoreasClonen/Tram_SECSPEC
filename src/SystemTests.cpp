//
// Created by luuk on 19-3-17.
//

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

#include "Parser.h"
#include "TestUtils.h"

class SystemDomainTest: public ::testing::Test {
protected:
    friend class System;

    System system;
};

TEST_F(SystemDomainTest, DefaultConstructor) {
    Station* testStation = new Station();
    Tram* testTram = new Tram();
    EXPECT_TRUE(system.properlyInitialized());
    EXPECT_TRUE(testStation->properlyInitialized());
    EXPECT_TRUE(testTram->properlyInitialized());

}

TEST_F(SystemDomainTest, HappyDay) {
    Station station1;
    Station station2;

    station1.setNaam("A");
    station1.setType("halte");

    Spoor spoor1;
    spoor1.setSpoorNr(6);
    spoor1.setVorige("B");
    spoor1.setVolgende("B");

    station1.addSpoor(&spoor1, spoor1.getSpoorNr());

    station2.setNaam("B");
    station2.setType("metrostation");

    Spoor spoor2;
    spoor2.setSpoorNr(12);
    spoor2.setVorige("A");
    spoor2.setVolgende("A");

    station2.addSpoor(&spoor2, spoor2.getSpoorNr());

    system.addStation(station1.getNaam(), &station1);
    system.addStation(station2.getNaam(), &station2);


    Tram tram;

    tram.setLijnNr(10);
    tram.setZitplaatsen(30);
    tram.setSnelheid(75);
    tram.setBeginStation("A");
    tram.setHuidigStation("A");
    tram.setType("PCC");
    tram.setVoertuigNr(100);

    system.addTram(tram.getLijnNr(), &tram);

    EXPECT_EQ("A", station1.getNaam());
    EXPECT_EQ("B", station2.getNaam());
    EXPECT_EQ(10, tram.getLijnNr());

//    string output = system.ronde_rijden();
//
//    string expected = "Rondje rijden...";
//    expected += "\n";
//    expected += "Tram 10 reed van station A naar station B";
//    expected += "\n";
//    expected += "Tram 10 reed van station B naar station A";
//    expected += "\n";
//    expected += "\n";
//
//    EXPECT_EQ(output, expected);
}

// Station Class Tests
TEST_F(SystemDomainTest, SetStationNameViolation) {
    Station testStation;
    EXPECT_DEATH(testStation.setNaam(""), "No empty string for Station Name allowed");
}

TEST_F(SystemDomainTest, SetStationTypeViolation) {
    Station testStation;
    EXPECT_DEATH(testStation.setType(""), "No empty string for Station type allowed");
}

// Track Class Tests
TEST_F(SystemDomainTest, SetTrackNrViolation) {
    Spoor testSpoor;
    EXPECT_DEATH(testSpoor.setSpoorNr(-5), "No negative Track number allowed");
}

TEST_F(SystemDomainTest, SetVorigeViolation) {
    Spoor testSpoor;
    EXPECT_DEATH(testSpoor.setVorige(""), "No empty string for previous Station allowed");
}

TEST_F(SystemDomainTest, SetVolgendeViolation) {
    Spoor testSpoor;
    EXPECT_DEATH(testSpoor.setVolgende(""), "No empty string for next Station allowed");
}

// Tram Class Tests
TEST_F(SystemDomainTest, SetLijnNrViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setLijnNr(-60), "No negative line numbers allowed");
}

TEST_F(SystemDomainTest, SetZitplaatsenViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setZitplaatsen(-15), "No negative seats allowed");
}

TEST_F(SystemDomainTest, SetSpeedViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setSnelheid(-20), "No negative speed allowed");
}

TEST_F(SystemDomainTest, SetTramBeginstationViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setBeginStation(""), "No empty string for Starting Station allowed");
}

TEST_F(SystemDomainTest, SetTramHuidigstationViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setHuidigStation(""), "No empty string for Current Station allowed");
}

TEST_F(SystemDomainTest, SetTramTypeViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setType(""), "No empty string for Tram type allowed");
}

TEST_F(SystemDomainTest, SetVehicleNrViolation) {
    Tram testTram;
    EXPECT_DEATH(testTram.setVoertuigNr(-10), "No empty string for vehicle number allowed");
}

// Passenger Class Tests
TEST_F(SystemDomainTest, SetPassengerNameViolation) {
    Passagier testPassagier;
    EXPECT_DEATH(testPassagier.setNaam(""), "No empty string for Passenger Name allowed");
}

TEST_F(SystemDomainTest, SetPassengerBeginstationViolation) {
    Passagier testPassagier;
    EXPECT_DEATH(testPassagier.setBeginStation(""), "No empty string for Starting Station allowed");
}

TEST_F(SystemDomainTest, SetPassengerEndstationViolation) {
    Passagier testPassagier;
    EXPECT_DEATH(testPassagier.setEindStation(""), "No empty string for End Station allowed");
}

TEST_F(SystemDomainTest, SetPassengerAmountViolation) {
    Passagier testPassagier;
    EXPECT_DEATH(testPassagier.setHoeveelheid(-12), "No negative amount of passengers allowed");
}

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

//TEST_F(SystemInputTests, CircularTest) {
//    parser.XmlParser("testInput/testInput2.xml");
//
//    EXPECT_FALSE(parser.getSystem()->Valid_circuit());
//}

TEST_F(SystemInputTests, EmptyStationName){
    parser.XmlParser("testInput/StationsNaam.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

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

TEST_F(SystemInputTests, EmptyLineNr){
    parser.XmlParser("testInput/TramLijnNr.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptySeats){
    parser.XmlParser("testInput/TramZitplaatsen.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptySpeed){
    parser.XmlParser("testInput/TramSnelheid.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

TEST_F(SystemInputTests, EmptyStartingStation){
    parser.XmlParser("testInput/BeginStationTram.xml");
    EXPECT_DEATH(parser.getSystem()->properlyparsed(), "XML File wasn't properly parsed.");
}

class SystemOutputTests: public ::testing::Test {
protected:
    friend class System;

    System system;
};

TEST_F(SystemOutputTests, OutputFileTests){
    // Designed based on TicTacToeOutputTests:
    // Copyright: Project Software Engineering - BA1 informatica - Serge Demeyer -
    // University of Antwerp
    ASSERT_TRUE(DirectoryExists("testOutput"));

    ofstream outputFile;
    outputFile.open("testOutput/outputFile1.txt");
    outputFile.close();
    outputFile.open("testOutput/outputFile2.txt");
    outputFile.close();

    EXPECT_TRUE(FileExists("testOutput/outputFile1.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/outputFile1.txt"));
    EXPECT_TRUE(FileExists("testOutput/outputFile2.txt"));
    EXPECT_TRUE(FileIsEmpty("testOutput/outputFile1.txt"));

    EXPECT_TRUE(FileCompare("testOutput/outputFile1.txt", "testOutput/outputFile2.txt"));
    EXPECT_TRUE(FileCompare("testOutput/outputFile2.txt", "testOutput/outputFile1.txt"));

    Passagier passagier;
    passagier.setNaam("Groep1");
    passagier.setBeginStation("A");
    passagier.setEindStation("B");
    passagier.setHoeveelheid(25);

    Station station;
    station.setNaam("A");
    station.setType("halte");
    Spoor spoor;
    spoor.setSpoorNr(10);
    spoor.setVorige("C");
    spoor.setVolgende("B");

    station.addSpoor(&spoor, spoor.getSpoorNr());
    station.addPassagier("Groep1");
    //Adding station to system
    system.addStation(station.getNaam(), &station);

    //Setting tram variables
    Tram tram;
    tram.setLijnNr(10);
    tram.setZitplaatsen(55);
    tram.setSnelheid(60);
    tram.setBeginStation("A");
    tram.setVoertuigNr(22);
    tram.addPassagiers("Groep1");
    //Adding tram to system
    system.addTram(tram.getLijnNr(), &tram);
    system.addPassagier("Groep1", &passagier);

    //Creating output-string
    string outputString = system.Output();

    ofstream testOutput;
    testOutput.open("testOutput/outputFile1.txt");
    testOutput << outputString;
    testOutput.close();

    ofstream testOutput2;
    testOutput2.open("testOutput/outputFile2.txt");
    testOutput2 << "--== STATIONS ==--" << endl
                << "Station A" << endl
                << "Type: halte" << endl
                << "--== SPOREN ==--" << endl
                << "Spoor 10" << endl
                << "-> Station B" << endl
                << "<- Station C" << endl
                << "Wachtende passagiers:" << endl
                << " - Groep1, 25 mensen, reist naar Station: B" << endl << endl
                << "--== TRAMS ==--" << endl
                << "Tram 10 nr 22" << endl
                << "Zitplaatsen: 55" << endl
                << "Snelheid: 60km/h" << endl
                << "Huidig Station: A" << endl;

    testOutput2.close();
    EXPECT_TRUE(FileCompare("testOutput/outputFile1.txt", "testOutput/outputFile2.txt"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

