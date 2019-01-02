#include "pch.h"
#include"Solution.h"
#include"Problem.h"
#include <math.h>
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

	void Solution::set_solution(int i, double value)
	{
		_solution[i] = value;
	}


	void Solution::initialize()
	{
		_solution.clear();
			 	
			for (int i = 0; i < _problem.get_size_solution(); i++)
				{
				double x1 = random(_problem.LowerLimit, _problem.UpperLimit);
			
				_solution.push_back(x1);		
				}							
	}

	void Solution::fitness()
	{
		
		switch (_problem.get_problem_id())
		{
		case Problem::rastrigin: _current_fitness= rastrigin(); break;
		case Problem::ackley: _current_fitness = ackley(); break;
		case Problem::rosenbrock: _current_fitness = rosenbrock(); break;
		case Problem::schaffer:_current_fitness = schaffer(); break;
		case Problem::schwefel:_current_fitness = schwefel(); break;
		case Problem::weierstrass:_current_fitness = weierstrass(); break;
		default:
			break;
		}
	
	}

	// f(0,0,0,0,0,...) =0
	double Solution::rastrigin()
	{
	
		double top = 0;
		for ( int j = 0; j < _problem.get_dimension(); j++)
		{
			top = top + (pow(_solution[j], (double)2) - 10 * cos(2 * M_PI*_solution[j]) + 10);
		}
		return top;
	}

	// f(0,0,0,0,0,...) =0
	double Solution::ackley()
	{
		 double a = 20.0;
		double b = 0.2;
		 double c = 2 * M_PI;
		 double dimesntion = _problem.get_dimension();
		 double sum1 = 0.0, sum2 = 0.0;
		for (int i = 0; i < dimesntion; i++) {
			sum1 += pow(_solution[i], 2);
			sum2 += cos(c*get_solution()[i]);
		}
		return -a*exp(-b* sqrt((double(1) / dimesntion)*sum1)) - exp((double(1) / dimesntion)*sum2) + a + exp(1);


	
	}
	// f(1,1,1,1,1,...) =0
	double Solution::rosenbrock()
	{
		const double ALPHA = 100.0;
		double sum = 0.0;
		for (int i = 0; i < _problem.get_dimension() - 1; i++)
		{
			double temp1 =  _solution[i + 1] - pow(_solution[i], 2);
			double temp2 = _solution[i] - double(1.0);
			sum += ALPHA *pow( temp1 ,2) + pow(temp2, 2);
		}
		return sum;
	}
	// f(0,0,0,0,0,...) =0
	double Solution::schaffer()
	{
		const double A = 0.5;
		const double B = 0.001;
		double sum = 0.0;
		for (int i = 0; i < _problem.get_dimension(); ++i)
			sum += A + (double(pow(sin(pow(_solution[i], 2) - pow(_solution[i + 1], 2)), 2) - A) / pow(1 + B*(pow(_solution[i], 2) + pow(_solution[i + 1], 2)), 2));
		return sum;
	}
	//f(420.9687,..........,420.9687 )=0
	double Solution::schwefel()
	{
		
		const double alpha = 418.9829;
		double sum = 0.0;
		for (int i = 0; i < _problem.get_dimension(); ++i)
		{
			sum += _solution[i] * sin(sqrt(abs(_solution[i])));
		}

		return static_cast<int>(alpha*_solution.size() - sum); // min 420.9687
	}

	double Solution::weierstrass()
	{
		const double a = 0.5;
		const double b = 3;
		const double Kmax =20 ;

		double sum1 = 0.0;
		double sum2 = 0.0;
		for (int i = 0; i < _problem.get_dimension(); i++)
		{
			for (int k = 0; k <= Kmax; k++)
			{
				sum1 += pow(a, k) * cos(2.0*M_PI * pow(b, k) * (_solution[i] + a));
			}
			sum2 += pow(a, i) * cos(2.0*M_PI * pow(b, i) * (a));
		}

		
		return (sum1 - sum2 * (_solution.size()));
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
		os << "=============================================================================" << endl;
		os << "  " << endl;

		os << sol.get_problem() << endl;
		os << "Values of solution :" << endl;
		os << " ( ";
		for (double x : sol.get_solution()) {
			os << x << " , ";
		}
		os << " ) " << endl;
		os << "  " << endl;

		os << "Current fitness :"  ;
		os << sol.get_fitness() << endl;
		os << "  " << endl;

	
		os << "=============================================================================" << endl;
		return os;
	}
	istream & operator>>(istream & is, Solution & sol)
	{
		vector<double> _solution;
		
		return is;

	}
}