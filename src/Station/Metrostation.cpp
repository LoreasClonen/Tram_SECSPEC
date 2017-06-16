//
// Created by uauser on 6/14/17.
//

#include "Metrostation.h"

bool Metrostation::isMetrostation(){
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling acceptingAlbatros.");
    return true;
}

string Metrostation::typeString() {
    return "Metrostation";
}
