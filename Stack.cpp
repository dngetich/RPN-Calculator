/*********************
 *Stack.cpp
 *
 *David Ngetich
 *
 *This file has the function definitions for the Stack class
 *  which has the fundamental functions for the implementaion of
 *  The RPN Calculator
 *
 ********************/

#include <iostream>
#include "Stack.h"
using namespace std;

//constructor
Stack::Stack()
{
	curr_pos = NULL;
 	head = NULL;
 	length = 0;
}

 //Destructor
Stack::~Stack()
{
    NodeType *temp;
    NodeType *curr = head;

    while (curr != NULL)
    {
        temp = curr->next;
        delete curr;
        curr = temp;
    }

}

//copy constructor
Stack::Stack(const Stack &s)
{

	length = s.length;
    curr_pos = NULL;
    if (s.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->info = s.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *original = s.head;

        while (original->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = original->next->info;
            curr->next->next = NULL;
            original = original->next;
            curr = curr->next;
        }
    }
}

//assignment operator
Stack & Stack::operator = (const Stack &s)
{
    length = s.length;
    curr_pos = NULL;
    if (s.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->info = s.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *original = s.head;
        while (original->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = original->next->info;
            curr->next->next = NULL;
            original = original->next;
            curr = curr->next;
        }
    }
    return *this;
}

//Function: is_empty
//Parametres: None
//Returns: bool
//Does: Checks if the stack is empty
bool Stack::is_empty() const
{
	if (head == NULL)
		return true;
	else
		return false;
}


//Function: is_full 
//Inputs: None
//Returns: bool
//Does: Checks if the stack is full
bool Stack::is_full() const
{
    try
    {
        NodeType *node = new NodeType;
        delete node;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}


//Function: make_empty
//Inputs: None
//Returns: None
//Does: Empties out the stack, dealllocating allocated memory
void Stack::make_empty()
{
    NodeType *temp;
    NodeType *curr = head;

    while (curr != NULL)
    {
        temp = curr->next;
        delete curr;
        curr = temp;
        length--;
    }
    length = 0;
    curr_pos = NULL;
    head = NULL;
}

//Function:get_size
//Parameters:None
//Returns: int
//Does: Returns the number of elements currently in the stack
int Stack::get_size() const
{
    return length;
}

//Function: top
//Parameters: None
//Returns: double
//Does: Returns the value of the top element in the stack 
double Stack::top() const
{
    return head->info;
}


//Function: Push
//Parameters: double
//Returns: Nothing
//Does: Inserts the element to the top of stack
void Stack::push(double value)
{
    NodeType *ptr = new NodeType;
    ptr->info = value;
    ptr->next = head;
    head = ptr;
    length++;
}

//Function: pop
//paramaters: None
//Returns: Nothind
//Does: Deletes the top element in the stack
void Stack::pop()
{
    NodeType *ptr = head;
    head = head->next;
    delete ptr;
    length--;
}

//Function: print
//Parameters: None
//Returns: Nothing
//Does: Prints the top element in the stack
void Stack::print() 
{
    if (is_empty() == true)
    {
        return;
    } 
    else
    {
        cout << top() << endl;
    }  
}









