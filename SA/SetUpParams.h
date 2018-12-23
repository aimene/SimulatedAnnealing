
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

		 const unsigned int   _max_independent_runs ;         //number of independent runs
		 const unsigned int   _max_evolution_steps  ;       // number of iterations per run

	
		
		//unsigned int   _population_size;		// number of solutions in the population
		//unsigned int   _solution_size;	        // size of each particle

	public:
		
		SetUpParams(unsigned int   _max_independent_runs, unsigned int   _max_evolution_steps);
 		friend ostream& operator<< (ostream& os, const SetUpParams& setup);
		friend istream& operator>> (istream& is, SetUpParams& setup);

		const unsigned int   max_independent_runs() const;
		const unsigned int   max_evolution_steps() const;






		~SetUpParams();
  };
}
#endif // !SETUPPARAMS_H