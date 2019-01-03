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


	void MyAlgorithm::run()
	{
		_best_solution = _current_solution;
		while (_setup.is_less__max_independent_runs())
		{

			_setup.setup_temperature();
			solve();
			_setup.increment_nb_independent_runs();
		}
	}

	void MyAlgorithm::solve()

	{
		std::cout << "================= run( "<<_setup.get_nb_independent_runs() <<" )=====================" << endl;
		
		std::cout << _best_solution << std::endl;
	
		

		Solution* sol = new Solution{ _best_solution };

		while (_setup.is_less_max_evolution_steps())
		{
		if (_setup.get_current_temperature() < 0) break;

		updateSolution(sol);
		
		delete sol;

		sol = _problem.random_solution(_current_solution);

		sol->fitness();

		_setup.update_temperature();
		_setup.increment_nb_evolution_steps();

		}
		_setup.set_nb_evolution_steps(0);


		std::cout << _best_solution << std::endl;

	}

	

	void MyAlgorithm::updateSolution(Solution* sol)
	{

	
	      	double proba = 0.0;
	

			
			if (sol->get_fitness() > _current_solution.get_fitness())
			{
				proba = exp(-1 * (_current_solution.get_fitness()- sol->get_fitness()) /_setup.get_current_temperature());

			}
			
			double random =_current_solution.random(0, RAND_MAX);		

			if (random < proba)
			{
				_current_solution = *sol;										
			}
			if (_current_solution.get_fitness() > sol->get_fitness())
			{
				  _current_solution=*sol;
				 
			}
			if (_current_solution.get_fitness() < _best_solution.get_fitness())
			{			
				_best_solution = _current_solution;			
			}
				
			
		
			
		
		//cout << "=====================================updateSolution---END==================================" << endl;
	}

}