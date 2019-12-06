En este proyectomodelo un agencia de autos en el main demuestroque fucionan todas mic claes creando un objeto de cada una e imprimindo los datos porteriormente te llev a un menu donde puedes entrar como admin o cliente si quires entrar como cliende di que no estas registrado si quieres admin si que si estas registrado y escribe Jorge
mi programa es una agencia para autos hata el momento he creado 5 clases:
Las primeras 5 clases estan correlacionadas y contien informacion relevande de el auto
La clase padre Motor la cual contiene atributos importantes de un motor
Sus dos hijas MotorElectrico y MotorGasolina
La clase padre Auto  cuyos atributos son marca modelo  color transmision y precio
La clase hija AutoGasolinaRegular hereda los atributos de la clase padre Auto y tiene sus propio atributos: motor,acilindrada,turbo
el atributo motor ala vez es un objeto de la clase MotorGasolina por lo que podemos que hay una relacion de composicion
La clase hija AutoElectrico a su vez tambien tiene lo atributos de la clase padre y ademas tiene motor
el atributo motor ala vez es un objeto de la clase MotorElectrico por lo que podemos que hay una relacion de composicion
Aparte de estas 5 que estan relacionadas tabien hize la clase Agencia y la clase Cliente
La clase agencia servira en el futuro pues sera el conjunto de todos los autos
 de momento solo tiene los atributos nombre,telefono, correo electronico,domicilio y capacidad de alma
 cenamiento
La clase cliente tiene todos los datos de el comprador nombre,edad,telefono, correo electronico,rfc y domicilio

La clase base de datos es un conjunto de agencias y clientes