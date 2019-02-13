#pragma once

#ifndef PRATIC_FUNC_H
#define PRATIC_FUNC_H



#include "pch.h"
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

//STRING
void push_back_self(const string &cs1,string &s1);
void toupper_self(string &s1);
void nonempty_lower_upper(string &s1);
void os_upp_low_bla(string &s1);
void os_dig1(string &s1);


//VECTOR<INT>
void add_sum_one_to_hundred(vector<int> &v1);
void mult_i(vector<int> &v1);
void os_sum1_sum2_dig2(vector<int> &v1);
void os_change_order(vector<int> &v1);
void os_dig3(vector<int> &v1);
void os_order_question(vector<int> &v1);;


//VECTOR<STRING>
void os_push_back_self(const string &vs, vector<string> &vs1);


//VECTOR<CHAR>
void os_vector_char(const string &vs, vector<char> &vc1);

//class
void runPerson(Person_Infor &ps_infor_total);



#endif// !PRATIC_FUNC_H
