#include "s1081420_BigNUMv3.h"
#include<iostream>
using namespace std;

int main(){

	BigNUM n1(123456789123456789);
	BigNUM n2(-123456789);

	cout << n1 / n2 << endl;
	//cout << n2 / n1 << endl;

	/*cout<<"***input***"<<endl;
	BigNUM n1;
	cout << "input some number:" << endl;
	cin >> n1;
	cout << "output it:" << endl;
	cout << n1 << endl << endl<<endl;

	cout<<"*** / ***"<<endl;
	BigNUM n2(2, 10), n3(2,11);
	cout <<"n2="<< n2 << endl;
	cout <<"n3="<< n3 << endl;
	cout <<"n3/n2="<< n3 / n2 << endl;
	cout << "n2/n3="<<n2 / n3 << endl << endl << endl;
	
	cout << "*** getsize ***" << endl;
	BigNUM n4(2,10 );
	cout << "n4(2,10)=1024" << endl;
	cout << "n4size=" << n4.getSize() << endl << endl << endl;
	
	cout << "*** getcapacity ***" << endl;
	cout << "n4(2,10)=1024" << endl;
	cout << "n4capacity=" << n4.getCapcity() << endl << endl << endl;
	
	cout << "*** resize ***" << endl;
	BigNUM n5(123456789);
	cout << "n5=123456789" << endl;
	cout << "n5size_before=" << n5.getSize() << endl;
	n5.resize(11);
	cout << "n5size_after=" << n5.getSize() << endl << endl << endl;
	
	cout << "*** reserve ***" << endl;
	BigNUM n6(987654321);
	cout << "n6=987654321" << endl;
	cout << "n6capacity_before=" << n6.getCapcity() << endl;
	cout << "reserve(10)" << endl;
	n6.reserve(10);
	cout << "n6capacity_after=" << n6.getCapcity() << endl << endl << endl;
	n6.reserve(2);
	cout << "reserve(2)" << endl;
	cout << "n6capacity_before=" << n6.getCapcity() << endl;
	cout << "n6capacity_after=" << n6.getCapcity() << endl << endl << endl;

	cout << "*** output ***" << endl;
	BigNUM n7(517, 130);
	cout << "n7(517,430)" << endl;
	cout << "n7size=" << n7.getSize() << endl;
	cout << "n7capacity=" << n7.getCapcity() << endl;
	cout << "n7=" << n7 << endl << endl << endl;*/
	return 0;
}
