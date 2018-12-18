

#include "pch.h"
#include"Problem.h"


namespace simulatedAnnealing {
	Problem::Problem( int  problem_id): _problem_id{problem_id}
	{
		
		switch (get_problem_id())
		{
		case Problem::rastrigin: LowerLimit = -5.12; UpperLimit = 5.12; _size_solution = 20; break;
		case Problem::ackley:LowerLimit = -5; UpperLimit =5 ; break;
		case Problem::resenbrock:LowerLimit =0 ; UpperLimit =0 ; break;
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

	const vector<Solution*> Problem::neighborhood(Solution current_solution) const
	{
		vector<Solution*> sols;
		sols.clear();
		while (sols.size()<10)
		{
		
			Solution* s = new Solution{ *this };

			if (current_solution.get_fitness() > s->get_fitness())
					sols.push_back(s);
			
			if (current_solution.get_fitness() <= s->get_fitness())
				delete s;
			
		}

		
		return  sols;
	}

	Solution * Problem::random_solution() const
	{		
		Solution *randomsolution =  new Solution{ *this };		
		randomsolution->initialize();
		randomsolution->fitness();
		return randomsolution;
	}


	Solution * Problem::best_solution(vector<Solution*> solutions) const
	{
		Solution* bestsolution= random_solution();
		for (Solution* ss : solutions)
		{
			if (bestsolution->get_fitness() > ss->get_fitness())
				bestsolution = ss;
		}

		for (Solution *ss : solutions)
		{
			if (ss!=bestsolution)
			{
				delete ss;
			}
		}
		return bestsolution;

		
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
		case Problem::resenbrock:; break;
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
