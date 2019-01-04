
#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H


#include<istream>
#include<ostream>

/**
 * \file       SetUpParams.h
 * \author     Bilell IMLOUL
 * \brief      R�pr�sente les param�tres de l'application
 *
 * \details    Classe contenant tous les param�tres n�cessaires pour le bon fonctionnement de l'algorithme SA.
 */
namespace simulatedAnnealing {
	using namespace std;
      class SetUpParams
  {

	private:

		/**
			 * \brief    le nombre maximal d'ex�cution ind�pendante  de l'algorithme
		 */
		 const  int   _max_independent_runs ;   
		 /**
			 * \brief    le nombre maximal d'appel de la fonction objectif
		 */
		 const  int   _max_evolution_steps  ;     
		 /**
		 * \brief   compteur du d'ex�cution ind�pendante  de l'algorithme
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
		  * \brief   le  coefficient de d�croissement de la temperature
		 */
		 double _coef_decrois_temperature;

		
		

	public:

		/**
		 * \brief       constructeur par defaut de la classe setUpParams
		 * \details     Initialise les variables de la classse.
		 *
		 */
		SetUpParams();
		/**
		 * \brief       constructeur par defaut de la classe setUpParams
		 * \details     Initialise les variables de la classse.
		 *
		 * \param   max_independent_runs         le nombre maximale d'ex�cution ind�pendante  de l'algorithme
		 * \param   max_evolution_steps          le nombre maximale d'appel de la fonction objectif
		 * \param   temperature                  la temperature initiale  
		 * \param   coef_decrois                 le coefficient de d�croissement pour chaque iteration
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
		const double& get_current_temperature() const;

		/**
		 * \brief      renvoie _initial_temperature
		 * \return    \e double _initial_temperature
		 */
		const double& get_initial_temperature() const;

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
		* \brief      r�initialiser la temperature actuelle par la temperature initiale 
		*/
		void setup_temperature();

		/**
		* \brief      r�initialiser la temperature initiale par temp
		* \param      temp \e int la nouvelle valeure du _initial_temperature
		*/
		void set_initial_temperature(double temp);

		/**
		* \brief      r�initialiser _nb_evolution_steps par x 
		* \param      x \e int la nouvelle valeure du compteur _nb_evolution_steps
		*/
		void set_nb_evolution_steps(int x);

		/**
		* \brief      r�initialiser _nb_independent_runs par x
		* \param      x \e int la nouvelle valeure du compteur _nb_independent_runs
		*/
		void set_nb_independent_runs(int x);

	
		/**
		* \brief     incr�mente _nb_independent_runs de 1
		*/

		void increment_nb_independent_runs();

		/**
		* \brief     incr�mente _nb_evolution_steps de 1
		
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
		* \brief    surcharge d'op�rateurs <<
		* \details  permet d'afficher les variables � l'�cran
		*
		* \param    os \e ostream flux de sortie
		* \param    setup \e SetUpParams param�tre
		*
		*/
 		friend ostream& operator<< (ostream& os, const SetUpParams& setup);
		/**
		 * \brief       Lit avec le format: _max_independent_runs,_max_evolution_steps,_temperature,_coef_decrois_temperature
		 * \details     permet d'entrer les valeurs num�riques au clavier pour cr�er un param�tre
		 *
		 * \param       is \e istream flux d'entr�e
		 * \param       setup \e SetUpParams param�tre
		 *
		 */
		friend istream& operator>> (istream& is, SetUpParams& setup);

		



		

		/**
		* \brief      destructeur de la classe SetUpParams
		*/

		~SetUpParams();
	
		
  };
}
#endif // !SETUPPARAMS_H