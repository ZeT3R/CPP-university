#include "func.h"

	Fraction::Fraction() : chislitel(0), znamenatel(1){
  	}
  
  
	Fraction::Fraction(const int &number) : chislitel(number), znamenatel(1){
  	}
  
  
	Fraction::Fraction(const int &chislitel, const int &znamenatel)
    : chislitel(chislitel), znamenatel(znamenatel){
	}
	
	
    Fraction::Fraction(const Fraction &other) : chislitel(other.chislitel), znamenatel(other.znamenatel){	
    }
	
	
	Fraction::operator float() const{
		return (float) chislitel/znamenatel;
	}
	
	
	Fraction::operator double() const{
		return (double) chislitel/znamenatel;
	}
  
  
	Fraction Fraction::Sokratitb() const{
    	int NOD = getNOD(getChislitel(), getZnamenatel());
    	int chislitel = getChislitel() / NOD;
    	int znamenatel = getZnamenatel() / NOD;
    	if (znamenatel < 0) {
      		chislitel = -chislitel;
      		znamenatel = -znamenatel;
    	}
    	return Fraction(chislitel, znamenatel);
  	}
  
  
	int Fraction::getNOD(const int &a, const int &b){
    	int x = abs(a);
    	int y = abs(b);
    	while(true){
      		x = x % y;
      		if (x == 0){
        		return y;
      		 }
      		y = y % x;
      		if (y == 0){
        		return x;
      		 }
    	}
 	}
 	
 	
 	Fraction& Fraction::operator =(const Fraction &a){
 		chislitel = a.chislitel;
 		znamenatel = a.znamenatel;
 		return *this;
 	}
 	
 	
 	Fraction& Fraction::operator +=(const Fraction &a){
	 chislitel += a.chislitel;
	 znamenatel += a.znamenatel;
	 return *this;   
	}


Fraction& Fraction::operator -=(const Fraction &a){
	chislitel -= a.chislitel;
	znamenatel -= a.znamenatel;
	return *this;   
	}


Fraction& Fraction::operator *=(const Fraction &a){
	chislitel *= a.chislitel;
	znamenatel *= a.znamenatel;
	return *this;   
	}


Fraction& Fraction::operator /=(const Fraction &a){
	chislitel /= a.chislitel;
	znamenatel /= a.znamenatel;
	return *this;   
	}
	
	
Fraction operator +(const Fraction &a, int b){
	return Fraction(a.getChislitel() + a.getZnamenatel()*b, a.getZnamenatel());
}


Fraction operator +(int b, const Fraction &a){
	return Fraction(a.getChislitel() + a.getZnamenatel()*b, a.getZnamenatel());
}
 
Fraction operator +(const Fraction &a, const Fraction &b){
  return Fraction(a.getChislitel() * b.getZnamenatel() +
    b.getChislitel() * a.getZnamenatel(),
    a.getZnamenatel() * b.getZnamenatel());
}

 
Fraction operator -(const Fraction &a, const Fraction &b){
  return Fraction(a.getChislitel() * b.getZnamenatel() -
    b.getChislitel() * a.getZnamenatel(),
    a.getZnamenatel() * b.getZnamenatel());
}


Fraction operator -(const Fraction &a, int b){
	return Fraction(a.getChislitel() - a.getZnamenatel()*b, a.getZnamenatel());
}


Fraction operator -(int b, const Fraction &a){
	return Fraction(-(a.getChislitel() - a.getZnamenatel()*b), a.getZnamenatel());
}


Fraction operator -(const Fraction &a) {
  return Fraction(-a.getChislitel(), a.getZnamenatel());
}
 
 
Fraction operator *(const Fraction &a, const Fraction &b){
  return Fraction(a.getChislitel() * b.getChislitel(),
    a.getZnamenatel() * b.getZnamenatel());
}
 
 
Fraction operator /(const Fraction &a, const Fraction &b){
  return Fraction(a.getChislitel() * b.getZnamenatel(),
    a.getZnamenatel() * b.getChislitel());
}
 
 
ostream &operator <<(ostream &stream, const Fraction &fraction){
  Fraction kratno = fraction.Sokratitb();
  return stream << kratno.getChislitel() << "/" << kratno.getZnamenatel();
}


istream &operator >>(istream &stream, const Fraction &fraction){
	Fraction chislitel = fraction.getChislitel();
	Fraction znamenatel = fraction.getZnamenatel();
		
}

 
int sravnenie(const Fraction &a, const Fraction &b){
    return a.getChislitel() * b.getZnamenatel() -
    b.getChislitel() * a.getZnamenatel();
}
 
 
bool operator ==(const Fraction &a, const Fraction &b){
  return sravnenie(a, b) == 0;
}
 
 
bool operator !=(const Fraction &a, const Fraction &b){
  return sravnenie(a, b) != 0;
}
 
 
bool operator >(const Fraction &a, const Fraction &b){
  return sravnenie(a, b) > 0;
}
 
 
bool operator <(const Fraction &a, const Fraction &b){
  return sravnenie(a, b) < 0;
}
 
 
bool operator >=(const Fraction &a, const Fraction &b){
  return sravnenie(a, b) >= 0;
}
 
 
bool operator <=(const Fraction &a, const Fraction &b){
  return sravnenie(a, b) <= 0;
}


void output_tabl(){
	cout << "\nКакие действия вы хотите выполнить с дробями? ";
	cout << "\n1. Сложить 2 дроби";
	cout << "\n2. Вычесть 2 дроби";
	cout << "\n3. Умножить 2 дроби";
	cout << "\n4. Поделить 2 дроби";
	cout << "\n5. Сравнить (первая больше второй?)";
	cout << "\n6. Сравнить (вторая больше первой?)";
	cout << "\n7. Дроби равны?";
	cout << "\n8. Ввести первую дробь заново.";
	cout << "\n9. Ввести вторую дробь заново.";
	cout << "\n0. Закончить работу с дробями\n\n\n";
}
 
