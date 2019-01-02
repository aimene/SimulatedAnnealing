#include "pch.h"
#include "SetUpParams.h"
namespace simulatedAnnealing {

	

	SetUpParams::SetUpParams( int   _max_independent_runs,  int   _max_evolution_steps):
		_max_evolution_steps{_max_evolution_steps}, _max_independent_runs{ _max_independent_runs }
	{
		setup_nb_evolution_steps(1);
		setup_nb_independent_runs (1);
	}

	const int& SetUpParams::get_max_independent_runs() const
	{
		return _max_independent_runs;
	}

	const int& SetUpParams::get_max_evolution_steps() const
	{
		return _max_evolution_steps;
	}

	const double & SetUpParams::get_temperature()
	{
		return _temperature;
	}



	const  int& SetUpParams::get_nb_independent_runs() const
	{
		return _nb_independent_runs;
	}

	const  int& SetUpParams::get_nb_evolution_steps() const
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

	void SetUpParams::setup_nb_evolution_steps(int x)
	{
		_nb_evolution_steps = x;
	}

	void SetUpParams::setup_nb_independent_runs(int x)
	{
		_nb_independent_runs = x;
	}

	void SetUpParams::increment_nb_independent_runs()
	{
		++_nb_independent_runs;
	}

	void SetUpParams::increment_nb_evolution_steps()
	{
		++_nb_evolution_steps;
	}

	bool SetUpParams::is_less__max_independent_runs() const
	{
		return _nb_independent_runs <= get_max_independent_runs();
	}

	bool SetUpParams::is_less_max_evolution_steps() const
	{
		return _nb_evolution_steps <= get_max_evolution_steps();
	}
	


	ostream & operator<<(ostream & os, const SetUpParams & setup)
	{
		os << "Number of max independet runs" << setup.get_max_independent_runs() << endl;
		os << "Number of max evolution runs" << setup.get_max_evolution_steps() << endl;
	
		return os;
	}
	istream& operator>> (istream& is, SetUpParams& setup)
	{		
	
		return is;
	}

	SetUpParams::~SetUpParams()
	{
	}
}