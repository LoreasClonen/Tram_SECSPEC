//
// Created by uauser on 5/4/17.
//

#include "Spoor.h"

Spoor::Spoor() {
    Spoor::spoorNr = -1;
    Spoor::volgende = "";
    Spoor::vorige = "";
    Spoor::_initCheck = this;
}

bool Spoor::properlyInitialized() {
    return _initCheck == this;
}

int Spoor::getSpoorNr() {
    REQUIRE(this->properlyInitialized(),
            "Spoor wasn't initialized when calling getSpoorNr.");
    return spoorNr;
}

void Spoor::setSpoorNr(int spoorNr) {
    REQUIRE(this->properlyInitialized(),
            "Spoor wasn't initialized when calling setSpoorNr.");
    ENSURE(spoorNr > 0, "No negative Track number allowed");
    Spoor::spoorNr = spoorNr;
    REQUIRE(this->getSpoorNr() == spoorNr, "Track Number wasn't set correctly.");
}

string Spoor::getVolgende() {
    REQUIRE(this->properlyInitialized(),
            "Spoor wasn't initialized when calling getVolgende.");
    return volgende;
}

void Spoor::setVolgende(string volgende) {
    REQUIRE(this->properlyInitialized(),
            "Spoor wasn't initialized when calling setVolgende.");
    ENSURE(volgende != "","No empty string for next Station allowed");
    Spoor::volgende = volgende;
    REQUIRE(this->getVolgende() == volgende, "Next Station wasn't set correctly.");
}

string Spoor::getVorige() {
    REQUIRE(this->properlyInitialized(),
            "Spoor wasn't initialized when calling getVorige.");
    return vorige;
}

void Spoor::setVorige(string vorige) {
    REQUIRE(this->properlyInitialized(),
            "Spoor wasn't initialized when calling setVorige.");
    ENSURE(vorige != "","No empty string for previous Station allowed");
    Spoor::vorige = vorige;
    REQUIRE(this->getVorige() == vorige, "Previous Station wasn't set correctly.");
}
