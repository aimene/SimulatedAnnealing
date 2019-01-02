#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include"Problem.h"
#include"SetUpParams.h"
#include"Solution.h"
#include<vector>
#include<iostream>

#include <cstdlib>
using namespace std;

namespace simulatedAnnealing {
	


	using namespace std;
  class MyAlgorithm
  {
	private:
		//vector<Solution*> _solutions;     // individuals in population
		//vector<struct particle> _fitness_values;
		
		//unsigned int _upper_cost,_lower_cost; // lower and upper fitness of individuals in population

	    SetUpParams& _setup;
		Problem _problem;
		Solution _current_solution;
		Solution _best_solution;

		

	public:
		MyAlgorithm(const Problem& pbm, SetUpParams& setup);
		~MyAlgorithm();


	

	  	bool stop_condition();

		void updateSolution(Solution* sol);

		

		const SetUpParams& setup() const;
		

		Solution get_best_solution() const;

		void solve();

		void run();

		friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);
		friend istream& operator>> (istream& is, MyAlgorithm& myAlgo);
		MyAlgorithm& operator= (const MyAlgorithm& myAlgo);

		// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
       /* void evaluate();

	 	const vector<Solution*>& solutions() const;
		unsigned int upper_cost() const;
		unsigned int lower_cost() const;
		Solution& solution(const unsigned int index) const;
        vector<struct particle>&  fitness_values();
		double fitness(const unsigned int index) const;


		double best_cost() const;
		double worst_cost() const;
		Solution& best_solution() const;
		Solution& worst_solution() const;

		void evolution(int iter); /*makes an evolution step*/

  };
}
#endif