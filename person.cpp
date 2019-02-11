#include "pch.h"
#include "Person.h"


ostream  &print(ostream &infor,const Person_Calculate &ps1)
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

