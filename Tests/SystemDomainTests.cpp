#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

#include "TestUtils.h"
#include "../src/Parser/Parser.h"

class SystemDomainTest: public ::testing::Test {
protected:
    friend class Parser;

    Parser parser;
    System system;
};

TEST_F(SystemDomainTest, DefaultConstructor) {
    Station* testStation = new Station();
    Tram* testTram = new Tram();
    Spoor* testSpoor = new Spoor();
    EXPECT_TRUE(system.properlyInitialized());
    EXPECT_TRUE(testStation->properlyInitialized());
    EXPECT_TRUE(testTram->properlyInitialized());
    EXPECT_TRUE(testSpoor->properlyInitialized());

}

TEST_F(SystemDomainTest, HappyDay) {
    parser.XmlParser("testInput/HappyDay.xml");

    parser.getSystem()->autoSimulation();

    EXPECT_TRUE(FileCompare("LogFiles/autoSimulation.txt", "testOutput/ronde_expected.txt"));
}

// Station Class Tests
TEST_F(SystemDomainTest, SetStationNameViolation) {
    Station testStation;
    EXPECT_DEATH(testStation.setNaam(""), "No empty string for Station Name allowed");
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