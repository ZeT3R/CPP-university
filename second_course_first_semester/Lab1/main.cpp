#include <iostream>
#include "Stack.h"
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

        Stack<int> st1({10, 2, 5, 7, 9, 6, 8, 2, 10, 15});
        std::cout << st1 << "\n" << st1.size_length() << "\n";
        for(int i = 0; i < 2; i++)
            std::cout << st1.pop() << " ";
        std::cout << "\n" << st1 << "\n";
        std::cout << st1.check_pop() << " \n";
        std::cout << st1 << "\n";
        st1.push(5);
        std::cout << st1 << "\n\n\n";


        Stack<double> st2({3.1415, 8.4562});
        std::cout << st2 << "\n";
        st2.push(89.45325);
        st2.push(22.3242222342);
        std::cout << st2 << "\n\n\n";


        LOL object(36);
        LOL object2(72);
        Stack<LOL> st3({object});
        std::cout << st3 << "\n";
        st3.push(object2);
        std::cout << st3 << "\n";
        st3.pop();
        std::cout << st3 << "\n\n\n";


        Stack<std::string> st4({"Alexey", "Viktorovich", "Postavte", "Zachet,", "Pozhalyista", "Nu"});
        std::cout << st4 << "\n";
        for(int i = 0; i < 2; i++)
            std::cout << st4.pop() << " ";
        std::cout << "\n" << st4 << "\n";
        std::cout << st4.check_pop() << " \n";
        std::cout << st4 << "\n\n";

        Stack<std::string> st5;
        st5.push("PLEASE");
        st5.push("POSTAVTE");
        st5.push("ZACHET");
        std::cout << st5 << "\n\n\n";
    }

    catch(std::logic_error &err) {
        std::cerr << err.what() << "\n";
    }
    catch(...){
        std::cerr << "UNEXPECTED ERROR!!!";
    }
    return 0;
}
