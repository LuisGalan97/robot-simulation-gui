# GUI de simulacion de robots
Este proyecto construido en RAD Studio C++ Builder, presenta un GUI de simulacion del movimiento y deteccion de colision de robots en un plano de dos dimensiones.

![GIF Robots](https://github.com/LuisGalan97/robots-project/blob/docs/docs/1.gif)

## Funcionamiento
El programa inicialmente consulta la cantidad de robots a simular, lo que permite ingresar un valor entre 1 a 50 robots para posteriormente pulsar el boton comenzar. 

![Imagen GUI](https://github.com/LuisGalan97/robots-project/blob/docs/docs/1.png)

Al hacerlo, el GUI de simulacion pasará a mostrar la cantidad de robots ingresados, cada uno representado con un shape circular de color verde, junto con etiquetas que muestran el nombre y las coordenadas de cada robot en los ejes X, Y. A su vez aparecerá un mensaje, que dará indicaciones sobre como mover los robots.

![Imagen GUI](https://github.com/LuisGalan97/robots-project/blob/docs/docs/2.png)

El movimiento de los robots se da por iteracciones accionadas por la rueda del mouse, para los cuales cada uno de los robots se movera en linea recta, en una distancia y direccion aleatoria.

![GIF Robots](https://github.com/LuisGalan97/robots-project/blob/docs/docs/2.gif)

Las cuales se establecen representando la distancia como un radio que toma valores de 0 a 200 pixeles, y la direccion como un angulo que toma valores de 0 a 360°, permitiendo que las coordenadas objetivos sean determinadas por el producto del radio con el cos y sin del angulo respectivamente:

$$coord\_x = r \cdot \cos(\theta)$$
$$coord\_y = r \cdot \sin(\theta)$$

A su vez se establece  la ecuacion de la linea recta, para permitir el movimiento del robot punto por punto, desde su posicion inicial a su posicion destino:

$$y = mx + b$$

Donde la pendiente $m$ se calcula como:

$$m = \frac{y_2 - y_1}{x_2 - x_1}$$

Y $b$ se puede determinar como:

$$b = y_2 - m \cdot x_2$$

Con lo anterior, si en su desplazamiento hacia la posicion destino, el robot se encuentra con otro robot, este se detendra para evitar la colision y cambiara su color a rojo.

![GIF Robots](https://github.com/LuisGalan97/robots-project/blob/docs/docs/3.gif)
![Imagen GUI](https://github.com/LuisGalan97/robots-project/blob/docs/docs/3.png)

Lo cual se consigue mediante la ecuacion de la distancia euclidiana:

$$d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$$

Que permite evaluar la distancia de dos robots de tal forma que si esta es inferior al radio de los mismos, implicará una colision y por tanto el robot deberá detenerse.

Por ultimo, el formulario de consulta de la cantidad de robots posee diversas validaciónes, por lo que si el usuario intenta ingresar valores invalidos, sera informado debidamente y no dara lugar a mayores errores.

![GIF Robots](https://github.com/LuisGalan97/robots-project/blob/docs/docs/4.gif)
![Imagen GUI](https://github.com/LuisGalan97/robots-project/blob/docs/docs/4.png)

## Estructura del proyecto
El proyecto de nombre ___Robots___ se encuentra estructurado de la siguiente forma:
- __Robots.cbproj__ -> Archivo principal del proyecto de RAD Studio C++ Builder. no es directamente modificable.
- __Robots.cpp | RobotsPCH1.h__ -> Modulo principal con la implementacion que inicializa el proyecto.
- __Form.h | Form.dfm | Form.cpp__ -> Modulo con la declaracion, configuracion e implementacion de la clase __TForm1__, la cual define el diseño, configuracion y comportamiento del GUI. 
- __Field.h | Field.cpp__ -> Modulo con la declaracion e implementacion de la clase __Field__, diseñada para gestionar la visualizacion, movimiento e interaccion de todos los robots sobre el GUI.
- __Robot.h | Robot.cpp__ -> Modulo con la declaracion e implementacion de la clase __Robot__, cuyo proposito es definir el comportamiento de cada robot de forma individual.
- __Utils.h | Utils.cpp__ -> Modulo con la declaracion e implementacion de la clase __Utils__, la cual habilita metodos estaticos que realizan la inicializacion y configuracion de los elementos del GUI tales como Shape y Label.
- __Validations.h | Validations.cpp__ -> Modulo con la declaracion e implementacion de la clase __Validations__, en donde se dispone de un metodo estatico que permite validar el dato ingresado en el campo de entrada del GUI, asociado con el numero de robots que se desean simular.
- __Seed.h | Seed.cpp__ ->  Modulo con la declaracion e implementacion de la clase __Seed__, diseñada para la generacion de valores pseudo-aleatorios en los diferentes lugares del codigo.
- __ThreadF.h | ThreadF.cpp__ -> Modulo con la declaracion e implementacion de la clase __ThreadF__, la cual habilita la funcionalidad multihilo en el programa, ejecutando la logica de la simulacion en un hilo independiente, con el fin de permitir interacciones multiples con el GUI sin que sucedan bloqueos.


**Por:** <br />
Ing. Luis Miguel Galán Salazar <br />
**Ingeniero Mecatronico.**
