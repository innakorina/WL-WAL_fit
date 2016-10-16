#include <iostream>
#include "StringParser.h"
#include "MonteCarloFit.h"

#include <vector>
#include <string>

#include "Digamma.cpp"
#include "RandomGenerator.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    /*StringParser spobj;
    spobj.setString("HI, this is a test, 10");

    std::vector<std::string> result;
    result = spobj.getResult();

    for(size_t i = 0; i != result.size(); ++i){
        std::cout<<result[i]<<"\n";
    }*/

    MonteCarloFit fitobj;
    fitobj.readDataFile();
    fitobj.printAfterReadingFile();

    int errorflag;
    std::cout<<"ph(0.1)="<<digamma(0.1, &errorflag)<<"\n";
    RandGenerator randObj;
    randObj.SetSeed(3434);
    for(int i=0; i<10; ++i){
        std::cout<<randObj.Rand()<<", ";
    }

    int temp;
    std::cin>>temp;
    return 0;
}
