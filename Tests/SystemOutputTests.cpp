#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>

using namespace std;

#include "TestUtils.h"
#include "../src/Parser/Parser.h"
#include "../src/Tram/Albatros.h"
#include "../src/Station/Halte.h"
#include "../src/Tram/PCC.h"

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

    Station* station = new Halte;
    station->setNaam("A");
    Spoor spoor;
    spoor.setSpoorNr(10);
    spoor.setVorige("C");
    spoor.setVolgende("B");

    station->addSpoor(&spoor, spoor.getSpoorNr());
    station->addPassagier("Groep1");
    //Adding station to system
    system.addStation(station->getNaam(), station);

    //Setting tram variables
    Tram* tram = new PCC;
    tram->setLijnNr(10);
    tram->setZitplaatsen(55);
    tram->setSnelheid(60);
    tram->setBeginStation("A");
    tram->setVoertuigNr(22);
    //Adding tram to system
    system.addTram(tram->getLijnNr(), tram);
    system.addPassagier("Groep1", &passagier);

    //Creating outputLog
    system.Output();

    ofstream testOutput2;
    testOutput2.open("testOutput/outputFile2.txt");
    testOutput2 << "--== STATIONS ==--" << endl
    << "Station A" << endl
    << "Type: Halte" << endl
    << "--== SPOREN ==--" << endl
    << "Spoor 10" << endl
    << "-> Station B" << endl
    << "<- Station C" << endl
    << "Wachtende passagiers:" << endl
    << " - Groep1, 25 mensen, reist naar Station: B" << endl << endl
    << "--== TRAMS ==--" << endl
    << "Tram 10 nr 22" << endl
    << "Type: PCC" << endl
    << "Zitplaatsen: 55" << endl
    << "Snelheid: 60km/h" << endl
    << "Huidig Station: A" << endl;

    testOutput2.close();
    EXPECT_TRUE(FileCompare("LogFiles/outputLog.txt", "testOutput/outputFile2.txt"));
}