// 5S Lab1 Calculator.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <map>
#include <string>
#include "Calc.h"
#include "PluginLoader.h"

using namespace std;


int main()
{
	LoadBaseFunctions();
	LoadBaseOperations();

	PluginLoader Plugins;
	try {
		Plugins.LoadAll();

		for (int i = 0; i < Function::List.size(); i++)
			for (int j = i + 1; j < Function::List.size(); j++)
				if (Function::List[i]->FunctionName == Function::List[j]->FunctionName)
					throw std::runtime_error("The function '" + Function::List[i]->FunctionName + "' is defined in 2 different places.");
		for (int i = 0; i < Operation::List.size(); i++)
			for (int j = i + 1; j < Operation::List.size(); j++)
				if (Operation::List[i]->Signature == Operation::List[j]->Signature && Operation::List[i]->Type == Operation::List[j]->Type)
					throw std::runtime_error("There are 2 operations with the same signature '" + Operation::List[i]->Signature + "'.");
	}
	catch (std::runtime_error x) {
		std::cout << "Exception: " << x.what() << std::endl;
		return 0;
	}
	std::cout << "Input: ";
	std::string Str;
	std::getline(cin, Str);
	while (Str != "") {
		try {
			Parser P(Str);
			double Answ = P.Calc();
			std::cout << "Output: " << Answ << std::endl;
		}
		catch (std::runtime_error x) {
			std::cout << "Exception: " << x.what() << std::endl;
		}
		//int r = rand() % 100 + 1;
		//char T[27] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '(', ')', 'c', 'p', 'w', '.', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' };
		//Str = "";
		//for (int i = 0; i < r; i++)
		//	Str += T[rand() % 27];
		//std::cout << Str << std::endl;
		std::cout << "Input: ";
		std::getline(cin, Str);
	}
	// 53 ++ 32.2 - 43.4 -(-41 / 53 + 1111111  - .2! - sqrt(5 - 4)!) + pow(3 - 2 + 1 - sqrt2(1), 2)
	
	return 0;
}
