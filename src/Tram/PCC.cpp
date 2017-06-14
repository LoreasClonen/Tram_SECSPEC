

#include "PCC.h"

string PCC::verplaatsTram(string station) {
    PCC::setHuidigStation(station);

    string stationsNaam = this->getHuidigStation();

    if(stationsNaam == ""){
        stationsNaam = this->getBeginStation();
    }

    this->setHuidigStation(station);
    string output = "Tram " + to_string(this->getVoertuigNr()) + " reed van station " + stationsNaam
                    + " naar station " + station + "\n";
    return output;
}

bool PCC::validStation(string type) {
    return true;
}

string PCC::typeString() {
    return "PCC";
}

