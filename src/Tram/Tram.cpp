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
    REQUIRE(this->lijnNr == lijnNr, "Tram Line Nr wasn't set correctly");
}

void Tram::setZitplaatsen(int zitplaatsen) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setZitplaatsen.");
    ENSURE(zitplaatsen > 0,"No negative seats allowed");
    Tram::zitplaatsen = zitplaatsen;
    REQUIRE(this->zitplaatsen == zitplaatsen, "Tram Amount of Seats wasn't set correctly");
}

void Tram::setSnelheid(int snelheid) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setSnelheid.");
    ENSURE(snelheid > 0,"No negative speed allowed");
    Tram::snelheid = snelheid;
    REQUIRE(this->snelheid == snelheid, "Tram Speed wasn't set correctly");
}

void Tram::setBeginStation(string beginStation) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setBeginStation.");
    ENSURE(beginStation != "","No empty string for Starting Station allowed");
    Tram::beginStation = beginStation;
    REQUIRE(this->lijnNr == lijnNr, "Tram Starting Station wasn't set correctly");
}

void Tram::setHuidigStation(string huidigStation) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setHuidigStation.");
    Tram::huidigStation = huidigStation;
    REQUIRE(this->huidigStation == huidigStation, "Tram Current Station wasn't set correctly");
}

int Tram::getVoertuigNr() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getVoertuigNr.");
    return voertuigNr;
}

void Tram::setVoertuigNr(int voertuigNr) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling setVoertuigNr.");
    ENSURE(voertuigNr > 0,"No negative number for vehicle number allowed");
    Tram::voertuigNr = voertuigNr;
    ENSURE(this->voertuigNr == voertuigNr, "Tram Vehicle Nr. wasn't set correctly.");
}

bool Tram::plaatsenTeKort(int n ) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling plaatsenTeKort.");
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
    ENSURE(aantal > 0,"No negative number for Amount of Passengers allowed");
    ENSURE(passagier != "", "No empty string for Passenger Name allowed.");
    ENSURE(station != "", "No empty string for Station Name allowed.");
    string output;
    if(!plaatsenTeKort(aantal)){
        output += "Plaatsen te kort voor " + passagier + "\n";
    }
    else{
        int setSize = Tram::passagiers.size();
        Tram::passagiers.insert(passagier);
        REQUIRE(setSize + 1 == this->passagiers.size(), "Passenger wasn't added correctly to Tram");
        setZitplaatsen(getZitplaatsen() - aantal);
        output += "\t" + passagier + " stapt op op Tram " + to_string(getVoertuigNr()) + " vanaf Station " + station + "\n";
    }
    return output;
}

string Tram::removePassagiers(string passagier, int aantal, string station) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling addPassagiers.");
    ENSURE(aantal > 0,"No negative number for Amount of Passengers allowed");
    ENSURE(passagier != "", "No empty string for Passenger Name allowed.");
    ENSURE(station != "", "No empty string for Station Name allowed.");

    string output;
    int setSize = Tram::passagiers.size();

    Tram::passagiers.erase(passagier);

    REQUIRE(setSize - 1 == this->passagiers.size(), "Passenger wasn't added correctly to Tram");

    setZitplaatsen(getZitplaatsen() + aantal);

    output += "\t" + passagier + " stapt af uit Tram " + to_string(getVoertuigNr()) + " op Station " + station + "\n";
    return output;
}

set<string> Tram::getPassagiers() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling getPassagiers.");
    return passagiers;
}

string Tram::typeString() {
    return std::__cxx11::string();
}

string Tram::verplaatsTram(string station) {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling addPassagiers.");
    ENSURE(station != "", "No empty string for Station Name allowed.");

    Tram::setHuidigStation(station);

    string stationsNaam = this->getHuidigStation();

    if(stationsNaam == ""){
        stationsNaam = this->getBeginStation();
    }

    this->setHuidigStation(station);

    string output = "Tram " + to_string(this->getVoertuigNr()) + " reed van station " + stationsNaam
                    + " naar station " + station + "\n";

    return output;
}

bool Tram::isAlbatros() {
    REQUIRE(this->properlyInitialized(),
            "Tram wasn't initialized when calling isAlbatros.");
    return false;
}


