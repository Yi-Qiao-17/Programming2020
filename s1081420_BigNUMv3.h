#pragma once
#ifndef s1081420_BigNUMv3_H
#define s1081420_BigNUMv3_H

#include<iostream>
#include "s1081420_MyArray.h"
using namespace std;

class BigNUM :public MyArray {
	friend BigNUM  operator+(const  int&, const  BigNUM&);
	friend BigNUM  operator-(const  int&, const  BigNUM&);
	friend BigNUM  operator*(const int&, const  BigNUM&);
	friend BigNUM  operator/(const int&, const  BigNUM&);
	private:

	public:
		BigNUM() :MyArray() {};
		BigNUM(const BigNUM& right) :MyArray(right) {};//copy
		BigNUM(long long int num) :MyArray(num) {};
		BigNUM(int n, int m) ;
		//~BigNUM();
		const BigNUM& operator=(const BigNUM& right) { 
			MyArray::operator=(right);
			return *this;
		};
		BigNUM operator-() const;//­t¸¹

		BigNUM operator+(const BigNUM&);
		BigNUM operator-(const BigNUM&);
		BigNUM operator*(const BigNUM&);
		BigNUM operator/(const BigNUM&);

		BigNUM operator+(const int&);
		BigNUM operator-(const int&);
		BigNUM operator*(const int&);
		BigNUM operator/(const int&);

		
		void addition(BigNUM&);
		void subtraction(BigNUM&);
		bool less(BigNUM&);//<
		bool equal(BigNUM&);//==
		
};
#endif // !s1081420_BigNUMv3_H
