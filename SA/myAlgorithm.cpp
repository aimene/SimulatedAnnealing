#include "pch.h"
#include"MyAlgorithm.h"

namespace simulatedAnnealing {


	/**
	* \brief	Construit un MyAlgorithm
	* \details	Initialise les valeurs  : 	_problem{ pbm }, _setup{ setup }, _current_solution{_problem},_best_solution{_problem}
	* \param    pbm \e Problem problème
	* \param    setup \e SetUpParams setup
	*/
	MyAlgorithm::MyAlgorithm(const Problem & pbm,  SetUpParams & setup) :
		_problem{ pbm }, _setup{ setup }, _current_solution{_problem}
	,_best_solution{_problem}
	{
		
	}

	/**
	* \brief	détruit MyAlgorithm
	*/
	MyAlgorithm::~MyAlgorithm()
	{
	}

	/**
	* \brief	renvoie une référence vers l'objet qui contient les paramètres de l'algorithme SA
	* \return   Un \e SetUpParams représentant une référence vers l'objet qui contient les paramètres de l'algorithme  SA
	*/
	const SetUpParams & MyAlgorithm::get_setup() const
	{
		return _setup;

	}

	/**
	* \brief	renvoie une référence vers _best_solution qui contient la meilleur solution trouvé
	* \return   Un \e Solution représentant une référence vers  _best_solution
	*/
	const Solution& MyAlgorithm::get_best_solution() const
	{
		return _best_solution;
	}

	/**
	* \brief	renvoie une référence vers _current_solution qui contient la solution  courante
	* \return   Un \e Solution représentant une référence vers  _current_solution
	*/
	const Solution & MyAlgorithm::get_current_solution() const
	{
		return _current_solution;
	}
	/**
		* \brief	renvoie une référence vers _problem qui contient le problem à optimiser
		* \return   Un \e Problem représentant une référence vers  _problem
	*/
	const Problem & MyAlgorithm::get_problem() const
	{
		return _problem;
	}

	/**
	* \brief  lance l'exécution de l'algorithme SA
	*/
	void MyAlgorithm::run()
	{
		_best_solution = _current_solution;
		while (_setup.is_less__max_independent_runs())
		{
			std::cout << "================= run( " << _setup.get_nb_independent_runs() << " )=====================" << endl;
			std::cout << _best_solution << std::endl;

			_setup.setup_temperature();
			solve();
			_setup.increment_nb_independent_runs();

			std::cout << _best_solution << std::endl;
		}
	}

	/**
	* \brief  résout le problème en trouvant une solution optimale
	*/
	void MyAlgorithm::solve()

	{
		
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
		delete sol;
		_setup.set_nb_evolution_steps(0);

	}

	/**
	* \brief  mis à jour la solution courante et la meilleure solution en fonction de la loi de metropolis
	*/
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
				
	}

   /**
	* \brief    surcharge d'opérateurs <<
	* \details  permet d'afficher les variables à l'écran
	*
	* \param    os \e ostream flux de sortie
	* \param    myAlgo \e MyAlgorithm algorithme
	*/	
	ostream & operator<<(ostream & os, const MyAlgorithm & myAlgo)
	{
		os << myAlgo.get_problem() << endl;
		os << myAlgo.get_setup() << endl;
		os << myAlgo.get_current_solution() << endl;
		os << myAlgo.get_best_solution() << endl;
	}

}