#include "IntegralTask.h"
#include "Constants.h"
#include <iostream>

using namespace std;



IntegralTask::IntegralTask(double lowerBound_,double upperBound_,double interval_,double *result_) :
	lowerBound(lowerBound_) ,upperBound(upperBound_) , interval(interval_) , result(result_) {}



task* IntegralTask::execute() {
	*this->result = calculateIntegral(this->lowerBound, this->upperBound, this->interval)*this->interval;
	//std::cout << "Rezlutat jednog taska:" << *this->result<< "\n";
	return NULL;
}



double calculateIntegral(double lowwerBound, double upperBound, double interval) {
	double sum = 0;
	for (double i = lowwerBound; i <= upperBound; i += interval) {
		sum = sum + exp(-0.5*i)*cos(i);
	}
	return sum;
}


void createTasks(double lowwerBound, double upperBound, double interval) {
	tbb::empty_task* parent = new(tbb::task::allocate_root()) tbb::empty_task;
	if (interval < INTERVAL) {
		double resenje1, resenje2;
		IntegralTask* task1 = new(parent->allocate_child()) IntegralTask(lowwerBound, lowwerBound + (upperBound - lowwerBound) / 2, interval, &resenje1);
		IntegralTask* task2 = new(parent->allocate_child()) IntegralTask(lowwerBound + (upperBound - lowwerBound) / 2, upperBound, interval, &resenje2);
		parent->set_ref_count(3);
		parent->spawn(*task1);
		parent->spawn(*task2);
		parent->wait_for_all();
		double resenje = resenje1 + resenje2;
		std::cout << "\nParalelno resenje :" << resenje << std::endl;
	}
	else {
		parent->set_ref_count(2);
		double rez;
		IntegralTask* root = new(parent->allocate_child()) IntegralTask(lowwerBound, upperBound*M_PI,interval,&rez);
		parent->spawn(*root);
		parent->wait_for_all();
		std::cout << "\nParalelno resenje :" << rez << std::endl;


	}
}
