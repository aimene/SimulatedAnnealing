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

	double Solution::random(double min, double max) const
	{
		return rand()/(double)RAND_MAX)*(max-min)+min;
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

	void Solution::initialize()
	{
		switch (_problem.get_problem_id())
		{
		case Problem::rastrigin: for (int i = 0; i < _problem.get_size_solution(); i++)
				{
			_solution.push_back(random(_problem.LowerLimit, _problem.UpperLimit));
				}
				   ; break;
		case Problem::ackley:; break;
		case Problem::resenbrock:; break;
		case Problem::schaffer: ; break;
		case Problem::schwefel: ; break;
		case Problem::weierstrass: ; break;
		default:
			break;
		}
	}

	double Solution::fitness()
	{
		double fitness;
		switch (_problem.get_problem_id)
		{
		case Problem::rastrigin: fitness =rastrigin(); break;
		case Problem::ackley:; break;
		case Problem::resenbrock:; break;
		case Problem::schaffer:; break;
		case Problem::schwefel:; break;
		case Problem::weierstrass:; break;
		default:
			break;
		}
		return fitness ;
	}

	double Solution::rastrigin()
	{
	
		
		double top = 0;
		for ( int j = 0; j < _solution.size(); j++)
		{
			top = top + (pow(_solution[j], (double)2) - 10 * cos(2 * M_PI*_solution[j]) + 10);
		}
		return top;
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
	istream & operator>>(istream & is, Solution & sol)
	{
		vector<double> _solution;
		

	}
}