# 7542 - Taller de Programación

### 2do Cuatrimestre 2018

## TP4: dune

Dune es un juego de estrategia en tiempo real basado en el icónico juego Dune 2000 de Westwood Studios
del año 1998 ambientado en la novela Dune de Frank Herbert.

El objetivo es simple: destruir a todos los adversarios y quedarse con el control planeta Arrakis, conocido como Dune.

En este remake, el jugador podrá elegir jugar con una de las tres Casas: los nobles Atreides, los insidiosos Ordos y los malvados Harkonnen

### USER STORIES

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
