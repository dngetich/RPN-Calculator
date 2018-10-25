/*
*David Ngetich
*declaration and the definition of the stack nodetype
*/

#include <iostream>
#include "Stack.h"
#include "RPNCalc.h"
#include <string>
using namespace std;

#ifndef NODETYPE_H_
#define NODETYPE_H_


struct NodeType
{
    Stack info;
    NodeType *next;
};

#endif

