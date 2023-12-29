#include <iostream>
#include <thread>
#include "Tree.h"
#include <iomanip>


class Prikol{
public:
    int sravnenie;

    Prikol(){
        sravnenie = 0;
    }

    explicit Prikol(int param = 10){
        sravnenie = param;
    }

    friend bool operator >(const Prikol& obj1, const Prikol& obj2){
        return (obj1.sravnenie > obj2.sravnenie);
    }

    friend bool operator <(const Prikol& obj1, const Prikol& obj2){
        return (obj1.sravnenie < obj2.sravnenie);
    }


    friend std::ostream& operator <<(std::ostream& out, const Prikol& obj){
        out << obj.sravnenie;
        return out;
    }
};


int main(){
    try {

        Tree<int> intTree;
        std::thread thread1([&]() {
            intTree.add(8);
            intTree.add(10);
            intTree.add(2);
            intTree.add(6);
        });
        std::thread thread2([&]() {
            intTree.add(7);
            intTree.add(12);
            intTree.add(5);
            intTree.add(9);
        });

        Tree<int> intTree2;
        intTree2.add(20);
        intTree2.add(30);
        intTree2.add(40);
        intTree2.add(50);

        intTree.add(intTree2);

        thread1.join();
        thread2.join();
        std::cout << intTree << "\n";

        std::cout << intTree.find(6) << "\n";

        std::cout << intTree.returnSubTree(10) << "\n";

        intTree.deleteSubTree(10);

        std::cout << intTree << "\n";

        intTree.deleteElem(5);

        std::cout << intTree << "\n";

        intTree.clear();

        std::cout << intTree << "\n";

        intTree2.lkp();

        std::cout << intTree2 << "\n";

        intTree2.lpk();

        std::cout << intTree2 << "\n";
        char w = 0;
        char f = '0';


        Tree<double> *dd2;
        Tree<double> **dd = &dd2;

        Tree<double> doubleTree;
        std::thread thread3([&]() {
            doubleTree.add(3.1415);
            doubleTree.add(6.134545345345533);
            doubleTree.add(-999.999999);
            doubleTree.add(1.0000001);
        });
        thread3.join();
        std::cout << doubleTree << "\n";
        std::cout << std::setprecision(9) << doubleTree << "\n";

        Prikol first(25);
        Prikol second(35);

        Tree<Prikol> PrikolnoeDerevo;
        PrikolnoeDerevo.add(first);
        PrikolnoeDerevo.add(second);

        std::cout << PrikolnoeDerevo << "\n";



        Tree<int> tr_i1;

        tr_i1.add(12);

        tr_i1.add(24);

        tr_i1.add(15);

        tr_i1.add(32);

        tr_i1.add(48);

        tr_i1.add(16);

        Tree<int> tr_i2(tr_i1);

        std::cout << tr_i2 << " \n";

        tr_i2.deleteElem(12);

        std::cout << tr_i2 << " \n";

        tr_i2.deleteElem(15);

        std::cout << tr_i2 << " \n";

        tr_i2.deleteElem(16);

        std::cout << tr_i2 << " \n";

        tr_i2.deleteElem(24);

        std::cout << tr_i2 << " \n";

        tr_i2.deleteElem(32);

        std::cout << tr_i2 << " \n";

        tr_i2.deleteElem(48);

        std::cout << tr_i2 << " \n";

        std::cout << w << "\n";
        std::cout << w;
        std::cout << w;
        std::cout << w;
        std::cout << w;
        std::cout << w;
        std::cout << w;
        std::cout << w;
        
    }

    catch(std::logic_error &err) {
        std::cerr << err.what() << "\n";
    }
    catch(...){
        std::cerr << "UNEXPECTED ERROR!!!";
    }
    return 0;
}
