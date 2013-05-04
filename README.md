UtilsRTClibTimer
================

Ma librairie UtilsRTClibTimer est une surcouche de ma librairie Utils et implémente une fonction d'analyse des chaînes en réception série pour gérer les timers RTC créés avec ma lib RTClibTimer

Cette librairie ne dispose que d'une seule fonction : 
void analyseChaine(String chaineReceptionIn, RTClibTimer timerRTCIn[], int nombreTimersIn); 

Les chaînes reconnues par cette librairie sont : 
* start(index, intervalle) pour une activation d'un timer avec intervalle donné 
* start(index, intervalle, max) pour une activation d'un timer avec intervalle donné et nombre limite d'événements
* startAll(intervalle) : pour une activation de tous les timers avec intervalle donné et sans limite 
* startAll(intervalle, max) pour une activation de tous les timers avec intervalle donné et nombre limite d'événements
* info(index) pour obtenir de l'information sur un timer donné
* stop(index) : pour stopper un timer donné
* stopAll() : stoppe tous les timers
* restart(index) : pour réactiver un timer avec les paramètres courants


Cette librairie est utilisée notamment dans mon projet "The Open Datalogger Project" : https://github.com/sensor56/TheOpenDataloggerProject
