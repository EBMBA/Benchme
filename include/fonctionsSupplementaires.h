/**
 * @file fonctionsSupplementaires.h
 * @author Kubilay KAPLAN et Emile METRAL (kubilay.kpl@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FONCTIONSUP_H
#define FONCTIONSUP_H

/**
 * @brief 
 * 
 */
void afficherMenu();

/**
 * @brief 
 * 
 * @param choix 
 * @param val 
 */
void traiterChoix(int choix, float *val);

/**
 * @brief 
 * 
 * @param tab 
 * @return int 
 */
int obtenirTaille(float *tab);

/**
 * @brief 
 * 
 * @param Tab 
 * @return float* 
 */
float *inverserTab(float *Tab);
void copierTab(const float *tableauACopier, float *tableauCopie);

#endif