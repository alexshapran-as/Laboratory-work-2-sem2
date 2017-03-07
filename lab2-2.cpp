#include <iostream> 
#include <string.h>
#include <conio.h>
using namespace std;

class KFC
{
	char name[64]; 
	float price;
public:
	KFC(char name_p[], float price_p)
	{
		for(unsigned int i = 0; i < 64; ++i) name[i] = name_p[i];
		price = price_p;
	}
	double get()
	{
		return price;
	}
	void print()
	{
		cout << endl << "Order name: " << name << "  Price: " << price;
	}
};

int main(void)
{
	int n = 0;
	float p = 0.0;
	char string[64];

	cout << endl << "The number of orders: ";
	cin >> n;

	KFC **ppKFC; 
	ppKFC = new KFC*[n];

	for (unsigned int i = 0; i < n; ++i)
	{
	cout << "Order #" << (i + 1) << endl << "Name: ";
	fflush(stdin); 
	cin.getline(string, 64);
	cout << "Price: "; 
	cin >> p;
	if ( p < 0 )
	 { 
	 	cout << "Error: price can't be negative! Please enter the order again" << endl;
	 	p = 0;
	 	--i;
	  }
	else  ppKFC[i] = new KFC(string, p);  
	}

	for (unsigned int i = 0; i < n; ++i) ppKFC[i]->print();

	for (unsigned int i = 0; i < n-1; ++i)  p += ppKFC[i]->get(); 

	cout << endl << "Full price of order: " << p;

	for (unsigned int i = 0; i < n; ++i) delete ppKFC[i]; 
	delete []ppKFC;

	cout << endl << endl << "Press any button to exit the program!" << endl;

	_getch();
	return 0;
}