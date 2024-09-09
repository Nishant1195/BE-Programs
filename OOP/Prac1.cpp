#include <iostream>
using namespace std;

class Complex{
    public:
        int real;
        int img;

    Complex(){
        real=0;
        img=0;
    }

    Complex operator+(Complex& c){
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    friend istream& operator>>(istream& input, Complex& c){
        cout<<"Enter Real Number: ";
        input>>c.real;
        cout<<"Enter Imaginary Number: ";
        input>>c.img;
        return input;
    }

    friend ostream& operator<<(ostream& output, const Complex& c){
        output<<c.real<<"+"<<c.img<<"i";
        return output;
    }



};

int main(){
    Complex c1, c2;

    cin >> c1 >> c2;
    Complex c3=c1+c2;

    cout<<"Sum: "<<c3<<endl;

    return 0;
}