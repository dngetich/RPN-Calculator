/*******************
 *RPNCalc.cpp
 *David Ngetich
 *
 *This file has definitions for the functions
 *  of the class needed to implement the calculator.
 *
 ******************/

#include <iostream>
#include "RPNCalc.h"
#include <fstream>
#include <string>
using namespace std;


RPNCalc::RPNCalc()
{
    input = "";
}

  
//Function:run_program
//Parameters:istream &s_cin
//Return:nothing
//Does: runs the program with the istream &s_cin passed in
//      which reads in from the file when "F" is the input.
void RPNCalc::run_program(istream &s_cin)
{
    bool quit;

    do
    {
        quit = false;
        s_cin >> input;
    
        //if the input is a double then push it into the stack
        double op;
        bool is_double;
        try
        {   
            op = stod(input);
            is_double = true;
        }
        catch(invalid_argument exception)
        {
            is_double = false;
        }   
        //push the double to the stack if the stack is not full
        if(is_double == true)
        {
            bool full = r.is_full();

            if(full == true)
                return;
            else
            r.push(op);
        } 
        else    
        print_conditions(input, quit, s_cin);
        
    } while(not quit);    
}


//Function: run
//Parameters: none
//Returns: Nothing
//Does: Runs the entire calculator
void RPNCalc::run()
{   
    run_program(cin);
}

//Function: is_operator
//Parameters: String value
//Returns: bool
//Does: Returns true if the input entered is an operator else
//      returns false
bool RPNCalc::is_operator(string &value)
{
	string operators[] = {"-", "+", "*", "/"};

        for(int i=0; i<4; i++)
        {
            if(value == operators[i])
            {
                return true;
            }
        }

        return false;

}

//Function: perform_operation
//Parameters: String value, double firstOperand, double secondOperand
//Returns: double
//Does: Performs all the operations entered by the user as operators
double RPNCalc::perform_operation(string value, double firstOperand,
                                double secondOperand)
{
    double result = 0;

    

     if(value == "-")
    {
        result = firstOperand-secondOperand;
    }

    else if (value == "+")
    {
        result = firstOperand + secondOperand;
    }

    else if (value == "*")
    {
        result = firstOperand * secondOperand;
    }

    else
    {
    result = firstOperand / secondOperand;
    }
    return result;
}

//Function: read_in_file
//Parameters: none
//Returns: Nothing
//Does: Reads in from the file when command is "f" or "F" 
void RPNCalc::read_in_file(istream &s_cin)
{
    string filename;
    s_cin >> filename;

    ifstream infile;
    infile.open(filename);

    //error check
    if(!infile.is_open())
    {
        cerr << "Could not open file for reading \n";
        return;
    }

    run_program(infile);

}

//Functions:print_functions 
//Parameters: string input, bool end
//Return:Nothing
//Does: Prints all the functions needed to run the RPN Calculator 
//      in the run function
void RPNCalc::print_conditions(string input, bool &end, istream &s_cin)
{
    //if input is an operator 
    if (is_operator(input) == true) 
    {
        double firstOperand = r.top();
        r.pop();
        double secondOperand = r.top();
        r.pop();

        double num = perform_operation(input, firstOperand, secondOperand);
        r.push(num);
            
    }
    //if input is a "p" or "P" then print
    else if(input == "P" || input == "p")
        {
            r.print();    
        }
    //if input is a "C" or "c" then call make_empty function
    else if(input == "C" || input == "c") 
        {
            r.make_empty();
        }
    //if input is "F" or "f" then read in from the file  
    else if (input == "F" || input == "f") 
        {
            read_in_file(s_cin);
        }
    //if input is is "q" or "Q" then quit the while loop   
    else if (input == "q" || input == "Q")
        {
            end = true;
        }
    else
        cerr << "Command " << input << " not implemented \n";        
}

















