#include <cmath>
#include "Polinom.h"

Polinom::Polinom(){
	length = 0;
	coefficient = new float[1];
	coefficient[0]= 0.0;
}


Polinom::Polinom(float *Coefficient, int Length){
	coefficient = new float[Length];
	length = Length - 1;
	for(int i = 0; i < Length; i++){
	coefficient[length - i] = Coefficient[i];
	}
	
	reduction();
}


Polinom::Polinom(const Polinom &polinom){
	coefficient = new float[polinom.length + 1];
	length = polinom.length;
	for(int i = 0; i <= polinom.length; i++){
	coefficient[i] = polinom.coefficient[i];
	}
}


Polinom::~Polinom(){
	delete[] coefficient;
}


std::ostream& operator <<(std::ostream& vivod, const Polinom& polinom){
	if (polinom.length == 0){
		vivod << polinom.coefficient[polinom.length];
		return vivod;
	}	
	for(int i = polinom.length; i >= 0; i--){
		if(polinom.coefficient[i] != 0){
			if(polinom.coefficient[i] >= 1 && i != polinom.length)
				vivod << "+";
				
			if(polinom.coefficient[i] == -1 && i != 0)
				vivod << "-";
				
			if((polinom.coefficient[i] != 1 && polinom.coefficient[i] != -1) || i == 0)
				vivod << polinom.coefficient[i];
				
			if(i != 0)
				vivod << "x";
				
			if(i > 1)
				vivod << "^" << i;
		}
	}
	return vivod;
}


std::istream& operator >>(std::istream& vvod, Polinom& polinom){
	delete[] polinom.coefficient;
	vvod >> polinom.length;
	polinom.length--;
	polinom.coefficient = new float[polinom.length];
	for (int i = 0; i <= polinom.length; i++) 
		vvod >> polinom.coefficient[i];
	return vvod;								
}


float Polinom::rasschet(const float x){
	float result = 0;
	for (int i = 0; i <= length; i++){
		result += coefficient[i] * pow(x,i);
	}
		
	return result;
}


float& Polinom::operator [](int index){
	return coefficient[index];
}


float Polinom::at(const int index){
	return coefficient[index];
}


const Polinom Polinom::operator +(const Polinom& polinom){
	int len_max, len_min;
	if(length > polinom.length){
		len_max = length;
		len_min = polinom.length;
		float res_m[len_max + 1];
		Polinom result(res_m, len_max + 1);
		for(int i = 0; i <= result.length; i++)
			result.coefficient[i] = 0;
			
		for(int i = 0; i <= len_min; i++)
			result.coefficient[i] = coefficient[i] + polinom.coefficient[i];
			
		for(int j = len_min + 1; j <= len_max; j++) 
			result.coefficient[j] = coefficient[j];
			
		result.reduction();
		return result;
	} 
	else{
		len_max = polinom.length;
		len_min = length;
		float res_m[len_max + 1];
		Polinom result(res_m, len_max + 1);
		for(int i = 0; i <= result.length; i++) 
			result.coefficient[i] = 0;
			
		for(int i = 0; i <= len_min; i++) 
			result.coefficient[i] = coefficient[i] + polinom.coefficient[i];
			
		for(int j = len_min+1; j <= len_max; j++) 
			result.coefficient[j] = polinom.coefficient[j];
			
		result.reduction();
		return result;
	} 
}


const Polinom Polinom::operator -(const Polinom& polinom){
	int len_max, len_min;
	if(length > polinom.length){
		len_max = length;
		len_min = polinom.length;
		float res_m[len_max + 1];
		Polinom result(res_m, len_max + 1);
		for(int i = 0; i <= result.length; i++) 
			result.coefficient[i] = 0;
			
		for(int i = 0; i <= len_min; i++) 
			result.coefficient[i] = coefficient[i] - polinom.coefficient[i];
			
		for(int j = len_min + 1; j <= len_max; j++) 
			result.coefficient[j] = coefficient[j];
			
		result.reduction();
		return result;
	} 
	else{
		len_max = polinom.length;
		len_min = length;
		float res_m[len_max + 1];
		Polinom result(res_m, len_max + 1);
		for(int i = 0; i <= result.length; i++) 
			result.coefficient[i]=0;
			
		for(int i = 0; i <= len_min; i++) 
			result.coefficient[i] = coefficient[i] - polinom.coefficient[i];
			
		for(int j = len_min + 1; j <= len_max; j++) 
			result.coefficient[j] = -polinom.coefficient[j];
			
		result.reduction();
		return result;
	} 
}


const Polinom Polinom::operator *(const Polinom& polinom){
	float res_m[length + polinom.length + 1];
	Polinom result(res_m, length + polinom.length + 1);
	for(int i = 0; i <= result.length; i++) 
		result.coefficient[i] = 0;
		
	for(int i = 0; i <= result.length; i++) 
		for(int j = 0; j <= length; j++)
			for(int k = 0; k <= polinom.length; k++)
				if(i == j + k) 
					result.coefficient[i] += coefficient[j] * polinom.coefficient[k];
	result.reduction();			
	return result;	
}


const Polinom Polinom::operator /(const Polinom& polinom){
	if (polinom.length > length)
		return Polinom();
	Polinom copy(*this);
	int len = copy.length - polinom.length + 1;
	float res_m[len];
	Polinom result(res_m, len);
	
	for (int i = 0; i <= len; i++) 
		result.coefficient[i] = 0;
	for (int i = 0; i <= result.length; i++){
		result.coefficient[result.length - i] = copy.coefficient[copy.length-i] / polinom.coefficient[polinom.length];
		for (int j = 0; j < polinom.length; j++) 
			copy.coefficient[copy.length - j - i - 1] -= polinom.coefficient[polinom.length - j - 1] * result.coefficient[result.length - i];
	}
	result.reduction();
	return result;
}


const Polinom Polinom::operator %(const Polinom& polinom){
	if (polinom.length == 0){
		float test[1]{0.0};
		return Polinom(test, 1);
	}
	if (length < polinom.length) 
		return *this;
	Polinom copy(*this);
	int len = copy.length - polinom.length + 1;
	float res_m[len], res_m2[polinom.length];
	Polinom result(res_m, len);
	Polinom res_ost(res_m2, polinom.length);
	
	for (int i = 0; i <= len; i++) 
		result.coefficient[i] = 0;
		
	for (int i = 0; i <= result.length; i++){
		result.coefficient[result.length - i] = copy.coefficient[copy.length - i] / polinom.coefficient[polinom.length];
		for (int j = 0; j < polinom.length; j++) 
			copy.coefficient[copy.length - j - i - 1] -= polinom.coefficient[polinom.length - j - 1] * result.coefficient[result.length - i];
	}
	for(int i = 0; i < polinom.length; i++) 
		res_ost.coefficient[i] = copy.coefficient[i];
	res_ost.reduction();
	return res_ost;
}


Polinom& Polinom::operator =(const Polinom& polinom){
	if (&polinom == this) 
		return *this;
	delete[] coefficient;
	length = polinom.length;
	coefficient = new float[length + 1];
	for (int i = 0; i <= length; i++) 
		coefficient[i] = polinom.coefficient[i];
	return *this;
}


Polinom& Polinom::operator +=(const Polinom& polinom){
	*this = *this + polinom;
	return *this;
}


Polinom& Polinom::operator -=(const Polinom& polinom){
	*this = *this - polinom;
	return *this;
}


Polinom& Polinom::operator *=(const Polinom& polinom){
	*this = *this * polinom;
	return *this;
}


Polinom& Polinom::operator /=(const Polinom& polinom){
	*this = *this / polinom;
	return *this;
}


Polinom& Polinom::operator %=(const Polinom& polinom){
	*this = *this % polinom;
	return *this;
}


const Polinom Polinom::operator -(){
	Polinom copy(*this);
	for (int i = 0; i <= copy.length; i++) 
		copy.coefficient[i] = -copy.coefficient[i];
	return copy;
}


void Polinom::reduction(){
	while (length > 0 && coefficient[length] == 0)
		length--;
}
