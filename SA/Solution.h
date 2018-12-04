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
		
	//contient la déclaration d'une solution
	public:

		Solution (const Problem& pbm);
		Solution (const Solution& sol);
		~Solution();

		void initialize();
		void fitness();

		double rastrigin();
		double ackley();
		double resenbrock();
		double schaffer();
		double schwefel();
		double weierstrass();

		//unsigned int size() const;
		

		double get_fitness() const;
		const Problem& get_problem() const;
	    const vector<double>& get_solution() const ;

		double random(double min, double max) const;


		friend ostream& operator<< (ostream& os, const Solution& sol);
		friend istream& operator>> (istream& is, Solution& sol);
		Solution& operator=  (const Solution& sol);
		bool operator== (const Solution& sol) const;
		bool operator!= (const Solution& sol) const;

		//double& position(const int index); //retournera une position du tableau _solution
       // void  position(const int index, const double value);


	private:
        vector<double> _solution;
        double _current_fitness;
	    const  Problem& _problem;
  };
}
#endif // !SOLUTION_H