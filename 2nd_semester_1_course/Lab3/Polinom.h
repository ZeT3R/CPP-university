#pragma once

#include <iostream>

class Polinom{
	float *coefficient;
	int length;
	void reduction();
	
	public:

		Polinom();
		
		Polinom(float *Coefficient, int Length);
		
		Polinom(const Polinom & polinom);
		
		~Polinom();
		
		
		friend std::ostream& operator <<(std::ostream& out, const Polinom& polinom);
		
		friend std::istream& operator >>(std::istream& in, Polinom& polinom);
		
		
		float at(const int index);

		float rasschet(const float x);

		float& operator [](int index);

		const Polinom operator +(const Polinom& polinom);
		
		const Polinom operator -(const Polinom& polinom);
		
		const Polinom operator *(const Polinom& polinom);
		
		const Polinom operator /(const Polinom& polinom);
		
		const Polinom operator %(const Polinom& polinom);

		Polinom& operator =(const Polinom& polinom);
		
		Polinom& operator +=(const Polinom& polinom);
		
		Polinom& operator -=(const Polinom& polinom);
		
		Polinom& operator *=(const Polinom& polinom);
		
		Polinom& operator /=(const Polinom& polinom);
		
		Polinom& operator %=(const Polinom& polinom);
		
		const Polinom operator -();
};
