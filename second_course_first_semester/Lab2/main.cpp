#include <iostream>
#include "Queue.h"
#include <string>

struct LOL{
    int number;


    LOL(){
        number = 0;
    }

    explicit LOL(int numb){
        number = numb;
    }

    friend std::ostream& operator <<(std::ostream& out, const LOL& obj){
        out << "Your number is: " << obj.number;
        return out;
    }
};

int main() {
    try{

        Queue<int> qu1({10, 6, 3, 7, 2, 9, 3, 89, 54});
        std::cout << qu1.size_length() << "\n";
        std::cout << qu1 << "\n";
        for(int i = 0; i < 4; i++)
            std::cout << qu1.pop() << " ";
        qu1.push(999);
        std::cout << "\n" << qu1 << "\n\n\n";



        Queue<double> qu2({3.1415, 8.4562});
        std::cout << qu2 << "\n\n";
        std::cout << qu2.check_pop() << "\n";
        std::cout << qu2 << "\n";
        qu2.push(7.77);
        std::cout << qu2 << "\n\n\n";



        Queue<std::string> qu3({"Alexey", "Viktorovich", "Postavte", "Zachet,", "Pozhalyista", "Nu"});
        std::cout << qu3 << "\n";
        for(int i = 0; i < 2; i++)
            std::cout << qu3.pop() << " ";
        std::cout << "\n" << qu3 << "\n";
        std::cout << qu3.check_pop() << " \n";
        std::cout << qu3 << "\n\n";


        Queue<std::string> qu4;
        qu4.push("PLEASE");
        qu4.push("POSTAVTE");
        qu4.push("ZACHET");
        std::cout << qu4 << "\n";


    }


    catch(std::logic_error &err) {
        std::cerr << err.what() << "\n";
    }
    catch(...){
        std::cerr << "UNEXPECTED ERROR!!!";
    }
    return 0;
}
