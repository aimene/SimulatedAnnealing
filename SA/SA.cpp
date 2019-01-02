// SA.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include<ctime>
#include"MyAlgorithm.h"
#include"Solution.h"
#include"Problem.h"
#include"SetUpParams.h"


int main()
{
	srand(time(NULL));

	simulatedAnnealing::SetUpParams setup{30,2000};
	simulatedAnnealing::Problem problem{1};
	simulatedAnnealing::Solution solution{ problem };
	simulatedAnnealing::MyAlgorithm myalgo{ problem,setup };


	myalgo.run();



	std::cout << " best solution =" << std::endl;
	std::cout << myalgo.get_best_solution();
}
