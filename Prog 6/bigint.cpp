// Name:            Min Hein
// Class:           CECS 325-02
// Project Name:    Prog 6 - BigInt
// Due Date:        May / 8 / 2025

// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <climits>

using namespace std;

class BigInt
{
    private:
        vector<char> v; //<- notice this is a vector of char, not int

    public:
        // Constructors
        BigInt();
        BigInt(int);
        BigInt(string);

        // Arithmetic operators
        BigInt operator+ (BigInt);  // addition
        BigInt operator* (BigInt);  // multiplication
        BigInt operator++(int);     // post-increment
        BigInt operator++();        // pre-increment
        BigInt operator-(BigInt);   // subtraction
        BigInt operator/(BigInt);   // division
        BigInt operator%(BigInt);   // modulo


        // Utility methods
        int size();
        void print() const;

        // Recursive methods
        BigInt fibo(BigInt);
        BigInt fact(BigInt);

        //Output operator
        friend ostream& operator<<(ostream&, const BigInt&);

        friend bool operator==(const BigInt& a, const BigInt& b);
        friend bool operator<(const BigInt& a, const BigInt& b);
        friend bool operator<=(const BigInt& a, const BigInt& b);
        friend bool operator>=(const BigInt& a, const BigInt& b);

        friend BigInt operator+(int, BigInt);
        friend BigInt operator+(int lhs, BigInt rhs);



};

BigInt::BigInt() // Constructors
{
    v.push_back(0);
}

BigInt::BigInt(int num) // Constructors
{
    if (num == 0) v.push_back(0);
    else
    {
        while (num > 0) 
        {
            v.push_back(num%10);
            num /= 10;
        }
    }
}

BigInt::BigInt(string str) // Constructors
{
    for (int i = str.length() - 1; i >= 0; i --)
    {
        if (isdigit(str[i]))
        {
            v.push_back(str[i] - '0');
        }
    }
}

BigInt BigInt::operator+(BigInt other) // Arithmetic operators - addition
{
    BigInt result;
    result.v.clear();

    int carry = 0, n = max(v.size(), other.v.size());
    for (int i = 0; i < n || carry; i++)
    {
        int d1 = (i < v.size()) ? v[i] : 0;
        int d2 = (i < other.v.size()) ? other.v[i] : 0;
        int sum = d1 + d2 + carry;
        
        result.v.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;
}

BigInt operator+(int lhs, BigInt rhs) // for adding int and bigint
{
    return BigInt(lhs) + rhs;
}

BigInt BigInt::operator*(BigInt other) // Arithmetic operators - multiplication
{
    BigInt result;
    result.v = vector<char>(v.size() + other.v.size(), 0);

    for (int i = 0; i < v.size(); i++)
    {
        int carry = 0;
        for (int j = 0; j < other.v.size() || carry; j++)
        {
            int prod = result.v[i + j] + v[i] * (j < other.v.size() ? other.v[j] : 0) + carry;
            result.v[i + j] = prod % 10;
            carry = prod / 10;
        }
    }

    while (result.v.size() > 1 && result.v.back() == 0)
    {
        result.v.pop_back();
    }

    return result;
}

BigInt BigInt::operator++(int) // Arithmetic operator - post-increment
{
    BigInt temp = *this;
    *this = *this + BigInt(1);
    return temp;
}

BigInt BigInt::operator++() // Arithmetic operator - pre-increment
{
    *this = *this + BigInt(1);
    return *this;
}

BigInt BigInt::operator-(BigInt other) // Arithmetic operator - subtraction
{
    BigInt result;
    result.v.clear();

    int borrow = 0;
    for (int i = 0; i <v.size(); i++)
    {
        int d1 = v[i];
        int d2 = (i < other.v.size()) ? other.v[i] : 0;
        int diff = d1 - d2 - borrow;

        if (diff < 0) 
        {
            diff += 10;
            borrow = 1;
        }

        else
        {
            borrow = 0;
        }

        result.v.push_back(diff);
    }

    while (result.v.size() > 1 && result.v.back() == 0)
        result.v.pop_back();
    
    return result;
}

BigInt BigInt::operator/(BigInt other) // Arithmetic opeartor - division
{
    if (other == BigInt(0))
    {
        cerr << "Error: Division by 0";
        return BigInt(0);
    }

    BigInt count(0);
    BigInt temp = *this;

    while (temp >= other)
    {
        temp = temp - other;
        count = count + BigInt(1);
    }

    return count;
}

BigInt BigInt::operator%(BigInt other) // Arithmetic operator - Modulo
{
    if (other == BigInt(0))
    {
        cerr << "Error: Modulo by zero\n";
        return BigInt(0);
    }
    
    BigInt temp = *this;

    while (temp >= other)
    {
        temp = temp - other;
    }

    return temp;
}

bool operator==(const BigInt& a, const BigInt& b) // Comparison
{
    if (a.v.size() != b.v.size()) return false;
    for (int i = 0; i < a.v.size(); i++) {
        if (a.v[i] != b.v[i]) return false;
    }
    return true;
}

bool operator<(const BigInt& a, const BigInt& b) // Comparison
{
    if (a.v.size() != b.v.size())
        return a.v.size() < b.v.size();

    for (int i = a.v.size() - 1; i >= 0; i--) {
        if (a.v[i] != b.v[i])
            return a.v[i] < b.v[i];
    }
    return false; // they're equal
}

bool operator<=(const BigInt& a, const BigInt& b) // Comparison
{
    return (a < b) || (a == b);
}

bool operator>=(const BigInt& a, const BigInt& b) // Comaprison
{
    return !(a < b);
}

void BigInt::print() const // Utility
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << (int)v[i];
    }
}

ostream& operator<<(ostream& out, const BigInt& b) //Output method
{
    int n = b.v.size();
    
    if (n <= 12)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            out << (int)b.v[i];
        }
    }
    
    else
    {
        out << fixed << setprecision(6);
        double mantissa = 0.0;
        int count = 0;
        for (int i = n - 1; i >= max(0, n - 7); i--) 
        {
            mantissa = mantissa * 10 + b.v[i];
            count++;
        }
        mantissa /= pow(10, count - 1);

        out << mantissa << "e" << (n-1);
    }

    return out;
}

BigInt fibo_tail(BigInt n, BigInt a, BigInt b)
{
    if (n == BigInt(0)) return a;
    if (n == BigInt(1)) return b;

    return fibo_tail(n - BigInt(1), b, a+b);
}

BigInt BigInt::fibo(BigInt n)
{
    return fibo_tail(n, BigInt(0), BigInt(1));
}

BigInt fact_tail(BigInt n, BigInt acc)
{
    if (n == BigInt(0) || n == BigInt(1))
        return acc;

    return fact_tail(n - BigInt(1), acc * n);
}

BigInt BigInt::fact(BigInt n)
{
    return fact_tail(n, BigInt(1));
}

void testUnit()
{
    int space = 10;
    cout << "TestUnit:\n"<<flush;
    system("whoami");
    system("date");

    // initialize variables
    BigInt n1(25);
    BigInt s1("25");
    BigInt n2(1234);
    BigInt s2("1234");
    BigInt n3(n2);
    BigInt fibo(12345);
    BigInt fact(50);
    BigInt imax = INT_MAX;
    BigInt big("9223372036854775807");

    // display variables
    cout << "n1(int)    :"<<setw(space)<<n1<<endl;
    cout << "s1(str)    :"<<setw(space)<<s1<<endl;
    cout << "n2(int)    :"<<setw(space)<<n2<<endl;
    cout << "s2(str)    :"<<setw(space)<<s2<<endl;
    cout << "n3(n2)     :"<<setw(space)<<n3<<endl;
    cout << "fibo(12345):"<<setw(space)<<fibo<<endl;
    cout << "fact(50)   :"<<setw(space)<<fact<<endl;
    cout << "imax       :"<<setw(space)<<imax<<endl;
    cout << "big        :"<<setw(space)<<big<<endl;
    cout << "big.print(): "; big.print(); cout << endl;
    cout << n2 << "/"<< n1<< " = "<< n2/n1 <<" rem "<<n2%n1<<endl; //something wrong, check the division and modulo
    cout << "fibo("<<fibo<<") = "<<fibo.fibo(fibo) << endl;
    cout << "fact("<<fact<<") = "<<fact.fact(fact) << endl;
    cout << "10 + n1 = " << 10+n1 << endl;
    cout << "n1 + 10 = " << n1+10 << endl;
    cout << "(n1 == s1)? --> "<<((n1==s1)?"true":"false")<<endl;
    cout << "n1++ = ? --> before:"<<n1++<<" after:"<<n1<<endl;
    cout << "++s1 = ? --> before:"<<++s1<<" after:"<<s1<<endl;
    cout << "s2 * big = ? --> "<< s2 * big<<endl;
    cout << "big * s2 = ? --> "<< big * s2<<endl;
}

int main()
{
    testUnit();
    return 0;
}
