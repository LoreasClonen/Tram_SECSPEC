//
// Created by uauser on 4/19/17.
//

#include "Passagier.h"

Passagier::Passagier() {
    _initCheck = this;
    naam = "";
    beginStation = "";
    eindStation = "";
    hoeveelheid = -1;
}

bool Passagier::properlyInitialized() {
    return _initCheck == this;
}

string Passagier::getNaam() {
    REQUIRE(this->properlyInitialized(),
            "Passagier wasn't initialized when calling getNaam.");
    return naam;
}

void Passagier::setNaam(string naam) {
    REQUIRE(this->properlyInitialized(),
            "Passagier wasn't initialized when calling setNaam.");
    ENSURE(naam != "", "No empty string for Passenger Name allowed");
    Passagier::naam = naam;
}

string Passagier::getBeginStation() {
    REQUIRE(this->properlyInitialized(),
            "Passagier wasn't initialized when calling getBeginStation.");
    return beginStation;
}

void Passagier::setBeginStation(string beginStation) {
    REQUIRE(this->properlyInitialized(),
            "Passagier wasn't initialized when calling setBeginStation.");
    ENSURE(beginStation != "", "No empty string for Starting Station allowed");
    Passagier::beginStation = beginStation;
}

string Passagier::getEindStation() {
    REQUIRE(this->properlyInitialized(),
            "Passagier wasn't initialized when calling getEindStation.");
    return eindStation;
}

void Passagier::setEindStation(string eindStation) {
    REQUIRE(this->properlyInitialized(),
            "Passagier wasn't initialized when calling setEindStation.");
    ENSURE(eindStation != "", "No empty string for End Station allowed");
    Passagier::eindStation = eindStation;
}

int Passagier::getHoeveelheid() {
    REQUIRE(this->properlyInitialized(),
            "Passagier wasn't initialized when calling getHoeveelheid.");
    return hoeveelheid;
}

void Passagier::setHoeveelheid(int hoeveelheid) {
    REQUIRE(this->properlyInitialized(),
            "Passagier wasn't initialized when calling setHoeveelheid.");
    ENSURE(hoeveelheid > 0, "No negative amount of passengers allowed");
    Passagier::hoeveelheid = hoeveelheid;
}
