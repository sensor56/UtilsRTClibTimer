/*
 * Copyright (c) 2013 by Xavier HINAULT - support@mon-club-elec.fr
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 3
 * or the GNU Lesser General Public License version 3, both as
 * published by the Free Software Foundation.
 */

/* Cette librairie est une surcouche de ma librairie Utils 
 * et implémente une fonction d'analyse des chaînes en réception série 
 * pour gérer les timers RTC créé avec ma lib RTClibTimer
*/

#ifndef UtilsRTClibTimer_h
#define UtilsRTClibTimer_h

#include "Arduino.h"
#include "Utils.h"
//#include "RTClib.h"


class UtilsRTClibTimer { 

  private : // variables internes
  
  public : // variables publiques de la classe 

  Utils _utils; // objet utils donnant accès aux fonctions de la lib
  
  public : // fonctions publiques 
  // toutes les fonctions publiques de la librairie doivent être pré-déclarées ici 
  
  	UtilsRTClibTimer(); // constructeur
  	
  	void analyseChaine(String chaineReceptionIn, RTClibTimer timerRTCIn[], int nombreTimersIn); 
  

  private : // fonctions internes
  // toutes les fonctions internes (ou privées) de la librairie doivent être pré-déclarées ici 
  

}; // fin classe 


#endif
