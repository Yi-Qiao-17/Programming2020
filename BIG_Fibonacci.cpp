#include"s1081420_BigNUM_P1.h"
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define LEN 5


BigNUM::BigNUM() {
	space = LEN;
	fa = new int[space]();
	for (int i = 0; i < space; i++) {
		fa[i]=0;
	}
}

BigNUM::BigNUM(int a)
{
	space = LEN;
	fa = new int[space]();
	for (int i = 0; i < space; i++) {
		fa[i] = 0;
	}

	if (a == 0) {
		//continue;

	}
	else {
		int size=0;
		//space = 0;
		//fa = new int[space]() ;
		int value = a;
		while (value % 1000 > 0) {
			fa[size++] = value % 1000;
			value = value / 1000;
			
		}
		
	}
	
	
}

BigNUM::BigNUM(const BigNUM& right) {
	space = right.space;
	fa = new int[space]();
	for (int i = 0; i < space; i++) {
		fa[i] = right.fa[i];
	}
}//copy constructor

const BigNUM& BigNUM::operator=(const BigNUM& right) {
	if (&right != this) {//避免自我複製
		if (space != right.space) {
			delete[]fa;
			//space = right.space;
			fa = new int[space]();
		}
		for (int i = 0; i < space; i++) {
			fa[i] = right.fa[i];
		}
	}
	return *this;
} // assignment operator

BigNUM::~BigNUM() {
	delete[]fa;
}


BigNUM BigNUM::operator+(const BigNUM& right)const {

	BigNUM sum(*this);
	//int M =max(sum.space,right.space);
	/*if (sum.space > right.space) {
		M = sum.space;
	}
	else M = right.space;*/
	int value = 0;
	for (int i = sum.space - 1; i >= 0; i--) {//先找出不為0的元素位置
		if (sum.fa[i] != 0) {
			value = i;
			break;
		}
	}
	int i = 0, carry = 0;
	for (i = 0; i < value+1; ++i) {//減少運算時間
		sum.fa[i] += right.fa[i];
		if (sum.fa[i] > 1000){
			//M++;
			/*BigNUM copy;
			copy.space = sum.space + 1;
			for (int i = 0; i < copy.space; i++) {
				if(i!=copy.space-1)
				copy.fa[i] = sum.fa[i];
				else if(i == copy.space - 1)copy.fa[i] = 0;
			}
			copy.fa[i + 1] += copy.fa[i] / 1000;
			copy.fa[i] %= 1000;
			sum=copy;*/
			sum.fa[i + 1] += sum.fa[i] / 1000;
			sum.fa[i] = sum.fa[i] % 1000;
			//sum.fa[i + 1] += carry;
		}
		
	}
	/*if (sum.fa[M] > 0) {
		BigNUM copy;
		copy.space = sum.space + 1;
		for (int i = 0; i < copy.space; i++) {
			if (i != copy.space - 1)
				copy.fa[i] = sum.fa[i];
			else if (i == copy.space - 1)copy.fa[i] = 0;
		}
		//sum.space++;//避免溢位
		//sum.fa[space - 1] = 0;
		sum = copy;
	}
	else sum.space = M;*/
	return sum;
}//const 寫在後面代表class中的這個function不能更改傳入值的值

 ostream& operator<<(ostream& out, const BigNUM& right) {
	 /*
	 if (right.space == 1) {
		 out << right.fa[right.space - 1] << endl;
	 }
	 else {
		 out << right.fa[right.space - 1]<<",";
		 for (int i = right.space - 2; i > 0; i--) {
			 out << right.fa[i] << ",";
		 }
		 out << right.fa[0] << endl;
	 }*/
	 
	 
	 int value = 0;
	 for (int i = right.space - 1; i >= 0; i--) {//先找出不為0的元素位置
		 if (right.fa[i] != 0) {
			 value = i;
			 break;
		 }
	 }
	 
	 if (value != 0) out << right.fa[value] << ",";
	 for (int i = value-1; i > 0; i--) {//判斷
		/*if (right.fa[i] < 100)out << "0";
		 else if (right.fa[i] < 10)out << "00";*/
		 out.width(3);
		 out.fill('0');
		 out << right.fa[i] << ",";

		 
	 }
	 if (value==0&&right.fa[0]==0)out << "0" << endl;
	 else {
		 /*if (right.fa[0] < 100)out << "0";
		 else if (right.fa[0] < 10)out << "00";*/
		 if(value==0)out << right.fa[0] << endl;
		 else {
			 out.width(3);
			 out.fill('0');
			 out << right.fa[0] << endl;
		 }
		

	 } 
	 return out;
}

 /*int BigNUM::getspace() {
	 return space;
 }*/