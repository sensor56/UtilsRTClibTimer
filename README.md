UtilsRTClibTimer
================

Ma librairie UtilsRTClibTimer est une surcouche de ma librairie Utils et implémente une fonction d'analyse des chaînes en réception série pour gérer les timers RTC créés avec ma lib RTClibTimer

Cette librairie ne dispose que d'une seule fonction : 
void analyseChaine(String chaineReceptionIn, RTClibTimer timerRTCIn[], int nombreTimersIn); 

Les chaînes reconnues par cette librairie sont : 
* start(index, intervalle) 
* start(index, intervalle, max)
* startAll(intervalle)
* startAll(intervalle, max)
* stop(index) 
* stopAll()
* restart(index)
* info(index) 


Cette librairie est utilisée notamment dans mon projet "The Open Datalogger Project" : https://github.com/sensor56/TheOpenDataloggerProject
