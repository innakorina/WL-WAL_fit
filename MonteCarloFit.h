#ifndef MONTECARLOFIT_H
#define MONTECARLOFIT_H


#include "RandomGenerator.h"

namespace{
    const int ARRAY_MAX = 10000;
}

class MonteCarloFit
{
    private:
        double d_fieldTesla[ARRAY_MAX];
        double d_sheetConductance[ARRAY_MAX];
        int d_size;

        RandGenerator d_myRand;

    public:
        MonteCarloFit();
        virtual ~MonteCarloFit();

        bool readDataFile();

        // for testing -----
        void printAfterReadingFile() const;


};

#endif // MONTECARLOFIT_H
