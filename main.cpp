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
    double a, da, B_phi, dB_phi, B_SO, dB_SO, B_e, dB_e;
    double r;
    int n;
    string fileName;

    while(choice != 99){
        cout<<"\n";
        cout<<"1. Read data file\n";
        cout<<"2. a = " << mcObj.a() <<", set a\n";
        cout<<"3. da/a = " << mcObj.da()/mcObj.a() << ", set da\n";
        cout<<"4. B_phi = " << mcObj.B_phi() <<", set B_phi\n";
        cout<<"5. dB_phi/B_phi = " << mcObj.dB_phi()/mcObj.B_phi() <<", set dB_phi\n";
        cout<<"6. B_SO = " << mcObj.B_SO() <<", set B_SO\n";
        cout<<"7. dB_SO/B_SO = " << mcObj.dB_SO()/mcObj.B_SO() <<", set dB_SO\n";
        cout<<"8. B_e = " << mcObj.B_e() <<", set B_e\n";
        cout<<"9. dB_e/B_e = " << mcObj.dB_e()/mcObj.B_e() <<", set dB_e\n";
        cout<<"10. Do fast Monte Carlo\n";
        cout<<"11. Plot result\n";
        cout<<"99. exit\n";
        if(mcObj.sum_diff_squares() < 1E999){cout<<"=== sum_diff_squares = "<<mcObj.sum_diff_squares()<<"\n";}
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
            mcObj.updateSumDiffSquares();
            break;
        case 3:
            cout<<"da/a = ";
            cin >> r;
            mcObj.setda(r*mcObj.a());
            break;
        case 4:
            cout<<"B_phi = ";
            cin>>B_phi;
            mcObj.setB_phi(B_phi);
            mcObj.updateSumDiffSquares();
            break;
        case 5:
            cout<<"dB_phi/B_phi = ";
            cin>>r;
            mcObj.setdB_phi(r*mcObj.B_phi());
            break;
        case 6:
            cout<<"B_SO = ";
            cin>>B_SO;
            mcObj.setB_SO(B_SO);
            mcObj.updateSumDiffSquares();
            break;
        case 7:
            cout<<"dB_SO/B_SO = ";
            cin>>r;
            mcObj.setdB_SO(r*mcObj.B_SO());
            break;
        case 8:
            cout<<"B_e = ";
            cin>>B_e;
            mcObj.setB_e(B_e);
            mcObj.updateSumDiffSquares();
            break;
        case 9:
            cout<<"dB_e/B_e = ";
            cin>>r;
            mcObj.setdB_e(r*mcObj.B_e());
            break;
        case 10:
            cout<<"How many times to try: ";
            cin>>n;
            mcObj.fastMonteCarloNTimes(n);
            break;
        case 11:
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
