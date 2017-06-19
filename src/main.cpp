
#include "Parser/Parser.h"
#include <iostream>


using namespace std;

int main(int argc, char** argv){

    Parser parser;
    parser.XmlParser(argv[1]);
    System* system = parser.getSystem();
    system->properlyparsed();
    system->autoSimulation();
    system->Output();
}