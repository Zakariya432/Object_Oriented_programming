#include<iostream>
using namespace std;

class Vector
{   
    float x, y, z;
    public:
        void create()
        {
            cout<<"\nEnter scalar values of the vector in x, y and z directions: ";
            cin>>x>>y>>z;
        }
        void modify()
        {
            int i;
            while(1)
            {
                cout<<"\nEnter value you wish to modify\n";
                cout<<"1. In x direction\n";
                cout<<"2. In y direction\n";
                cout<<"3. In z direction\n";
                cout<<"4. Exit\n";

                cout<<"Enter your choice: ";
                cin>>i;

                switch(i)
                {
                    case 1: cout<<"\nEnter new value in x direction: ";
                            cin>>x;
                            break;
                    case 2: cout<<"\nEnter new value in y direction: ";
                            cin>>y;
                            break;
                    case 3: cout<<"\nEnter new value in z direction: ";
                            cin>>z;
                            break;
                    case 4: return;
                }

            }
        }
        void multiply()
        {
            int scalar;
            cout<<"\nEnter scalar value to multiply with: ";
            cin>>scalar;
            x=x*scalar;
            y=y*scalar;
            z=z*scalar;
        }
        void display()
        {
            cout<<"\nThe vector is: ("<<x<<", "<<y<<", "<<z<<")\n";
        }
        void add()
        {
            int x2, y2, z2;
            cout<<"\nEnter second vector values to perform addition: ";
            cin>>x2>>y2>>z2;
            x=x+x2;
            y=y+y2;
            z=z+z2;
        }
};
int main()
{   
    system("CLS");
    int choice;
    Vector vect;
    
    while(1)
    {
        cout<<"\nPLAYING WITH VECTORS\n";
        cout<<"1. Create the vector\n";
        cout<<"2. Modify the vector\n";
        cout<<"3. Multiply with scalar\n";
        cout<<"4. Display vector\n";
        cout<<"5. Add two vectors\n";
        cout<<"6. Exit\n";
        cout<<"\nEnter you choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: vect.create();
                    break;
            case 2: vect.modify();
                    break;
            case 3: vect.multiply();
                    break;
            case 4: vect.display();
                    break;
            case 5: vect.add();
                    break;
            case 6: exit(0);

        }
    }
    return 0;
}