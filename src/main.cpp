
#include "Parser/Parser.h"
#include <iostream>


using namespace std;

int main(int argc, char** argv){

    Parser parser;



    if (string(argv[1]) == "1") {
        parser.XmlParser("");
        System* system = parser.getSystem();
        system->properlyparsed();
        system->Output();
    } else if (string(argv[1]) == "2") {
        parser.XmlParser("testInput/MultipleErrors.xml");
        System* system = parser.getSystem();
        system->properlyparsed();
    }
    else{
        parser.XmlParser("InputFiles/XML_Test.xml");
        System* system = parser.getSystem();
        system->properlyparsed();
        system->autoSimulation();
        system->Output();
    }
}