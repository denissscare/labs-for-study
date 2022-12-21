#include <iostream>
#include "Person.h"
#include <stdlib.h>

#define UNDEFINE "Undefine"


Person::Person(std::string ID, std::string firstName, std::string secondName, std::string postcode, std::string phoneNumber) :
								ID(ID), firstName(firstName), secondName(secondName), postcode(postcode), phoneNumber(phoneNumber){}
Person::Person() {
	ID = "000000";
	firstName = UNDEFINE;
	secondName = UNDEFINE;
	postcode = UNDEFINE;
	phoneNumber = UNDEFINE;
}

void Person::setID(std::string ID) { this->ID = ID; }
void Person::setFirstName(std::string firstName) { this->firstName = firstName; }
void Person::setSecondName(std::string secondName) { this->secondName = secondName; }
void Person::setPostcode(std::string postcode) { this->postcode = postcode; }
void Person::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }

std::string Person::getID() { return ID; }
std::string Person::getFirstName() { return firstName; }
std::string Person::getSecondName() { return secondName; }
std::string Person::getPostcode() { return postcode; }
std::string Person::getPhoneNumber() { return phoneNumber; }




void Person::showInfo() {
	std::cout << "\n\n";
	std::cout << "\tID: " << ID << std::endl;
	std::cout << "\tFirst name: " << firstName << std::endl;
	std::cout << "\tSecond name: " << secondName << std::endl;
	std::cout << "\tPostcode: " << postcode << std::endl;
	std::cout << "\tPhone number: " << phoneNumber << std::endl;
	std::cout << "\n\n";
}




//Определение для класса PersonList
void PersonList::sortByID() { sortAscending(arr_ID); }
void PersonList::sortByFirstName() { sortAscending(arr_firstName); }
void PersonList::sortBySecondName() { sortAscending(arr_secondName); }
void PersonList::sortByPostcode() { sortAscending(arr_postcode); }
void PersonList::sortByPhoneNumber() { sortAscending(arr_phoneNumber); }


void PersonList::sortByIDDown() { sortDescending(arr_ID); }
void PersonList::sortByFirstNameDown() { sortDescending(arr_firstName); }
void PersonList::sortBySecondNameDown() { sortDescending(arr_secondName); }
void PersonList::sortByPostcodeDown() { sortDescending(arr_postcode); }
void PersonList::sortByPhoneNumberDown() { sortDescending(arr_phoneNumber); }



void PersonList::print() {
	for (int i = 0; i < arr_.size(); i++){
		arr_[i].showInfo();
	}
}
void PersonList::addItem(Person item) { 
	arr_.push_back(item);
	arr_ID.push_back(item.getID());
	arr_firstName.push_back(item.getFirstName());
	arr_secondName.push_back(item.getSecondName());
	arr_postcode.push_back(item.getPostcode());
	arr_phoneNumber.push_back(item.getPhoneNumber());
}

void PersonList::sortAscending(std::vector<std::string> &vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j] > vec[j + 1]) {
				std::string temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}

void PersonList::sortDescending(std::vector<std::string> &vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j] < vec[j + 1]) {
				std::string temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}



void PersonList::getInfoByIndex(int index) { arr_[index].showInfo(); }
void PersonList::getInfoByID(std::string ID){
	int count = 0;
	for (int i = 0; i < arr_.size(); i++){
		if (ID == arr_[i].getID()) {
			count++;
			arr_[i].showInfo();
		}
	}
	if (count == 0) {
		std::cout << "No matches" << std::endl;
	}
}

void PersonList::getInfoByFirstName(std::string firstName){
	int count = 0;
	for (int i = 0; i < arr_.size(); i++) {
		if (firstName == arr_[i].getFirstName()) {
			count++;
			arr_[i].showInfo();
		}
	}
	if (count == 0) {
		std::cout << "No matches" << std::endl;
	}
	else{
		std::cout << "Matches: " << count << std::endl;
	}
}

void PersonList::getInfoBySecondName(std::string secondName){
	int count = 0;
	for (int i = 0; i < arr_.size(); i++) {
		if (secondName == arr_[i].getSecondName()) {
			count++;
			arr_[i].showInfo();
		}
	}
	if (count == 0) {
		std::cout << "No matches" << std::endl;
	}
	else {
		std::cout << "Matches: " << count << std::endl;
	}
}

void PersonList::getInfoByPhoneNumber(std::string phoneNumber){
	int count = 0;
	for (int i = 0; i < arr_.size(); i++) {
		if (phoneNumber == arr_[i].getPhoneNumber()) {
			count++;
			arr_[i].showInfo();
		}
	}
	if (count == 0) {
		std::cout << "No matches" << std::endl;
	}
}

void PersonList::getInfoByPostcode(std::string postcode){
	int count = 0;
	for (int i = 0; i < arr_.size(); i++) {
		if (postcode == arr_[i].getPostcode()) {
			count++;
			arr_[i].showInfo();
		}
	}
	if (count == 0) {
		std::cout << "No matches" << std::endl;
	}
	else {
		std::cout << "Matches: " << count << std::endl;
	}
}

void PersonList::showAllItems() {
	std::cout << "\nIDs: "; 
	for (int i = 0; i < arr_.size(); i++)
	{
		std::cout << arr_ID[i] << ", ";
	}
	std::cout << "\nFirst names: ";
	for (int i = 0; i < arr_.size(); i++)
	{
		std::cout << arr_firstName[i] << ", ";
	}
	std::cout << "\nSecond names: ";
	for (int i = 0; i < arr_.size(); i++)
	{
		std::cout << arr_secondName[i] << ", ";
	}
	std::cout << "\nPostcodes: ";
	for (int i = 0; i < arr_.size(); i++)
	{
		std::cout << arr_postcode[i] << ", ";
	}
	std::cout << "\nPhone numbers: ";
	for (int i = 0; i < arr_.size(); i++)
	{
		std::cout << arr_phoneNumber[i] << ", ";
	}
	std::cout << std::endl;
}

