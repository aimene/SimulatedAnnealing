#include "pch.h"
#include"MyAlgorithm.h"

namespace simulatedAnnealing {


	MyAlgorithm::MyAlgorithm(const Problem & pbm,  SetUpParams & setup) :
		_problem{ pbm }, _setup{ setup }, _current_solution{_problem}
	,_best_solution{_problem}
	{
		
	}

	MyAlgorithm::~MyAlgorithm()
	{
	}

	const SetUpParams & MyAlgorithm::setup() const
	{
		return _setup;

	}

	bool MyAlgorithm::stop_condition()
	{
		return _setup.is_less_max_evolution_steps() || _setup.is_less__max_independent_runs();
	}

	
		

	


	

	Solution MyAlgorithm::get_best_solution() const
	{
		return _best_solution;
	}

	void MyAlgorithm::solve()

	{
		std::cout << "================= run( "<<_setup.get_nb_independent_runs() <<" )=====================" << endl;
		

		if (_best_solution.get_fitness() >= _current_solution.get_fitness())
		{
			_best_solution = _current_solution;

		}
		cout << _best_solution << endl;

		   _setup.setup_temperature();
		    Solution* sol = new Solution{ _current_solution };
			updateSolution(sol);
			_setup.setup_nb_evolution_steps(0);
			

		cout << _best_solution << endl;

	}

	void MyAlgorithm::run()
	{
		while (_setup.is_less__max_independent_runs())
		{
			
			solve();
			_setup.increment_nb_independent_runs();
		}
	}

	void MyAlgorithm::updateSolution(Solution* sol)
	{

	
		double proba = 0.0;
		while (_setup.is_less_max_evolution_steps())
		{


			if (_setup.get_temperature() < 0) break;

			if (sol->get_fitness() > _current_solution.get_fitness())
			{
				proba = exp(-1 * (_current_solution.get_fitness()- sol->get_fitness()) /_setup.get_temperature());

			}
			
			double random =_current_solution.random(0, RAND_MAX);		

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
				
			
			delete sol;
		
			sol = _problem.random_solution(_current_solution);
		
			sol->fitness();

			_setup.update_temperature();

			_setup.increment_nb_evolution_steps();
		}
		//cout << "=====================================updateSolution---END==================================" << endl;
	}

}