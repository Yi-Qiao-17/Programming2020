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
		int size;//�����e���Ŷ�
		int capacity;//�C���Ŷ��椣�����ܦ���U2���j
		int* array = nullptr;
	public:
		MyArray(long long int); // �w�]�Ŷ���3 �C�ӪŶ��s3��� 
		MyArray();
		//MyArray(int n, int m);
		MyArray(const MyArray&);
		~MyArray();
		const MyArray& operator=(const MyArray& right);
		//==�B!= ����capacity �i�H���@�ˤj
		bool operator==(const MyArray& right) const;
		bool operator!=(const MyArray& right) const 
		{
			return !(*this == right);
		}
		int& operator[](int);//����
		int operator[](int) const;//��¶ǭ�
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
		//void shrink_to_fit();//�����k�Ψ�
		//
		void de();//�bBIGNUM���R��array

};

#endif // !s1081420_MyArray_H
