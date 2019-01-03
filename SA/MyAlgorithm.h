#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include"Problem.h"
#include"SetUpParams.h"
#include"Solution.h"
#include<vector>
#include<iostream>

#include <cstdlib>
using namespace std;

namespace simulatedAnnealing {
	


	using namespace std;

//=======================================================================
/**
 * \file       MyAlgorith.h
 * \author     Preyankan Anandharoopan
 * \version    1.7
 * \date       13 Novembre 2015
 * \brief      Classe représentant le noyau de l'algorithme
 */
  class MyAlgorithm
  {
	private:

		/**
		* \brief	les paramètres de l'algorithme  SA
		*/
	    SetUpParams& _setup;

		/**
		* \brief	le problème de l'algorithme 
		*/
		Problem _problem;

		/**
		* \brief	la solution courante dans un moment choisi
		*/
		Solution _current_solution;

		/**
		* \brief	la meilleur solution tirer pendant l'exécution de l'algorithme  SA
		*/
		Solution _best_solution;

		

	public:

		/**
		* \brief	Construit un MyAlgorithm
		* \details	Initialise les valeurs  : 	_problem{ pbm }, _setup{ setup }, _current_solution{_problem},_best_solution{_problem}		
		* \param    pbm \e Problem problème
		* \param    setup \e SetUpParams setup
		*/
		MyAlgorithm(const Problem& pbm, SetUpParams& setup);

		/**
		* \brief	détruit MyAlgorithm
		*/
		~MyAlgorithm();

		/**
		* \brief	renvoie une référence vers l'objet qui contient les paramètres de l'algorithme SA
		* \return   Un \e SetUpParams représentant une référence vers l'objet qui contient les paramètres de l'algorithme  SA
		*/
		const SetUpParams& get_setup() const;

		/**
		* \brief	renvoie une référence vers _best_solution qui contient la meilleur solution trouvé 
		* \return   Un \e Solution représentant une référence vers  _best_solution
		*/
		const Solution& get_best_solution() const;

		/**
		* \brief	renvoie une référence vers _current_solution qui contient la solution  courante
		* \return   Un \e Solution représentant une référence vers  _current_solution
		*/
		const Solution& get_current_solution() const;

		/**
		* \brief	renvoie une référence vers _problem qui contient le problem à optimiser
		* \return   Un \e Problem représentant une référence vers  _problem
		*/
		const Problem& get_problem() const;

		/**
		* \brief  lance l'exécution de l'algorithme SA
		*/
		void run();

		/**
		* \brief  résout le problème en trouvant une solution optimale
		*/
		void solve();

		/**
		* \brief  mis à jour la solution courante et la meilleure solution en fonction de la loi de metropolis
		*/
		void updateSolution(Solution* sol);
		
		/**
		* \brief    surcharge d'opérateurs <<
		* \details  permet d'afficher les variables à l'écran
		*
		* \param    os \e ostream flux de sortie
		* \param    myAlgo \e MyAlgorithm algorithme
		*/
		friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);


  };
}
#endif