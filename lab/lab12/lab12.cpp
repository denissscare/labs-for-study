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

	char str[] = "������� ������� ��� ������ � 1661 ���� �� ������ ������ ������.� 1686 ���� ��� �������� ������ ������.� 1764 ���� � ����� ��������� ��������.";
	cout << "\nT����: " << str << endl;

	find(str, '�'); 

	return 0;
}