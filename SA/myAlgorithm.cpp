#include "pch.h"
#include"MyAlgorithm.h"

namespace simulatedAnnealing {


	MyAlgorithm::MyAlgorithm(const Problem & pbm, const SetUpParams & setup) :
		_problem{ pbm }, _setup{ setup }, _current_solution{_problem}
	,_best_solution{_problem}, _nb_independent_runs{}, _nb_evolution_steps{}
	{}

	MyAlgorithm::~MyAlgorithm()
	{
	}

	const SetUpParams & MyAlgorithm::setup() const
	{
		return _setup;

	}

	bool MyAlgorithm::stop_condition()
	{
		return is_less_max_evolution_steps() || is_less__max_independent_runs();
	}

	
		

	void MyAlgorithm::increment()
	{
		++_nb_evolution_steps;
		++_nb_independent_runs;
	}


	const unsigned int MyAlgorithm::nb_independent_runs() const
	{
		return _nb_independent_runs;
	}

	const unsigned int MyAlgorithm::nb_evolution_steps() const
	{
		return _nb_evolution_steps;
	}

	void MyAlgorithm::update_temperature(const double & x)
	{
		_temperature *= x;

	}

	void MyAlgorithm::setup_temperature(const double & x)
	{
		_temperature = x;
	}

	void MyAlgorithm::increment_nb_independent_runs()
	{
		++_nb_independent_runs;
	}

	void MyAlgorithm::increment_nb_evolution_steps()
	{
		++_nb_evolution_steps;
	}

	bool MyAlgorithm::is_less__max_independent_runs() const
	{
		return _nb_independent_runs<= _setup.max_independent_runs();
	}

	bool MyAlgorithm::is_less_max_evolution_steps() const
	{
		return _nb_evolution_steps<=_setup.max_evolution_steps();
	}

	Solution MyAlgorithm::get_best_solution() const
	{
		return _best_solution;
	}

	void MyAlgorithm::solve()

	{
		std::cout << "=================random =====================" << endl;
		

		if (_best_solution.get_fitness() >= _current_solution.get_fitness())
		{
			_best_solution = _current_solution;

		}
		

		cout << "best_solution.get_fitness() before while = "<<_best_solution.get_fitness() << endl;
		setup_temperature(10000000);

		
			
		//	vector <Solution*> solutions = _problem.neighborhood(_current_solution);
		//	Solution* bestSolution = _problem.best_solution(solutions);

			//Solution* bestSolution = _problem.random_solution();
		   Solution* sol = new Solution{ _current_solution };
			updateSolution(sol);
			_nb_evolution_steps = 0;
			//cout << "_current_solution.get_fitness() =" << _current_solution.get_fitness() << ""<<endl;

			
		//	cout << "=====best_solution.get_fitness() pn loop=" << _best_solution.get_fitness() << "" <<endl;
			
			
			//std::cout << "=====================================solve- while--end==================================" << endl;
		

		cout << "best_solution.get_fitness() after=" << _best_solution.get_fitness() << "" << endl;

	}

	void MyAlgorithm::run()
	{
		while (is_less__max_independent_runs())
		{
			solve();
			increment_nb_independent_runs();
		}
	}

	void MyAlgorithm::updateSolution(Solution* sol)
	{
		//std::cout << "=====================================updateSolution---BEGIN==================================" << endl;

	
		double proba = 0.0;
		while (is_less_max_evolution_steps())
		{

		//	cout<<"_temperature " << _temperature << endl;

			if (_temperature < 0) break;

			//cout << "sol.get_fitness() > _current_solution.get_fitness() ==" << (sol.get_fitness() < _current_solution.get_fitness()) << endl;
			if (sol->get_fitness() > _current_solution.get_fitness())
			{
				proba = exp(-1 * (_current_solution.get_fitness()
					- sol->get_fitness()) /
					//	_current_solution.get_fitness() /
					_temperature);

			}
			
			double random =_current_solution.random(0, RAND_MAX);
			//cout << "proba  : " << proba << endl;
			//cout << "random :  " << random << endl;

			if (random < proba)
			{
				_current_solution = *sol;										
			}
			if (_current_solution.get_fitness() >sol->get_fitness())
			{
				  _current_solution=*sol;
				 
			}
			if (_current_solution.get_fitness() < _best_solution.get_fitness())
			{			
				_best_solution = _current_solution;			
			}
			if (nb_evolution_steps()>1)
			{
				delete sol;
			}
			
			sol = _problem.random_solution(_current_solution);
			//vector<Solution*> sols = _problem.neighborhood(_current_solution);
			//sol =* _problem.best_solution(sols);
			sol->fitness();
			update_temperature(0.95);
			increment_nb_evolution_steps();
		}
		//cout << "=====================================updateSolution---END==================================" << endl;
	}

}