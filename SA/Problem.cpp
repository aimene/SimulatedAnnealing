#include"Problem.h"
#include"Solution.h"

namespace simulatedAnnealing {
	Problem::Problem(const int & problem_id): _problem_id{problem_id}{}


	int Problem::get_problem_id() const
	{
		return _problem_id;
	}

}
