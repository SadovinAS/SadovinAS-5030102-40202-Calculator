#include "trig.h"
#include <cmath>
#include <string>

double CotFunc::operator()(const std::vector<double>& List) {
	double s = std::sin(List[0]);
	if (s == 0)
		throw std::runtime_error("Cotan of " + std::to_string(List[0]) + " is udentifyed.");
	return std::cos(List[0]) / s;
	
}

extern "C" __declspec(dllexport) void LoadFunc(std::vector<std::shared_ptr<Function>>& List) {
	List.push_back(std::make_shared<SinFunc>());
	List.push_back(std::make_shared<CosFunc>());
	List.push_back(std::make_shared<TanFunc>());
	List.push_back(std::make_shared<CotFunc>());
}
