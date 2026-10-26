#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Term.h"

class Parser {
	std::unique_ptr<Term> Tree;
public:
	Parser(std::string Str);
	
	double Calc() { return Tree->Calc(); }
};