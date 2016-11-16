#include "MonteCarloFit.h"
#include <fstream>
#include <string>
#include "StringParser.h"
#include <iostream>

MonteCarloFit::MonteCarloFit(): d_size(0)
{
    d_myRand.SetSeed(3435);
    d_a = 1;
    d_da = 0.1;
    d_Dtau = 1;
    d_dDtau = 0.1;
    d_Dtau_i = 1;
    d_dDtau_i = 0.1;
    d_sum_diff_squares = 0xDEADBEEF;
}

MonteCarloFit::~MonteCarloFit()
{
    //dtor
}

bool MonteCarloFit::readDataFile(){
    std::string fileName;
    std::cout<<"Read data from file: ";
    while(fileName.size()==0){std::getline(std::cin, fileName);}
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

    calcSumDiffSquares(d_a, d_Dtau, d_Dtau_i);
}

double MonteCarloFit::calcSumDiffSquares(double a, double Dtau, double Dtau_i) {
    double sum = 0;
    for(size_t i=0; i!=d_size; ++i){
        double diff = sigma(d_field[i], a, Dtau, Dtau_i) - d_sheetConductance[i];
        sum += diff * diff;
    }
    return sum;
}

void MonteCarloFit::printAfterReadingFile() const{
    std::cout<<"d_size="<<d_size<<"\n";
    for(size_t i=0; i!=d_size; ++i){
        std::cout<<d_field[i]<<"\t"<<d_sheetConductance[i]<<"\n";
    }
}

void MonteCarloFit::fastMonteCarloOnce(){
    double newa = d_a + (d_myRand.Rand() * 2 -1) * d_da;
    double newSumDiffSquares = calcSumDiffSquares(newa, d_Dtau, d_Dtau_i);
    if(newSumDiffSquares < d_sum_diff_squares){
        //accept newa
        d_a = newa;
        d_sum_diff_squares = newSumDiffSquares;
    }

    double newDtau = d_Dtau + (d_myRand.Rand() * 2 - 1) * d_dDtau;
    newSumDiffSquares = calcSumDiffSquares(d_a, newDtau, d_Dtau_i);
    if(newSumDiffSquares < d_sum_diff_squares){
        //accept newDtau
        d_Dtau = newDtau;
        d_sum_diff_squares = newSumDiffSquares;
    }

    double newDtau_i = d_Dtau_i + (d_myRand.Rand() * 2 - 1) * d_dDtau_i;
    newSumDiffSquares = calcSumDiffSquares(d_a, d_Dtau, newDtau_i);
    if(newSumDiffSquares < d_sum_diff_squares){
        //accept newDtau_i
        d_Dtau_i = newDtau_i;
        d_sum_diff_squares = newSumDiffSquares;
    }
}

void MonteCarloFit::fastMonteCarloNTimes(int n){
    for(size_t i = 0; i < n; ++i){
        fastMonteCarloOnce();
    }
}

bool MonteCarloFit::plotResult(){
    double H_max;
    std::cout<<"H_max = ";
    std::cin>>H_max;
    int n;
    std::cout<<"How many points to plot: ";
    std::cin>>n;

    std::string filename;
    std::cout<<"Save data to file: ";
    while(filename.size()==0){
        std::getline(std::cin, filename);
    }

    std::fstream myfile;
    myfile.open(filename.c_str(), std::ios::out);

    double dH = H_max/n;
    double H_min = dH/1000;
    for(double H=H_min; H<H_max; H+=dH){
        double s = sigma(H,d_a,d_Dtau,d_Dtau_i);
        myfile<<H<<"\t"<<s<<"\n";
    }
    return true;
}

void MonteCarloFit::seta(double a){
    d_a = a;
}

void MonteCarloFit::setda(double da){
    d_da = da;
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
