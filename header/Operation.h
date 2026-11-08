#pragma once 
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>

enum OperationType {
	PREFIX,
	POSTFIX,
	BINARY
};

class Operation {
protected:
	Operation(const std::string &Sign, const OperationType OperType, const int Prec) : Signature(Sign), Type(OperType), Precedence(Prec) {}
public:
	OperationType Type;
	std::string Signature;
	int Precedence;

	static std::vector<std::shared_ptr<Operation>> List;
	virtual double operator()(const std::vector<double>& List) = 0;
};


class PosOper : public Operation {
public:
	PosOper() : Operation("+", PREFIX, 3) {}
	double operator()(const std::vector<double>& List) override { return List[0]; }
};

class NegOper : public Operation {
public:
	NegOper() : Operation("-", PREFIX, 3) {}
	double operator()(const std::vector<double>& List) override { return -List[0]; }
};
class SumOper : public Operation {
public:
	SumOper() : Operation("+", BINARY, 5) {}

	double operator()(const std::vector<double>& List) override { return List[0] + List[1]; }
};

class SubOper : public Operation {
public:
	SubOper() : Operation("-", BINARY, 5) {}

	double operator()(const std::vector<double>& List) override { return List[0] - List[1]; }
};

class MulOper : public Operation {
public:
	MulOper() : Operation("*", BINARY, 4) {}

	double operator()(const std::vector<double>& List) override {	return List[0] * List[1]; }
};

class DivOper : public Operation {
public:
	DivOper() : Operation("/", BINARY, 4) {}

	double operator()(const std::vector<double>& List) override;
};

void LoadBaseOperations();