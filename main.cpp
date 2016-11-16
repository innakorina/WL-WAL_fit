#include <iostream>
#include "StringParser.h"
#include "MonteCarloFit.h"

#include <vector>
#include <string>

#include "Digamma.cpp"
#include "RandomGenerator.h"

using namespace std;

void menu_UI(){
    MonteCarloFit mcObj;
    int choice = 0;
    double a, da, Dtau, dDtau, Dtau_i, dDtau_i;
    double r;
    int n;
    string fileName;

    while(choice != 99){
        cout<<"\n";
        cout<<"1. Read data file\n";
        cout<<"2. a = " << mcObj.a() <<", set a\n";
        cout<<"3. da/a = " << mcObj.da()/mcObj.a() << ", set da\n";
        cout<<"4. Dtau = " << mcObj.Dtau() <<", set Dtau\n";
        cout<<"5. dDtau/Dtau = " << mcObj.dDtau()/mcObj.Dtau() <<", set dDtau\n";
        cout<<"6. Dtau_i = " << mcObj.Dtau_i() <<", set Dtau_i\n";
        cout<<"7. dDtau_i/Dtau_i = " << mcObj.dDtau_i()/mcObj.Dtau_i() <<", set dDtau_i\n";
        cout<<"8. Do fast Monte Carlo\n";
        cout<<"9. Plot result\n";
        cout<<"99. exit\n";
        if(mcObj.sum_diff_squares() != 0xDEADBEEF){cout<<"=== sum_diff_squares = "<<mcObj.sum_diff_squares()<<"\n";}
        cout<<"\nChoose: ";
        cin>>choice;

        switch(choice){
        case 1:
            mcObj.readDataFile();
            cout<<"sum_diff_squares = "<<mcObj.sum_diff_squares()<<"\n";
            break;
        case 2:
            cout<<"a = ";
            cin>>a;
            mcObj.seta(a);
            break;
        case 3:
            cout<<"da/a = ";
            cin >> r;
            mcObj.setda(r*mcObj.a());
            break;
        case 4:
            cout<<"Dtau = ";
            cin>>Dtau;
            mcObj.setDtau(Dtau);
            break;
        case 5:
            cout<<"dDtau/Dtau = ";
            cin>>r;
            mcObj.setdDtau(r*mcObj.Dtau());
            break;
        case 6:
            cout<<"Dtau_i = ";
            cin>>Dtau_i;
            mcObj.setDtau_i(Dtau_i);
            break;
        case 7:
            cout<<"dDtau_i/Dtau_i = ";
            cin>>r;
            mcObj.setdDtau_i(r*mcObj.Dtau_i());
            break;
        case 8:
            cout<<"How many times to try: ";
            cin>>n;
            mcObj.fastMonteCarloNTimes(n);
            break;
        case 9:
            mcObj.plotResult();
            break;
        }

    }

}

int main()
{
    menu_UI();
    return 0;
}
