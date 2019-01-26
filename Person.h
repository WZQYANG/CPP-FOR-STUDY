#pragma once

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "pratic_func.h"

using namespace std;

class Person{
	friend  istream &read(istream &information, Person ps1);
	friend  ostream &print(ostream &information, const Person ps1);
	friend  Person add(const Person &ps1, const Person &ps2);
public:
	Person() = default;
	Person(const string &n,const string &ad) : name(n), address(ad) {}
	Person(const string &n,const string &ad, int pr_ad) :name(n), address(ad),price_address(pr_ad) {}
	Person(istream &information) { read(information, *this); }
	Person(const Person&) = default;
	Person &operator=(const Person&) = default;
    string name_information()  const{ return name; }
	string address_information() { return address; }
	Person &add_price_count_address(const Person &ps1);
	Person &change_the_most_expensive_value_address(const Person &ps1);
	Person &change_the_lowest_value_address(const Person &ps1);
	Person &first_define_exp_low_value_address();
private:
	string name;
    string address;
	int count_address = 1;
	int price_address = 0;
	int the_most_expensive_value_address = 0;
	int the_lowest_value_address = 0;
};
istream &read(istream &information, Person ps1);
ostream &print(ostream &information, const Person ps1);
Person add(const Person &p1, const Person &p2);



istream &read(istream &information, Person ps1)
{
	cin >> ps1.name >> ps1.address >>ps1.count_address>>ps1.price_address;
	ps1.the_most_expensive_value_address = ps1.price_address;
	ps1.the_lowest_value_address = ps1.price_address;
	return information;
}

ostream &print(ostream &information,  Person ps1)
{
	cout << ps1.name_information() << " " << ps1.address_information()
		<< " " << ps1.count_address << " " << ps1.price_address
		<<" "<<ps1.the_most_expensive_value_address<<" "
		<<ps1.the_lowest_value_address;
	return information;
} 



Person &Person::add_price_count_address(const Person &ps1)
{
	count_address += ps1.count_address;
	price_address += ps1.price_address;
	address += " " + ps1.address;
	return *this;
}


Person add(const Person &ps1,const Person &ps2)
{
	Person ps3 = ps1;
	ps3.add_price_count_address(ps2);
	return ps3;
}


inline Person &Person::change_the_most_expensive_value_address(const Person &ps1)
{
	if (the_most_expensive_value_address < ps1.price_address) {
		the_most_expensive_value_address = ps1.price_address;
	}
	return *this;
}

inline Person &Person::change_the_lowest_value_address(const Person & ps1)
{
	if (the_lowest_value_address > ps1.the_lowest_value_address) {
		the_lowest_value_address = ps1.the_lowest_value_address;
	}
	return *this;
}

inline Person & Person::first_define_exp_low_value_address()
{
	the_most_expensive_value_address = price_address;
	the_lowest_value_address = price_address;
	return *this;
}
