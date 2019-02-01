#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map> 
#include "pratic_func.h"
#include "Person.h"
#include "windows.h"

using namespace std;

int main()
{
	/**
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

	string str("91111111111");
	stringstream ss;
	int digit;
	ss << str;
	ss >> digit;
	cout << digit;
	cout << endl;

	MessageBoxA(NULL, "C++", "HUAN YING", NULL);

	*/


	//class Person 

	Person ps1("peter", "wuhan", 100);
	Person ps2("peter", "shanghai", 2000);
	Person ps3("peter", "wuhan", 300);

	if (ps1.name_infor() == ps2.name_infor()) {	
		ps1 += ps2;
	}
	ps1 += ps3;
	cout << ps1 << endl;

	return 0;
}


