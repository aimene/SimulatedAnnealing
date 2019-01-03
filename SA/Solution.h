#ifndef SOLUTION_H
#define SOLUTION_H
#include <cmath>
#define M_PI 3.14159265358979323846
#define alphaa 418.9829




#include<vector>
namespace simulatedAnnealing {
	using namespace std;
	class Problem;

    class Solution
  {
		
	public:
		/**
		* \brief	Construit une Solution � partir d'un probl�me
		* \param    pbm \e Problem probl�me
		*/
		Solution (const Problem& pbm);

		/**
		* \brief	Construit une Solution � partir d'une autre solution 
		* \param    pbm \e Solution Solution
		*/
		Solution (const Solution& sol);

		/**
		* \brief	d�truit un solution
		*/
		~Solution();

		/**
		* \brief    initialise le tableau _solution
		*/
		void initialize();

		/**
		* \brief	calcule la fitness de _solution et la stocke dans _current_fitness
		*/
		void fitness();

		/**
		* \brief	renvoie le fitness
		* \return	Un \e double le fitness de la solution
		*/
		double get_fitness() const;


		/**
		* \brief	renvoie une r�f�rence vers le probl�me de cette solution
		* \return   Un \e Problem repr�sentant une r�f�rence vers _problem
		*/
		const Problem& get_problem() const;

		/**
		* \brief	renvoie une r�f�rence vers le tableau de solution 
		* \return   Un \e  vector<double> repr�sentant une r�f�rence vers _solution
		*/
	    const vector<double>& get_solution() const ;

		/**
		* \brief      change la valeur de _solution en position i par value
		* \param      i \e int la position de la valeur � changer
		* \param      value \e double  la valeur de remplacement 
		*/
		void set_solution(int i , double value) ;

		/**
		* \brief	renvoie un nombre r�el compris entre [min,max]
		* \param      min \e double minimum de l'intervalle
		* \param      max \e int la maximum de l'intervalle
		* \return   Un \e  double un nombre r�el compris entre [min,max]
		*/
		double random(double min, double max) const;


		/**
		* \brief	renvoie la fitness de _solution pour rastrigin
		* \return   Un \e  double 
		*/
		double rastrigin();

		/**
		* \brief	renvoie la fitness de _solution pour ackley
		* \return   Un \e  double
		*/
		double ackley();

		/**
		* \brief	renvoie la fitness de _solution pour rosenbrock
		* \return   Un \e  double
		*/
		double rosenbrock();

		/**
		* \brief	renvoie la fitness de _solution pour schaffer
		* \return   Un \e  double
		*/
		double schaffer();

		/**
		* \brief	renvoie la fitness de _solution pour schwefel
		* \return   Un \e  double
		*/
		double schwefel();

		/**
		* \brief	renvoie la fitness de _solution pour weierstrass
		* \return   Un \e  double
		*/
		double weierstrass();

		/**
		 * \brief    surcharge d'op�rateurs <<
		 * \details  permet d'afficher les variables � l'�cran
		 *
		 * \param    os \e ostream flux de sortie
		 * \param    sol \e Solution solution
		 */
		friend ostream& operator<< (ostream& os, const Solution& sol);

		/**
		 * \brief       Lit avec le format: (x1,x2,x2,....,xn)
		 * \details     permet d'entrer les valeurs num�riques au clavier pour cr�er une solution
		 *
		 * \param       is \e istream flux d'entr�e
		 * \param       sol \e Solution solution
		 */
		friend istream& operator>> (istream& is, Solution& sol);

		/**
		 * \brief       constructeur de recopie d'un probl�me
		 * \param       sol \e Solution solution
		 * \return      Une r�f�rence de type \e Solution
		 */
		Solution& operator=  (const Solution& sol);

		/**
		* \brief    surcharge d'op�rateurs ==
		* \param    sol \e Solution solution
		* \return	 Un \e bool
		*/
		bool operator== (const Solution& sol) const;

		/**
		* \brief    surcharge d'op�rateurs !=
		* \param    sol \e Solution solution
		* \return	 Un \e bool
		*/
		bool operator!= (const Solution& sol) const;

	


	private:

		/**
		* \brief	le tableau qui contient l'ensemble de valeurs de la solutions
		*/
        vector<double> _solution;

		/**
		* \brief	la fitness de _solution en fonction de _problem
		*/
        double _current_fitness;

		/**
		* \brief	probl�me
		*/
	    const  Problem& _problem;
  };
}
#endif // !SOLUTION_H