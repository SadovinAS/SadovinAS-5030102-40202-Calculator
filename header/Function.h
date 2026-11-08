#pragma once 
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>

class Function {
protected:
	Function(const std::string &Name, const int Count) : ListCount(Count), FunctionName(Name) {}
public:
	std::string FunctionName;
	int ListCount;

	virtual double operator()(const std::vector<double>& List) = 0;

	static std::vector<std::shared_ptr<Function>> List;
};

class ConstFunc : public Function {
public:
	ConstFunc() : Function("", 1) {}
	double operator()(const std::vector<double>& List) override { return List[0]; }
};

void LoadBaseFunctions();