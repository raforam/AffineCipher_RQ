## AffineCipher_RQ

Esta es una implementación del cifrado afín en el lenguaje c++ 

Instrucciones de ejecución:
* Descargar los archivo 'cifrados.h' y 'affine.cpp' ejecutar el último (affine.cpp)
* Primero ingresar el valor de la clave 'a' y luego el valor de la clave 'b' como pide en la consola. El valor de la clave 'a' tiene que tener inverso con la longitud del string usado para el abecedario, en este caso, 27. Caso contrario se notificará en consola que el número no tiene inversa y fallará la encriptación.
* Una vez ingresadas las claves se pedirá ingresar el mensaje a encriptar
* Al presionar ENTER se mostrará en pantalla el mensaje ya encriptado y el mensaje descifrado usando los algoritmos vistos en clase

ADVERTENCIA: Dependiendo de donde se ejecute el código (VS2019, VSC, etc) los caracteres con tilde o la letra Ñ no se procesarán correctamente por no usar la codificación UTF-8, para ello se debe sustituir cualquier "Ñ" con el caracter "_" de la misma manera no acepta espacios en los mensajes para cifrarlos por lo que hay que escribir junto todo el texto.


## Descifrado Afín sin claves

Para descifrar un mensaje sin saber las claves 'a' ni 'b' siga las siguietnes instrucciones
*  Descargar el archivo 'adivinador.cpp' y ejecútelo. Este archivo depende del encabezado 'cifrados.h' así que ya tiene que estar descargado y en la misma ubicación
*  Este código no cuenta con ingreso por consola porque puede resultar tedioso ingresar textos largos, para modificar el mensaje modifique el código en la línea 34.
*  Recuerde que las mismas advertencias aplican para este programa.
*  Al ejecutarse el código este imprimirá en consola todos los posibles mensajes descifrados con el algoritmo afín. El mensaje de prueba que yá está en el código ya ha sido encontrado y las claves solo se imprimen en pantalla





Curso: Álgebra Abstracta - CCOMP3-2

Profesor: Jose Armando Chavez Alvarez (jachaveza@ucsp.edu.pe)

Alumno: Rafael Alejandro Ramirez Quiroz (rafael.ramirez@ucsp.edu.pe)


