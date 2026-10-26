#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include "Operation.h"
#include "Function.h"
#include <iterator>
#include <exception>

class Term {
public:
	std::vector<Term> Params;
	std::vector<std::string> Str;
	std::shared_ptr<Function> Func = nullptr;
	
	Term() {}
	Term(std::vector<std::string> String, std::string FuncName = "");

	void ClacStack(std::vector<double>& Numbers, std::vector<std::shared_ptr<Operation>>& Operations);

	std::shared_ptr<Operation> Find(std::string& Sign, OperationType OperType);

	double Calc();

	void Draw(int i = 0) {
		for (int j = 0; j < i; j++)
			std::cout << " ";
		if(Func->FunctionName != "")
			std::cout << Func->FunctionName;
		for(auto s : Str)
			std::cout << s << " ";
		std::cout << std::endl;
		for (auto& T : Params)
			T.Draw(i+5);
	}
};
