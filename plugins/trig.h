#pragma once
#include "Function.h"
#include <iostream>

class SinFunc : public Function {
public:
	SinFunc() : Function("sin", 1) {}
	double operator()(std::vector<double>& List) override;
};

class CosFunc : public Function {
public:
	CosFunc() : Function("cos", 1) {}
	double operator()(std::vector<double>& List) override;
};


class TanFunc : public Function {
public:
	TanFunc() : Function("tan", 1) {}
	double operator()(std::vector<double>& List) override;
};


class CotFunc : public Function {
public:
	CotFunc() : Function("cot", 1) {}
	double operator()(std::vector<double>& List) override;
};