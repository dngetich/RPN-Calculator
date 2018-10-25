/**********************
 *Stack.h
 *
 *David Ngetich
 *
 *This file has the function and attributes declarations for the 
 *	Stack class.
 *
 ********************/

#include <iostream>
#include <stack>
#include <string>
using namespace std;


#ifndef STACK_H_
#define STACK_H_
 
class Stack
{
public:
	//Constructor
	Stack();
	//Destructor;
	~Stack();

	//Copy constructor
	Stack(const Stack &);

	//Assignment operator
	Stack & operator = (const Stack &);

	//is_empty function
	bool is_empty() const;

	//is_full function
	bool is_full() const;

	//make empty function
	void make_empty();

	//get size function
	int get_size() const;

	//top value function
	double top() const;

	//push function
	void push(double);

	//pop function
	void pop();

	//print function
	void print();

private:
	int length;

	struct NodeType
	{
   		double info;
    	NodeType *next;
	};	

    NodeType *head;
    NodeType *curr_pos;
};
#endif



