#include "pch.h"
#include "SetUpParams.h"
namespace simulatedAnnealing {

	simulatedAnnealing::SetUpParams::SetUpParams() : _nb_evolution_steps{},
		_nb_independent_runs{}, _temperature{}{}

	const unsigned int SetUpParams::max_independent_runs() const
	{
		return _max_independent_runs;
	}

	const unsigned int SetUpParams::max_evolution_steps() const
	{
		return _max_evolution_steps;
	}

	const unsigned int SetUpParams::nb_independent_runs() const
	{
		return _nb_independent_runs;
	}

	const unsigned int SetUpParams::nb_evolution_steps() const
	{
		return _nb_evolution_steps;
	}

	void SetUpParams::update_temperature(const double & x)
	{
		_temperature *= x;

	}

	void SetUpParams::setup_temperature(const double & x)
	{
		_temperature = x;
	}



	ostream & operator<<(ostream & os, const SetUpParams & setup)
	{
		os << "Number of max independet runs" << setup.max_independent_runs() << endl;
		os << "Number of max evolution runs" << setup.max_evolution_steps() << endl;
		os << "Number of current independet runs" << setup.nb_independent_runs() << endl;
		os << "Number of current evolution steps" << setup.nb_evolution_steps()<< endl;

	}
	istream& operator>> (istream& is, SetUpParams& setup)
	{		
		double temperature;
		is >> temperature;
	}


}