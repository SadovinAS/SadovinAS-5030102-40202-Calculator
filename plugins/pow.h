#pragma once
#include "Function.h"
#include <iostream>

class PowFunc : public Function {
public:
	PowFunc() : Function("pow", 2) {}
	double operator()(const std::vector<double>& List) override;
};

