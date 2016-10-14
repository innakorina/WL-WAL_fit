#include <iostream>
#include "StringParser.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    StringParser spobj;
    spobj.setString("This is a test, hahaha!   fdfd,,,aaa;;;d   yy123456");

    vector<string> result;
    result=spobj.getResult();
    for(size_t i=0; i!=result.size(); ++i){
        cout<<result[i]<<endl;
    }
    return 0;
}
