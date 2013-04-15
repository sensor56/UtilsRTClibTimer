/*
 * Copyright (c) Avril 2013 by Xavier HINAULT - support@mon-club-elec.fr
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

#include "Arduino.h"
//#include "RTClib.h"
#include "RTClibTimer.h"
#include "Utils.h"
#include "UtilsRTClibTimer.h"


  UtilsRTClibTimer::UtilsRTClibTimer(){ // constructeur par défaut
  
  }
  
//////////// fonctions membre de la classe //////////////

//------------ analyseChaine ---------------
void UtilsRTClibTimer::analyseChaine(String chaineReception, RTClibTimer timerRTC[], int nombreTimersIn) { // fonction d'analyse de la chaine recue

 String paramString=""; // chaine locale - initialiser à "" !
 long params[6]; // tableau de paramètres pour instructions à paramètres multiples - taille du tableau fixée par le nombre max de paramètres utilisés 

  // ---- analyse de la chaine recue sur le port Série ---- 
  chaineReception.trim(); // enlève les espaces - version 1.0

         //================================= start(index, intervalle) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"start(",2,params)==true) { // si chaine FONCTION(valeur,valeur) bien reçue 

        int indexTimer=params[0]; 
        int intervalTimer=params[1];
        
        Serial.println("index : " + (String)indexTimer);
        Serial.println("intervalle : " + (String)intervalTimer);
        
        if (indexTimer<nombreTimersIn) {
          /*
          timer[interval][indexTimer]==intervalTimer; // fixe intervalle du Timer
          Serial.println("Intervalle Timer = " + (String)intervalTimer);
          
          timer[etat][indexTimer]=1; // active le Timer
          Serial.print("Timer " + (String)indexTimer);
          Serial.println(" actif.");
          */
          
          //initTimerRTC(indexTimer, intervalTimer, 0, ON); // initialise timer RTC
          //timerRTC[indexTimer].begin(intervalTimer, 0); // initialise timer RTC sans fin
          timerRTC[indexTimer].start(intervalTimer); // équiv - initialise timer RTC sans fin
          
        } // fin if params < nombreTimers
        
        return; // loop suivant
        
    	} // fin si testInstructionLong==true

        //================================= startAll(intervalle) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"startAll(",1,params)==true) { // si chaine FONCTION(valeur) bien reçue 

        int intervalTimer=params[0];
        
       Serial.println("intervalle : " + (String)intervalTimer);

          for (int i=0; i<nombreTimersIn; i++) { // défile les timer 
            //initTimerRTC(i, intervalTimer, 0, ON); // initialise timer RTC
            timerRTC[i].start(intervalTimer); // initialise timer RTC sans fin

          } // fin for 
                  
        return; // loop suivant
        
    	} // fin si testInstructionLong==true

        //================================= start(index, intervalle, max) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"start(",3,params)==true) { // si chaine FONCTION(valeur,valeur,valeur) bien reçue 

        int indexTimer=params[0]; 
        int intervalTimer=params[1];
        int maxTimer=params[2];
        
        Serial.println("index : " + (String)indexTimer);
        Serial.println("intervalle : " + (String)intervalTimer);
        Serial.println("limite : " + (String)maxTimer);
        
        if (indexTimer<nombreTimersIn) {
          /*
          timer[interval][indexTimer]==intervalTimer; // fixe intervalle du Timer
          Serial.println("Intervalle Timer = " + (String)intervalTimer);
          
          timer[etat][indexTimer]=1; // active le Timer
          Serial.print("Timer " + (String)indexTimer);
          Serial.println(" actif.");
          */
          
          //initTimerRTC(indexTimer, intervalTimer, maxTimer, ON); // initialise timer RTC
          timerRTC[indexTimer].start(intervalTimer,maxTimer); // initialise timer RTC avec limite
          
        } // fin if params < nombreTimers
        
        return; // loop suivant
        
    	} // fin si testInstructionLong==true

        //================================= startAll(intervalle, max) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"startAll(",2,params)==true) { // si chaine FONCTION(valeur,valeur) bien reçue 

        int intervalTimer=params[1];
        int maxTimer=params[2];
        
        Serial.println("intervalle : " + (String)intervalTimer);
        Serial.println("limite : " + (String)maxTimer);
        
          for (int i=0; i<nombreTimersIn; i++) { // défile les timer 
            //initTimerRTC(i, intervalTimer, maxTimer, ON); // initialise timer RTC
            timerRTC[i].start(intervalTimer,maxTimer); // initialise timer RTC avec limite

          } // fin for 
          
                  
        return; // loop suivant
        
    	} // fin si testInstructionLong==true
    
        //================================= restart(index) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"restart(",1,params)==true) { // si chaine FONCTION(valeur) bien reçue 

        int indexTimer=params[0]; 
        
        Serial.println("index : " + (String)indexTimer);
        
        if (indexTimer<nombreTimersIn) {
          
          //timer[etat][indexTimer]=1; // active le Timer sans modifier les paramètres courants
          //activeTimer(timer, indexTimer); // active le timer
          //activeTimer(indexTimer); // active le timer
          timerRTC[indexTimer].start(); // initialise timer RTC avec limite
         
          
          Serial.print("Timer " + (String)indexTimer);
          Serial.println(" actif.");
        
        } // fin if params < nombreTimers
        
        return; // loop suivant
        
    	} // fin si testInstructionLong==true
    

        //================================= stop(index) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"stop(",1,params)==true) { // si chaine FONCTION(valeur) bien reçue 

        int indexTimer=params[0]; 

        Serial.println("index : " + (String)indexTimer);
        if (indexTimer<nombreTimersIn) {
          //timer[etat][indexTimer]=0; // désactive le Timer
          //stopTimer(indexTimer); 
          timerRTC[indexTimer].stop();// stoppe le Timer 
          Serial.print("Timer " + (String)indexTimer);
          Serial.println(" inactif.");

        } // fin if params < nombreTimers
        
        return; // loop suivant
        
    	} // fin si testInstructionLong==true

        //================================= info(index) ===================================== 

    	if(_utils.testInstructionLong(chaineReception,"info(",1,params)==true) { // si chaine FONCTION(valeur) bien reçue 

        int indexTimer=params[0]; 

        Serial.println("index : " + (String)indexTimer);
        
        if (indexTimer<nombreTimersIn) {
          
          //infoTimer(indexTimer); // affiche infos sur le Timer
          timerRTC[indexTimer].status(); // affiche les infos sur le port série 
          
          //String infosTimer=""; 
          // timerRTC[indexTimer].status(infosTimer); // status met infos dans le String - marche pas 
          //Serial.println(infosTimer); // affiche infos sur le Timer 
          
        } // fin if params < nombreTimers
        
        return; // loop suivant
        
    	} // fin si testInstructionLong==true
    
        //================================= stopAll() ===================================== 
        if (chaineReception.startsWith("stopAll()")==true) {

          for (int i=0; i<nombreTimersIn; i++) { // défile les timer 
            // timer[etat][i]=0; // désactive le Timer
            //stopTimer(i); 
            timerRTC[i].stop(); // stoppe le timer RTC
            
          } // fin for 
          
          Serial.println("Tous les timers inactifs.");
        
        return; // loop suivant
        
    	} // fin si chaineReception == 
  


} // fin analyse chaine 



