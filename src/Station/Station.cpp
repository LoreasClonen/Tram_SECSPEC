//
// Created by uauser on 3/2/17.
//

#include "Station.h"

Station::Station() {
    Station::naam = "";
    Station::_initCheck = this;
}

bool Station::properlyInitialized() {
    return _initCheck == this;
}

string Station::getNaam() {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling getNaam.");
    return naam;
}

void Station::setNaam(string naam) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setNaam.");
    ENSURE(naam != "","No empty string for Station Name allowed");
    Station::naam = naam;
}

void Station::addPassagier(string passagier) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling addPassagier.");
    ENSURE(passagier != "","No empty string for Passenger Name allowed");
    int setSize = this->getPassagier().size();
    Station::passagier.insert(passagier);
    REQUIRE(setSize + 1 == this->getPassagier().size(), "Passenger wasn't correctly added to Station.");
}

set<string> Station::getPassagier() {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling getPassagier.");
    return passagier;
}

void Station::removePassagier(string passagier) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setNaam.");
    ENSURE(passagier != "","No empty string for Passenger Name allowed");
    int setSize = this->getPassagier().size();
    Station::passagier.erase(passagier);
    REQUIRE(setSize - 1 == this->getPassagier().size(), "Passenger wasn't correctly removed from Station.");
}

map<int, Spoor*> Station::getSporen() {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling getSporen.");
    return sporen;
}

void Station::setSporen(map<int, Spoor *> sporen){
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling setSporen.");
    ENSURE(sporen.size() == 0, "Tracks weren't set due to empty map");
    Station::sporen = sporen;
    REQUIRE(this->getSporen() == sporen, "Tracks weren't correctly set.");
}

void Station::addSpoor(Spoor* spoor, int spoorNr){
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling addSpoor.");
    ENSURE(spoorNr < 0, "No negative number for Track Number allowed");
    int setSize = this->getPassagier().size();
    Station::sporen[spoorNr] = spoor;
    REQUIRE(setSize + 1 == this->getPassagier().size(), "Passenger wasn't correctly removed from Station.");
}

string Station::typeString() {
    return std::__cxx11::string();
}

bool Station::isMetrostation() {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling isMetrostation.");
    return false;
}






