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
 * @param Tab 
 * @return float* 
 */
float *inverserTab(float *Tab, int taille);

/**
 * @brief 
 * 
 * @param tableauACopier 
 * @param tableauCopie 
 */
void copierTab(const float *tableauACopier, float *tableauCopie);

/**
 * @brief 
 * 
 * @param TableauARemplir 
 * @param taille 
 */
void remplirTab(float TableauARemplir[], int taille);
#endif