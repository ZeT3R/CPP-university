#pragma once

#include <iostream>
#include "matrix.h"

class SLAU : public matrix{
    public:

        SLAU(double *res, int line);

        double* Method_of_Kramer() const;

};
