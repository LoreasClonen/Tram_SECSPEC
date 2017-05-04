//
// Created by uauser on 4/19/17.
//

#include "Passagier.h"

Passagier::Passagier() {}

 string Passagier::getNaam() {
    return naam;
}

void Passagier::setNaam(string naam) {
    Passagier::naam = naam;
}

string Passagier::getBeginStation() {
    return beginStation;
}

void Passagier::setBeginStation(string beginStation) {
    Passagier::beginStation = beginStation;
}

string Passagier::getEindStation() {
    return eindStation;
}

void Passagier::setEindStation(string eindStation) {
    Passagier::eindStation = eindStation;
}

int Passagier::getHoeveelheid() {
    return hoeveelheid;
}

void Passagier::setHoeveelheid(int hoeveelheid) {
    Passagier::hoeveelheid = hoeveelheid;
}
