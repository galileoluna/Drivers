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
Cuando nostros creamos el char device nosotros utilizamos las siguientes funciones:
**init_module:**  Que llama al modulo si este esta cargado, posee la misma función que el main.
 **cleanup_module:** Esta es la función   llamada cuando se descarga el modulo, es parecida al delete en c++. 


## Secuencia para crearlo

 1. Creo el archivo del device en la carpeta */dev*

	    sudo mknod /dev/driverTest c 91 1
	 

 2. Le otorgo los permisos necesarios para la ejecución
 
		chmod a+r+w /dev/driverTest

 3. Ejecuto el archivo Makefile
 
		make -f Makefile

 4. Cargo el modulo
		
		sudo insmod ./driverTest.ko

 5. Ejecuto el siguiente comando y la respuesta sera los modulos ekecutando

			 cat /proc/modules
			 driverTest 16384 0 - Live 0x0000000000000000 (OE)

 6. Ejecutamos el comando
	
   

cat /proc/devices
    Character devices:
  1 mem
  4 /dev/vc/0
  4 tty
  4 ttyS
  5 /dev/tty
  5 /dev/console
  5 /dev/ptmx
  5 ttyprintk
  7 vcs
 10 misc
 13 input
 21 sg
 29 fb
 89 i2c
 91 driverTest <---
 99 ppdev
108 ppp
116 alsa
128 ptm
136 pts
180 usb
189 usb_device
204 ttyMAX
226 drm
246 hidraw
247 aux
248 bsg
249 watchdog
250 rtc
251 dimmctl
252 ndctl
253 tpm
254 gpiochip


    

7 . Ejecutamos el comando 

	make test

8. Y por ultimo ejecutamos el siguiente comando
	
	
	    ./test "hola"
	    Input: hola



 
