#include "s1081420_MyArray.h"
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
#define LEN 3;

istream& operator>>(istream& in,  MyArray& right) {
    right = 0;
    //cout << right;
    MyArray temp(0);
    string s;
    in >> s;
    int value = 0;
    int  si = s.size();
    if (s[0] == '-')si -= 1;
    value = ceil(si / 3.0);
    right.resize(value);
    temp.resize(si);

    if (s[0] == '-') {
        right.setsign(999);
        temp.sign = 999;
        for (int i = 1; i < s.size(); i++) {
            temp.array[i-1] = s[s.size() - i ] - '0';
        }
    }
    else {
        right.setsign(000);
        temp.sign = 000;
        for (int i = 0; i < s.size(); i++) {
           // temp.array[i] = s[s.size() - i - 1] - '0';
            temp.array[i] = s[s.size()-i-1] - '0';
        }
    }
    //for (int i = 0; i < si; i++) {//+pass -fail
    //    cout << temp.array[i] << " ";
    //}
    //cout << endl;
    int j = 0;
    for (int i = 0; i < si; i++) {
        if ((i + 1) % 3 == 0) {
            int x = 0, y = 0, z = 0;
            x = temp.array[i]*100;
            if (i - 1 <= si && i - 1 >= 0)y = temp.array[i - 1] * 10;
            if (i - 2 <= si && i - 2 >= 0)z = temp.array[i - 2] ;
            if (j < value) {
                right.array[j] = x + y + z;
                j++;
                x = 0, y = 0, z = 0;
            }
            continue;
        }
        int v = i / 3;
        if (i == si - 1&&v>=1 && si % 3 == 2) {
            int x = 0, y = 0;
            x = temp.array[i]*10;
            y = temp.array[i - 1];
            right.array[right.size - 1] = x + y;
            x = 0, y = 0;
            continue;
        }
        if (i == si - 1&&v>=1&&si%3==1) {
            int x = 0;
            x = temp.array[i];
            right.array[right.size - 1] = x;
            x = 0;
            continue;
        }
    }
    return in;

}

ostream& operator<<(ostream& out, const MyArray& right) {//done
    if (right.sign == 999)cout << "-";
    if (right.size != 1) out << right.array[right.size - 1] << ",";
    for (int i = right.size - 2; i > 0; i--) {//判斷
        out.width(3);//輸出三個數字以0填滿
        out.fill('0');
        out << right.array[i] << ",";
    }
    if (right.size == 0 && right.array[0] == 0)out << "0" << endl;
    else {
        /*if (right.fa[0] < 100)out << "0";
        else if (right.fa[0] < 10)out << "00";*/
        if (right.size == 1)out << right.array[0] << endl;
        else {
            out.width(3);
            out.fill('0');
            out << right.array[0] << endl;
        }
    }
    return out;
}

MyArray::MyArray() {
    sign = 000;//000=0
    capacity = LEN;
    array = new int[capacity]();
}
MyArray::MyArray(long long int num) {
    if (num == 0) {
        size = 1;
        capacity = LEN;
        array = new int[capacity]();
        sign = 000;
    }

    else {
        long long int value = num;//value為取絕對值的num
        if (value < 0)value *= (-1);
        int sizenum = 0;//一開始一定至少為0會有一格
        while (value % 1000 > 0) {//算需要多少格
            sizenum++;
            value /= 1000;
        }
        size = sizenum;//有多少格有內容
        capacity = LEN;
        while (capacity<size)//capacity大小
        {
            capacity *= 2;
        }
        value = num;
        if (value < 0)value *= (-1);
        array = new int[capacity]();
        //要判斷正負,999為負,000為正
        if (num < 0)sign = 999;
        else sign = 000;
        int space = 0;
        while (value % 1000 > 0) {//放入數字
            array[space++] = value % 1000;
            value /= 1000;
        }
    }
} // 預設空間為3 每個空間存3位數 
MyArray::MyArray(const MyArray& right) {
    sign = right.sign;
    capacity = right.capacity;
    size = right.size;
    array = new int[capacity]();
    for (int i = 0; i < size; i++) {
        array[i] = right.array[i];
    }
}

MyArray::~MyArray() {
    sign = 0;
    capacity = 0;
    size = 0;
    delete[]array;
    array = nullptr;
}
const MyArray& MyArray::operator=(const MyArray& right) {
    sign = right.sign;
    if (&right != this) // avoid self-assignment
    {
        if (size != right.size)
        {
            delete[] array; // release spac
            capacity = right.capacity;
            size = right.size; // resize this object
            array = new int[capacity](); // create space for array copy
        } // end inner if

        for (int i = 0; i < size; i++)
            array[i] = right.array[i]; // copy array into object
    } // end outer if
    return *this;
}


//==、!= 附註capacity 可以不一樣大
bool MyArray ::operator==(const MyArray& right) const {
    if (size != right.size)
        return false;
    else {
        for (int i = size - 1; i >= 0; i--) {
            if (array[i] != right.array[i])return false;
        }
        return true;
    }

}
int& MyArray::operator[](int subscript) {
    if (subscript < 0 || subscript >= size) {
        cout << "Errror subscript" << endl;
        exit(1);
    }
    return array[subscript];
}//更改值
int MyArray::operator[](int subscript) const {
    if (subscript < 0 || subscript >= size) {
        cout << "Errror subscript" << endl;
        exit(1);
    }
    return array[subscript];
}//單純傳值
int MyArray::getSize() {
    return size;
}
int MyArray::getSign() {
    return sign;
}
int MyArray::getCapcity() {
    return capacity;
}
void MyArray::resize(size_t newsize, int c ) {
    if (newsize <= capacity)size = newsize;
    else {
        int newcap = capacity * 2;
        while (newsize > newcap)newcap *= 2;
        int* buffer = new int[newcap]();
        for (int i = 0; i < size; i++) {
            buffer[i] = array[i];
        }
        delete[]array;
        array = buffer;
        size = newsize;
        capacity = newcap;
    }
}
void MyArray::reserve(size_t newcap) {//看空間不夠就增加空間
    if (newcap <= capacity);
    else {
        while (newcap > capacity)capacity *= 2;
        int* buffer = new int[capacity]();
        for (int i = 0; i < size; i++) {
            buffer[i] = array[i];
        }
        delete[]array;
        array = buffer;
    }
}
void MyArray::to_zero() {
    MyArray zero(0);
    *this = zero;
}

void MyArray::de() {
    sign = 0;
    capacity = 0;
    size = 0;
    delete[]array;
    array = nullptr;

}
