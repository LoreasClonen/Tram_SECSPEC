

#include "PCC.h"

bool PCC::isAlbatros(){
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling isAlbatros.");
    return false;
}

string PCC::typeString() {
    return "PCC";
}


