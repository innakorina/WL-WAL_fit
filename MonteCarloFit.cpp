#include "MonteCarloFit.h"
#include <fstream>
#include <string>
#include "StringParser.h"
#include <iostream>

MonteCarloFit::MonteCarloFit(): d_size(0)
{
    d_myRand.SetSeed(3435);
}

MonteCarloFit::~MonteCarloFit()
{
    //dtor
}

bool MonteCarloFit::readDataFile(){
    std::string fileName;
    std::cout<<"Read data from file: ";
    std::getline(std::cin, fileName);
    std::fstream myFile;
    myFile.open(fileName.c_str(), std::ios::in|std::ios::out);
    StringParser spobj;

    while(!myFile.eof()){
        std::string line;
        std::getline(myFile,line);
        if(line.size() == 0){
            continue;
        }
        spobj.setString(line);
        std::vector<std::string> result;
        result = spobj.getResult();
        d_field[d_size]=std::stod(result[0]);
        d_sheetConductance[d_size]=std::stod(result[1]);
        ++d_size;
    }
}

void MonteCarloFit::printAfterReadingFile() const{
    std::cout<<"d_size="<<d_size<<"\n";
    for(size_t i=0; i!=d_size; ++i){
        std::cout<<d_field[i]<<"\t"<<d_sheetConductance[i]<<"\n";
    }
}

void MonteCarloFit::setDtau(double Dtau){
    d_Dtau = Dtau;
}

void MonteCarloFit::setDtau_i(double Dtau_i){
    d_Dtau_i = Dtau_i;
}

void MonteCarloFit::setdDtau(double dDtau){
    d_dDtau = dDtau;
}

void MonteCarloFit::setdDtau_i(double dDtau_i){
    d_dDtau_i = dDtau_i;
}
