#pragma once

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "pratic_func.h"

using namespace std;

class Person{
	friend  istream &operator>>(istream &, Person &);
	friend  ostream &operator<<(ostream &, const Person &);
	friend  Person operator+(const Person &, const Person &);
	friend  bool operator==(const Person &, const Person &);
	friend  bool operator!=(const Person &, const Person &);
public:
	Person() = default;
	Person(const string &n,const string &ad) : name(n), address(ad) {}
	Person(const string &n,const string &ad, int pr_ad) :name(n), address(ad),
		 address_price(pr_ad),the_most_exp_price(pr_ad), the_low_price(pr_ad),total_price(pr_ad) {}
	Person(istream &) {}
	Person(const Person&);
	Person(Person&&) = default; 
	Person &operator=(const Person&);
	Person &operator+=(const Person&);
	Person &operator=(Person&&) = default;
    string name_infor() const{ return name; }
	string address_infor() const { return address; }
	~Person() = default;
private:
	void change_the_most_exp_low_value_address_price(const Person &ps1);
	string name;
	string address;
	int address_count = 1;	
	int address_price = 0,the_most_exp_price = 0 ,the_low_price = 0 ,total_price = 0;
}; 
istream &operator>>(istream &, Person &);
ostream &operator<<(ostream &, const Person &);
Person operator+(const Person &, const Person &);
bool operator==(const Person &, const Person &);
bool operator!=(const Person &, const Person &);
 



istream &operator>>(istream &infor, Person &ps1)
{
	cin >> ps1.name >> ps1.address >> ps1.address_count >> ps1.address_price;
	return infor;
}

ostream &operator<<(ostream &infor, const Person &ps1)
{
	cout << "NAME   "<< ps1.name_infor() << endl;
	cout << "IN   " << ps1.address_infor() << endl;
	cout << "TOTAL COUNT   " << ps1.address_count << endl;
	cout << "TOTAL PRICE   " << ps1.total_price << endl;
	cout << "MOST EXPENSIVE   " << ps1.the_most_exp_price << endl;
	cout << "lOWEST   " << ps1.the_low_price << endl;
	return infor;
}

Person operator+(const Person &ps1, const Person &ps2)
{
	Person sum = ps1;
	sum += ps2;
	return sum;
}

bool operator==(const Person &ps1, const Person &ps2)
{
	return ps1.name == ps2.name &&
		   ps1.address_count == ps2.address_count &&
	       ps1.address_price == ps2.address_price;
}

bool operator!=(const Person &ps1, const Person &ps2)
{
	return !(ps1 == ps2);
}

inline Person::Person(const Person &ps1):
	name(ps1.name),
	address(ps1.address),
	address_count(ps1.address_count),
	address_price(ps1.address_price),
	the_most_exp_price(ps1.the_most_exp_price),
	the_low_price(ps1.the_low_price), 
	total_price(ps1.total_price)
	{}

inline Person & Person::operator=(const Person &ps1)
{
	name = ps1.name;
	address = ps1.address;
	address_count = ps1.address_count;
	address_price = ps1.address_price;
	the_most_exp_price = ps1.the_most_exp_price;
	the_low_price = ps1.the_low_price;
	total_price = ps1.total_price;
	return *this;
}

inline Person & Person::operator+=(const Person &ps1)
{
	address_count += ps1.address_count;
	if (address.find(ps1.address)>address.size()) {
		address += " " + ps1.address;
	}
	total_price += ps1.address_price;
	this->change_the_most_exp_low_value_address_price(ps1);
	return *this;
}

inline void Person::change_the_most_exp_low_value_address_price(const Person & ps1)
{
	if(the_most_exp_price < ps1.address_price) {
		the_most_exp_price = ps1.address_price;
	}

	if(the_low_price > ps1.address_price) {
	the_low_price = ps1.address_price;
	}
}





