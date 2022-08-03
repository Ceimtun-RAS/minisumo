
# InitSensor 
Clase de sensor IR para el control de inicio profesional. Depende de un estado 
interno de lectura. Si el control se oprime *start* el estado se vuelve un 1 lógico. Si el control procesde a *stop* el estado se vuelve un 0 lógico. 

>__Importante__: Se debe calibrar el control. Para esto, se oprime el botón *program*, y se espera que el sensor parpadee 2 veces. 
---


### InitSensor(int test, int allowable )
* __Test__: Pin Digital de calibracion (No sirve bien :v)
* __Allowable__: Pin digital de lectura del sensor. (STOP)

### ContinueReading()
Es un muestreo de la lectura del sensor. Se necesita ejecutar para actualizar el 
estado interno de sensado. 

---
>__Importante__: Una vez en estado *STOP*, toca reiniciar el sensor y recalibrar para volver a funcionar. 
