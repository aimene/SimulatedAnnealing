#ifndef SOLUTION_H
#define SOLUTION_H




#include<vector>
namespace simulatedAnnealing {
	using namespace std;
	class Problem;
    class Solution
  {
	//contient la déclaration d'une solution
	public:
		Solution (const Problem& pbm);
		Solution (const Solution& sol);
		~Solution();

 		friend ostream& operator<< (ostream& os, const Solution& sol);
		friend istream& operator>> (istream& is, Solution& sol);

		

		Solution& operator=  (const Solution& sol);
		bool operator== (const Solution& sol) const;
		bool operator!= (const Solution& sol) const;

		void initialize();

		double fitness();
		

		//unsigned int size() const;

		double get_fitness() const;
		const Problem& get_problem() const;
	    const vector<double>& get_solution() const ;



		//double& position(const int index); //retournera une position du tableau _solution
       // void  position(const int index, const double value);


	private:
        vector<double> _solution;
        double _current_fitness;
	    const  Problem& _problem;
  };
}
#endif // !SOLUTION_H