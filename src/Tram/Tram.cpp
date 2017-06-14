//
// Created by uauser on 3/2/17.
//

#include "Tram.h"

Tram::Tram() {
    Tram::lijnNr = -1;
    Tram::zitplaatsen = -1;
    Tram::snelheid = -1;
    Tram::beginStation = "";
    Tram::huidigStation = "";
    Tram::type = "";
    Tram::voertuigNr = -1;
    _initCheck = this;
}

bool Tram::properlyInitialized() {
    return _initCheck == this;
}

int Tram::getLijnNr() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getLijnNr.");
    return lijnNr;
}

int Tram::getZitplaatsen() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getZitplaatsen.");
    return zitplaatsen;
}

int Tram::getSnelheid() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getSnelheid.");
    return snelheid;
}

string Tram::getBeginStation() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getBeginStation.");
    return beginStation;
}

string Tram::getHuidigStation() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getHuidigStation.");
    return huidigStation;
}

void Tram::setLijnNr(int lijnNr) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setLijnNr.");
    ENSURE(lijnNr > 0, "No negative line numbers allowed");
    Tram::lijnNr = lijnNr;
}

void Tram::setZitplaatsen(int zitplaatsen) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setZitplaatsen.");
    ENSURE(zitplaatsen > 0,"No negative seats allowed");
    Tram::zitplaatsen = zitplaatsen;
}

void Tram::setSnelheid(int snelheid) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setSnelheid.");
    ENSURE(snelheid > 0,"No negative speed allowed");
    Tram::snelheid = snelheid;
}

void Tram::setBeginStation(string beginStation) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setBeginStation.");
    ENSURE(beginStation != "","No empty string for Starting Station allowed");
    Tram::beginStation = beginStation;
}

void Tram::setHuidigStation(string huidigStation) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setHuidigStation.");
    Tram::huidigStation = huidigStation;
}


int Tram::getVoertuigNr() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getVoertuigNr.");
    return voertuigNr;
}

void Tram::setVoertuigNr(int voertuigNr) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setVoertuigNr.");
    ENSURE(voertuigNr > 0,"No empty string for vehicle number allowed");
    Tram::voertuigNr = voertuigNr;
}

bool Tram::plaatsenTeKort(int n ) {
    if(Tram::zitplaatsen < n) {
        return false;
    }
    else{
        return true;
    }
}

string Tram::addPassagiers(string passagier, int aantal, string station) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling addPassagiers.");
    string output;
    if(!plaatsenTeKort(aantal)){
        output += "Plaatsen te kort voor " + passagier + "\n";
    }
    else{
        Tram::passagiers.insert(passagier);
        setZitplaatsen(getZitplaatsen() - aantal);
        output += "\t" + passagier + " stapt op op Tram " + to_string(getVoertuigNr()) + " vanaf Station " + station + "\n";
    }
    return output;
}

string Tram::removePassagiers(string passagier, int aantal, string station) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling addPassagiers.");
    string output;
    Tram::passagiers.erase(passagier);
    setZitplaatsen(getZitplaatsen() + aantal);
    output += "\t" + passagier + " stapt af uit Tram " + to_string(getVoertuigNr()) + " op Station " + station + "\n";
    return output;
}

set<string> Tram::getPassagiers() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getPassagiers.");
    return passagiers;
}

string Tram::getPlaats() {
    string stationsNaam = Tram::getHuidigStation();

    if(stationsNaam == ""){
        stationsNaam = Tram::getBeginStation();
    }
    return stationsNaam;
}

string Tram::typeString() {
    return std::__cxx11::string();
}

string Tram::verplaatsTram(string station) {
    return std::__cxx11::string();
}



