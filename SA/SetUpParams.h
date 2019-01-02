
#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H


#include<istream>
#include<ostream>

namespace simulatedAnnealing {
	using namespace std;
      class SetUpParams
  {
  	//ici vous devez mettre quelques paramètres tels que :

	private:

		 const  int   _max_independent_runs ;         //number of independent runs
		 const  int   _max_evolution_steps  ;       // number of iterations per run

		 unsigned int _nb_independent_runs;
		 unsigned int _nb_evolution_steps;

		 double _temperature;

		
		

	public:
		const  int&   get_nb_independent_runs() const;
		const  int&   get_nb_evolution_steps() const;

		const  int&   get_max_independent_runs() const;
		const  int&  get_max_evolution_steps() const;

		const double& get_temperature();

		void update_temperature(const double& x);
		void setup_temperature(const double& x);

		void setup_nb_evolution_steps(int x);
		void setup_nb_independent_runs(int x);

		void increment_nb_independent_runs();
		void increment_nb_evolution_steps();

		bool is_less__max_independent_runs()const;
		bool is_less_max_evolution_steps()const;
		
		SetUpParams( int   _max_independent_runs,  int   _max_evolution_steps);
 		friend ostream& operator<< (ostream& os, const SetUpParams& setup);
		friend istream& operator>> (istream& is, SetUpParams& setup);

		



		



		~SetUpParams();
  };
}
#endif // !SETUPPARAMS_H