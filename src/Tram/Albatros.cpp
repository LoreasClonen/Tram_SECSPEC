//
// Created by uauser on 5/11/17.
//

#include "Albatros.h"

bool Albatros::isAlbatros(){
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling isAlbatros.");
    return true;
}

string Albatros::typeString() {
    return "Albatros";
}

