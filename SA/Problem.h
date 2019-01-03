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
 * \brief      définition des méthodes de la class Problem de l'algorithme SA
 */
     class Problem
  {
	public:

		/**
		* \brief    Construit un problème
		* \details  Initialise les valeurs  : _size_solution, LowerLimit, UpperLimit
		* \param    problem_id         \e int l'identifiant du problem
		*/
		Problem( int problem_id);

		/**
		* \brief    Le destructeur du problème
		*/
		~Problem();

		/**
		* \brief	renvoie une référence vers la valeur de l'identifiant du problem
		* \return   Un \e int représentant une référence vers _id_problem
		*/
		const int& get_problem_id()const;

		/**
		* \brief	renvoie une référence vers la valeur de la taille de la solution
		* \return   Un \e int représentant une référence vers _size_solution
		*/
		const int& get_size_solution()const;

		/**
		* \brief	renvoie une référence vers la valeur de ladimension du problem
		* \return   Un \e int représentant une référence vers _dimension
		*/
		const int& get_dimension() const;


		/**
		* \brief	renvoie un nombre réel  compris entre  [-1,1]
		* \return   Un \e double
		*/
		double random_sign();

		/**
		* \brief	renvoie un nombre réel  compris entre  [0,1]
		* \return   Un \e double
		*/
		double random_01();

		/**
		* \brief	renvoie un pointeur vers une solution meilleur que la solution passé en paramètre
		* \details  cette methode génère une solution plus optimale en rajoutant à chaque valeur de la solution passé en paramètre
		*			(qui passe le teste de la probabilité avec succes) une petite valeur positive ou négative en fonction de la valeur retourné
		*			par random_sign()
		* \return   Un \e Solution représentant un pointeur
		*/
		Solution* random_solution(const Solution& current) ;


		/**
		 * \brief       constructeur de recopie d'un problème
		 * \param       pbm \e Problem problème
		 * \return      Une référence de type \e Problem
		 */
		Problem& operator=  (const Problem& pbm);

		/**
		 * \brief       surcharge d'opérateur de comparaison == d'un problème
		 * \param       pbm \e Problem problème
		 * \return      \e bool
		 */
		bool operator== (const Problem& pbm) const;

		/**
		 * \brief       surcharge d'opérateur de comparaison != d'un problème
		 * \param       pbm \e Problem problème
		 * \return      \e bool
		 */
		bool operator!= (const Problem& pbm) const;

		/**
		 * \brief    surcharge d'opérateurs <<
		 * \details  permet d'afficher les variables à l'écran
		 *
		 * \param    os \e ostream flux de sortie
		 * \param    pbm \e Problem problème
		 */
		friend ostream& operator<< (ostream& os, const Problem& pbm);

		/**
		 * \brief       Lit avec le format: problem_id
		 * \details     permet d'entrer les valeurs numériques au clavier pour créer un problème
		 *
		 * \param       is \e istream flux d'entrée
		 * \param       pbm \e Problem problème
		 */
		friend istream& operator>> (istream& is, Problem& pbm);



		/**
		* \brief	le min du domaine de définition du problème
		*/
		double LowerLimit;

		/**
		* \brief	le max du domaine de définition du problème
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
		* \brief	l'identifiant de chaque problème
		*/
		int _problem_id;

		/**
		* \brief	la taille de la solution propre à chaque problème
		*/
		int _size_solution;

		/**
		* \brief	la dimension de tous les problèmes
		*/
		const static int _dimension = 20;
  };
}
#endif //