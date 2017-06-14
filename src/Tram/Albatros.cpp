//
// Created by uauser on 5/11/17.
//

#include "Albatros.h"

string Albatros::verplaatsTram(string station) {
    Albatros::setHuidigStation(station);

    string stationsNaam = this->getHuidigStation();

    if(stationsNaam == ""){
        stationsNaam = this->getBeginStation();
    }

    this->setHuidigStation(station);
    string output = "Tram " + to_string(this->getVoertuigNr()) + " reed van station " + stationsNaam
                    + " naar station " + station + "\n";
    return output;
}

bool Albatros::validStation(string type) {
    if(type == "metrostation"){
        return true;
    }
    return false;
}

string Albatros::typeString() {
    return "Albatros";
}

