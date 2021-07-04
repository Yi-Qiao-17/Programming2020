#pragma once
#ifndef s1081420_MyArray_H
#define s1081420_MyArray_H

#include<iostream>
using namespace std;

class MyArray {
	friend ostream& operator<<(ostream&, const MyArray&);
	friend istream& operator>>(istream&, MyArray&);
	private:
		int sign;//000+ 999-
		int size;//有內容的空間
		int capacity;//每次空間格不夠時變成當下2倍大
		int* array = nullptr;
	public:
		MyArray(long long int); // 預設空間為3 每個空間存3位數 
		MyArray();
		//MyArray(int n, int m);
		MyArray(const MyArray&);
		~MyArray();
		const MyArray& operator=(const MyArray& right);
		//==、!= 附註capacity 可以不一樣大
		bool operator==(const MyArray& right) const;
		bool operator!=(const MyArray& right) const 
		{
			return !(*this == right);
		}
		int& operator[](int);//更改值
		int operator[](int) const;//單純傳值
		void setsize(int set) { size = set; };
		void setsign(int set) { sign = set; };
		void setcapacity(int set) { capacity = set; };
		int getSize();
		int getSign();
		int getCapcity(); 
		void resize(size_t, int c=0);
		void reserve(size_t );

		void to_zero();
		//void to_fit();
		//void shrink_to_fit();//乘除法用到
		//
		void de();//在BIGNUM中刪掉array

};

#endif // !s1081420_MyArray_H
