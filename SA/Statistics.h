#ifndef STATISTICS_H
#define STATISTICS_H

#include<vector>

/**
 * \file       Statistics.h
 * \author     
 * \brief      classe permettant de gérer des données statistiques
 *
 * \details    classe pour calculer la moyenne et l'écrt type.
 */
class Statistics
{
public:
	/**
     * \brief       constructeur par defaut de la classe Statistics
     * \details     Initialise un tableau contenant des données à traiter
     *                  
     * \param	    v \e vector tableau contenant les données
     */
    Statistics(std::vector<double>& v);

    /**
     * \brief     renvoie la moyenne
     * \return    \e double la moyenne
     */
    double get_moyenne() const;

    /**
     * \brief     renvoie l'écart type
     * \param	  mean \e double moyenne pour éviter de la recalculer
     * \return    \e double l'écart type
     */
    double get_ecart_type(double mean) const;
private:
	/**
     * \brief     \e vector<double> tableau contenant les données
     */
    std::vector<double> _data;
};


#endif // STATISTICS_H
