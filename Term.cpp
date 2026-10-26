#include "Term.h"

Term::Term(std::vector<std::string> String, std::string FuncName) : Str(String) {
	for (auto F : Function::List)
		if (F->FunctionName == FuncName)
			Func = F;
	if (Func == nullptr)
		throw std::exception(("Function '" + FuncName + "' not found.").c_str());

	for (int i = 0; i < Str.size(); i++) {
		if (Str[i] == ")")
			throw std::exception("Missing '('");
		if (Str[i].back() == '(') {

			Str[i].pop_back();
			Params.push_back(Term({}, Str[i]));
			auto& T = Params.back();
			int pos = i;
			i++;
			do {
				int OldI = i;
				int k = 0;
				while (i < Str.size() && (Str[i] != "," && Str[i] != ")" || k > 0)) {
					if (Str[i].back() == '(')
						k++;
					else if (Str[i] == ")")
						k--;
					i++;
				}
				if (i == Str.size())
					throw std::exception("Missing ')'");
				else if (Str[i] == "," && k == 0 && T.Func->FunctionName == "")
					throw std::exception("Missing function name before ().");

				std::vector<std::string> nS(Str.begin() + OldI, Str.begin() + i);
				if (!nS.empty())
					T.Params.push_back(nS);
				i++;
			} while (Str[i - 1] != ")");

			if (T.Func->FunctionName != "" && T.Params.size() != T.Func->ListCount)
				throw std::exception(("The amount of args in function '" + T.Func->FunctionName +
					"' does not match. Expected '" + std::to_string(T.Func->ListCount) +
					"'. Given '" + std::to_string(T.Params.size()) + "'.").c_str());
			else if (T.Func->FunctionName == "" && T.Params.empty())
				throw std::exception("Empty space");

			Str.erase(Str.begin() + pos, Str.begin() + i);
			Str.insert(Str.begin() + pos, "$");
			i = pos;
		}
	}
}

void Term::ClacStack(std::vector<double>& Numbers, std::vector<std::shared_ptr<Operation>>& Operations) {
	Operation& Oper = *Operations.back();
	Operations.erase(Operations.end() - 1);

	if (Oper.Type == BINARY && Numbers.size() < 2)
		throw std::exception(("The amount of args in Binary operation '" + Oper.Signature +
			"' does not match. Expected '2'. Given '" + std::to_string(Numbers.size()) + "'.").c_str());
	else if (Numbers.size() == 0)
		throw std::exception(("The amount of args in unary operation '" + Oper.Signature +
			"' does not match. Expected '1'. Given '0'.").c_str());

	int Count = 1 + (Oper.Type == BINARY);
	std::vector<double> A(Numbers.end() - Count, Numbers.end());
	Numbers.erase(Numbers.end() - Count, Numbers.end());
	Numbers.push_back(Oper(A));
}

std::shared_ptr<Operation> Term::Find(std::string& Sign, OperationType OperType) {
	for (int i = 0; i < Operation::List.size(); i++)
		if (Operation::List[i]->Type == OperType && Operation::List[i]->Signature == Sign)
			return Operation::List[i];
	return nullptr;
}

double Term::Calc() {
	if (Str.empty()) {
		std::vector<double> A;
		for (auto& P : Params)
			A.push_back(P.Calc());
		return (*Func)(A);
	}

	std::vector<double> NumbStack;
	std::vector<std::shared_ptr<Operation>> OperStack;


	bool NumbOrUnar = true;
	for (auto& S : Str) {
		if (NumbOrUnar && (S == "$" || std::isdigit(S[0]) || S[0] == '.')) {
			if (S == "$") {
				NumbStack.push_back(Params[0].Calc());
				Params.erase(Params.begin());
			}
			else
				NumbStack.push_back(std::stod(S));

			NumbOrUnar = false;
		}
		else if (NumbOrUnar) {
			auto Oper = Find(S, PREFIX);
			if (Oper == nullptr)
				throw std::exception(("Prefix Operator '" + S + "' not defined.").c_str());
			OperStack.push_back(Oper);
		}
		else {
			auto Oper = Find(S, POSTFIX);
			if (Oper != nullptr) {
				while (!OperStack.empty() && OperStack.back()->Precedence <= Oper->Precedence)
					ClacStack(NumbStack, OperStack);

				OperStack.push_back(Oper);
				ClacStack(NumbStack, OperStack);
			}
			else {
				Oper = Find(S, BINARY);
				if (Oper == nullptr)
					throw std::exception(("Operator '" + S + "' not defined.").c_str());

				while (!OperStack.empty() && OperStack.back()->Precedence <= Oper->Precedence)
					ClacStack(NumbStack, OperStack);

				OperStack.push_back(Oper);
				NumbOrUnar = true;
			}
		}
	}

	if (NumbOrUnar)
		throw std::runtime_error("Missing Number at the end.");

	while (!OperStack.empty())
		ClacStack(NumbStack, OperStack);

	return NumbStack[0];
}
