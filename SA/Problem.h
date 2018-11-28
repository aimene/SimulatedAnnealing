#ifndef PROBLEM_H
#define PROBLEM_H

#include<ostream>
#include<istream>
#include<vector>

#include"Solution.h"

namespace simulatedAnnealing {
	using namespace std;
	 class Solution;
     class Problem
  {
	public:
		Problem(const int& problem_id);
		~Problem();

		friend ostream& operator<< (ostream& os, const Problem& pbm);
		friend istream& operator>> (istream& is, Problem& pbm);

		Problem& operator=  (const Problem& pbm);
		bool operator== (const Problem& pbm) const;
		bool operator!= (const Problem& pbm) const;

		const vector<Solution*> neighborhood(Solution current_solution) const;
		const Solution& random_solution() const;
		const Solution& best_solution(vector<Solution*> solutions)const;

		int get_problem_id()const;

		///Direction direction () const; //Maximize or Minimize
		int dimension() const;
		double LowerLimit, UpperLimit;

	private:
		int _problem_id;
		int _size_solution
		const static int _dimension = 20;
  };
}
#endif //