

#include "pch.h"
#include"Problem.h"


namespace simulatedAnnealing {
	Problem::Problem( int  problem_id): _problem_id{problem_id}
	{
		_size_solution = 20;
		switch (get_problem_id())
		{
		case Problem::rastrigin: LowerLimit = -5.12; UpperLimit = 5.12; break;
		case Problem::ackley:LowerLimit = -5; UpperLimit =5 ; break;
		case Problem::rosenbrock:LowerLimit =-INT_MAX; UpperLimit = INT_MAX; break;
		case Problem::schaffer: LowerLimit =-100 ; UpperLimit =100 ; break;
		case Problem::schwefel:LowerLimit = -500; UpperLimit =500 ; break;
		case Problem::weierstrass:LowerLimit = -0.5 ; UpperLimit = 0.5 ; break;
		default:
			break;
		}
	}

	Problem::~Problem()
	{
		
	
	}



	int Problem::get_problem_id() const
	{
		return _problem_id;
	}

	int Problem::get_size_solution() const
	{
		return _size_solution;
	}

	int Problem::get_dimension() const
	{
		return _dimension;
	}

	double Problem::random_sign()
	{
		double value = 2 * random_01() - 1;
		return value;
	}

	double Problem::random_01()
	{
		const double kMaxPlusOne = (double)RAND_MAX + 1;
		double value = (double)rand() / kMaxPlusOne;
		return value;
	}

	Solution * Problem::random_solution(const Solution& current) 
	{
		Solution *randomsolution = new Solution{ current };
		double r, probability;
		switch (randomsolution->get_problem().get_problem_id())
		{
		case rastrigin: // pour Rastrigin
			r = 0.1; // r= 0.1
			probability = 0.15; // p = 0.15
			break;
		case ackley: 
			r = 0.01; 
			probability = 0.1; 
			break;
		case rosenbrock: 
			r = 0.3; 
			probability = 0.25; 
			break;
		case schaffer: 
			r = 0.05; 
			probability = 0.15; 
			break;
		case schwefel: 
			r = 0.05; 
			probability = 0.3; 
			break;
		case weierstrass: 
			r = 0.025; 
			probability = 0.09; // p = 0.15
			break;

		default: r = 0.0015; probability = 0.5; break;
		}
		double value;
		
		double upper = current.get_problem().UpperLimit;
		double lower = current.get_problem().LowerLimit;
		for (int i = 0; i <randomsolution->get_problem().get_dimension(); i++)
		{
			if (randomsolution->random(0,1)<probability)
			{
				value = current.get_solution()[i] + r*random_sign()*(upper - lower);
				randomsolution->set_solution(i,value);
			}
			if (randomsolution->get_solution()[i]< lower || randomsolution->get_solution()[i]>upper)
			{
				value = randomsolution->random(lower, upper);
				randomsolution->set_solution(i, value);
			}
			randomsolution->fitness();
		}
	
		return randomsolution;
	}

	

	

	Problem & Problem::operator=(const Problem & pbm)
	{
		if ( this->get_problem_id() != pbm.get_problem_id()) {
		_problem_id = pbm.get_problem_id();
		_size_solution = pbm.get_size_solution();
		}
		return *this;
	}
	
	bool Problem::operator!=(const Problem & pbm) const
	{
		if (_problem_id != pbm.get_problem_id())
			return false;
		else
			return  true;
	}
	
	bool Problem::operator==(const Problem & pbm) const
	{
		return !(*this != pbm);
	}


	ostream & operator<<(ostream & os, const Problem & pbm)
	{
		os << "=====================================PROBLEM---BEGIN==================================" << endl;

		os << " function : " ;
		switch (pbm.get_problem_id())
		{
		case Problem::rastrigin: 
			os << "rastrigin";
			; break;
		case Problem::ackley:; break;
		case Problem::rosenbrock:; break;
		case Problem::schaffer: ; break;
		case Problem::schwefel:; break;
		case Problem::weierstrass:; break;
		default:
			break;
		}
		os << " dimension : " <<pbm.get_dimension() << endl;
		os << "=====================================PROBLEM---END==================================" << endl;
		return os;

	}

	istream & operator>>(istream & is, Problem & pbm)
	{
		cout <<" Choose a function " <<endl;
		cout << " For rastrigin function enter 1" << endl;
		cout << " For  ackley function enter 2" << endl;
		cout << " For resenbrock function enter 3 " << endl;
		cout << " For schaffer function enter 4 " << endl;
		cout << " For schwefel function enter  5 " << endl;
		cout << " For weierstrass function enter 6 " << endl;

		int problem_id;
		is >> problem_id;
		if (is.good())
			pbm = Problem{problem_id};

		return is;

	}

}
