#include "Operation.h"

std::vector<std::shared_ptr<Operation>> Operation::List;

double DivOper::operator()(std::vector<double>& List) {
	if (List[1] == 0)
		throw std::exception("Division by 0 is undefined.");
	return List[0] / List[1];
}


void LoadBaseOperations() {
	Operation::List.push_back(std::make_shared<PosOper>());
	Operation::List.push_back(std::make_shared<NegOper>());
	Operation::List.push_back(std::make_shared<SumOper>());
	Operation::List.push_back(std::make_shared<SubOper>());
	Operation::List.push_back(std::make_shared<MulOper>());
	Operation::List.push_back(std::make_shared<DivOper>());
}