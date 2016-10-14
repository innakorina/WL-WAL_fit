#include "MonteCarloFit.h"
#include <fstream>
#include <string>
#include "StringParser.h"
#include <iostream>

MonteCarloFit::MonteCarloFit(): d_size(0)
{
    //d_myRand.SetSeed(3435);

}

MonteCarloFit::~MonteCarloFit()
{
    //dtor

}

bool MonteCarloFit::readDataFile(){
    std::string fileName;
    std::cout<<"Read data from file: ";
    std::getline(std::cin, fileName);
    //std::cout<<"fileName="<<fileName<<"\n";
    std::fstream myFile;
    myFile.open(fileName.c_str(), std::ios::in|std::ios::out);
    StringParser spobj;

    while(!myFile.eof()){
        std::string line;
        std::getline(myFile,line);
        //std::cout<<"Got a line: "<<line<<"\n";
        if(line.size() == 0){
            continue;
        }
        spobj.setString(line);
        std::vector<std::string> result;
        //std::cout<<"after declaration result.size()="<<result.size()<<"\n";
        result = spobj.getResult();
        //std::cout<<"result.size()="<<result.size()<<"\n";
        //std::cout<<"result[1]="<<result[1]<<"\n";
        //std::cout<<"std::stod(result[1])="<<std::stod(result[1])<<"\n";
        d_fieldTesla[d_size]=std::stod(result[0]);
        d_sheetConductance[d_size]=std::stod(result[1]);
        ++d_size;
    }
}

void MonteCarloFit::printAfterReadingFile() const{
    std::cout<<"d_size="<<d_size<<"\n";
    for(size_t i=0; i!=d_size; ++i){
        std::cout<<d_fieldTesla[i]<<"\t"<<d_sheetConductance[i]<<"\n";
    }
}
