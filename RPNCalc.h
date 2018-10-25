/**********************
 *RPNCalc.h
 *David Ngetich
 *
 *This file has the function and attributes declarations for the 
 *	RUNCalc class
 *
 ******************/



#include <iostream>
#include "Stack.h"
#include <string>
#include <fstream>
using namespace std;

#ifndef RPNCALC_H_
#define RPNCALC_H_

class RPNCalc
{
public:
	//constructor
	RPNCalc();

	//main run function
	void run();

	//read from file function
	void read_in_file(istream &s_cin);

	//check for operator function
	bool is_operator(string &);

	//perform the operation function
	double perform_operation(string, double, double);

	//print_conditions functions
	void print_conditions(string, bool &, istream &s_cin);

	//passes in the istream so that the run function doesn't have 
	//pass in any parameters
	void run_program(istream &s_cin);

private:
	string input;
	Stack r;



};
#endif
