
#include <iostream>
#include <cmath>
#include "tbb/tbb.h"
#include "tbb/task.h"
#include "TestIntegral.h"
#include "IntegralTask.h"
#include "Constants.h"
using namespace tbb;
using namespace std;


int main()
{
	vector<Test> listaTestova;
	loadTestFiles(listaTestova);
	vector<Test>::iterator iB = listaTestova.begin();
	vector<Test>::iterator iE = listaTestova.end();
	int i = 0;
	for (; iB != iE;iB++) {
		i++;
		cout << "\nDonja granica :" << iB->lowwerBound << "; Gornja granica : " << iB->upperBound << "; Interval: " << iB->interval << "\n"<<endl;
		tick_count startTime = tick_count::now();
		double suma = calculateIntegral(iB->lowwerBound, iB->upperBound*M_PI, iB->interval);
		cout << "Serijsko resenje :" << suma*(iB->interval) << endl;;
		tick_count stopTime = tick_count::now();
		cout << "Vreme izvrsavanja serijskog: " <<
			(stopTime - startTime).seconds() * 1000 << "ms.\n\n" << endl;

		tick_count startTime2 = tick_count::now();
		createTasks(iB->lowwerBound, iB->upperBound*M_PI, iB->interval);
		tick_count stopTime2 = tick_count::now();
		cout << "Vreme izvrsavanja paralelnog: " <<
			(stopTime2 - startTime2).seconds() * 1000 << "ms." << endl;
		double vremeSI = (stopTime - startTime).seconds() * 1000;
		double  vremePI = (stopTime2 - startTime2).seconds() * 1000;
		double procenatUbrzanja = abs(vremePI - vremeSI) / vremeSI * (100);
		if (vremeSI < vremePI) {
			cout << "\nSerijski program se izvrsio brze, ubrzanje u procentima je: " << procenatUbrzanja << " %" << endl;
		}
		else {
			cout << "\nParalelni program se izvrsio brze, ubrzanje u procentima je: " << procenatUbrzanja << " %" << endl;
		}
		cout << "\n\n--------------ITERACIJA BROJ " << i << "----------------\n\n" << endl;
		
	}

	return 0;
}

