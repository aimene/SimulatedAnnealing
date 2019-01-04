

#include "pch.h"
#include"Problem.h"


namespace simulatedAnnealing {


	//=======================================================================
/**
 * \file       Problem.cpp
 * \author     Yanes SAID MENSOUR
 * \brief      d�finition des m�thodes de la classe Problem de l'algorithme SA
 */



	/**
	* \brief    Construit un probl�me
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
	* \brief    Le destructeur du probl�me
	*/
	Problem::~Problem()
	{
			
	}

	/**
	* \brief	renvoie une r�f�rence vers la valeur de l'identifiant du probl�me
	* \return   Un \e int repr�sentant une r�f�rence vers _id_problem
	*/
	const int& Problem::get_problem_id() const
	{
		return _problem_id;
	}

	/**
	* \brief	renvoie une r�f�rence vers la valeur de la taille de la solution
	* \return   Un \e int repr�sentant une r�f�rence vers _size_solution
	*/
	const int& Problem::get_size_solution() const
	{
		return _size_solution;
	}

	/**
	* \brief	renvoie une r�f�rence vers la valeur de la dimension du probl�me
	* \return   Un \e int repr�sentant une r�f�rence vers _dimension
	*/
	const int& Problem::get_dimension() const
	{
		return _dimension;
	}


	/**
	* \brief	renvoie un nombre r�el  comprit entre  [-1,1]
	* \return   Un \e double
	*/
	double Problem::random_sign()
	{
		double value = 2 * random_01() - 1;
		return value;
	}

	/**
	* \brief	renvoie un nombre r�el  comprit entre  [0,1]
	* \return   Un \e double
	*/
	double Problem::random_01()
	{
		const double kMaxPlusOne = (double)RAND_MAX + 1;
		double value = (double)rand() / kMaxPlusOne;
		return value;
	}


	/**
	* \brief	renvoie un pointeur vers une solution meilleure que la solution pass�e en param�tre
	* \details  cette methode g�n�re une solution plus optimale en rajoutant � chaque valeur de la solution pass� en param�tre
	*			(qui passe le teste de la probabilit� avec succ�s) une petite valeur positive ou n�gative en fonction de la valeur retourn� 
	*			par random_sign()
	* \return   Un \e Solution repr�sentant un pointeur
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
	 * \brief       constructeur de recopie d'un probl�me
	 * \param       pbm \e Problem probl�me
	 * \return      Une r�f�rence de type \e Problem
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
	 * \brief       surcharge d'op�rateur de comparaison == d'un probl�me
	 * \param       pbm \e Problem probl�me
	 * \return      \e bool
	 */
	bool Problem::operator==(const Problem & pbm) const
	{
		return !(*this != pbm);
	}

	/**
	 * \brief       surcharge d'op�rateur de comparaison != d'un probl�me
	 * \param       pbm \e Problem probl�me
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
	 * \brief    surcharge d'op�rateurs <<
	 * \details  permet d'afficher les variables � l'�cran
	 *
	 * \param    os \e ostream flux de sortie
	 * \param    pbm \e Problem probl�me
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
	 * \details     permet d'entrer les valeurs num�riques au clavier pour cr�er un probl�me
	 *
	 * \param       is \e istream flux d'entr�e
	 * \param       pbm \e Problem probl�me
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
