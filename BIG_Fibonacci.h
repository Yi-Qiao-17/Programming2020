#ifndef S1081420_BIGNUM_P1_H
#define S1081420_BIGNUM_P1_H
//#define LEN 2
#include<iostream>
using namespace std;

class BigNUM {
	friend ostream& operator<<(ostream&, const BigNUM&);
	private:
		int space=1;
		int* fa=nullptr;
	public:
		BigNUM();
		BigNUM(int a);
		BigNUM(const BigNUM&);//copy constructor
		//int getspace();
		const BigNUM& operator=(const BigNUM&); // assignment operator
		~BigNUM();
		BigNUM operator+(const BigNUM&)const;//const �g�b�᭱�N��class�����o��function������ǤJ�Ȫ���
		
};
#endif // !S1081420_BIGHNUM_H

