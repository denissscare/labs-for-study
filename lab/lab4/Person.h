#include <string>
#include <vector>
#include <iostream>


class Person {
private:
	std::string ID;
	std::string firstName;
	std::string secondName;
	std::string postcode;
	std::string phoneNumber;
public:
	Person(std::string,std::string,std::string,std::string, std::string);
	Person();

	void setID(std::string);
	void setFirstName(std::string);
	void setSecondName(std::string);
	void setPostcode(std::string);
	void setPhoneNumber(std::string);

	std::string getID();
	std::string getFirstName();
	std::string getSecondName();
	std::string getPostcode();
	std::string getPhoneNumber();

	void showInfo();
};

class PersonList {
private:
	std::vector<Person> arr_;
	std::vector<std::string> arr_ID;
	std::vector<std::string> arr_firstName;
	std::vector<std::string> arr_secondName;
	std::vector<std::string> arr_postcode;
	std::vector<std::string> arr_phoneNumber;

public:
	void addItem(Person);
	void print();
	void getInfoByIndex(int);
	void getInfoByID(std::string);
	void getInfoByFirstName(std::string);
	void getInfoBySecondName(std::string);
	void getInfoByPhoneNumber(std::string);
	void getInfoByPostcode(std::string);

	void sortAscending(std::vector<std::string> &vec);
	void sortDescending(std::vector<std::string> &vec);

	void sortByID();
	void sortByFirstName();
	void sortBySecondName();
	void sortByPostcode();
	void sortByPhoneNumber();

	void sortByIDDown();
	void sortByFirstNameDown();
	void sortBySecondNameDown();
	void sortByPostcodeDown();
	void sortByPhoneNumberDown();

	void showAllItems();
};