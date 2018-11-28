#include"Solution.h"
#include"Problem.h"

namespace simulatedAnnealing
 {

	// constructors
	Solution::Solution(const Problem & pbm) : _problem{ pbm } {}

	Solution::Solution(const Solution & sol): _problem{sol.get_problem()}
	{
		*this = sol;

	}
	// desctructor
	Solution::~Solution()
	{
	}

	// getters
	double Solution::get_fitness() const
	{
		return _current_fitness;
	}

	const Problem & Solution::get_problem() const
	{
		return  _problem;
	}

	const vector<double>& Solution::get_solution() const
	{
		return _solution;
	}

	// override  operator
	Solution & Solution::operator=(const Solution & sol)
	{
		if (get_problem().get_problem_id() ==
			sol.get_problem().get_problem_id())
		{
			_solution = sol.get_solution();
			_current_fitness = sol.get_fitness();

		}
		return *this;
	}

	bool Solution::operator==(const Solution & sol) const
	{
		return _solution == sol.get_solution() &&
			_current_fitness == sol.get_fitness() &&
			_problem == sol.get_problem();
	}
	bool Solution::operator!=(const Solution & sol) const
	{
		return !(*this == sol);
	}


	ostream & operator<<(ostream & os, const Solution & sol)
	{
		os << "Values of solution :" << endl;
		os << " ( ";
		for (double x : sol.get_solution()) {
			os << x << " , ";
		}
		os << " ) " << endl;
		os << "Current fitness :" << endl;
		os << sol.get_fitness() << endl;

		os << sol.get_problem << endl;

	}
}