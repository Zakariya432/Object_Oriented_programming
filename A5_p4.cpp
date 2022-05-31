#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class String
{
	char s[30];

	public:

	String()
	{
		strcpy(s, "\0"); // null string
	}

	String(char*str)
	{
		strcpy(s, str);
	}

	String operator=(String); // copying two strings!!
	String operator+(String); // concatenate strings!!
	void display();
};


String String::operator=(String s2)
{
	strcpy(s, s2.s);

	return *this; // this is a pointer that stores the address of the invocking object

	/*invocking object:

	  object that calls a function
	  e.g.

	  a.add(b); here a is the invocking object

	*/
}

String String::operator+(String s2)
{
	strcat(s, s2.s); // strcat(): concatenate strings

	return *this;
}

void String::display()
{
	cout<<s<<endl;
}


int main(void)
{
	String s1; // a null string, has not been initialized to any kind of string!!
	cout<<"Null string s1 = ";
	s1.display();
	cout<<endl;

	cout<<"Object with string constant string s2 = ";
	String s2("Well Done!!"); // object with string constant!!
	s2.display();
	cout<<endl;

	cout<<"Object with string constant s3 = ";
	String s3(" Great!!"); // object with string constant!!
	s3.display();
	cout<<endl;

	cout<<"Null string s4 = ";
	String s4;
	s4.display();
	cout<<endl;

	s1=s2; // calling the operator=() function, same as writing s1.operator=(s2);
	cout<<"Copied string s1 = ";
	s1.display();
	cout<<endl;

	s4=s2+s3; // concatenating two strings using operator+(), this is same as writing s4=s2.operator=(s3);
	cout<<"Concatenated string s4 = ";
	s4.display();
	cout<<endl;


	return 0;
}