
#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H


#include<istream>
#include<ostream>

/**
 * \file       SetUpParams.h
 * \author     Imloul bilell
 * \brief      Réprésente les paramètres de l'application
 *
 * \details    Classe contenant tous les paramètres nécessaires pour le bon fonctionnement de l'algorithme SA.
 */
namespace simulatedAnnealing {
	using namespace std;
      class SetUpParams
  {

	private:

		/**
			 * \brief    le nombre maximale d'exécution indépendante  de l'algorithme
		 */
		 const  int   _max_independent_runs ;   
		 /**
			 * \brief    le nombre maximale d'appel de la fonction objectif
		 */
		 const  int   _max_evolution_steps  ;     
		 /**
		 * \brief   compteur du d'exécution indépendante  de l'algorithme
		 */
		  int _nb_independent_runs;
		 /**
			* \brief    compteur du nombre  d'appel de la fonction objectif
		 */
		  int _nb_evolution_steps;
		 /**
		   * \brief   la temperature actuelle de l'algorithme
		 */
		 double _temperature;

		 /**
		   * \brief   la temperature initiale de l'algorithme
		 */
		 double  _initial_temperature;

		 /**
		  * \brief   le  coefficient de décroissement de la temperature
		 */
		 double _coef_decrois_temperature;

		
		

	public:
		/**
		 * \brief       constructeur par defaut de la classe setUpParams
		 * \details     Initialise les variables de la classse.
		 *
		 * \param   max_independent_runs         le nombre maximale d'exécution indépendante  de l'algorithme
		 * \param   max_evolution_steps          le nombre maximale d'appel de la fonction objectif
		 * \param   temperature                  la temperature initiale  
		 * \param   coef_decrois                  le coefficient de décroissement pour chaque iteration
		 *
		 */
		SetUpParams(int   max_independent_runs, int   max_evolution_steps,double temperature,double coef_decrois);

		/**
		 * \brief      renvoie _nb_independent_runs
		 * \return    \e int _nb_independent_runs		
		 */
		const  int&   get_nb_independent_runs() const;

		/**
		 * \brief      renvoie _nb_evolution_steps
		 * \return    \e int _nb_evolution_steps
		 */
		const  int&   get_nb_evolution_steps() const;

		/**
		 * \brief      renvoie _max_independent_runs
		 * \return    \e int _max_independent_runs
		 */
		const  int&   get_max_independent_runs() const;


		/**
		 * \brief      renvoie _max_evolution_steps
		 * \return    \e int _max_evolution_steps
		 */
		const  int&  get_max_evolution_steps() const;

		/**
		 * \brief      renvoie _temperature
		 * \return    \e double _temperature
		 */
		const double& get_temperature();

		/**
		 * \brief      renvoie _coef_decrois_temperature
		 * \return    \e double _coef_decrois_temperature
		 */
		const double& get_coef_decrois_temperature();

		/**
		* \brief      modifie la temperature en multipliant par _coef_decrois_temperature
		*/
		void update_temperature();

		/**
		* \brief      réinitialiser la temperature actuelle par la temperature initiale 
		*/
		void setup_temperature();

		/**
		* \brief      réinitialiser _nb_evolution_steps par x 
		* \param      x \e int la nouvelle valeur du compteur _nb_evolution_steps
		*/
		void setup_nb_evolution_steps(int x);

		/**
		* \brief      réinitialiser _nb_independent_runs par x
		* \param      x \e int la nouvelle valeur du compteur _nb_independent_runs
		*/
		void setup_nb_independent_runs(int x);

		/**
		* \brief     incrémente _nb_independent_runs de 1
		*/
		void increment_nb_independent_runs();

		/**
		* \brief     incrémente _nb_evolution_steps de 1
		
		*/
		void increment_nb_evolution_steps();

		/**
		 * \brief      renvoie vrai SI  _nb_independent_runs est inferieur a _max_independent_runs
		 * \return    \e bool 
		 */
		bool is_less__max_independent_runs()const;

		/**
		 * \brief      renvoie vrai SI  _nb_evolution_steps est inferieur a _max_evolution_steps
		 * \return    \e bool
		 */
		bool is_less_max_evolution_steps()const;
		
		/**
		* \brief    surcharge d'opérateurs <<
		* \details  permet d'afficher les variables à l'écran
		*
		* \param    os \e ostream flux de sortie
		* \param    setup \e SetUpParams paramètre
		*
		*/
 		friend ostream& operator<< (ostream& os, const SetUpParams& setup);
		/**
		 * \brief       Lit avec le format: _max_independent_runs,_max_evolution_steps,_temperature,_coef_decrois_temperature
		 * \details     permet d'entrer les valeurs numériques au clavier pour créer un paramètre
		 *
		 * \param       is \e istream flux d'entrée
		 * \param       setup \e SetUpParams paramètre
		 *
		 */
		friend istream& operator>> (istream& is, SetUpParams& setup);

		



		



		~SetUpParams();
  };
}
#endif // !SETUPPARAMS_H