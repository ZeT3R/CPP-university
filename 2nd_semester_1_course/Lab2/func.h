#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Fraction{
	
 private:
  	int chislitel;
  	int znamenatel;
  		
 public:
	Fraction();
  
	Fraction(const int &number);
  
	Fraction(const int &chislitel, const int &znamenatel);
	
    Fraction(const Fraction &other);
	
	inline int getChislitel() const;
  
	inline int getZnamenatel() const;
	
	explicit operator float() const;
	
	explicit operator double() const;
  
	Fraction Sokratitb() const;
  
	static int getNOD(const int &a, const int &b);
 	
 	Fraction& operator =(const Fraction &a);
 	
 	Fraction& operator +=(const Fraction &a);
 	
 	Fraction& operator -=(const Fraction &a);
 	
 	Fraction& operator *=(const Fraction &a);
 	
 	Fraction& operator /=(const Fraction &a);	
 	
 	friend ostream &operator <<(ostream &stream, const Fraction &fraction);
 	
 	friend istream &operator >>(istream &stream, const Fraction &fraction);
 	
 	friend int sravnenie(const Fraction &a, const Fraction &b);
 	
 	friend Fraction operator +(const Fraction &a, int b);
 	
 	friend Fraction operator +(int b, const Fraction &a);
 	
 	friend Fraction operator +(const Fraction &a, const Fraction &b);
 	
 	friend Fraction operator -(const Fraction &a, const Fraction &b);
 	
 	friend Fraction operator -(const Fraction &a, int b);
 	
 	friend Fraction operator -(int b, const Fraction &a);

	friend Fraction operator -(const Fraction &a);

	friend Fraction operator *(const Fraction &a, const Fraction &b);

	friend Fraction operator /(const Fraction &a, const Fraction &b);
	
	friend bool operator ==(const Fraction &a, const Fraction &b);

	friend bool operator !=(const Fraction &a, const Fraction &b);

	friend bool operator >(const Fraction &a, const Fraction &b);

	friend bool operator <(const Fraction &a, const Fraction &b);

	friend bool operator >=(const Fraction &a, const Fraction &b);

	friend bool operator <=(const Fraction &a, const Fraction &b);
 		
};

int Fraction::getChislitel() const{
	return chislitel;
}


int Fraction::getZnamenatel() const{
	return znamenatel;
}

void output_tabl();
