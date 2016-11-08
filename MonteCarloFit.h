#ifndef MONTECARLOFIT_H
#define MONTECARLOFIT_H


#include "RandomGenerator.h"
#include "Digamma.cpp"

namespace{
    const int ARRAY_MAX = 10000;
    const double e = 1.602176565e-19;
    const double pi = 3.14159265359;
    const double h_bar = 1.05457172534e-34;
    const double A = -e*e/2/pi/h_bar;
    const double B = h_bar/4/e;
}

class MonteCarloFit
{
    private:
        double d_field[ARRAY_MAX];
        double d_sheetConductance[ARRAY_MAX];
        int d_size;

        RandGenerator d_myRand;
        int errorflag;


        double d_Dtau;
        double d_Dtau_i;

        double d_dDtau;
        double d_dDtau_i;

    public:
        MonteCarloFit();
        virtual ~MonteCarloFit();

        bool readDataFile();

        double sigma(double H, double Dtau, double Dtau_i) {
            return A * (digamma((0.5 + B/Dtau/H), &errorflag) - digamma((0.5 + B/Dtau_i/H), &errorflag));
        }


        // setters
        void setDtau(double Dtau);
        void setDtau_i(double Dtau_i);
        void setdDtau(double dDtau);
        void setdDtau_i(double dDtau_i);

        // getters
        double Dtau(){return d_Dtau;}
        double Dtau_i(){return d_Dtau_i;}
        double dDtau(){return d_dDtau;}
        double dDtau_i(){return d_dDtau_i;}


        // for testing -----
        void printAfterReadingFile() const;


};

#endif // MONTECARLOFIT_H
