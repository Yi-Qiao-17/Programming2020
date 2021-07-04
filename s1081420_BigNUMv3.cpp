#include "s1081420_BigNUMv3.h"

BigNUM::BigNUM(int n, int m) {
    int size = getSize();
    //BigNUM left(*this);
    if (m <= 0) {
        BigNUM one(1);
        *this = one;
    }
    else {
        BigNUM num(n);
        if (n >= 0 || m % 2 == 0) {
            for (int i = 1; i < m + 1; i++) {
                if (i == 1)n = n;
                else  num = num * n;
            }
            *this = num;
        }
        else if (n < 0 && m % 2 == 1) {//加負號

            for (int i = 1; i < m + 1; i++) {
                if (i == 1)num = num;
                else  num = num * n;
            }

           //array[size - 1] = 999;
            num.setsign(999);
            *this = num;
        }

    }
}
BigNUM BigNUM::operator-() const {
    BigNUM right(*this);
    int size2 = right.getSize();
    if (right.getSign() == 999)right.setsign(000);
    else right.setsign(999);
    return right;
}//負號

BigNUM BigNUM::operator+(const BigNUM& right1) {
    BigNUM sum(0);
    BigNUM zero(0);
    BigNUM right(right1);
    BigNUM left(*this);
    int size = getSize();
    int size2 = right.getSize();
    int size3 = sum.getSize();
    if (size >= size2) {
        sum = left;
    }
    else{//用right的長度存left(this)的值
        sum = right;
        for (int i = 0; i < size2; i++) {
            if (i < size)
                sum[i] = left[i];
            else sum[i] = 0;
        }
        int x = left.getSign();
        sum.setsign(x);
    }

    if (this->equal(zero))sum = right1;
    else if (right.equal(zero));
    //正+正
    else if (right.getSign() == 000 && sum.getSign() == 000) {

        sum.addition(right);
    }
    //正+負
    else if (sum.getSign() == 000 && right.getSign() == 999) {
        if (less(right)) {
            BigNUM sm(sum);
            BigNUM ri(right);
            ri.subtraction(sm);
            sum = ri;
            sum.setsign(999);

        }
        else if (equal(right)) {
            sum.to_zero();
        }
        else {
            sum.subtraction(right);
            sum.setsign(000);
        }
    }
    //負+正
    else if (sum.getSign() == 999 && right.getSign() == 000) {
        if (less(right)) {
            BigNUM sm(sum);
            BigNUM ri(right);
            ri.subtraction(sm);
            sum = ri;
            sum.setsign(000);
        }
        else if (equal(right)) {
            sum.to_zero();
        }
        else {
            sum.subtraction(right);
            sum.setsign(999);
            //
        }
    }
    //負+負
    else if (sum.getSign() == 999 && right.getSign() == 999) {
        sum.addition(right);
        sum.setsign(999);
    }
    return sum;
}
BigNUM BigNUM::operator-(const BigNUM& right1) {
    BigNUM sum;
    BigNUM zero(0);
    BigNUM right(right1);
    BigNUM left(*this);
    int size = getSize();
    int size2 = right.getSize();
    int size3 = sum.getSize();
    if (size >= size2) {
        sum = left;
    }
    else {//用right的長度存left(this)的值
        sum = right;
        for (int i = 0; i < size2; i++) {
            if (i < size)
                sum[i] = left[i];
            else sum[i] = 0;
        }
        int x = left.getSign();
        sum.setsign(x);
    }

    //0
    if (this->equal(zero)) {
        sum = right1;
        if (sum.getSign() == 999) sum.setsign(000);
        else  sum.setsign(999);
        //sum.array[sum.size - 1] = 999;
    }
    else if (right.equal(zero));
    //正-正
    else if (right.getSign() == 000 && sum.getSign() == 000) {
        if (less(right)) {
            BigNUM sm(sum);
            BigNUM ri(right);
            ri.subtraction(sm);
            sum = ri;
            sum.setsign(999);
        }
        else if (equal(right)) {
            sum.to_zero();
        }
        else {
            sum.subtraction(right);
            sum.setsign(000);

        }
    }
    //正-負
    else if (sum.getSign() == 000 && right.getSign() == 999) {
        sum.addition(right);
        sum.setsign(000);
    }
    //負-正
    else if (sum.getSign() == 999 && right.getSign() == 000) {
        sum.addition(right);
        sum.setsign(999);
    }
    //負-負
    else if (sum.getSign() == 999 && right.getSign() == 999) {
        if (less(right)) {
            BigNUM sm(sum);
            BigNUM ri(right);
            ri.subtraction(sm);
            sum = ri;
            sum.setsign(000);
        }
        else if (equal(right)) {
            sum.to_zero();
            //sum.shrink_to_fit();
        }
        else {
            sum.subtraction(right);
            sum.setsign(999);

        }
    }
    return sum;

}
BigNUM BigNUM::operator*(const BigNUM& right1) {
    BigNUM sum(0);
   // BigNUM zero(0);
    BigNUM right(right1);
    BigNUM left(*this);
    int size = getSize();
    int size2 = right.getSize();

    //sum.size = (size >= right.size) ? size *2 : right.size*2 ;
    sum.resize(size + size2) ;
    int size3 = sum.getSize();
    sum.reserve(sum.getSize());
    /*sum.de();
    for (int i = 0; i < size3; i++) {
        sum[i] = 0;
    }*/
    /*int x = left.getSign();
    sum.setsign(x);*/


    for (int i = 0; i < size; ++i) {
        // if (right.array[i] == 0) continue;
        for (int j = 0; j < size2; ++j) {
            sum[i + j] += (left[i] * right[j]);
        }
    }


    for (int i = 0; i < size3; ++i) {
        if (sum[i] > 999) {
            sum[i + 1] += sum[i] / 1000;
            sum[i] = sum[i] % 1000;
        }
    }

    int value = size3 - 1;
    for (int i = value; sum[i] == 0 && i >= 1; i--)
    {

        sum.resize(--size3);
       // sum.shrink_to_fit();
    }

    *this = left;



    BigNUM zero(0);
    //0
    if (this->equal(zero) || right.equal(zero))sum = zero;

    //正*正
    else if (right.getSign() == 000 && left.getSign() == 000) {
        sum.setsign(000);
        /* cout << "1" << endl;*/
         //cout << this->array[sum.size - 1] << endl << right.array[right.size - 1] << endl;
    }
    //正*負
    else if (left.getSign() == 000 && right.getSign() == 999) {
        sum.setsign(999);
        /* cout << "2" << endl;*/
    }
    //負*正
    else if (left.getSign() == 999 && right.getSign() == 000) {
        sum.setsign(999);
        /* cout << "3" << endl;*/
    }
    //負*負
    else if (left.getSign() == 999 && right.getSign() == 999) {
        sum.setsign(000);
        /*cout << "4" << endl;*/
    }
    return sum;
}
BigNUM BigNUM::operator/(const BigNUM& right1) {
    BigNUM zero(0);
    BigNUM quotient(0);//商
    BigNUM remainder(0);//餘
    BigNUM right(right1);
    BigNUM divisor(right1);
    divisor.setsign(000);

    if (this->equal(zero))
    {
        return quotient;
    }

    if (equal(divisor))
    {
        quotient = 1;
        return quotient;
    }

    remainder = *this;
    remainder.setsign(000);

    if (less(divisor))
    {
        return quotient;
    }

    int size = this->getSize();
    int divisorsize = divisor.getSize();
    int n = size - divisorsize;
    BigNUM buffer(0);
    buffer.resize(size);

    for (int i = divisorsize - 1; i >= 0; i--) //shift to left對其this有數字的最左邊
        buffer[i + n] = divisor[i];

    for (int count = 0; count < n; count++) //把左移後剩下的位置補0
        buffer[count] = 0;

    quotient.resize(size - divisorsize + 1);

    int quotientsize = quotient.getSize();

    for (int i = quotientsize - 1; i >= 0; i--)
    {
        while (buffer.less(remainder) || buffer.equal(remainder))
        {
            BigNUM temp(0);
            temp.resize(remainder.getSize());
            temp = remainder - buffer;

            remainder = temp;
            temp.de();
            quotient[i]++;
        }
        int buffersize = buffer.getSize();
        if (buffer.getSize() == 1)buffer = 0;
        else {
            for (int i = 1; i < buffersize; i++) {//從0往後推才不會改到值
                buffer[i - 1] = buffer[i];
            }
        }
        buffer.resize(buffersize - 1);
    }

    buffer.de();

    for (int i = quotientsize - 1; i > 0 && quotientsize > 1; i--)
    {
        if (quotient[i] == 0)
        {
            quotient.resize(quotientsize-1);
           // quotient.shrink_to_fit();
        }

        else
            break;
    }
    //正/正
     if (right.getSign() == 000 && this->getSign() == 000) {
        quotient.setsign(000);
        /* cout << "1" << endl;*/
         //cout << this->array[sum.size - 1] << endl << right.array[right.size - 1] << endl;
    }
    //正/負
    else if (right.getSign() == 000 && this->getSign() == 999) {
        quotient.setsign(999);
        /* cout << "2" << endl;*/
    }
    //負/正
    else if (right.getSign() == 999 && this->getSign() == 000) {
         quotient.setsign(999);
        /* cout << "3" << endl;*/
    }
    //負/負
    else if (right.getSign() == 999 && this->getSign() == 999) {
         quotient.setsign(000);
        /*cout << "4" << endl;*/
    }
    return   quotient;

}

BigNUM BigNUM::operator+(const int& num) {
    BigNUM right(num);
    BigNUM left(*this);
    return left + right;
}
BigNUM BigNUM::operator-(const int& num) {
    BigNUM right(num);
    BigNUM left(*this);
    return left - right;
}
BigNUM BigNUM::operator*(const int& num) {
    BigNUM right(num);
    BigNUM left(*this);
    return left * right;
}
BigNUM BigNUM::operator/(const int& num) {
    BigNUM right(num);
    BigNUM left(*this);
    return left / right;
}

BigNUM  operator+(const int& num, const  BigNUM& right) {//done
    BigNUM number(num);
    return number + right;
}
BigNUM  operator-(const int& num, const  BigNUM& right) {//done
    BigNUM number(num);
    return number - right;
}
BigNUM  operator*(const int& num, const  BigNUM& right) {//done
    BigNUM number(num);
    return number * right;
}
BigNUM  operator/(const int& num, const  BigNUM& right) {//done
    BigNUM number(num);
    return number / right;
}
void BigNUM::addition(BigNUM& right) {
    BigNUM left(*this);
    int size = getSize();
    int size2 = right.getSize();
    int max = (size >= size2) ? size : size2;
    int min = (size <= size2) ? size : size2;
    for (int i = 0; i < min; ++i) {//減少運算時間
        left[i] += right[i];
    }

    for (int i = 0; i < max; ++i) {
        if (left[i] > 999) {
            if (i + 1 == size)left.resize(++size);
            left[i + 1] += left[i] / 1000;
            left[i] = left[i] % 1000;
        }
    }
    *this = left;
}
void BigNUM::subtraction(BigNUM& right) {
    BigNUM left(*this);
    int size = getSize();
    int size2 = right.getSize();
    for (int i = 0; i < size2; i++)
        left[i] = left[i] - right[i];

    for (int i = size2; i < size; i++)
        left[i] = left[i];

    int i = 0;//carry = 0;
    for (i = 0; i < size ; ++i) {//減少運算時間
       // array[i] -= right.array[i];
        if (left[i] < 0) {
            left[i + 1] --;
            left[i] += 1000;
        }

    }
    int value = size - 1;
    for (int i = value; left[i] == 0 && i >= 1; i--)
    {
        left.resize(--size);
    }
    *this = left;
}
bool BigNUM::less(BigNUM& right) {
    BigNUM left(*this);
    int size = getSize();
    int size2 = right.getSize();
    if (size < size2)
        return true;
    else if (size > size2)
        return false;
    else {//=
        for (int i = size - 1; i >= 0; i--) {
            if (left[i] < right[i])return true;
            else if (left[i] > right[i])return false;
        }
    }
    return false;//equal
}//<
bool BigNUM::equal(BigNUM& right) {
    BigNUM left(*this);
    int size = getSize();
    int size2 = right.getSize();
    if (size != size2)
        return false;
    else {
        for (int i = size - 1; i >= 0; i--) {
            if (left[i] != right[i])return false;
        }
        return true;
    }
}//==
