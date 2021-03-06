//
// Created by Luuk van Sloun on 3/9/17.
//

#include "Parser.h"
#include "../Station/Metrostation.h"
#include "../Station/Halte.h"
#include "../Tram/Albatros.h"
#include "../Tram/PCC.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Parser::Parser() {}

string Parser::getElement(TiXmlElement* elem){
    TiXmlNode* firstChild = elem->FirstChild();
    if(firstChild == NULL){
        return "";
    }

    string t = firstChild->Value();

    return t;
}

bool Parser::is_number(string s)
{
    if(s[0] == '-'){
        s = s.substr(1, s.size());
    }
    return !s.empty() && find_if(s.begin(),
                                      s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

bool Parser::XmlParser(string inputFile) {
    ofstream outputFile;
    outputFile.open("LogFiles/parserLog.txt");
    ofstream errorFile;
    errorFile.open("LogFiles/errorLog.txt");

    bool outputStation = true;
    bool outputTram = true;
    bool outputPassenger = true;
    bool outputTrack = true;
    outputFile << "======================" << endl;
    outputFile << "Starting XML Parser..." << endl;
    outputFile << "======================" << endl << endl;
    TiXmlDocument doc;
    const char *file = inputFile.c_str();
    if (!doc.LoadFile(file)) {
        doc.Clear();
        return false;
    }

    TiXmlElement* root = doc.FirstChildElement();
    if (root == NULL) {
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        return false;
    }
    System* system = new System;

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL;
         elem = elem->NextSiblingElement()) {
        string elemName = elem->Value();

        if (elemName == "station") {
            outputFile << "Creating new Station:" << endl;
            outputFile << "---------------------" << endl;
            map<int, Spoor*> tracks;

            string naam = "";
            string type = "";

            for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                 insideElem = insideElem->NextSiblingElement()) {
                string elemName = insideElem->Value();


                if (elemName == "naam") {
                    outputFile << "\tGetting Station name..." << endl;
                    naam = getElement(insideElem);
                    if(naam == ""){
                        outputFile << "\t\tFAULT IN STATION NAME: EMPTY" << endl;
                        errorFile << "FAULT IN STATION NAME: EMPTY" << endl;
                        outputStation = false;
                    }
                    else{
                        outputFile << "\t\tStation Name: " + naam << endl;
                    }
                }
                if (elemName == "spoor") {
                    outputFile << "\tGetting Station Track..." << endl;
                    Spoor* spoor = new Spoor();

                    string volgende = "";
                    string vorige = "";
                    int spoorNr = -1;

                    for (TiXmlElement *inInsideElem = insideElem->FirstChildElement(); inInsideElem != NULL;
                         inInsideElem = inInsideElem->NextSiblingElement()) {
                        string elemName = inInsideElem->Value();

                        if(elemName == "spoorNr") {
                            if(getElement(inInsideElem) == ""){
                                outputFile << "\t\tFAULT IN STATION TRACK NUMBER: EMPTY" << endl;
                                errorFile << "FAULT IN STATION TRACK NUMBER: EMPTY" << endl;
                                outputTrack = false;
                            }
                            else if (is_number(getElement(inInsideElem))) {
                                spoorNr = stoi(getElement(inInsideElem));
                                if(spoorNr > 0){
                                    outputFile << "\t\tTrack Number: " + getElement(inInsideElem) << endl;
                                }
                                else{
                                    outputFile << "\t\tFAULT IN STATION TRACK NUMBER: NEGATIVE" << endl;
                                    errorFile << "FAULT IN STATION TRACK NUMBER: NEGATIVE" << endl;
                                    outputTrack = false;
                                }
                            } else {
                                outputFile << "\t\tFAULT IN STATION TRACK NUMBER: NOT AN INTEGER" << endl;
                                errorFile << "FAULT IN STATION TRACK NUMBER: NOT AN INTEGER" << endl;
                                outputTrack = false;
                            }
                        }
                        if (elemName == "volgende") {
                            volgende = getElement(inInsideElem);
                            outputFile << "\tGetting Next Station..." << endl;
                            if(volgende == ""){
                                outputFile << "\t\tFAULT IN NEXT STATION: EMPTY" << endl;
                                errorFile << "FAULT IN NEXT STATION: EMPTY" << endl;
                                outputTrack = false;
                            }
                            else{
                                outputFile << "\t\tNext Station: " + volgende << endl;
                            }
                        }
                        if (elemName == "vorige") {
                            vorige = getElement(inInsideElem);
                            outputFile << "\tGetting Previous Station..." << endl;
                            if(vorige == ""){
                                outputFile << "\t\tFAULT IN PREVIOUS STATION: EMPTY" << endl;
                                errorFile << "FAULT IN PREVIOUS STATION: EMPTY" << endl;
                                outputTrack = false;
                            }
                            else{
                                outputFile << "\t\tPrevious Station: " + vorige << endl;
                            }
                        }
                    }
                    if(!outputTrack) {
                        outputFile << "\tDELETING INCOMPLETE TRACK" << endl;
                        delete spoor;
                    }
                    if(outputTrack) {
                        tracks[spoorNr] = spoor;
                        spoor->setSpoorNr(spoorNr);
                        spoor->setVolgende(volgende);
                        spoor->setVorige(vorige);
                    }
                }

                if (elemName == "type") {
                    outputFile << "\tGetting Station Type..." << endl;
                    type = getElement(insideElem);
                    if(type != "halte" and type != "metrostation") {
                        if(type == ""){
                            outputFile << "\t\tFAULT IN STATION TYPE: EMPTY" << endl;
                            errorFile << "FAULT IN STATION TYPE: EMPTY" << endl;
                            outputStation = false;
                        }
                        else {
                            outputFile << "\t\tFAULT IN STATION TYPE: INCORRECT TYPE" << endl;
                            errorFile << "FAULT IN STATION TYPE: INCORRECT TYPE" << endl;
                            outputStation = false;
                        }
                    }
                    else if(type == "halte" or type == "metrostation"){
                        outputFile << "\t\tStation Type: " +  type << endl;
                    }
                }
            }
            Station* station;
            if(type == "halte" or type == "metrostation") {
                if (type == "halte") {
                    station = new Halte;
                    station->setSporen(tracks);
                }

                else if (type == "metrostation") {
                    station = new Metrostation;
                    station->setSporen(tracks);
                }

                if (!outputStation) {
                    outputFile << "DELETING INCOMPLETE STATION" << endl;
                    for (auto c : station->getSporen()) {
                        c.second = NULL;
                    }
                    delete station;
                } else {
                    station->setNaam(naam);

                    system->addStation(naam, station);
                }
            }
            outputFile << endl;
        }

        else if (elemName == "tram") {
            outputFile << "Creating new Tram:" << endl;
            outputFile << "------------------" << endl;

            int lijnNr = -1;
            int zitplaatsen = -1;
            int snelheid = -1;
            string beginStation = "";
            string type = "";
            int voertuigNr = -1;

            for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                 insideElem = insideElem->NextSiblingElement()) {
                 string elemName = insideElem->Value();


                if (elemName == "lijnNr") {
                    outputFile << "\tGetting Tram Number..." << endl;
                    if(getElement(insideElem) == ""){
                        outputFile << "\t\tFAULT IN TRAM LINE NUMBER: EMPTY" << endl;
                        errorFile << "FAULT IN TRAM LINE NUMBER: EMPTY" << endl;
                        outputTram = false;
                    }
                    else if(is_number(getElement(insideElem))){
                        lijnNr = stoi(getElement(insideElem));
                        if(lijnNr > 0){
                            outputFile << "\t\tTram Line Number: " + to_string(lijnNr) << endl;
                        }
                        else{
                            outputFile << "\t\tFAULT IN TRAM LINE NUMBER: NEGATIVE" << endl;
                            errorFile << "FAULT IN TRAM LINE NUMBER: NEGATIVE" << endl;
                            outputTram = false;
                        }
                    }
                    else {
                        outputFile << "\t\tFAULT IN TRAM LINE NUMBER: NOT AN INTEGER" << endl;
                        errorFile << "FAULT IN TRAM LINE NUMBER: NOT AN INTEGER" << endl;
                        outputTram = false;
                    }
                }
                if (elemName == "zitplaatsen") {
                    outputFile << "\tGetting Tram seats..." << endl;
                    if(getElement(insideElem) == ""){
                        outputFile << "\t\tFAULT IN TRAM SEATS: EMPTY" << endl;
                        errorFile << "FAULT IN TRAM SEATS: EMPTY" << endl;
                        outputTram = false;
                    }
                    else if(is_number(getElement(insideElem))){
                        zitplaatsen = stoi(getElement(insideElem));
                        if(zitplaatsen > 0){
                            outputFile << "\t\tTram Seats: " + to_string(zitplaatsen) << endl;
                        }
                        else{
                            outputFile << "\t\tFAULT IN TRAM SEATS: NEGATIVE" << endl;
                            errorFile << "FAULT IN TRAM SEATS: NEGATIVE" << endl;
                            outputTram = false;
                        }
                    }
                    else {
                        outputFile << "\t\tFAULT IN TRAM SEATS: NOT AN INTEGER" << endl;
                        errorFile << "FAULT IN TRAM SEATS: NOT AN INTEGER" << endl;
                        outputTram = false;
                    }
                }

                if (elemName == "snelheid") {
                    outputFile << "\tGetting Tram speed..." << endl;
                    if(getElement(insideElem) == ""){
                        outputFile << "\t\tFAULT IN TRAM SPEED: EMPTY" << endl;
                        errorFile << "FAULT IN TRAM SPEED: EMPTY" << endl;
                        outputTram = false;
                    }
                    else if(is_number(getElement(insideElem))){
                        snelheid = stoi(getElement(insideElem));
                        if(snelheid > 0){
                            outputFile << "\t\tTram Speed: " + to_string(snelheid) << endl;
                        }
                        else{
                            outputFile << "\t\tFAULT IN TRAM SPEED: NEGATIVE" << endl;
                            errorFile << "FAULT IN TRAM SPEED: NEGATIVE" << endl;
                            outputTram = false;
                        }
                    }
                    else {
                        outputFile << "\t\tFAULT IN TRAM SPEED: NOT AN INTEGER" << endl;
                        errorFile << "FAULT IN TRAM SPEED: NOT AN INTEGER" << endl;
                        outputTram = false;
                    }
                }

                if (elemName == "beginStation") {
                    beginStation = getElement(insideElem);
                    if(beginStation != "") {
                        outputFile << "\tGetting Starting Station..." << endl;
                        outputFile << "\t\tStarting Station: " + beginStation << endl;
                        outputFile << "\tGetting Current Station..." << endl;
                        outputFile << "\t\tCurrent Station: " + beginStation << endl;
                    }
                    else{
                        outputFile << "\t\tFAULT IN TRAM STARTING STATION: EMPTY" << endl;
                        errorFile << "FAULT IN TRAM STARTING STATION: EMPTY" << endl;
                        outputTram = false;
                    }
                }

                if (elemName == "type") {
                    outputFile << "\tGetting Tram Type..." << endl;
                    type = getElement(insideElem);
                    if(type != "PCC" and type != "Albatros") {
                        if(type == ""){
                            outputFile << "\t\tFAULT IN TRAM TYPE: EMPTY" << endl;
                            errorFile << "FAULT IN TRAM TYPE: EMPTY" << endl;
                            outputTram = false;
                        }
                            outputFile << "\t\tFAULT IN TRAM TYPE: INCORRECT TYPE" << endl;
                            errorFile << "FAULT IN TRAM TYPE: INCORRECT TYPE" << endl;
                            outputTram = false;
                    }
                    else if(type == "PCC" or type == "Albatros"){
                        outputFile << "\t\tTram Type: " +  type << endl;
                    }
                }

                if (elemName == "voertuigNr") {
                    outputFile << "\tGetting Tram Vehicle Number..." << endl;
                    if(getElement(insideElem) == ""){
                        outputFile << "\t\tFAULT IN TRAM VEHICLE NUMBER: EMPTY" << endl;
                        errorFile << "FAULT IN TRAM VEHICLE NUMBER: EMPTY" << endl;
                        outputTram = false;
                    }
                    else if(is_number(getElement(insideElem))){
                        voertuigNr = stoi(getElement(insideElem));
                        if(voertuigNr > 0){
                            outputFile << "\t\tTram Vehicle Number: " + to_string(voertuigNr) << endl;
                        }
                        else{
                            outputFile << "\t\tFAULT IN TRAM VEHICLE NUMBER: NEGATIVE" << endl;
                            errorFile << "FAULT IN TRAM VEHICLE NUMBER: NEGATIVE" << endl;
                            outputTram = false;
                        }
                    }
                    else {
                        outputFile << "\t\tFAULT IN TRAM VEHICLE NUMBER: NOT AN INTEGER" << endl;
                        errorFile << "FAULT IN TRAM VEHICLE NUMBER: NOT AN INTEGER" << endl;
                        outputTram = false;
                    }
                }
            }
            Tram* tram;
            if(type == "Albatros" or type == "PCC") {
                if (type == "Albatros") {
                    tram = new Albatros;
                }
                else if (type == "PCC") {
                    tram = new PCC;
                }
                if (!outputTram) {
                    outputFile << "DELETING INCOMPLETE TRAM" << endl;
                    delete tram;
                } else if(outputTram) {
                    tram->setLijnNr(lijnNr);
                    tram->setZitplaatsen(zitplaatsen);
                    tram->setSnelheid(snelheid);
                    tram->setBeginStation(beginStation);
                    tram->setVoertuigNr(voertuigNr);

                    system->addTram(voertuigNr, tram);
                }
            }
            outputFile << endl;
        }
        else if (elemName == "passagier") {
            Passagier* passagier = new Passagier;
            outputFile << "Creating new Passagier:" << endl;
            outputFile << "-----------------------" << endl;

            string naam = "";
            string beginStation = "";
            string eindStation = "";
            int hoeveelheid = -1;

            for (TiXmlElement *insideElem = elem->FirstChildElement(); insideElem != NULL;
                 insideElem = insideElem->NextSiblingElement()) {
                string elemName = insideElem->Value();


                if (elemName == "naam") {
                    outputFile << "\tGetting Passenger Name..." << endl;
                    naam = getElement(insideElem);
                    if(naam != ""){
                        outputFile << "\t\tPassenger Name: " + naam << endl;
                    }
                    else{
                        outputFile << "\t\tFAULT IN PASSENGER NAME: EMPTY";
                        errorFile << "FAULT IN PASSENGER NAME: EMPTY" << endl;
                        outputPassenger = false;
                    }
                }
                if (elemName == "beginstation") {
                    outputFile << "\tGetting Passenger Starting Station..." << endl;
                    beginStation = getElement(insideElem);

                    if(beginStation != "") {
                        outputFile << "\t\tStarting Station: " + beginStation << endl;
                    }
                    else{
                        outputFile << "\t\tFAULT IN PASSENGER STARTING STATION: EMPTY" << endl;
                        errorFile << "FAULT IN PASSENGER STARTING STATION: EMPTY" << endl;
                        outputPassenger = false;
                    }
                }

                if (elemName == "eindstation") {
                    outputFile << "\tGetting Passenger End Station..." << endl;
                    eindStation = getElement(insideElem);

                    if(eindStation != "") {
                        outputFile << "\t\tEnd Station: " + eindStation << endl;
                    }
                    else{
                        outputFile << "\t\tFAULT IN PASSENGER END STATION: EMPTY" << endl;
                        errorFile << "FAULT IN PASSENGER END STATION: EMPTY" << endl;
                        outputPassenger = false;
                    }
                }

                if (elemName == "hoeveelheid") {
                    outputFile << "\tGetting Amount of Passengers..." << endl;
                    if(getElement(insideElem) == ""){
                        outputFile << "\t\tFAULT IN PASSENGER AMOUNT: EMPTY" << endl;
                        errorFile << "FAULT IN PASSENGER AMOUNT: EMPTY" << endl;
                        outputPassenger = false;
                    }
                    else if(is_number(getElement(insideElem))){
                        hoeveelheid = stoi(getElement(insideElem));
                        if(hoeveelheid > 0){
                            outputFile << "\t\tPassenger Amount: " + to_string(hoeveelheid) << endl;
                        }
                        else{
                            outputFile << "\t\tFAULT IN PASSENGER AMOUNT: NEGATIVE" << endl;
                            errorFile << "FAULT IN PASSENGER AMOUNT: NEGATIVE" << endl;
                            outputPassenger = false;
                        }
                    }
                    else {
                        outputFile << "\t\tFAULT IN PASSENGER AMOUNT: NOT AN INTEGER" << endl;
                        errorFile << "FAULT IN PASSENGER AMOUNT: NOT AN INTEGER" << endl;
                        outputPassenger = false;
                    }
                }
            }
            if(!outputPassenger){
                outputFile << "DELETING PASSENGER" << endl;
                delete passagier;
            }
            else{
                system->addPassagier(naam, passagier);
                passagier->setNaam(naam);
                passagier->setBeginStation(beginStation);
                passagier->setEindStation(eindStation);
                passagier->setHoeveelheid(hoeveelheid);

                if(system->getStations().find(beginStation) != system->getStations().end()){
                    system->getStations().find(beginStation)->second->addPassagier(naam);
                }
                else{
                    outputFile << "STARTING STATION OF PASSENGER: NOT IN SYSTEM" << endl;
                    errorFile << "STARTING STATION OF PASSENGER: NOT IN SYSTEM" << endl;
                }
            }
            outputFile << endl;
        }
    }

    Parser::setSystem(system);

    outputFile << "===================" << endl;
    outputFile << "XML Parser finished" << endl;
    outputFile << "===================" << endl << endl;
    doc.Clear();
    outputFile.close();
    bool output = false;

    if(outputPassenger and outputTrack and outputTram and outputStation){
        output = true;
    }
    system->setProperlyParsed(output);
    return output;
}

System *Parser::getSystem() const {
    return system;
}

void Parser::setSystem(System *system) {
    Parser::system = system;
}
