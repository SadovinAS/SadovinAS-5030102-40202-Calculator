#pragma once
#include "Operation.h"
#include <iostream>

class PowOper : public Operation {
public:
	PowOper() : Operation("^", BINARY, 2) {}
	double operator()(const std::vector<double>& List) override;
};

