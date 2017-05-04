//
// Created by Loreas Clonen on 3/9/17.
//

#include "System.h"
#include <memory>
#include <fstream>

using namespace std;

System::System() {
    _initCheck = this;
}

bool System::properlyInitialized() {
    return _initCheck == this;
}

map<string, Station *> System::getStations() {
    return stations;
}

map<int, Tram *> System::getTrams() {
    return trams;
}

void System::addStation(string naam, Station* station) {

        System::stations[naam] = station;
}

void System::addTram(int lijnNr, Tram* tram){
    System::trams[lijnNr] = tram;
}

void System::addPassagier(string naam, Passagier* passagier) {

    System::passagiers[naam] = passagier;
}

string System::Output(){
    ofstream outputLog;
    outputLog.open("LogFiles/outputLog.txt");

    string output =  "--== STATIONS ==--\n";
    for(auto c : System::stations){
        output += "Station " + c.first + "\n";
        output += "Type: " + c.second->getType() + "\n";
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

Station* System::findNextStation(Station* station, int spoorNr, string type){
    Station* volgendStation = System::getStations().find(station->getSporen().find(spoorNr)->second->getVolgende())->second;

    if(type == "PCC"){
        return volgendStation;
    }
    else {
        if(volgendStation->getType() == "metrostation"){
            return volgendStation;
        }
        else{
            return findNextStation(volgendStation, spoorNr, type);
        }
    }
}

string System::verplaatsTram(Tram* tram){
    string stationsNaam = tram->getHuidigStation();

    Station* volgendStation = findNextStation(System::getStations().find(stationsNaam)->second, tram->getLijnNr(),
            tram->getType());

    string volgende = volgendStation->getNaam();

    tram->setHuidigStation(volgende);
    string output = "Tram " + to_string(tram->getLijnNr()) + " reed van station " + stationsNaam
                    + " naar station " + volgende + "\n";
    return output;
}

bool System::Valid_circuit() {
    for (auto it_stations : stations) {
        for(auto it_spoor : it_stations.second->getSporen()){
            string prev_naam = it_spoor.second->getVorige();
            Station* prev_station = stations.find(prev_naam)->second;
            string prev_next_naam = prev_station->getSporen().find(it_spoor.first)->second->getVolgende();
            Station* prev_next_station = stations.find(prev_next_naam)->second;
            if(prev_next_station != it_stations.second){
                return false;
            }
        }
    }
    return true;
}

void System::properlyparsed() {
    REQUIRE(System::properlyParsed, "XML File wasn't properly parsed.");
    ENSURE(System::Valid_circuit(), "Circuit is not valid.");
}


void System::ronde_rijden(bool ronde_gedaan = false) {

    ofstream outputFile;
    outputFile.open("LogFiles/ronde_rijden.txt");
    outputFile << "Rondje rijden...";
    outputFile << "\n";
    for (auto const &j : trams) {

        if(j.second->getBeginStation() != j.second->getHuidigStation() or ronde_gedaan){
            Station* station = new Station();
            if(j.second->getHuidigStation() != "") {
                station = System::stations.find(j.second->getHuidigStation())->second;
            }
            else{
                station = System::stations.find(j.second->getBeginStation())->second;
            }
            set<string> copy_tram = j.second->getPassagiers() ;
            //afstappen
            for(auto const &it : copy_tram){
                if(System::passagiers.find(it)->second->getEindStation()==j.second->getHuidigStation()){
                    j.second->removePassagiers(it);
                    outputFile << "    Passagier " + it + " stapte af." + "\n";
                }
            }

            set<string> copy_station = station->getPassagier();
            //opstappen
            for(auto &it : copy_station) {
                if (!j.second->plaatsenTeKort(System::passagiers.find(it)->second->getHoeveelheid())) {
                    j.second->addPassagiers(it);
                    station->removePassagier(it);
                    outputFile << "    Passagier ";
                    outputFile << it;
                    outputFile << " stapte op.";
                    outputFile << "\n";
                }
            }
        }


        outputFile << System::verplaatsTram(j.second);
    }
    outputFile << "\n";

    outputFile.close();
}

void System::setProperlyParsed(bool properlyParsed) {
    System::properlyParsed = properlyParsed;
}

map<string, Passagier *> System::getPassagiers() {
    return passagiers;
}

void System::autoSimulation() {

}


