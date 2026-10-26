#include "deg.h"
#include <cmath>

double PowOper::operator()(std::vector<double>& List) {
	if (List[0] < 0)
		throw std::exception("Operatoin 'x^y' requires x >= 0.");
	return std::pow(List[0], List[1]);
}

extern "C" __declspec(dllexport) void LoadOper(std::vector<std::shared_ptr<Operation>>& List) {
	List.push_back(std::make_shared<PowOper>());
}
