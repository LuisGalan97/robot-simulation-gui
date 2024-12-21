# GUI de simulacion de robots
Este proyecto construido en RAD Studio C++ Builder, presenta un GUI de simulacion del movimiento y deteccion de colision de robots en un plano de dos dimensiones.

![GIF Robots](https://github.com/LuisGalan97/robots-project/blob/docs/docs/1.gif)

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

**Por:** <br />
Ing. Luis Miguel Galán Salazar <br />
**Ingeniero Mecatronico.**
