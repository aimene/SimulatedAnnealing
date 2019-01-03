#ifndef PROBLEM_H
#define PROBLEM_H

#include<ostream>
#include<istream>
#include<iostream>
#include<vector>



namespace simulatedAnnealing {
	using namespace std;

	//=======================================================================
/**
 * \file       Problem.cpp
 * \author     Yanes SAID MENSOUR
 * \brief      d�finition des m�thodes de la class Problem de l'algorithme SA
 */
     class Problem
  {
	public:

		/**
		* \brief    Construit un probl�me
		* \details  Initialise les valeurs  : _size_solution, LowerLimit, UpperLimit
		* \param    problem_id         \e int l'identifiant du problem
		*/
		Problem( int problem_id);

		/**
		* \brief    Le destructeur du probl�me
		*/
		~Problem();

		/**
		* \brief	renvoie une r�f�rence vers la valeur de l'identifiant du problem
		* \return   Un \e int repr�sentant une r�f�rence vers _id_problem
		*/
		const int& get_problem_id()const;

		/**
		* \brief	renvoie une r�f�rence vers la valeur de la taille de la solution
		* \return   Un \e int repr�sentant une r�f�rence vers _size_solution
		*/
		const int& get_size_solution()const;

		/**
		* \brief	renvoie une r�f�rence vers la valeur de ladimension du problem
		* \return   Un \e int repr�sentant une r�f�rence vers _dimension
		*/
		const int& get_dimension() const;


		/**
		* \brief	renvoie un nombre r�el  compris entre  [-1,1]
		* \return   Un \e double
		*/
		double random_sign();

		/**
		* \brief	renvoie un nombre r�el  compris entre  [0,1]
		* \return   Un \e double
		*/
		double random_01();

		/**
		* \brief	renvoie un pointeur vers une solution meilleur que la solution pass� en param�tre
		* \details  cette methode g�n�re une solution plus optimale en rajoutant � chaque valeur de la solution pass� en param�tre
		*			(qui passe le teste de la probabilit� avec succes) une petite valeur positive ou n�gative en fonction de la valeur retourn�
		*			par random_sign()
		* \return   Un \e Solution repr�sentant un pointeur
		*/
		Solution* random_solution(const Solution& current) ;


		/**
		 * \brief       constructeur de recopie d'un probl�me
		 * \param       pbm \e Problem probl�me
		 * \return      Une r�f�rence de type \e Problem
		 */
		Problem& operator=  (const Problem& pbm);

		/**
		 * \brief       surcharge d'op�rateur de comparaison == d'un probl�me
		 * \param       pbm \e Problem probl�me
		 * \return      \e bool
		 */
		bool operator== (const Problem& pbm) const;

		/**
		 * \brief       surcharge d'op�rateur de comparaison != d'un probl�me
		 * \param       pbm \e Problem probl�me
		 * \return      \e bool
		 */
		bool operator!= (const Problem& pbm) const;

		/**
		 * \brief    surcharge d'op�rateurs <<
		 * \details  permet d'afficher les variables � l'�cran
		 *
		 * \param    os \e ostream flux de sortie
		 * \param    pbm \e Problem probl�me
		 */
		friend ostream& operator<< (ostream& os, const Problem& pbm);

		/**
		 * \brief       Lit avec le format: problem_id
		 * \details     permet d'entrer les valeurs num�riques au clavier pour cr�er un probl�me
		 *
		 * \param       is \e istream flux d'entr�e
		 * \param       pbm \e Problem probl�me
		 */
		friend istream& operator>> (istream& is, Problem& pbm);



		/**
		* \brief	le min du domaine de d�finition du probl�me
		*/
		double LowerLimit;

		/**
		* \brief	le max du domaine de d�finition du probl�me
		*/
		double UpperLimit;

		/**
		* \brief	l'identifiant de la fonction rastrigin
		*/
		const static int rastrigin = 1;

		/**
		* \brief	l'identifiant de la fonction ackley
		*/
		const static int ackley = 2;

		/**
		* \brief	l'identifiant de la fonction rosenbrock
		*/
		const static int rosenbrock = 3;

		/**
		* \brief	l'identifiant de la fonction schaffer
		*/
		const static int schaffer = 4;

		/**
		* \brief	l'identifiant de la fonction schwefel
		*/
		const static int schwefel = 5;

		/**
		* \brief	l'identifiant de la fonction weierstrass
		*/
		const static int weierstrass = 6;


	private:

		/**
		* \brief	l'identifiant de chaque probl�me
		*/
		int _problem_id;

		/**
		* \brief	la taille de la solution propre � chaque probl�me
		*/
		int _size_solution;

		/**
		* \brief	la dimension de tous les probl�mes
		*/
		const static int _dimension = 20;
  };
}
#endif //