#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;


class books
{
	char* author[10]; // array of pointers to character
	char* title[10];
	float price[10];
	char* publisher[10];
	int stockPos[10];

	void modify(int index, float cost)
	{
		cout<<"Price updated successfully!!!\n\n";
		price[index]=cost;
	}

	public:
	static int successfulT[10]; //successful transactions
	static int unsuccessfulT[10]; //unsuccessful transactions

	books()
	{
		for(int i=0; i<10; i++)
		{
			author[i]=new char[30];
			title[i]=new char[30];
			publisher[i]=new char[30];
			strcpy(author[i], "noauthor");
			strcpy(title[i], "notitle");
			price[i]=0.0;
			strcpy(publisher[i], "nopublisher");
			stockPos[i]=-1;
		}
	}


	~books()
	{
		for(int i=0; i<10; i++)
		{
			delete author[i];
			delete title[i];
			delete publisher[i];
		}
	}
	
	void getDetails();
	void searchBooks(char*, char*);
	void getQuantity(int);
	void display(int);
	void recordTransactions(char*, int); // to store the successful and unsuccessful transactions
	void update(char*, char*);
	void displayBooks();
	

};

int books::unsuccessfulT[10]; // creating memory for unsuccessfulT
int books::successfulT[10]; // creating memory for successfulT


void books::displayBooks()
{
	cout<<"\n\nDETAILS OF BOOKS.....\n\n";

	for(int i=0; i<10; i++)
	{
		cout<<"Book title: "<<title[i]<<endl;
		cout<<"Book author: "<<author[i]<<endl;
		cout<<"Price: "<<price[i]<<endl;
		cout<<"Publisher: "<<publisher[i]<<endl;
		cout<<"Stock position: "<<stockPos[i]<<endl;
		cout<<"Successful transactions: "<<successfulT[i]<<endl;
		cout<<"Unsuccessful transactions: "<<unsuccessfulT[i]<<endl<<endl;
	}

}

void books::update(char*t, char*a)
{

	for(int i=0; i<10; i++)
	{
		if((strcmp(title[i], t)==0) && (strcmp(author[i], a)==0))
		{
			float amt;
			cout<<"Enter new price: ";
			cin>>amt;

			modify(i, amt);
			return;
		}
	}

	cout<<"Update unsuccessful!!\n\n";
}


void books::getDetails()
{
	for(int i=0; i<10; i++)
	{
		cout<<"BOOK "<<i+1<<endl;
		cout<<"Book title: ";
		cin>>title[i];
		cout<<"Author: ";
		cin>>author[i];
		cout<<"Price: ";
		cin>>price[i];
		getchar();
		cout<<"Publishher: ";
		cin>>publisher[i];
		cout<<"Stock position: ";
		cin>>stockPos[i];
		getchar();
		

	}

}

void books::searchBooks(char*t, char*a)
{
	for(int i=0; i<10; i++)
	{
		if((strcmp(title[i], t)==0) && (strcmp(author[i], a)==0))
		{
			display(i); // display the book details
			return;
		}
	}

	cout<<"\n\nbook out of stock!!\n\n";
}

void books::display(int index)
{

	cout<<"Book title: "<<title[index]<<endl;
	cout<<"Author: "<<author[index]<<endl;
	cout<<"Price: "<<price[index]<<endl;
	cout<<"Publisher: "<<publisher[index]<<endl;
	cout<<"Stock position: "<<stockPos[index]<<endl;
	getQuantity(index);
}

void books::getQuantity(int index)
{
	int quantity;
	cout<<"Enter number of copies: ";
	cin>>quantity;

	if(quantity>stockPos[index])
	{
		cout<<"Required copies not in stock!!\n\n";
		recordTransactions("unsuccessful", index);
		return;
	}

	else
	{
		cout<<"Total cost of "<<quantity<<" copies: "<<quantity*price[index]<<endl;
		stockPos[index]-=quantity; // updating the stock position
		recordTransactions("successful", index);
	}

}

void books::recordTransactions(char*status, int index)
{
	if(strcmp(status, "successful")==0)
		successfulT[index]++;
	else
		unsuccessfulT[index]++;
}

int main(void)
{
	books b;
	char*author, *title;
	int opt;

	author=new char[30];
	title=new char[30];


	cout<<"Enter details of the books:\n";
	b.getDetails();

	while(1)
	{
		cout<<"\n\n---menu---\n\n";
		cout<<"1. Buy book.\n";
		cout<<"2. Update price of a book.\n";
		cout<<"3. Display books.\n";
		cout<<"4. Exit.\n";
		cin>>opt;

		switch(opt)
		{
			case 1:
				cout<<"Enter book you want to buy: ";
				cout<<"Book title: ";
				cin>>title;
				cout<<"Book author: ";
				cin>>author;
				b.searchBooks(title, author);
				break;

			case 2:
				cout<<"Enter book title: ";
				cin>>title;
				cout<<"Enter book author: ";
				cin>>author;

				b.update(title, author);
				break;

			case 3:
				b.displayBooks(); // display everything, successful transactions, etc....
				break;

			case 4:
				exit(0);

			default:
				cout<<"\n\ninvalid option!!!\n\n";
		}

	}


	
	delete author;
	delete title;

	return 0;
}
