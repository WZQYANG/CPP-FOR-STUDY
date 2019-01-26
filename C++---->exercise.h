#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "pratic_func.h"
#include "Person.h"
#include <sstream>
#include "windows.h"

using namespace std;

int main()
{
	
	//STRING


	//const string 
	const string s("Hello World");


	//string s1
	string s1; //string s1 = s;

	push_back_self(s,s1);
	toupper_self(s1);
	nonempty_lower_upper(s1);
	os_upp_low_bla(s1);
	os_dig1(s1);
	


	// VECTOR


	// const vector<int>vi
	const vector<int>vi(9, 10);


	//vector<int>vi1
	vector<int>vi1(vi);
	vector<int>vi2{ 1, 23, 21, 111, 500, 45 };

	add_sum_one_to_hundred(vi1);
	mult_i(vi1);
	os_sum1_sum2_dig2(vi1);
	os_change_order(vi1);
	os_dig3(vi1);
	os_order_question(vi2);


	// const vector<string>
	const string cs("First Study for c++");


	//vector<string>vs1
	vector<string> vs1;

	os_push_back_self(cs, vs1);	

	//vector<string>vs2
	vector<char>vc1;

	os_vector_char(cs,vc1);


	//class Person 

	Person ps1("peter","wuhan", 100);
	Person ps2("peter","shanghai", 2000);
	Person ps3("peter","wuhan", 300);
	

	ps1.first_define_exp_low_value_address();
	ps2.first_define_exp_low_value_address();
	if (ps1.name_information() == ps2.name_information() 
		&& ps2.name_information() == ps3.name_information()) {
		ps1.change_the_lowest_value_address(ps2);
		ps1.change_the_most_expensive_value_address(ps2).change_the_most_expensive_value_address(ps3);
	    ps1.add_price_count_address(ps2).add_price_count_address(ps3);
		
	}
	print(cout, ps1) << endl;
	

	
	string str("91111111111");
	stringstream ss;
	int digit;
	ss << str;
	ss >> digit;
	cout << digit;
	cout << endl;
	
	MessageBoxA(NULL, "C++", "HUAN YING", NULL);

	return 0;
}


