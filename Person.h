#pragma once

#ifndef PERSON_H
#define PERSON_H

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
  
using namespace std;

/*
	总体要求：

	1、从输入中读取出name、address和address_price，构建multimap<string,map<string,int>>.
	2、统计出每个name对应的所有address（set<string>) 、address_count(int)、每个name对应的最高(int)、最低的address值(int)、最后是所有address的总值(int)。
	3、打印出每一个name对应的所有有效数据。

	构建过程：

	1、一个Person_Infor类，用于构建并保存数据 ：multimap<string,map<string,int>>。
	2、一个Person_Calculate类，用于读取Person_Infor中的数据并计算出最高和最低的address_price值，将值保存到下一个Person_Result类。
	3、一个Person_Result类，保存address（set<string>）、address_count(int)、每个name对应的最高(int)、最低的address值(int)、最后是所有address的总值(int)。
		并构建一个map<set<string>,vector<int>>.

	Person_Infor ps_infor_total(ifstream &infile);
	Person_Calculate ps_cal_total(ps_infor_total.multimap);
	Person_Result ps_res(ps_cal_total);
	print(cout,ps_res);



	总体要求：

	1、从输入中读取出name、address，构建multimap<string,string>.
	2、统计出每个name对应的所有address（set<string>).
	3、打印出每一个name对应的所有有效数据。

	构建过程：

	1、一个Person_Infor类，用于构建并保存数据 ：multimap<string,string>.
	2、一个Person_Calculate类，用于构建一个set<string>,然后构建一个map<string,set<string>>.
	3、打印。

	Person_Infor ps_infor_total(istream &infile);
	Person_Calculate ps_cal_total(ps_infor_total);
	cout<<ps_cal_total;

*/

class Person_Calculate;

class Person_Infor
{
	friend class Person_Calculate;
public:
	Person_Infor() = default;
	Person_Infor(ifstream &is) :name(), address(), two_string_multimap()
	{
		string ex;
		while (getline(is, ex)) {
			if(ex != "over") {
				istringstream line(ex);
				line >> name;
				line >> address;
				two_string_multimap.insert({ name, address });// 向map添加元素 《cpp primer》p384
			}
		}
	}
	Person_Infor(const Person_Infor &) = delete;
	Person_Infor(Person_Infor &&) = delete;
	multimap<string, string> map() { return two_string_multimap; }
	~Person_Infor() = default;
private:
	string name;
	string address;
	multimap<string, string> two_string_multimap;
};



class Person_Calculate
{
	friend ostream &print(ostream &,const Person_Calculate &);
public:
	Person_Calculate() = default;
	Person_Calculate(Person_Infor &p_i) :name(), address(), address_set(), name_string_set()
	{
		auto goto_map = p_i.map();
		auto search_person = goto_map.begin();
		auto search = search_person->first;
		auto beg = goto_map.lower_bound(search), end = goto_map.upper_bound(search);
		for (; beg != goto_map.end();) {
			for (; beg != end; ++beg) {
				address_set.insert({ beg->second });
			}
			--beg;
			name_string_set.insert({ beg->first, address_set });
			address_set.erase(address_set.begin(), address_set.end());
			if (end != goto_map.end()) {
				search = end->first;
				beg = goto_map.lower_bound(search);
				end = goto_map.upper_bound(search);
			}
			else
				break;
		}
	}
	~Person_Calculate() = default;
private:
	string name;
	string address;
	set<string> address_set;
	map<string, set<string>> name_string_set;
};
ostream &print(ostream &,const Person_Calculate &);

/*
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
*/

#endif //!PERSON_H








