#include "pch.h"
#include "SetUpParams.h"
namespace simulatedAnnealing {

	

	const unsigned int SetUpParams::max_independent_runs() const
	{
		return _max_independent_runs;
	}

	const unsigned int SetUpParams::max_evolution_steps() const
	{
		return _max_evolution_steps;
	}

	SetUpParams::~SetUpParams()
	{
	}


	


	ostream & operator<<(ostream & os, const SetUpParams & setup)
	{
		os << "Number of max independet runs" << setup.max_independent_runs() << endl;
		os << "Number of max evolution runs" << setup.max_evolution_steps() << endl;
	
		return os;
	}
	istream& operator>> (istream& is, SetUpParams& setup)
	{		
	
		return is;
	}


}