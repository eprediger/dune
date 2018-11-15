# 7542 - Taller de Programación

### 2do Cuatrimestre 2018

## TP4: dune

Dune es un juego de estrategia en tiempo real basado en el icónico juego Dune 2000 de Westwood Studios
del año 1998 ambientado en la novela Dune de Frank Herbert.

El objetivo es simple: destruir a todos los adversarios y quedarse con el control planeta Arrakis, conocido como Dune.

En este remake, el jugador podrá elegir jugar con una de las tres Casas: los nobles Atreides, los insidiosos Ordos y los malvados Harkonnen

### Compilación

Instalación de librerías externas:

	sudo apt-get install libsdl2-dev libsdl2-mixer-dev libsdl2-ttf-dev

Compilación desde carpeta de proyecto:

	mkdir build; cd build; rm -rf *; cmake ..; make

Ejecución desde carpeta build/:

	./dune

## USER STORIES

1. El juego finaliza cuando se destruyen todos los centros de construcción menos uno, el jugador cuyo centro queda en pie, será el ganador, informandole a todos los clientes si resultaron victoriosos o derrotados.

2. ~~Al seleccionar una unidad con click izquierdo o varias arrastrando el mouse con el click presionado~~, se informa por mensaje de voz la unidad seleccionada, ~~y enviarla a atacar a una unidad enemiga, haciendo click derecho sobre esta, se acercará hasta encontrarse en rango y ahí comenzará el ataque. Si la atacada se desplaza, por ejemplo, intentando escapar, la atacante comenzará a perseguirla automáticamente, hasta encontrarse dentro de su rango de ataque.~~

3. Para crear una unidad, se debe contar con dinero suficiente correspondiente a su costo y los edificios que requiera, mostrando un botón con la imagen de la unidad _habilitado_, caso contrario se _deshabilitará_ el botón en la vista del jugador. Al iniciar el entrenamiento de cualquier unidad, se _restará_ el dinero correspondiente del jugador, se _deshabilitará_ el botón en la vista durante el tiempo de entrenamiento. Al finalizar el entrenamiento, la unidad creada será posicionada en el **primer cuartel** que posea el jugador.

4. Al morir una unidad, se mostrará la animación correspondiente a su muerte/destrucción por pantalla y desaparecerá del mapa.

5. Seleccionar una cosechadora, se la envía a recolectar especia y automáticamente realiza el recorrido hacia ese punto, cuando se completa su capacidad de 200 unidades en 20 segundos, retorna a la refinería, descarga lo cosechado en 5 segundos, incrementando en 1 la cantidad de dinero del jugador por cada unidad de especia recolectada. Cuando se agota la especia en la zona donde la cosechadora recolecta, debe buscar más especia en las cercanías automáticamente, continuando la cosecha. En el momento en que no encuentra más especia en sus alrededores, la cosechadora retorna a la refinería.

6. Para construir un edificio, se debe contar con el dinero suficiente correspondiente a su costo. Caso contrario, se _deshabilitará_ el botón para comenzar su construcción. Al inicial la construcción de cualquier edificio, se restará el dinero correspondiente del jugador y se actualizará la energía consumida por el mismo, sumando y pasado el tiempo de construcción correspondiente a cada uno, se podrá colocar en cualquier parte del mapa cuyo terreno sean rocas, no haya unidades en el mismo y se encuentre al menos a 5 bloques de distancia de otros edificios. El edificio pasara a ocupar tantos bloques como su superficie lo indique.

7. Al destruirse un edificio, se disminuirá la energía consumida por el jugador que perdió el edificio mostrando una animación en pantalla de su destrucción y posterior borrado del mapa.

8. Los jugadores al iniciar la aplicación, ingresan host y puerto, la casa con la cual jugará cada uno y se inicia la partida con los jugadores repartidos en el mapa con su dinero inicial y el centro de construcción.

9. Para iniciar el servidor, se deberá indicar, puerto al cual escuchar, mapa sobre el que se jugará y cantidad de jugadores. El juego no iniciará hasta que se hayan conectado la cantidad de clientes indicada por parámetro. Una vez alcanzado ese número, se iniciará el juego para todos.

10. Las distintas unidades de cada jugador se podrán diferenciar mediante un color característico para cada uno de ellos.

11. Si la energía consumida por los edificios supera a la energía generada por las Trampas de Viento, los tiempos de construcción de edificios y de entrenamiento de unidades se verán incrementados en un factor proporcional a la energía consumida sobre la energía generada.

12. Debe aparecer un gusano de arena en intervalos de tiempo aleatorios, en lugares aleatorio, el cual devora cualquier unidad aleatoriamente. Estos no pueden ser atacados. Tras un numero aleatorio de ataques, desaparece.

13. Cuando el jugador seleccione un edificio, se habilitará el botón de venta, sobre el cual al hacer click izquierdo, destruirá el edificio, devolviendole al jugador una parte de dinero de su costo de construcción.

14. ~~Si una unidad se encuentra quieta y una unidad enemiga ingresa dentro de su rango de ataque, la primera, comenzará a atacarla sin desplazarse. Cuando la segunda salga del rango, detendrá el ataque.~~


* Servidor:

	1. Abrir archivo configuración
	2. Cargar mapas
	3. Cargar parámetros del juego (daños, velocidades)
	4. Recibir clientes
	5. Recibir nuevas partidas (creada por cliente)


* Cliente

	1. Mostrar pantalla de login (host y puerto)
	2. Unirse a partida disponible (que no se estén jugando)
	3. Crear partida
	4. Elegir mapa
	5. Elegir casa
	6. Ingresar a la partida
	7. Ver recursos disponibles
	8. Ver mapa
	9. Desplazarse a través del mapa
	10. Construir edificio, mostrando tiempos de finalización
	11. Ubicar edificio en mapa
	12. Demoler edificio
	13. Crear unidad (infantería, vehículos), mostrando tiempos de finalización
	14. Seleccionar unidad/es mostrando HP
	15. Mover unidad/es
	16. Atacar unidad/es y edificio/s
	17. Recolectar *especia* (con cosechadoras)
	18. Descargar *especia*
	19. Gusanos
	20. Oír música de fondo/FX (frases de eventos, unidades)
	21. Mostrar pantalla final (victoria/derrota + estadísticas)

* Editor

	1. Editar terreno
	2. Editar cantidad de jugadores
	3. Editar ubicación de Centros de Construcción

## DOCUMENTACION

* Instalacion y uso
* Archivo de Configuracion (detalles)

### TAREAS

Semana 1: 

Alumno 1: Implementación del algoritmo A-Star sobre un mapa con distintos terrenos y con unidades con diferentes movilidades.

	* Implementar A*
	* Moverse de punto A a punto B mediante A*
	* Moverse a través del mapa
		* Implementar Mapa
		* Implementar distintos terrenos
	* Moverse dentro de mapa con posibles obstáculos
	* Moverse a distintas velocidades.

__SIN GRAFICOS__

Alumno 2: Mostrar una imagen. Mostrar una animación. Mostrar ambas en un lugar fijo o desplazándose por la pantalla (movimiento).

	* Mostrar imagen (de unidad)
	* Mostrar sprites s/movimiento (desplazamiento, ataque, cosecha)
	* Mostrar animacion s/movimientos
	* Mostrar desplazamiento

Alumno 3: Emitir un sonido. Carga y guardado de información a disco. Draft de la interfaz (​wireframes).

	* Emitir un sonido.
	* Carga y guardado de información a disco.
		* Formato YAML

<!-- 
Semana 2:
Semana 3:
Semana 4:
Semana 5:
Semana 6: 
-->
