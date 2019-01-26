#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "pratic_func.h"
using namespace std;

//FUNC OF STRING
void push_back_self(const string &cs1, string &s1)
{
	for (auto alph : cs1) {
		s1.push_back(alph);
	}
}

void toupper_self(string &s1)
{
	for (auto &blook : s1) {
		if (!isspace(blook)) {
			blook = toupper(blook);
		}
	}
}

void nonempty_lower_upper(string &s1)
{
	if (!s1.empty()) {
		for (auto &i : s1) {
			if (i != tolower(i)) {
				i = tolower(i);
			}
			else if (i != toupper(i)) {
				i = toupper(i);
			}
		}
	}
}

void os_upp_low_bla(string &s1) 
{
	string::size_type nupper = 0, nlower = 0;
	decltype(s1.size()) nblank = 0;

	auto &nupp = nupper, &nlow = nlower;
	decltype(nblank) &nbla = nblank;

	for (auto pot = s1.begin(); pot != s1.end(); ++pot) {
		if (!isblank(*pot) && (*pot) != tolower(*pot)) {
			*pot = 'U';
			++nupp;
		}
		else if (!isblank(*pot) && (*pot) != toupper(*pot)) {
			*pot = 'L';
			++nlow;
		}
		else if (isblank(*pot)) {
			++nbla;
		}
	}
	cout << "upper  " << nupp<< "\n" << "lower  " 
		<< nlow << "\n" << "s1 " << s1
		<< "\n" << "blank  " << nbla << "\n" << endl;
}

void os_dig1(string &s1)
{
	auto const dig1 = s1.size();
	cout << "dig1  " << dig1 << endl;
}

//FUNC OF VECTOR<INT>

void add_sum_one_to_hundred(vector<int> &v1)
{
	for (int i = 0; i != 10; ++i) {
		v1.push_back(i);
	}
}


void mult_i(vector<int> &v1)
{
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		(*i) *= (*i + 1);
	}
}

void os_sum1_sum2_dig2(vector<int> &v1)
{
	decltype(v1.size()) summary1 = 0;
	decltype(v1.size()) summary2 = 0;
	auto &sum1 = summary1;
	auto &sum2 = summary2;

	for (const auto i : v1) {
		if (i % 5 == 0) {
			sum1 += i;
		}
		else if (i % 2 == 0) {
			sum1 -= i;
		}
		cout << i << endl;
	}

	for (auto i : v1) {
		sum2 += i;
	}
	const auto dig2 = v1.size();
	cout << "dig2 " << dig2 << endl;
	cout << "sum for vi1 is " << sum1 << "\n" << endl;
	cout << "sum for vi2 is " << sum2 << "\n" << endl;
}

void os_change_order(vector<int> &v1)
{
	auto t = v1.begin();//这里的t 为std::vector<int>::iterator, 但是下面的n和j 均为int *，两者不一样。
	auto temp = 0;

	for (auto n = &v1[0], j = &v1[v1.size() - 1]; n < j; ++n, j--) { 
		temp = *n;
		*n = *j;
		*j = temp;
	}

	for (auto i : v1) {
		cout << i << endl;
	}
}

void os_dig3(vector<int> &v1)
{
	const auto dig3 = v1.size();
	cout << "dig3 " << dig3 << endl;
}

//FUN OF VECTOR<STRING>
void os_push_back_self(const string &vs,vector<string> &vs1)
{
	vs1.push_back(vs);

	for (auto i : vs1) {
		cout << i;
	}
	cout << endl;
}

void os_order_question(vector<int> &v1)
{
	int temp = 0;
	for (auto i = v1.begin(); i != v1.end(); i++) {
		for (auto j = i; j != v1.end(); j++) {
			if (*i < *j) {
				temp = *i;
				*i = *j;
				*j = temp;
			}
		}
	}
	for (auto i : v1) {
		cout << i << "\t";
	}
	cout << endl;
}

void os_vector_char(const string &vs, vector<char> &vc1)
{
	for (auto ch1 : vs) {
		vc1.push_back(ch1);
	}

	for (auto ch2 : vc1) {
		cout << ch2;
	}
	cout << "\n" << endl;
}

