#pragma once
#include "Function.h"
#include <iostream>

class SinFunc : public Function {
public:
	SinFunc() : Function("sin", 1) {}
	double operator()(const std::vector<double>& List) override { return std::sin(List[0]); };
};

class CosFunc : public Function {
public:
	CosFunc() : Function("cos", 1) {}
	double operator()(const std::vector<double>& List) override { return std::cos(List[0]); };
};


class TanFunc : public Function {
public:
	TanFunc() : Function("tan", 1) {}
	double operator()(const std::vector<double>& List) override { return std::tan(List[0]); };
};


class CotFunc : public Function {
public:
	CotFunc() : Function("cot", 1) {}
	double operator()(const std::vector<double>& List) override;
};