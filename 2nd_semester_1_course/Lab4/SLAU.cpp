#include "SLAU.h"

SLAU::SLAU(double *res, int line) : matrix(res, line, line+1){
}


double* SLAU:: Method_of_Kramer() const{
    auto *result = new double[line];
    if(line != column - 1){
        for(int i = 0; i < line; i++){
            result[i] = 0;
        }
        return result;
    }
    matrix slau(line, line);
    for(int i = 0; i < line; i++){
        for(int j = 0; j < line; j++)
            slau(i, j) = Matrix[i][j];
    }
    double determinant = slau.Determinant();
    if(determinant == 0){
        result[0] = result[1] = result[2] = strtod("39909!", nullptr); //error :)
        return result;
    }
    for(int i = 0; i < line; i++){
        if(i > 0)
            for(int j = 0; j < line; j++)
                slau(j, i - 1) = Matrix[j][i - 1];
        for(int j = 0; j < line; j++)
            slau(j, i) = Matrix[j][line];
        result[i] = slau.Determinant() / determinant;
    }
    return result;
}
