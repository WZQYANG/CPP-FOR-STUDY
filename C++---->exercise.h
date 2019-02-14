#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "pratic_func.h"
#include "Person.h"
#include "windows.h"

using namespace std;

int main()
{
	ifstream is("C://Users//strong//Desktop//exr.txt");
	Person_Infor ps1(is);
	runPerson(ps1);
	return 0;


	/*
	string ss;
	if (is.is_open()) {
		cout << "ok" << endl;
		while (getline(is, ss)) {
			stringstream t;
			string m;
			t << ss;
			t >> m;
			cout << m << endl;
		}
	}
	else if(!is.is_open()) {
		cout << "no" << endl;
	}


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

	


	//class Person 

	Person ps1("peter", "wuhan",100);             //第一个构造函数
	Person ps2("peter", "shanghai", 2000);    //第二个构造函数
	Person ps3("peter", "wuhan", 300);        // 同第二个构造函数
	string s = "peter";
	Person ps4(s, "shanghai", 100);
	Person ps5(ps4);
	Person ps6 = ps5;
	Person ps7(std::move(ps6));
	Person ps8 = std::move(ps7); 

	if (ps1.name_infor() == ps2.name_infor()) {	
		ps1 += ps2;
	}
	ps1 += ps3;
	ps1 += ps4;
	vector<Person> per = { ps1, ps2, ps3, ps4, ps5, ps6, ps7 };
	for (auto &i : per) {
		cout << i << endl;
	}
	

	string t("abcdefg");
	string f("mm");
	auto a = t.find(f);
	cout << a << endl;



	string ss = "abc" ;
	string &sref = ss;
	string *nonestring = &ss;
	string *dystring = new string(ss);
	string *dystring2 = new string(ss);
	*dystring = "bbbb";
	nonestring = dystring;
	delete nonestring;
	nonestring = dystring2;
	cout << ss << endl;
	cout << *nonestring << endl;

	*/

	
}


