#include "sqrt.h"
#include <cmath>

double SqrtFunc::operator()(std::vector<double>& List) {
	if (List[0] < 0)
		throw std::exception("Function 'sqrt(x)' requires x >= 0.");
	return std::sqrt(List[0]);
}

extern "C" __declspec(dllexport) void LoadFunc(std::vector<std::shared_ptr<Function>>& List) {
    List.push_back(std::make_shared<SqrtFunc>());
}
