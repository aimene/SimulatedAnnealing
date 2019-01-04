

#include "pch.h"
#include"Problem.h"


namespace simulatedAnnealing {


	//=======================================================================
/**
 * \file       Problem.cpp
 * \author     Yanes SAID MENSOUR
 * \brief      définition des méthodes de la classe Problem de l'algorithme SA
 */



	/**
	* \brief    Construit un problème
	* \details  Initialise les valeurs  : _size_solution, LowerLimit, UpperLimit
	* \param    problem_id         \e int l'identifiant du problem
	*/
	Problem::Problem( int  problem_id): _problem_id{problem_id}
	{
		_size_solution = 20;
		switch (get_problem_id())
		{
		case Problem::rastrigin: LowerLimit = -5.12; UpperLimit = 5.12; break;
		case Problem::ackley:LowerLimit = -5; UpperLimit =5 ; break;
		case Problem::rosenbrock:LowerLimit =-2.048; UpperLimit = 2.048; break;
		case Problem::schaffer: LowerLimit =-100 ; UpperLimit =100 ; break;
		case Problem::schwefel:LowerLimit = -500; UpperLimit =500 ; break;
		case Problem::weierstrass:LowerLimit = -0.5 ; UpperLimit = 0.5 ; break;
		default:
			break;
		}
	}

	/**
	* \brief    Le destructeur du problème
	*/
	Problem::~Problem()
	{
			
	}

	/**
	* \brief	renvoie une référence vers la valeur de l'identifiant du problème
	* \return   Un \e int représentant une référence vers _id_problem
	*/
	const int& Problem::get_problem_id() const
	{
		return _problem_id;
	}

	/**
	* \brief	renvoie une référence vers la valeur de la taille de la solution
	* \return   Un \e int représentant une référence vers _size_solution
	*/
	const int& Problem::get_size_solution() const
	{
		return _size_solution;
	}

	/**
	* \brief	renvoie une référence vers la valeur de la dimension du problème
	* \return   Un \e int représentant une référence vers _dimension
	*/
	const int& Problem::get_dimension() const
	{
		return _dimension;
	}


	/**
	* \brief	renvoie un nombre réel  comprit entre  [-1,1]
	* \return   Un \e double
	*/
	double Problem::random_sign()
	{
		double value = 2 * random_01() - 1;
		return value;
	}

	/**
	* \brief	renvoie un nombre réel  comprit entre  [0,1]
	* \return   Un \e double
	*/
	double Problem::random_01()
	{
		const double kMaxPlusOne = (double)RAND_MAX + 1;
		double value = (double)rand() / kMaxPlusOne;
		return value;
	}


	/**
	* \brief	renvoie un pointeur vers une solution meilleure que la solution passée en paramètre
	* \details  cette methode génère une solution plus optimale en rajoutant à chaque valeur de la solution passé en paramètre
	*			(qui passe le teste de la probabilité avec succès) une petite valeur positive ou négative en fonction de la valeur retourné 
	*			par random_sign()
	* \return   Un \e Solution représentant un pointeur
	*/
	Solution * Problem::random_solution(const Solution& current) 
	{
		Solution *randomsolution = new Solution{ current };
		double minimiseur, probability;
		switch (randomsolution->get_problem().get_problem_id())
		{
		case rastrigin: // pour Rastrigin : r = 0.14 and p = 0.0015 / temp 1000000  and coef 0.999999
			minimiseur = 0.15; // 
			probability = 0.015; // 
			break;
		case ackley:  // pour Ackely : r = 0.1 and p = 0.0017 / temp 1000000  and coef 0.999999
			minimiseur = 0.1;
			probability = 0.017; 
			break;
		case rosenbrock: 
			minimiseur = 0.3;
			probability = 0.015; 
			break;
		case schaffer:  // pour Schaffer : r = 0.3 and p = 0.0025 / temp 1000000  and coef 0.999999
			minimiseur = 0.3;
			probability = 0.025; 
			break;
		case schwefel: // pour Schwefel : r = 0.75 and p = 0.01 / temp 1000000  and coef 0.999999
			minimiseur = 0.75;
			probability = 0.1; 
			break;
		case weierstrass: // pour Weierstrass : r = 0.3 and p = 0.1 / temp 1000000  and coef 0.999999
			minimiseur = 0.3; //0.5
			probability = 0.1; // 0.023
			break;

		default: minimiseur = 0.0015; probability = 0.5; break;
		}
		double value;
		
		double upper = current.get_problem().UpperLimit;
		double lower = current.get_problem().LowerLimit;
		for (int i = 0; i <randomsolution->get_problem().get_dimension(); i++)
		{
			if (randomsolution->random(0,1)<probability)
			{
				value = current.get_solution()[i] + minimiseur*random_01()*random_sign()*(upper - lower);
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

	

	/**
	 * \brief       constructeur de recopie d'un problème
	 * \param       pbm \e Problem problème
	 * \return      Une référence de type \e Problem
	 */
	Problem & Problem::operator=(const Problem & pbm)
	{
		if ( this->get_problem_id() != pbm.get_problem_id()) {
		_problem_id = pbm.get_problem_id();
		_size_solution = pbm.get_size_solution();
		}
		return *this;
	}
	
	/**
	 * \brief       surcharge d'opérateur de comparaison == d'un problème
	 * \param       pbm \e Problem problème
	 * \return      \e bool
	 */
	bool Problem::operator==(const Problem & pbm) const
	{
		return !(*this != pbm);
	}

	/**
	 * \brief       surcharge d'opérateur de comparaison != d'un problème
	 * \param       pbm \e Problem problème
	 * \return      \e bool
	 */
	bool Problem::operator!=(const Problem & pbm) const
	{
		if (_problem_id != pbm.get_problem_id())
			return false;
		else
			return  true;
	}

	/**
	 * \brief    surcharge d'opérateurs <<
	 * \details  permet d'afficher les variables à l'écran
	 *
	 * \param    os \e ostream flux de sortie
	 * \param    pbm \e Problem problème
	 */
	ostream & operator<<(ostream & os, const Problem & pbm)
	{

		os << "function : "  ;
		switch (pbm.get_problem_id())
		{
		case Problem::rastrigin: os <<"rastrigin" << endl;;; break;
		case Problem::ackley: os << "ackley" <<endl; break;
		case Problem::rosenbrock:os << "rosenbrock" << endl;; break;
		case Problem::schaffer: os << "schaffer" << endl;; break;
		case Problem::schwefel:os << "schwefel" << endl;; break;
		case Problem::weierstrass :os << "weierstrass" << endl;; break;
		default:
			break;
		}
		os << "dimension : "<< pbm.get_dimension() << endl;
		return os;

	}

	/**
	 * \brief       Lit avec le format: problem_id
	 * \details     permet d'entrer les valeurs numériques au clavier pour créer un problème
	 *
	 * \param       is \e istream flux d'entrée
	 * \param       pbm \e Problem problème
	 */
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
