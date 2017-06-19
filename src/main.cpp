//
// Created by luuk on 19-3-17.
//

#include "Parser/Parser.h"
#include <iostream>


using namespace std;

int main(){
    Parser parser;
<<<<<<< HEAD
    parser.XmlParser("testInput/NoPassengerArrival.xml");
=======
    parser.XmlParser("testInput/TramSnelheid.xml");
>>>>>>> b257824e9d33be3961dbf2abc6250bc49efea7a0
    System* system = parser.getSystem();
    system->properlyparsed();
    system->Output();
    system->autoSimulation();
}

