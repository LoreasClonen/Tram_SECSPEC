//
// Created by Loreas Clonen on 3/9/17.
//

#include "System.h"
#include <memory>

using namespace std;

System::System() {
    _initCheck = this;
}

bool System::properlyInitialized() {
    return _initCheck == this;
}

map<string, Station *> System::getStations() {
    REQUIRE(this->properlyInitialized(),
            "System wasn't initialized when calling getStations.");
    return stations;
}

map<int, Tram *> System::getTrams() {
    REQUIRE(this->properlyInitialized(),
            "System wasn't initialized when calling getTrams.");
    return trams;
}

void System::addStation(string naam, Station* station) {
    REQUIRE(this->properlyInitialized(),
            "System wasn't initialized when calling addStation.");
    ENSURE(naam != "", "Empty Station Name is not allowed.");
    ENSURE(station != NULL, "Station Object Pointer is NULL");
    int setSize = stations.size();
    System::stations[naam] = station;
    REQUIRE(setSize + 1 == this->stations.size(), "Station wasn't correctly added to System");
}

void System::addTram(int lijnNr, Tram* tram){
    REQUIRE(this->properlyInitialized(),
            "System wasn't initialized when calling addTram.");
    ENSURE(lijnNr > 0, "Empty Line Nr is not allowed.");
    ENSURE(tram != NULL, "Tram Object Pointer is NULL");
    int setSize = trams.size();
    System::trams[lijnNr] = tram;
    REQUIRE(setSize + 1 == this->trams.size(), "Tram wasn't correctly added to System");
}

void System::addPassagier(string naam, Passagier* passagier) {
    REQUIRE(this->properlyInitialized(),
            "Station wasn't initialized when calling addPassagier.");
    ENSURE(naam != "","No empty string for Passenger Name allowed");
    ENSURE(passagier != NULL, "Passenger Object Pointer is NULL");
    int setSize = this->getPassagiers().size();
    System::passagiers[naam] = passagier;
    REQUIRE(setSize + 1 == this->getPassagiers().size(), "Passenger wasn't correctly added to Station.");
}

string System::Output(){
    ofstream outputLog;
    outputLog.open("LogFiles/outputLog.txt");

    string output =  "--== STATIONS ==--\n";
    output += System::stations.size() + "\n";
    for(auto c : System::stations){
        output += "Station " + c.first + "\n";
        output += "Type: " + c.second->typeString() + "\n";
        output += "--== SPOREN ==--\n";
        for(auto x : c.second->getSporen()){
            output += "Spoor " + to_string(x.second->getSpoorNr()) + "\n";
            output += "-> Station " + x.second->getVolgende() + "\n";
            output += "<- Station " + x.second->getVorige() + "\n";
        }
        output += "Wachtende passagiers:\n";
        for(auto q : c.second->getPassagier()){
            Passagier* current_passagier = System::passagiers.find(q)->second;
            output += " - " + q + ", " + to_string(current_passagier->getHoeveelheid()) + " mensen, ";
            output += "reist naar Station: " + current_passagier->getEindStation() + "\n";
        }
    }

    output += "\n--== TRAMS ==--\n";
    for(auto c : System::trams){
        output += "Tram " + to_string(c.first) + " nr " + to_string(c.second->getVoertuigNr()) + "\n";
        output += "Type: " + c.second->typeString() + "\n";
        output += "Zitplaatsen: " + to_string(c.second->getZitplaatsen()) + "\n";
        output += "Snelheid: " + to_string(c.second->getSnelheid()) + "km/h" + "\n";
        if(c.second->getHuidigStation() == "") {
            output += "Huidig Station: " + c.second->getBeginStation() + "\n";
        }
        else{
            output += "Huidig Station: " + c.second->getHuidigStation() + "\n";
        }
        }

    outputLog << output;
    outputLog.close();
    return output;
}

bool System::Valid_circuit() {
    for (auto it_stations : stations) {
        for(auto it_spoor : it_stations.second->getSporen()){
            Station* current_station = it_stations.second;
            string next_naam = current_station->getSporen().find(it_spoor.first)->second->getVolgende();
            Station* next_station = stations.find(next_naam)->second;
            if(next_station == stations.end()->second){
                return false;
            }
            Spoor* next_spoor = next_station->getSporen().find(it_spoor.first)->second;
            if(next_spoor->getVorige() != it_stations.first){
                return false;
            }
        }
    }
    return true;
}

void System::properlyparsed() {
    ifstream errors;
    errors.open("LogFiles/errorLog.txt");
    string error = "\n";
    string str;
    while(getline(errors,str)){
        error += str;
        error += "\n";
    }
    ENSURE(System::properlyParsed, error.c_str());
    ENSURE(System::Valid_circuit(), "Circuit is not valid.");
    ENSURE(System::isConsistent(), "System is not consistent.");
}

bool System::checkTram(Tram* tram, Station* station, Passagier* passagier){
    if(tram->isAlbatros() and !station->isMetrostation()){
        return false;
    }
    set<int> sporen = overeenkomstigeSporen(station, stations.find(passagier->getEindStation())->second);
    if(sporen.find(tram->getLijnNr()) == sporen.end()){
        return false;
    }
    return true;
}

string System::findNextStation(Station* station, int spoorNr, Tram* tram){
    Spoor* spoor = station->getSporen().find(tram->getLijnNr())->second;
    string volgende = spoor->getVolgende();
    Station* volgendStation = stations.find(volgende)->second;

    if(tram->isAlbatros() and !volgendStation->isMetrostation()){
        return findNextStation(volgendStation, spoorNr, tram);
    }
    else{
        return volgende;
    }
}

string System::help_ronde_rijden(int aantal_klaar, int aantal_trams, string output){
    for(auto it_tram: trams){
        if(it_tram.second->getHuidigStation() != it_tram.second->getBeginStation()){
            string huidigStation;
            if(it_tram.second->getHuidigStation() == ""){
                huidigStation = it_tram.second->getBeginStation();
            }
            else{
                huidigStation = it_tram.second->getHuidigStation();
            }

            // Afstappen
            if(it_tram.second->getPassagiers().size() != 0){
                set<string> copy_passagiers = it_tram.second->getPassagiers();
                for(auto &passagier : copy_passagiers) {
                    if(huidigStation == passagiers.find(passagier)->second->getEindStation()) {
                        stations.find(huidigStation)->second->addPassagier(passagier);
                        output += it_tram.second->removePassagiers(passagier, passagiers.find(
                                passagier)->second->getHoeveelheid(), huidigStation);
                    }
                }
            }
            // Opstappen
            if(stations.find(huidigStation)->second->getPassagier().size() != 0){
                set<string> copy_passagiers = stations.find(huidigStation)->second->getPassagier();
                for(auto &passagier : copy_passagiers) {
                    if(checkTram(it_tram.second, stations.find(huidigStation)->second,
                                 passagiers.find(passagier)->second)){
                        if(huidigStation != passagiers.find(passagier)->second->getEindStation()) {
                            output += it_tram.second->addPassagiers(passagier,
                                             passagiers.find(passagier)->second->getHoeveelheid(), huidigStation);
                            stations.find(huidigStation)->second->removePassagier(passagier);
                        }
                    }
                    else{
                        output += "Passagiers moeten wachten op de volgende tram. \n";
                    }
                }
            }
            string stationsNaam;

            if(it_tram.second->getHuidigStation() == ""){
                stationsNaam = it_tram.second ->getBeginStation();
            }
            else{
                stationsNaam = it_tram.second->getHuidigStation();
            }

            string volgendStation = findNextStation(System::getStations().find(stationsNaam)->second,
                                                      it_tram.second->getLijnNr(), it_tram.second);

            output += it_tram.second->verplaatsTram(volgendStation);

        }
        else{
            aantal_klaar += 1;
        }
    }
    if(aantal_klaar < aantal_trams){
        return help_ronde_rijden(aantal_klaar,aantal_trams, output);
    }
    else{
        return output;
    }
}

string System::ronde_rijden() {
    int aantal_klaar = 0;
    int aantal_trams = trams.size();
    string output = "";
    output = help_ronde_rijden(aantal_klaar,aantal_trams,output);
    // alle huidige stations leeg zetten voor sys reset
    for(auto it_trams : trams){
        it_trams.second->setHuidigStation("");
    }
    return output;
}

void System::setProperlyParsed(bool properlyParsed) {
    System::properlyParsed = properlyParsed;
}

map<string, Passagier *> System::getPassagiers() {
    REQUIRE(this->properlyInitialized(),
            "System wasn't initialized when calling getPassagiers.");
    return passagiers;
}

void System::autoSimulation() {
    bool end = true;
    ofstream file;
    file.open("LogFiles/autoSimulation.txt");

    file << "===================" << endl;
    file << "Starting Simulation" << endl;
    file << "===================" << endl;

    file << ronde_rijden();
    for(auto &tram : trams){
        if(tram.second->getPassagiers().size() != 0){
            file << endl << "De passagiers in Tram " << tram.second->getVoertuigNr() <<
                 " raken niet op hun eindbestemming" << endl;
            end = false;
        }
    }
    file << "===================" << endl;
    file << "Simulation finished" << endl;
    file << "===================";
    file.close();
    
    REQUIRE(end, "Passengers don't arrive on destination.");


}

set<int> System::overeenkomstigeSporen(Station* huidig, Station* eind){
    set<int> overeenkomstigeSporen;
    for(auto &spoor_huidig : huidig->getSporen()){
        if(eind->getSporen().find(spoor_huidig.first) != eind->getSporen().end()){
            overeenkomstigeSporen.insert(spoor_huidig.first);
        }
    }
    return overeenkomstigeSporen;
}

bool System::isConsistent() {
    if (stations.size() == 0) {
        return false;
    }
    if (trams.size() == 0) {
        return false;
    }

    for(auto &it_passagier : passagiers) {
        Station* begin = stations.find(it_passagier.second->getBeginStation())->second;
        Station* eind = stations.find(it_passagier.second->getEindStation())->second;
        set<int> sporen = overeenkomstigeSporen(begin, eind);
        if(sporen.size() == 0){
            return false;
        }
    }
    return true;
}


