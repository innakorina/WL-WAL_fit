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
        size_t d_size;

        RandGenerator d_myRand;
        int errorflag;

        double d_a;
        double d_da;

        double d_Dtau;
        double d_Dtau_i;

        double d_dDtau;
        double d_dDtau_i;

        double d_sum_diff_squares;

    public:
        MonteCarloFit();
        virtual ~MonteCarloFit();

        bool readDataFile();

        double sigma(double H, double a, double Dtau, double Dtau_i) {
            return a * (digamma((0.5 + B/Dtau/H), &errorflag) - digamma((0.5 + B/Dtau_i/H), &errorflag));
        }

        double calcSumDiffSquares(double a, double Dtau, double Dtau_i);
        // will call sigma(H,a,Dtau,Dtau_i) which is not a const member function

        void fastMonteCarloOnce();

        void fastMonteCarloNTimes(int n);

        bool plotResult();


        // setters
        void seta(double a);
        void setda(double da);
        void setDtau(double Dtau);
        void setDtau_i(double Dtau_i);
        void setdDtau(double dDtau);
        void setdDtau_i(double dDtau_i);

        // getters
        double a() const {return d_a;}
        double da() const {return d_da;}
        double Dtau() const {return d_Dtau;}
        double Dtau_i() const {return d_Dtau_i;}
        double dDtau() const {return d_dDtau;}
        double dDtau_i() const {return d_dDtau_i;}
        double sum_diff_squares() const {return d_sum_diff_squares;}



        // for testing -----
        void printAfterReadingFile() const;


};

#endif // MONTECARLOFIT_H
