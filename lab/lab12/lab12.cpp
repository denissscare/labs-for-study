#include<iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

void find(char str[], char letter) {
	char* tmp_char;
	tmp_char = strtok(str, " ");
	int count;
	while (tmp_char != NULL) {
		for(char i : tmp_char)
		tmp_char = strtok(NULL, " ");   
	}
	cout << count << endl;
}
void display() {

}

int main() {
	setlocale(LC_ALL, "Russian");

	vector<vector<string>> arr;
	arr.push_back(vector<string>()); 

	char str[] = "Иркутск основан как острог в 1661 году на правом берегу Ангары.В 1686 году ему присвоен статус города.С 1764 года – центр Иркутской губернии.";
	cout << "\nTекст: " << str << endl;

	find(str, 'о'); 

	return 0;
}