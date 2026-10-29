#pragma once
#include "Function.h"
#include <iostream>

class PowFunc : public Function {
public:
	PowFunc() : Function("pow", 2) {}
	double operator()(std::vector<double>& List) override;
};

