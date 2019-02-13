#include "pch.h"
#include "Person.h"

//class  Person_Infor 

ifstream &read(ifstream &is, Person_Infor &p_i)
{
	string ex;
	while (getline(is, ex)) {
		istringstream line(ex);
		line >> p_i.name >> p_i.address;
		p_i.two_string_multimap.insert(pair<string, string>(p_i.name, p_i.address));// 向map添加元素 《cpp primer》p384
	}
	return is;
}



//class Person_Calculate

ostream  &operator<<(ostream &infor,const Person_Calculate &ps1)
{
	for (auto print_infor : ps1.name_string_set) {
		auto print_name = print_infor.first;
		auto print_set = print_infor.second;
		cout << "name  " << print_name << endl;
		for (auto address_from_name : print_set) {
			cout << "address_set   " << address_from_name << '\t';
			cout << endl;
		}
	}
	return infor;
}

