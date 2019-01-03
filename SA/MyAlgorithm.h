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
 * \brief      Classe repr�sentant le noyau de l'algorithme
 */
  class MyAlgorithm
  {
	private:

		/**
		* \brief	les param�tres de l'algorithme  SA
		*/
	    SetUpParams& _setup;

		/**
		* \brief	le probl�me de l'algorithme 
		*/
		Problem _problem;

		/**
		* \brief	la solution courante dans un moment choisi
		*/
		Solution _current_solution;

		/**
		* \brief	la meilleur solution tirer pendant l'ex�cution de l'algorithme  SA
		*/
		Solution _best_solution;

		

	public:

		/**
		* \brief	Construit un MyAlgorithm
		* \details	Initialise les valeurs  : 	_problem{ pbm }, _setup{ setup }, _current_solution{_problem},_best_solution{_problem}		
		* \param    pbm \e Problem probl�me
		* \param    setup \e SetUpParams setup
		*/
		MyAlgorithm(const Problem& pbm, SetUpParams& setup);

		/**
		* \brief	d�truit MyAlgorithm
		*/
		~MyAlgorithm();

		/**
		* \brief	renvoie une r�f�rence vers l'objet qui contient les param�tres de l'algorithme SA
		* \return   Un \e SetUpParams repr�sentant une r�f�rence vers l'objet qui contient les param�tres de l'algorithme  SA
		*/
		const SetUpParams& get_setup() const;

		/**
		* \brief	renvoie une r�f�rence vers _best_solution qui contient la meilleur solution trouv� 
		* \return   Un \e Solution repr�sentant une r�f�rence vers  _best_solution
		*/
		const Solution& get_best_solution() const;

		/**
		* \brief	renvoie une r�f�rence vers _current_solution qui contient la solution  courante
		* \return   Un \e Solution repr�sentant une r�f�rence vers  _current_solution
		*/
		const Solution& get_current_solution() const;

		/**
		* \brief	renvoie une r�f�rence vers _problem qui contient le problem � optimiser
		* \return   Un \e Problem repr�sentant une r�f�rence vers  _problem
		*/
		const Problem& get_problem() const;

		/**
		* \brief  lance l'ex�cution de l'algorithme SA
		*/
		void run();

		/**
		* \brief  r�sout le probl�me en trouvant une solution optimale
		*/
		void solve();

		/**
		* \brief  mis � jour la solution courante et la meilleure solution en fonction de la loi de metropolis
		*/
		void updateSolution(Solution* sol);
		
		/**
		* \brief    surcharge d'op�rateurs <<
		* \details  permet d'afficher les variables � l'�cran
		*
		* \param    os \e ostream flux de sortie
		* \param    myAlgo \e MyAlgorithm algorithme
		*/
		friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);


  };
}
#endif