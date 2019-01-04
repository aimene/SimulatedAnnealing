#include "pch.h"
#include"Solution.h"
#include"Problem.h"
#include <math.h>
#include<algorithm>
namespace simulatedAnnealing
 {

	// constructors

	
		/**Construit une Solution � partir d'un probl�me
		* \para
		* \brief	m    pbm \e Problem probl�me
		*/
		Solution::Solution(const Problem & pbm) : _problem{ pbm } {
			initialize();
			fitness();
		}

		/**
		* \brief	Construit une Solution � partir d'une autre solution
		* \param    pbm \e Solution Solution
		*/
		Solution::Solution(const Solution & sol): _problem{sol.get_problem()}
		{
			*this = sol;

		}

		/**
		* \brief	d�truit un solution
		*/
		Solution::~Solution()
		{
		}

		/**
		* \brief    initialise le tableau _solution
		*/
		void Solution::initialize()
		{
			_solution.clear();

			for (int i = 0; i < _problem.get_size_solution(); i++)
			{
				double x1 = random(_problem.LowerLimit, _problem.UpperLimit);

				_solution.push_back(x1);
			}
		}

		/**
		* \brief	calcule la fitness de _solution et la stocke dans _current_fitness
		*/
		void Solution::fitness()
		{

			switch (_problem.get_problem_id())
			{
			case Problem::rastrigin: _current_fitness = rastrigin(); break;
			case Problem::ackley: _current_fitness = ackley(); break;
			case Problem::rosenbrock: _current_fitness = rosenbrock(); break;
			case Problem::schaffer:_current_fitness = schaffer(); break;
			case Problem::schwefel:_current_fitness = schwefel(); break;
			case Problem::weierstrass:_current_fitness = weierstrass(); break;
			default:
				break;
			}

		}

		/**
		* \brief	renvoie le fitness
		* \return	Un \e double le fitness de la solution
		*/
		double Solution::get_fitness() const
		{
			return _current_fitness;
		}

		/**
		* \brief	renvoie une r�f�rence vers le probl�me de cette solution
		* \return   Un \e Problem repr�sentant une r�f�rence vers _problem
		*/
		const Problem & Solution::get_problem() const
		{
			return  _problem;
		}

		/**
		* \brief	renvoie une r�f�rence vers le tableau de solution
		* \return   Un \e  vector<double> repr�sentant une r�f�rence vers _solution
		*/
		const vector<double>& Solution::get_solution() const
		{
			return _solution;
		}

		/**
		* \brief      change la valeur de _solution en position i par value
		* \param      i \e int la position de la valeur � changer
		* \param      value \e double  la valeur de remplacement
		*/
		void Solution::set_solution(int i, double value)
		{
			_solution[i] = value;
		}


		/**
		* \brief	renvoie un nombre r�el compris entre [min,max]
		* \param      min \e double minimum de l'intervalle
		* \param      max \e int la maximum de l'intervalle
		* \return   Un \e  double un nombre r�el compris entre [min,max]
		*/
		double Solution::random(double min, double max) const
		{
			double f = (double)rand() / RAND_MAX;
			return min + f * (max - min);
		}


		/**
		* \brief	renvoie la fitness de _solution pour rastrigin
		* \details    f(0,0,0,0,0,...) =0
		* \return   Un \e  double
		*/
		double Solution::rastrigin()
		{
	
			double top = 0;
			for ( int j = 0; j < _problem.get_dimension(); j++)
			{
				top = top + (pow(_solution[j], (double)2) - 10 * cos(2 * M_PI*_solution[j]) + 10);
			}
			return top;
		}

		/**
		* \brief	renvoie la fitness de _solution pour ackley
		* \details  f(0,0,0,0,0,...) =0
		* \return   Un \e  double
		*/
		double Solution::ackley()
		{
			 double a = 20.0;
			 double b = 0.2;
			 double c = 2 * M_PI;
			 double dimesntion = _problem.get_dimension();
			 double sum1 = 0.0, sum2 = 0.0;
			for (int i = 0; i < dimesntion; i++) {
				sum1 += pow(_solution[i], 2);
				sum2 += cos(c*get_solution()[i]);
			}
			return -a*exp(-b* sqrt((double(1) / dimesntion)*sum1)) - exp((double(1) / dimesntion)*sum2) + a + exp(1);
		}

		/**
		* \brief	renvoie la fitness de _solution pour rosenbrock
		* \details  f(1,1,1,1,1,...) =0
		* \return   Un \e  double
		*/
		double Solution::rosenbrock()
		{
			const double ALPHA = 100.0;
			double sum = 0.0;
			for (int i = 0; i < _problem.get_dimension() - 1; i++)
			{
				double temp1 =  _solution[i + 1] - pow(_solution[i], 2);
				double temp2 = _solution[i] - double(1.0);
				sum += ALPHA *pow( temp1 ,2) + pow(temp2, 2);
			}
			return sum;
		}

		/**
		* \brief	renvoie la fitness de _solution pour schaffer
		* \details  f(0,0,0,0,0,...) =0
		* \return   Un \e  double
		*/
		double Solution::schaffer()
		{
			const double A = 0.5;
			const double B = 0.001;
			double sum = 0.0;
			for (int i = 0; i < _problem.get_dimension()-1; ++i)
				sum += A + (double(pow(sin(pow(_solution[i], 2) - pow(_solution[i + 1], 2)), 2) - A) / pow(1 + B*(pow(_solution[i], 2) + pow(_solution[i + 1], 2)), 2));
			return sum;
		}

		/**
		* \brief	renvoie la fitness de _solution pour schwefel
		* \details  f(420.9687,..........,420.9687 )=0
		* \return   Un \e  double
		*/
		double Solution::schwefel()
		{
			const double alpha = 418.9829;
			double sum = 0.0;
			for (int i = 0; i < _problem.get_dimension(); ++i)
			{
				sum += _solution[i] * sin(sqrt(abs(_solution[i])));
			}

			return (alpha*_solution.size() - sum); // min 420.9687
		}

		/**
		* \brief	renvoie la fitness de _solution pour weierstrass
		* \details    f(0,0,0,0,0,...) =0
		* \return   Un \e  double
		*/
		double Solution::weierstrass()
		{
			const double a = 0.5;
			const double b = 3;
			const double Kmax =20 ;

			double sum1 = 0.0;
			double sum2 = 0.0;
			for (int i = 0; i < _problem.get_dimension(); i++)
			{
				for (int k = 0; k <= Kmax; k++)
				{
					sum1 += pow(a, k) * cos(2.0*M_PI * pow(b, k) * (_solution[i] + a));
				}
				sum2 += pow(a, i) * cos(2.0*M_PI * pow(b, i) * (a));
			}

		
			return (sum1 - sum2 * (_solution.size()));
		}

		/**
		 * \brief    surcharge d'op�rateurs <<
		 * \details  permet d'afficher les variables � l'�cran
		 *
		 * \param    os \e ostream flux de sortie
		 * \param    sol \e Solution solution
		 */
		ostream & operator<<(ostream & os, const Solution & sol)
		{
			os << "=============================================================================" << endl;
			os << "  " << endl;

			os << sol.get_problem() << endl;
			os << "Values of solution :" << endl;
			os << " ( ";
			for (double x : sol.get_solution()) {
				os << x << " , ";
			}
			os << " ) " << endl;
			os << "  " << endl;

			os << "Current fitness :"  ;
			os << sol.get_fitness() << endl;
			os << "  " << endl;

	
			os << "=============================================================================" << endl;
			return os;
		}

		/**
		 * \brief       Lit avec le format: (x1,x2,x2,....,xn)
		 * \details     permet d'entrer les valeurs num�riques au clavier pour cr�er une solution
		 *
		 * \param       is \e istream flux d'entr�e
		 * \param       sol \e Solution solution
		 */
		istream & operator>>(istream & is, Solution & sol)
		{
			vector<double> _solution;
		
			return is;

		}

		/**
		 * \brief       constructeur de recopie d'un probl�me
		 * \param       sol \e Solution solution
		 * \return      Une r�f�rence de type \e Solution
		 */
		Solution & Solution::operator=(const Solution & sol)
		{
			if (get_problem().get_problem_id() ==
				sol.get_problem().get_problem_id())
			{
				_solution = sol.get_solution();
				_current_fitness = sol.get_fitness();

			}
			return *this;
		}

		/**
		* \brief    surcharge d'op�rateurs ==
		* \param    sol \e Solution solution
		* \return	 Un \e bool
		*/
		bool Solution::operator==(const Solution & sol) const
		{
			return _solution == sol.get_solution() &&
				_current_fitness == sol.get_fitness() &&
				_problem == sol.get_problem();
		}

		/**
		* \brief    surcharge d'op�rateurs !=
		* \param    sol \e Solution solution
		* \return	 Un \e bool
		*/
		bool Solution::operator!=(const Solution & sol) const
		{
			return !(*this == sol);
		}
}