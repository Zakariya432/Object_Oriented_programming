//Name-Zakariya Momin Mondal
//CSE-38/20

#include <iostream>
using namespace std;

class Float{
    float *array;
    int size;

    public:
    Float(){}
    Float(int S){
        size=S;
        array =new float[size];
    }
    ~Float(){
        delete[] array;
    }
    Float operator++(){
        Float temp;
        temp.size = size;
        for(int i=0; i<size; i++){
            temp.array[i] =++array[i];
        }
        return temp;
    }
    friend :: istream &operator>>(istream &in,Float &obj){
        cout<<"Enter the value of the array:"<<endl;
        for(int i=0;i<obj.size;i++){
            in>> obj.array[i];
        }
        return in;
    }
    float  &operator[](int n){
        return array[n];
    }

    friend :: ostream &operator<<(ostream &out,Float &obj){
        cout<<"Enter the elements of the array :"<<endl;
        for(int i=0;i<obj.size;i++){
            out <<obj.array[i] <<"\t";
        }
        cout<< endl;
        return out;
    }
};

int main(){
    Float a (10), b;
   cin>>a;
   b = ++a;
   cout<<b;
   b[3]=0.01;
   a[8] = 0.345;
  cout<<b[3];
  cout<<a[8];
  return 0;
}