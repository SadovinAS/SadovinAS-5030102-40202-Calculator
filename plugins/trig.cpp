#include "trig.h"
#include <cmath>
#include <string>

double SinFunc::operator()(std::vector<double>& List) {
	return std::sin(List[0]);
}
double CosFunc::operator()(std::vector<double>& List) {
	return std::cos(List[0]);
}
double TanFunc::operator()(std::vector<double>& List) {
	return std::tan(List[0]);
}
double CotFunc::operator()(std::vector<double>& List) {
	return 1 / std::tan(List[0]);
}

extern "C" __declspec(dllexport) void LoadFunc(std::vector<std::shared_ptr<Function>>& List) {
	List.push_back(std::make_shared<SinFunc>());
	List.push_back(std::make_shared<CosFunc>());
	List.push_back(std::make_shared<TanFunc>());
	List.push_back(std::make_shared<CotFunc>());
}
