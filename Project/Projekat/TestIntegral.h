#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <list>


class Test {
public:

	double lowwerBound;
	double upperBound;
	double interval;
	
	// deafultni konstruktor klase Test
	Test();

	//	preklopljen operator za upis objkta u txt fajl
	friend std::ostream& operator<<(std::ostream& out, const Test& iT);
	// preklopljen operator za citanje objekta iz txt fajla
	friend std::istream& operator >> (std::istream& in, Test& iT);
	
	// ucitava podakte iz fajla 
	// kreira obejkat Test na osnovu ocitanih fajlova
	// dodaje Test u vektor testova
	friend void loadTestFiles(std::vector<Test>& listaTestova);

}; 
	

