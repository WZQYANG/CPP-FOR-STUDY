#include "pch.h"
#include "Person.h"

using namespace std;

//class  Person_Infor 

ifstream &read(ifstream &is, Person_Infor &p_i)
{
	string ex;
	while (getline(is, ex)) {
		if (ex != "OVER") {
			istringstream line(ex);
			line >> p_i.name;
			line >> p_i.address;
			line >> p_i.price;
			p_i.name_place_mmp.insert(pair<string, string>(p_i.name, p_i.address));// 向map添加元素 《cpp primer》p384
			p_i.name_price_mmp.insert(pair<string, int>(p_i.name, p_i.price));
		}
		else
			break;
	}
	return is;
}



//class Person_Calculate
Person_Calculate::Person_Calculate(Person_Infor & p_i)
{
	
	if (p_i.func_name_place().size() != 0) {    // can not dereference map/set iterator !
		multimap<string, string> n_place = p_i.func_name_place();
		multimap<string, string>::iterator n_place_iter = n_place.begin();
		string n_place_name = n_place_iter->first;
		multimap<string, string>::iterator beg = n_place.lower_bound(n_place_name),
			end = n_place.upper_bound(n_place_name);
		for (; beg != n_place.end();) {
			for (; beg != end; ++beg) {
				address_set.insert({ beg->second });
			}
			--beg;
			name_address_set_mp.insert(pair<string, set<string>>(beg->first, address_set));
			address_set.erase(address_set.begin(), address_set.end());
			if (end != n_place.end()) {
				n_place_name = end->first;
				beg = n_place.lower_bound(n_place_name);
				end = n_place.upper_bound(n_place_name);
			}
			else
				beg = n_place.end();
		}
	}

	if (p_i.func_name_price().size() != 0) { 
		multimap<string, int> n_price = p_i.func_name_price();
		multimap<string, int>::iterator n_price_iter = n_price.begin();
		string n_price_name = n_price_iter->first;
		multimap<string, int>::iterator beg = n_price.lower_bound(n_price_name),
			end = n_price.upper_bound(n_price_name);
		for (; beg != n_price.end();) {
			address_Low_price = beg->second;
			for (; beg != end; ++beg) {
				if (address_Low_price > beg->second) {
					address_Low_price = beg->second;
				}
				if (address_Exp_price < beg->second) {
					address_Exp_price = beg->second;
				}
				address_total_price += beg->second;
			}
			price_vect.push_back(address_Low_price);
			price_vect.push_back(address_Exp_price);
			price_vect.push_back(address_total_price);
			--beg;
			name_price_vec_map.insert(pair<string, vector<int>>(beg->first, price_vect));
			price_vect.resize(0);
			if (end != n_price.end()) {
				n_price_name = end->first;
				beg = n_price.lower_bound(n_price_name);
				end = n_price.upper_bound(n_price_name);
			}
			else
				beg = n_price.end();
		}
	}
}
 
ostream  &operator<<(ostream &infor, const Person_Calculate &ps1)
{
	auto print_name_address_infor = ps1.name_address_set_mp.begin();
	auto print_name_price_infor = ps1.name_price_vec_map.begin();
	while(print_name_address_infor != ps1.name_address_set_mp.end()) {
		string print_name = print_name_address_infor->first;
		set<string> print_set = print_name_address_infor->second;
		cout << "name  " << print_name << endl;
		cout << "address_set   ";
		for (string address_from_name : print_set) {
			cout << address_from_name << '\t';
		}
		cout << endl;
		if (print_name_price_infor != ps1.name_price_vec_map.end()) {
			cout << "The Low_price   " << (print_name_price_infor->second)[0]<<'\t';
			cout << "The Exp_price    " << (print_name_price_infor->second)[1] << '\t';
			cout << "The total_price    " << (print_name_price_infor->second)[2] << '\t';
			cout << '\n' << endl;
			++print_name_price_infor;
		}
		++print_name_address_infor;
	}

	return infor;
}
