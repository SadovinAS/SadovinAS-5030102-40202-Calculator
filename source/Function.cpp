#include "Function.h"

std::vector<std::shared_ptr<Function>> Function::List;

void LoadBaseFunctions() {
	Function::List.push_back(std::make_shared<ConstFunc>());
}