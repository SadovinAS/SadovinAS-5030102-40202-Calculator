#include "Calc.h"

Parser::Parser(std::string Str) {
	std::vector <std::string> ParsedString;
	int size = Str.size();
	int i = 0;
	while (i < size && Str[i] == ' ')
		i++;
	if (i == size)
		throw std::exception("Empty string");


	int k = 0;
	ParsedString.push_back("");
	while(i < size) {
		while (i < size && Str[i] == ' ')
			i++;
		if (std::isdigit(Str[i]) || Str[i] == '.')
			while (i < size && (std::isdigit(Str[i]) || Str[i] == '.'))
				ParsedString[k] += Str[i++];
		else if (Str[i] == '(' || std::isalpha(Str[i])) {
			while (i < size && Str[i] != '(' && Str[i] != ')' && (std::isdigit(Str[i]) || std::isalpha(Str[i])))
				ParsedString[k] += Str[i++];
			if (i < size && Str[i] != ')')
				ParsedString[k] += Str[i++];
		}
		else {
			while (i < size && !std::isdigit(Str[i]) && !std::isalpha(Str[i]) && Str[i] != ' ' && Str[i] != '(' && Str[i] != ')')
				ParsedString[k] += Str[i++];
			if (i < size && Str[i] == ')') {
				if (ParsedString[k].size() != 0) {
					k++;
					ParsedString.push_back(")");
				}
				else
					ParsedString[k].push_back(')');
				i++;
			}
		}
		if (i < size) {
			k++;
			ParsedString.push_back("");
		}
	}
	if (ParsedString.back() == "")
		ParsedString.pop_back();

	//for(auto s : ParsedString)
	//	std::cout << s << std::endl;

	Tree = std::make_unique<Term>(ParsedString);
}