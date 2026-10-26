#include "pow.h"
#include <cmath>

double PowFunc::operator()(std::vector<double>& List) {
	if (List[0] < 0)
		throw std::exception("Function 'pow(x, y)' requires x >= 0.");
	return std::pow(List[0], List[1]);
}

extern "C" __declspec(dllexport) void LoadFunc(std::vector<std::shared_ptr<Function>>& List) {
	List.push_back(std::make_shared<PowFunc>());
}
