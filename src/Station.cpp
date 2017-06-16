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
    Station::passagier.insert(passagier);

}

set<string> Station::getPassagier() {
    return passagier;
}

void Station::removePassagier(string Passagier) {
    Station::passagier.erase(Passagier);
}

map<int, Spoor*> Station::getSporen() {
    return sporen;
}


void Station::addSpoor(Spoor* spoor, int spoorNr){
    Station::sporen[spoorNr] = spoor;
}

string Station::typeString() {
    return std::__cxx11::string();
}

void Station::setSporen(const map<int, Spoor *> &sporen) {
    Station::sporen = sporen;
}


