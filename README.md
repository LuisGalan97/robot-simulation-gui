# Proyecto simulacion de robots
Este proyecto construido en RAD Studio C++ Builder, presenta un GUI de simulacion del movimiento y deteccion de colision de robots en un plano de dos dimensiones.

![GIF Robots](https://github.com/LuisGalan97/robots-project/blob/main/doc-assets/1.gif)

El programa inicialmente consulta la cantidad de robots a simular, lo que permite ingresar un valor entre 1 a 50 robots para posteriormente pulsar el boton comenzar. 

![Imagen GUI](https://github.com/LuisGalan97/robots-project/blob/main/doc-assets/1.png)

Al hacerlo, el GUI de simulacion pasará a mostrar la cantidad de robots ingresados, cada uno representado con un shape circular de color verde, junto con etiquetas que muestran el nombre y las coordenadas de cada robot en los ejes X, Y. A su vez aparecerá un mensaje, que dará indicaciones sobre como mover los robots.

![Imagen GUI](https://github.com/LuisGalan97/robots-project/blob/main/doc-assets/2.png)

El movimiento de los robots se da por iteracciones accionadas por la rueda del mouse, para los cuales cada uno de los robots se movera en linea recta, en una distancia y direccion aleatoria.

![GIF Robots](https://github.com/LuisGalan97/robots-project/blob/main/doc-assets/2.gif)


Esto es posible permitiendo que la distancia sea representada por un radio que tome valores de 0 a 200 pixeles, y la direccion representada como un angulo que puede tome valores de 0 a 360°, para lo cual las coordenadas objetivos son determinadas por el producto del radio por el cos y sin del angulo respectivamente:

- $coord\_x = r \cdot \cos(\theta)$
- $coord\_y = r \cdot \sin(\theta)$

A su vez ayudandose de la ecuacion de la linea recta, para permitir el movimiento del robot punto por punto, desde su posicion inicial a su posicion destino:

- $$y = mx + b$$

Donde la pendiente $m$ se calcula como:

- $$m = \frac{y_2 - y_1}{x_2 - x_1}$$

Y $b$ se puede determinar como:

- $$b = y_2 - m \cdot x_2$$



