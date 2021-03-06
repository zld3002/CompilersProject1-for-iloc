/* * * * * * * * * * * * * * * * * * * * * * *
 *                              			 *
 * parser.h									 *
 *											 *
 * Contains declarations for Instruction 	 *
 * structure and Parser class.				 *
 * 											 *
 * Written by: Austin James Lee				 *
 *											 *
 * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#include "scanner.h"
#include <list>

using std::list;


//// Instruction structure ////

struct Instruction {
	Instruction();			// default constructor
	Instruction(Opcode o);	// overloaded constructor
	Opcode op;				
	int src1;
	int src2;
	int dest;
	// allow for simple and pretty printing
	friend ostream& operator<<(ostream& os, const Instruction& i);
};


//// Parser class ////

class Parser {
	public:
		// constructor (calls parse)
		Parser(string infile, bool=false, bool=false);
		list<Instruction> intRep;	// list representing IR
	private:
		Scanner scanner;	// Scanner used to scan tokens
		void parse();		// main parse function
};
