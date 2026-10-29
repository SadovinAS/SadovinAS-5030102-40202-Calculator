#pragma once 
#include <iostream>
#include <vector>
#include <memory>
#include <exception>
#include <string>

class Function {
protected:
	Function(std::string Name, int Count) : ListCount(Count), FunctionName(Name) {}
public:
	std::string FunctionName;
	int ListCount;

	virtual double operator()(std::vector<double>& List) = 0;

	static std::vector<std::shared_ptr<Function>> List;
};

class ConstFunc : public Function {
public:
	ConstFunc() : Function("", 1) {}
	double operator()(std::vector<double>& List) override { return List[0]; }
};

void LoadBaseFunctions();