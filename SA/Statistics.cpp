#include"Statistics.h"
#include<cmath>

/**
 * \brief       constructeur par defaut de la classe Statistics
 * \details     Initialise un tableau contenant des données à traiter
 *
 * \param	    v \e vector tableau contenant les données
 */

/**
  * \brief       constructeur par defaut de la classe Statistics
  * \details     Initialise un tableau contenant des données à traiter
  *                  
  * \param      v \e vector tableau contenant les données
  */
Statistics::Statistics(std::vector<double>& v) : _data(v)
{
}

/**
* \brief     renvoie la moyenne
* \return    \e double la moyenne
*/
double Statistics::get_moyenne() const
{
    double sum = 0.0;
    for(int i=0;i<_data.size();i++)
    {
        sum += _data.at(i);
    }
    return sum/_data.size();
}

/**
* \brief     renvoie l'écart type
* \param     mean \e double moyenne pour éviter de la recalculer
* \return    \e double l'écart type
*/
double Statistics::get_ecart_type(double mean) const
{
    double temp = 0.0;
    for(int i=0;i<_data.size();i++)
    {
        temp += (mean - _data.at(i))*(mean - _data.at(i));
    }
    return sqrt(temp/_data.size());
}

