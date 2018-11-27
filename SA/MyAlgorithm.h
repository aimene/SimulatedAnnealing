#include"Problem.h"
#include"SetUpParams.h"
#include"Solution.h"
#include<vector>
#include<iostream>

namespace simulatedAnnealing {
	


	using namespace std;
  class MyAlgorithm
  {
	private:
		//vector<Solution*> _solutions;     // individuals in population
		//vector<struct particle> _fitness_values;
		
		//unsigned int _upper_cost,_lower_cost; // lower and upper fitness of individuals in population

		const SetUpParams& _setup;
		Problem _problem;
		Solution _current_solution;
		Solution _best_solution;

	public:
		MyAlgorithm(const Problem& pbm,const SetUpParams& setup);
		~MyAlgorithm();

		friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);
		friend istream& operator>> (istream& is, MyAlgorithm& myAlgo);
		MyAlgorithm& operator= (const MyAlgorithm& myAlgo);

		const SetUpParams& setup() const;
	  	void initialize();

		// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
        void evaluate();

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
