//Name-Zakariya Momin Mondal
//CSE-38/20

#include <iostream>
using namespace std;

class Int{
    int x; //Declare a variable x of interger type

    public:
    Int(){
        x=0; //initialize the variable using Default constructor
    }

    Int(int y){
        x=y;
    }
    Int operator+(Int &s){
        Int temp;
        temp.x=x +s.x;
        return temp;
    }
    Int operator+=(Int s){
        this->x=this->x +s.x;
        return *this;
    }
    Int operator++(int){
        Int temp;
        temp.x=x++;
        return temp;
    }

    friend :: ostream &operator<<(ostream &out,Int s){
        cout<<"Output :";
        out<< s.x <<endl;
        return out;
    }
};

int main(){
    Int a(5) , b(7),c;
    c=a+b;
    a+=1;
    c+=b++;
    cout<<a;

    return 0;
}
