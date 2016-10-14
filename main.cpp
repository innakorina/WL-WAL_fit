#include <iostream>
#include "StringParser.h"
#include "MonteCarloFit.h"

#include <vector>
#include <string>

#include "Digamma.cpp"

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

    int temp;
    std::cin>>temp;
    return 0;
}
