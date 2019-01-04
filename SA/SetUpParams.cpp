#include "pch.h"
#include "SetUpParams.h"
namespace simulatedAnnealing {
	//=======================================================================
	/**
	 * \file       SetUpParams.h
	 * \author     Bilell IMLOUL
	 * \brief      Réprésente les paramètres de l'application
	 *
	 * \details    Classe contenant tous les paramètres nécessaires pour le bon fonctionnement de l'algorithme SA.
	 */
	

	

	/**
	 * \brief       constructeur de la classe setUpParams
	 * \details     Initialise les variables de la classse.
	 *
	 * \param   max_independent_runs         le nombre maximale d'exécution indépendante  de l'algorithme
	 * \param   max_evolution_steps          le nombre maximale d'appel de la fonction objectif
	 * \param   temperature                  la temperature initiale
	 * \param   coef_decrois                 le coefficient de décroissement pour chaque iteration
	 *
	 */
	SetUpParams::SetUpParams( int   max_independent_runs,  int   max_evolution_steps, double initial_temperature, double coef_decrois):
		_max_evolution_steps{max_evolution_steps}, _max_independent_runs{ max_independent_runs }
		,_initial_temperature{ initial_temperature },_temperature{ initial_temperature },
	    _coef_decrois_temperature{coef_decrois}
	{
		set_nb_evolution_steps(1);
		set_nb_independent_runs (1);
	}

	/**
	 * \brief      renvoie _nb_independent_runs
	 * \return    \e int _nb_independent_runs
	 */
	const  int& SetUpParams::get_nb_independent_runs() const
	{
		return _nb_independent_runs;
	}

	/**
	 * \brief      renvoie _nb_evolution_steps
	 * \return    \e int _nb_evolution_steps
	 */
	const  int& SetUpParams::get_nb_evolution_steps() const
	{
		return _nb_evolution_steps;
	}
	/**
		 * \brief      renvoie _max_independent_runs
		 * \return    \e int _max_independent_runs
		 */
	const int& SetUpParams::get_max_independent_runs() const
	{
		return _max_independent_runs;
	}
	/**
	 * \brief      renvoie _max_evolution_steps
	 * \return    \e int _max_evolution_steps
	 */
	const int& SetUpParams::get_max_evolution_steps() const
	{
		return _max_evolution_steps;
	}
	/**
	 * \brief      renvoie _temperature
	 * \return    \e double _temperature
	 */
	const double & SetUpParams::get_current_temperature() const
	{
		return _temperature;
	}

	/**
	 * \brief      renvoie _temperature
	 * \return    \e double _temperature
	 */
	const double & SetUpParams::get_initial_temperature() const
	{
		return _initial_temperature;
	}
	/**
	 * \brief      renvoie _coef_decrois_temperature
	 * \return    \e double _coef_decrois_temperature
	 */
	const double & SetUpParams::get_coef_decrois_temperature()
	{
		return _coef_decrois_temperature;
	}

	/**
	* \brief      modifie la temperature en multipliant par _coef_decrois_temperature
	*/
	void SetUpParams::update_temperature()
	{
		_temperature *= _coef_decrois_temperature;

	}


	/**
	* \brief      réinitialiser la temperature actuelle par la temperature initiale
	*/
	void SetUpParams::setup_temperature()
	{
		_temperature = _initial_temperature;
	}

	/**
	* \brief      réinitialiser la temperature initialle par temp
	* \param      temp \e int la nouvelle valeur du _initial_temperature
	*/
	void SetUpParams::set_initial_temperature(double temp)
	{
		_initial_temperature = temp;
	}
	/**
	* \brief      réinitialiser _nb_evolution_steps par x
	* \param      x \e int la nouvelle valeur du compteur _nb_evolution_steps
	*/
	void SetUpParams::set_nb_evolution_steps(int x)
	{
		_nb_evolution_steps = x;
	}
	/**
	* \brief      réinitialiser _nb_independent_runs par x
	* \param      x \e int la nouvelle valeur du compteur _nb_independent_runs
	*/
	void SetUpParams::set_nb_independent_runs(int x)
	{
		_nb_independent_runs = x;
	}

	/**
	* \brief     incrémente _nb_independent_runs de 1
	*/
	void SetUpParams::increment_nb_independent_runs()
	{
		++_nb_independent_runs;
	}
	/**
	* \brief     incrémente _nb_evolution_steps de 1

	*/
	void SetUpParams::increment_nb_evolution_steps()
	{
		++_nb_evolution_steps;
	}

	/**
	 * \brief      renvoie vrai SI  _nb_independent_runs est inferieur a _max_independent_runs
	 * \return    \e bool
	 */
	bool SetUpParams::is_less__max_independent_runs() const
	{
		return _nb_independent_runs <= get_max_independent_runs();
	}

	/**
	 * \brief      renvoie vrai SI  _nb_evolution_steps est inferieur a _max_evolution_steps
	 * \return    \e bool
	 */
	bool SetUpParams::is_less_max_evolution_steps() const
	{
		return _nb_evolution_steps <= get_max_evolution_steps();
	}
	
	/**
	* \brief    surcharge d'opérateurs <<
	* \details  permet d'afficher les variables à l'écran
	*
	* \param    os \e ostream flux de sortie
	* \param    setup \e SetUpParams paramètre
	*
	*/
	ostream & operator<<(ostream & os, const SetUpParams & setup)
	{
		os << "le nombre maximum d'exécution " << setup.get_max_independent_runs() << endl;
		os << "le nombre maximum d'appel de la fonction objective" << setup.get_max_evolution_steps() << endl;
		os << "le nombre d'exécution déjà effectuée" << setup.get_nb_independent_runs() << endl;
		os << "le nombre d'appel de la fonction djà effectuée" << setup.get_nb_evolution_steps() << endl;
		os << "la temperature initialle" << setup.get_initial_temperature() << endl;
		os << "la temperature actuelle" << setup.get_current_temperature() << endl;

		return os;
	}

	/**
		 * \brief       Lit avec le format: _max_independent_runs,_max_evolution_steps,_temperature,_coef_decrois_temperature
		 * \details     permet d'entrer les valeurs numériques au clavier pour créer un paramètre
		 *
		 * \param       is \e istream flux d'entrée
		 * \param       setup \e SetUpParams paramètre
		 *
	*/
	istream& operator>> (istream& is, SetUpParams& setup)
	{		
		
		return is;
	}



	/**
	* \brief      destructeur de la classe SetUpParams
	*/

	SetUpParams::~SetUpParams()
	{
	}
}