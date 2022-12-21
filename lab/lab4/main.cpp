#include<iostream>
#include "Person.h"

using namespace std; 

int main() {

	Person john("092142", "John", "Gucci", "664025", "+79501381908");
	Person kate("214241","Kate","Swarowski", "664025","+79541242994");
	Person nade("555411", "Nate", "Kauq", "664025", "+7954164194");
	Person john2("152522", "John", "Sick", "664025", "+79541242144");
	Person antony("092142", "Antony", "Jonson", "664025", "+79504124251");
	
	PersonList list;

	list.addItem(john);
	list.addItem(kate);
	list.addItem(nade);
	list.addItem(john2);

	list.showAllItems();

	cout << "\n\n";

	list.print();

	return 0;
}