#pragma once
#include "Function.h"
#include <iostream>

class SqrtFunc : public Function {
public:
	SqrtFunc() : Function("sqrt", 1) {}
	double operator()(std::vector<double>& List) override;
};

