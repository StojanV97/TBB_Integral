#include "TestIntegral.h"

Test::Test() {
	
}

std::ostream& operator<<(std::ostream& out, const Test& iT) {
	out << iT.lowwerBound << "|" << iT.upperBound << "|" << iT.interval ;
	return out;
}

std::istream& operator >> (std::istream& in, Test& iT) {

	in >> iT.lowwerBound;
	in >> iT.upperBound;
	in >> iT.interval;
	return in;
}

void loadTestFiles(std::vector<Test>& listaTestova) {
	std::ifstream file("testovi.txt");
	while (!file.eof()) {
		Test t;
		file >> t;
		listaTestova.push_back(t);
	}

}



