
#include<istream>
#include<ostream>

namespace simulatedAnnealing {
	using namespace std;
      class SetUpParams
  {
  	//ici vous devez mettre quelques paramètres tels que :

	private:
		static const unsigned int   _independent_runs = 2000000;         //number of independent runs
		static const unsigned int   _nb_evolution_steps = 30 ;       // number of iterations per run

		//unsigned int   _population_size;		// number of solutions in the population
		unsigned int   _solution_size;	        // size of each particle

	public:
		SetUpParams ();

 		friend ostream& operator<< (ostream& os, const SetUpParams& setup);
		friend istream& operator>> (istream& is, SetUpParams& setup);

		const unsigned int   independent_runs() const;
		const unsigned int   nb_evolution_steps() const;
		const unsigned int   population_size() const;
		const unsigned int   solution_size() const;

		~SetUpParams();
  };
}
