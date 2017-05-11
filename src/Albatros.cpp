//
// Created by uauser on 5/11/17.
//

#include "Albatros.h"

void Albatros::verplaatsTram() {

    string stationsNaam = this->getHuidigStation();

    if(stationsNaam == ""){
       stationsNaam = this->getBeginStation();
    }


}

bool Albatros::validStation(string type) {
    if(type == "metrostation"){
        return true;
    }
    return false;
}
