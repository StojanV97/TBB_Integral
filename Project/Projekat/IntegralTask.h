#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "tbb/tbb.h"
#include "Constants.h"
using namespace tbb;
class IntegralTask : public task
{


public:
	double lowerBound;    // donja granica intervala
	double upperBound;	  // gornja granica intervala
	double interval;	  // velicina intervala ( delta X )
	double *result;		  // pokazivac ka promenljivoj koja predstavlja rezultat integrala u datom intervalu

	// konstruktor klaste IntegralTask
	// parametri:
	//		lowerBound_  - donja granica
	//		upperBound_  - goraja granica
	//      interval_    - velicina intervala
	//		result_		 - pokazivac ka rezultatu
	IntegralTask(double lowerBound_ , double upperBound_ , double interval_ ,double *result_);

	//	poziva funkciju calculateIntegral na oderedjenom intervalu
	// dodeljuje vrednost funckije promenljivoj result
	// ispisuje resenje algoritma za odgovarajuci task
	task * execute();
};
	//  racuna integral u odredjenom intervalu iterativnom metodom
	//	korak iteracije je promenljiva interval( delta X )
	//  
	//	parametri :
	//		lowerBound - donja granica intervala
	//		upperBound - gornja granica intervala
	//		interval   - velicina intervala
	//	povratne vrednosti :
	//		sum - vrednost integrala
	double calculateIntegral(double lowerBound, double upperBound, double interval);


	//  kreira taskove radi paralelizacije racunanja intervala
	//	prvo kreira prazan task kao koren
	//  proverava da li je interval < 0.01
	//  ukoliko jeste onda deli interval na pola 
	//  kreira dva taska kojima se dodeljuju polovine intervala
	//  sabira resenje dobijena iz taskova i ispisuje na konzolu
	//  ukoliko je interval >= 0.01
	//  kreiraj jedan tasko koji racuna vrednost integrala
	//
	//	parametri : 
	//		lowerBound - donja granica intervala
	//		upperBound - gornja granica intervala
	//		interval   - velicina intervala
	void createTasks(double lowerBound, double upperBound, double interval);



