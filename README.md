# Drivers

#Punto 1 

Para poder ejecutar el modulo que nos es previsto debemos realizar los siguientes pasos:

1.Primer Paso
  -Creo el archivo miModulo.c
  -Creo el archivo Makefile
2.Segundo Paso
  -Compilo el archivo Makefile mediante el comando en la terminal:
      ```
      make -f Makefile
      
      ```
3.Tercer Paso 
  -Cargo el modulo mediante el comando 
      ```
      sudo insmod ./miModulo.ko
      
      ```
  -Descarga el modulo 
      ```
      sudo rmmod miModulo.ko
      
      ```
4.Cuarto Paso 
    -Compruebo que funcione abriendo dos terminales en uno vemos el log del kernel mediante el siguiente comando.
      ```
      tail -f /var/log/syslog
      
      ```
      y luego ejecutamos en el otro terminal
        ```
      sudo insmod ./miModulo.ko
      
      ```
      y en la pestaña del primer terminal se mostrara el siguiente log 
         ```
            Apr 10 17:06:26 galileoluna kernel: [ 4610.279150]  UNGS : Driver registrado 
      
      ```
