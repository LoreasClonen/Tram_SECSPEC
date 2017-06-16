//
// Created by uauser on 6/14/17.
//

#include "Halte.h"

bool Halte::acceptingAlbatros() {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling acceptingAlbatros.");
    return false;
}

string Halte::typeString() {
    return "Halte";
}
