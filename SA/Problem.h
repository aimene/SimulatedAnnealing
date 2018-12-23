#ifndef PROBLEM_H
#define PROBLEM_H

#include<ostream>
#include<istream>
#include<iostream>
#include<vector>



namespace simulatedAnnealing {
	using namespace std;

	
     class Problem
  {
	public:
		Problem( int problem_id);
		~Problem();

		const vector<Solution*> neighborhood(Solution& current_solution) ;
		 Solution* random_solution(const Solution& current) ;
		 Solution* best_solution(vector<Solution*> solutions);

		 //random 

		 double random_sign();
		 double random_01();
		// getters
		int get_problem_id()const;
		int get_size_solution()const;
		int get_dimension() const;


		friend ostream& operator<< (ostream& os, const Problem& pbm);
		friend istream& operator>> (istream& is, Problem& pbm);
		Problem& operator=  (const Problem& pbm);
		bool operator== (const Problem& pbm) const;
		bool operator!= (const Problem& pbm) const;


		double LowerLimit, UpperLimit;

		const static int rastrigin = 1;
		const static int ackley = 2;
		const static int resenbrock = 3;
		const static int schaffer = 4;
		const static int schwefel = 5;
		const static int weierstrass = 6;

	private:
		int _problem_id;
		int _size_solution;
		const static int _dimension = 20;
  };
}
#endif //