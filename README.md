# Drivers

En este trabajo realizaremos un Driver Hola mundo y un Char Device.  



## Punto 1

Para poder ejecutar el modulo que nos es previsto debemos realizar los siguientes pasos:

 1.  Creo el archivo miModulo.c
 2. Creo el archivo Makefile
 3. Compilo el archivo Makefile mediante el comando en la terminal:
 4. Ejecuto el siguiente comando. 
 

	    make -f Makefile

 5. Cargo el modulo mediante el comando
 

	    sudo insmod ./miModulo.ko

 6. Descargo el modulo 

	    sudo rmmod miModulo.ko

 7. Compruebo que funcione abriendo dos terminales en uno vemos el log del kernel mediante el siguiente comando.
 

		  tail -f /var/log/syslog

   

   

 8.  Luego ejecutamos en el otro terminal
 

		  sudo insmod ./miModulo.ko

 9. Y en la pestaña del primer terminal se mostrara el siguiente log 

	     Apr 10 17:06:26 galileoluna kernel: [ 4610.279150]  UNGS : Driver registrado 

 

 
## Punto 2




