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
		return is_less_max_evolution_steps() && is_less__max_independent_runs();
	}

	void MyAlgorithm::updateSolution(Solution sol)
	{
		double proba = 0.0;
		if (sol.get_fitness() < _current_solution.get_fitness())
		{
			proba= exp(-1*(_current_solution.get_fitness()
				- sol.get_fitness()) /
				_current_solution.get_fitness() / 
				_temperature) ;
		}
		if ((sol.get_fitness() > _current_solution.get_fitness())|| (rand()<proba))
		{
			_current_solution = sol;
			if (sol.get_fitness() > _best_solution.get_fitness())
			{
				_best_solution = sol;
				_nb_evolution_steps = 0;
			}
		}
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
		return _nb_independent_runs>=_setup.max_evolution_steps;
	}

	bool MyAlgorithm::is_less_max_evolution_steps() const
	{
		return _nb_evolution_steps>=_setup.max_evolution_steps;
	}

	void MyAlgorithm::solve()
	{

	}

}