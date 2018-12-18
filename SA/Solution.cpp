#include "pch.h"
#include"Solution.h"
#include"Problem.h"

#include<algorithm>
namespace simulatedAnnealing
 {

	// constructors

	

	Solution::Solution(const Problem & pbm) : _problem{ pbm } {
		initialize();
		fitness();
	}

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
		//srand(time(NULL));
		double f = (double)rand() / RAND_MAX;
		return min + f *(max - min);
	
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
		case Problem::rastrigin: 
				
			_solution.clear();
			for (int i = 0; i < _problem.get_size_solution(); i++)
				{
				double x1 = random(_problem.LowerLimit, _problem.UpperLimit);
			
				_solution.push_back(x1);		
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

	void Solution::fitness()
	{
		
		switch (_problem.get_problem_id())
		{
		case Problem::rastrigin: _current_fitness= rastrigin(); break;
		case Problem::ackley:; break;
		case Problem::resenbrock:; break;
		case Problem::schaffer:; break;
		case Problem::schwefel:; break;
		case Problem::weierstrass:; break;
		default:
			break;
		}
	
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
		os << "=============================================================================" << endl;
		os << "Values of solution :" << endl;
		os << " ( ";
		for (double x : sol.get_solution()) {
			os << x << " , ";
		}
		os << " ) " << endl;
		os << "Current fitness :"  ;
		os << sol.get_fitness() << endl;

		os << sol.get_problem() << endl;
		os << "=============================================================================" << endl;
		return os;
	}
	istream & operator>>(istream & is, Solution & sol)
	{
		vector<double> _solution;
		
		return is;

	}
}