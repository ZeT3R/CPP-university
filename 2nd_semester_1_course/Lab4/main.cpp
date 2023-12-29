#include <iostream>
#include "SLAU.h"

using namespace std;

int main() {
    int count = 0;
    auto**arr1 = new double*[3];
    for(int i = 0; i < 3; i++){
        arr1[i] = new double[3];
        for(int j = 0; j < 3; j++){
            arr1[i][j] = count++;
        }
    }

    auto**arr2 = new double*[3];
    for(int i = 0; i < 3; i++){
        arr2[i] = new double[3];
        for (int j = 0; j < 3; j++) {
            arr2[i][j] = count--;
        }
    }


cout << " Our Matrixes: \n\n";
matrix a(arr1, 3, 3);
matrix b(arr2,3, 3);
cout << a << "\n";
cout << b << "\n\n\n";

cout << " Operations + - * / \n\n";
cout << a + b << "\n" << a - b << "\n" << a * b << "\n" << a / b << "\n\n\n";


cout << "Operations with numbers \n\n";
cout << 2 * a << "\n" << 2 / a << "\n";
cout << a * 2 << "\n" << a / 2 << "\n";

cout << " Unarniy - and + \n\n";
cout << -a << "\n" << +a << "\n";

cout << "Operations *= /= with numbers \n\n";
a *= 2;
cout << a << "\n";
a /= 2;
cout << a << "\n\n\n";

cout << "Opeartions += -= with matrixes: \n";
a += b;
cout << a << "\n";
a -= b;
cout << a << "\n";

cout << "Method of reversing the matrix: \n\n\n";
double invert[2][2]{
        {7,4},
        {5,3}
};


matrix Inv(*invert, 2, 2);
cout << "Normal matrix: \n\n" << Inv << "\n\n";
cout << "Invert matrix: \n\n" << Inv.invert() << "\n\n";

cout << "System Of Linear Algebraic Expression (SLAE) : \n\n";
double Slau[2][3]{
        {5, 2, 7},
        {2, 1, 9}
};
int countSLAU = 2;
SLAU Slau_test(*Slau, countSLAU);
cout << "Answer is: ";
    double* answer = Slau_test.Method_of_Kramer();
    for (int i = 0; i < countSLAU; i++) {
        cout << answer[i] << ' ';
    }
    delete answer;
    return 0;
}
