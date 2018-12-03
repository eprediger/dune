# 7542 - Taller de Programación

### 2do Cuatrimestre 2018

---
## TP4: dune

Dune es un juego de estrategia en tiempo real basado en el icónico juego Dune 2000 de Westwood Studios
del año 1998 ambientado en la novela Dune de Frank Herbert.

El __objetivo__ es simple: destruir a todos los adversarios y quedarse con el control planeta Arrakis, conocido como Dune.

En este remake, __el jugador podrá elegir__ jugar con una de las tres Casas: los nobles **Atreides**, los insidiosos **Ordos** y los malvados **Harkonnen**

---
### Instalación

Instalación de librerías externas:

	sudo apt-get install libsdl2-dev libsdl2-mixer-dev libsdl2-ttf-dev libsdl2-image-dev libyaml-cpp-dev nlohmann-json-dev

Instalación librería libsdl2-mixer-dev versión 2.0.1:

	https://packages.ubuntu.com/xenial/amd64/libsdl2-mixer-2.0-0/download
	https://packages.ubuntu.com/xenial/amd64/libsdl2-mixer-dev/download

	Instalación [amd64]: sudo dpkg -i libsdl2-mixer-2.0-0_2.0.1+dfsg1-1_amd64.deb
	Instalación [amd64]: sudo dpkg -i libsdl2-mixer-dev_2.0.1+dfsg1-1_amd64.deb

Instalación librería nlohmann-json-dev (solo en caso de no tener Ubuntu 18):

	https://packages.ubuntu.com/bionic/all/nlohmann-json-dev/download

	Instalación [amd64]: sudo dpkg -i nlohmann-json-dev_2.1.1-1.1_all.deb

Compilación desde carpeta de proyecto:

	mkdir build; cd build; rm -rf *; cmake ..; make

---
### Ejecución 

Desde carpeta build/:

Cliente: `./dune_Client`

Server: `./dune_Server <puerto> <mapa.yaml>`

---
## USER STORIES

1. ~~El juego finaliza cuando se destruyen todos los centros de construcción menos uno, el jugador cuyo centro queda en pie, será el ganador,~~ informándole a todos los clientes si resultaron victoriosos o derrotados.

2. ~~Al seleccionar una unidad con click izquierdo o varias arrastrando el mouse con el click presionado~~, se informa por mensaje de voz la unidad seleccionada, ~~y enviarla a atacar a una unidad enemiga, haciendo click derecho sobre esta, se acercará hasta encontrarse en rango y ahí comenzará el ataque. Si la atacada se desplaza, por ejemplo, intentando escapar, la atacante comenzará a perseguirla automáticamente, hasta encontrarse dentro de su rango de ataque.~~

3. ~~Para crear una unidad, se debe contar con dinero suficiente correspondiente a su costo y los edificios que requiera, mostrando un botón con la imagen de la unidad _habilitado_, caso contrario se _deshabilitará_ el botón en la vista del jugador. Al iniciar el entrenamiento de cualquier unidad, se _restará_ el dinero correspondiente del jugador, se _deshabilitará_ el botón en la vista durante el tiempo de entrenamiento. Al finalizar el entrenamiento, la unidad creada será posicionada en el **primer cuartel** que posea el jugador.~~

	* ~~Validar dinero suficiente (ahora puedo crear unidades sin dinero suficiente mostrando balance negativo)~~
	* ~~Habilitar Handler (mostrar botón) en base a edificios construidos~~
	* ~~Deshabilitar botón si no se cumplen los anteriores~~
	* ~~Restar dinero cuando se construye unidad (solo restan cosechadora y trike)~~
	* ~~No tener harcodeado en handler posición de unidad, leer del modelo (spawn en edificio)~~

4. ~~Al morir una unidad, se mostrará la animación correspondiente a su muerte/destrucción por pantalla y desaparecerá del mapa~~.

5. ~~Seleccionar una cosechadora, se la envía a recolectar especia y automáticamente realiza el recorrido hacia ese punto, cuando se completa su capacidad de 200 unidades en 20 segundos, retorna a la refinería, descarga lo cosechado en 5 segundos, incrementando en 1 la cantidad de dinero del jugador por cada unidad de especia recolectada. Cuando se agota la especia en la zona donde la cosechadora recolecta, debe buscar más especia en las cercanías automáticamente, continuando la cosecha. En el momento en que no encuentra más especia en sus alrededores, la cosechadora retorna a la refinería.~~

6. ~~Para construir un edificio, se debe contar con el dinero suficiente correspondiente a su costo. Caso contrario, se _deshabilitará_ el botón para comenzar su construcción. Al iniciar la construcción de cualquier edificio, se restará el dinero correspondiente del jugador y se actualizará la energía consumida por el mismo, sumando y pasado el tiempo de construcción correspondiente a cada uno, se podrá colocar en cualquier parte del mapa cuyo terreno sean rocas, no haya unidades en el mismo y se encuentre al menos a 5 bloques de distancia de otros edificios. El edificio pasara a ocupar tantos bloques como su superficie lo indique.~~

	* ~~Validar la cantidad de dinero (no resta al construir, no deshabilita botón si no hay suficiente)~~
	* ~~La construcción es instantánea~~
	* ~~Tomar posición de ubicación de edificio del input de click del jugador~~
	* ~~No se actualiza energía consumida~~

7. ~~Al destruirse un edificio, se disminuirá la energía consumida por el jugador que perdió el edificio mostrando una animación en pantalla de su destrucción y posterior borrado del mapa.~~

8. ~~Los jugadores al iniciar la aplicación, ingresan host y puerto, la casa con la cual jugará cada uno y se inicia la partida con los jugadores repartidos en el mapa con su dinero inicial y el centro de construcción.~~

9. ~~Para iniciar el servidor, se deberá indicar, puerto al cual escuchar, mapa sobre el que se jugará y cantidad de jugadores. El juego no iniciará hasta que se hayan conectado la cantidad de clientes indicada por parámetro. Una vez alcanzado ese número, se iniciará el juego para todos.~~

10. ~~Las distintas unidades de cada jugador se podrán diferenciar mediante un color característico para cada uno de ellos.~~

11. Si la energía consumida por los edificios supera a la energía generada por las Trampas de Viento, los tiempos de construcción de edificios y de entrenamiento de unidades se verán incrementados en un factor proporcional a la energía consumida sobre la energía generada.

12. Debe aparecer un gusano de arena en intervalos de tiempo aleatorios, en lugares aleatorio, el cual devora cualquier unidad aleatoriamente. Estos no pueden ser atacados. Tras un numero aleatorio de ataques, desaparece.

13. Cuando el jugador seleccione un edificio, se habilitará el botón de venta, sobre el cual al hacer click izquierdo, destruirá el edificio, devolviéndole al jugador una parte de dinero de su costo de construcción.

14. ~~Si una unidad se encuentra quieta y una unidad enemiga ingresa dentro de su rango de ataque, la primera, comenzará a atacarla sin desplazarse. Cuando la segunda salga del rango, detendrá el ataque.~~

---
## Listado de bugs

1. ~~Explota durante la animación al intentar renderizar un ataque.~~

2. ~~Al hacer click en los botones de unidades intenta crear el edificio de al lado.~~

3. ~~No se pueden seleccionar unidades~~

4. ~~Arreglar el bug de la desconexión al salir~~

5. ~~Al hacer click en la cruz, no cierra el juego.~~

6. Al agregar el sleep, la vista tarda en renderizar. 

7. ~~Arreglar bug de que no disminuye la plata al comprar unidades~~

8. ~~Chequear la salida al finalizar el juego~~

9. Al vender una refinería donde está descargando una cosechadora, esta sigue descargando en el mismo lugar como si aún estuviera el edificio.

## ISSUES

1. Renderizar solamente las unidades que se están viendo (dentro de la cámara)
2. ~~Quitar las velocidades con contadores~~
3. ~~Crear archivo de configuración. Eliminar (o cargarlo desde el archivo de conf) el GlobalConfig.~~
4. ~~Modificar el GlobalConfig para que no sea una variable global. Opción: Dejarla Static en el Model~~
5. Hacer el instalador "sudo make install"
	* /bin/dune => ejecutable
	* /var/dune/assets => todos los assets. Acá se puede cambiar el path en el código (ponerla como absoluto) o poner desde assets y el resto por archivo de configuración (esto solo si hay tiempo)
	* /etc/dune.cfg => archivo de configuración

6. Reducir tiempo en CPU 
7. ~~Ver de mejorar el envío de datos. Tratar de enviar solo novedades~~
8. Ver en todo caso, cambiar la librería de json
9. Ver si se puede renderizar solo las novedades (agregar un news = true dentro de cada update)
10. Ver de renderizar el mapa solamente si cambia la cámara (para esto ver issue 11)
11. ~~Testear si cambia el terreno de arena en base a la especia~~

## CORRECCIONES MARTÍN
* Prioridad Critica

	1. ~~Hacer un mapa con todos los terrenos~~
	2. ~~Agregar arena al mapa y verificar que funcione la cosecha automática~~
	3. ~~Revisar capacidad de refinería + silos~~
	4. ~~Corregir la distancia de los edificios (se debe construir a NO MAS de 5 bloques de distancia de otro edificio propio)~~
	5. ~~Corregir~~ Testear velocidad por terrenos
	6. ~~Reducción de energía edificios~~
	7. ~~Ralentización por falta de energía (testear)~~
	8. ~~Infantería puede moverse por cimas (testear)~~
	9. ~~Velocidad cambia según el terreno~~
	10. Efectividad de una unidad sobre otra (bono de armas?)
	11. ~~Verificar que el tanque aparezca~~
	12. Mejorar jugabilidad
	13. Hacer el juego en pantalla completa (permitir alternar)
	14. Hacer los manuales y documentación
	15. Borra código comentado!
	16. ~~Main.cpp agregar loop de juego~~
	17. Corregir los paths harcodeados para facilitar la instalación
	18. GameView.cpp : quitar los "magic numbers"
	19. GameView.cpp : corregir barra de energía RenderVPBar => percentage = 1 - percentage
	20. ~~GameHandler : variable global actual player~~
	21. Eliminar prints de debug

* Prioridad Media
	1. Hacer gusanos
	2. Mejorar interfaz de dinero/energía
	3. Mejorar progreso de construcción/entrenamiento

* Prioridad baja
	1. ~~Mejorar el botón de venta de edificios~~
	2. ~~Aumento de velocidad de entrenamiento (testear)~~
	3. Agregar sonidos y FX

## PROFILING

Usar "callgrind" para encontrar donde está consumiendo más memoria

Instalación:
```bash
sudo apt-get install kcachegrind
```

Uso:

```bash
valgrind --tool=callgrind ./dune_Client
kcachegrind <archivo_salida (callgrind.out.pid)>
```

## DOCUMENTACIÓN

### Manual de Proyecto

* Integrantes
* Enunciado
* División de tareas
* Evolución del proyecto: Cronograma propuesto y cronograma real
* Inconvenientes encontrados: Problemas principales encontrados
* Análisis de puntos pendientes: Cosas que faltan o deberían mejorar, cómo y por qué
* Herramientas: Herramientas auxiliares que utilizaron para hacer el proyecto, como editor de interfaz gráfica, control de versiones, herramienta para generar documentación, herramientas para debug, etcétera.
* Conclusiones


### Documentación Técnica

[Proyecto Overleaf](https://www.overleaf.com/project/5be8b82bfdbce4745a262a43)

* Requerimientos de software: ~~OS, bibliotecas y herramientas necesarias para compilar, desarrollar, probar y depurar el programa~~
* Descripción general: Arquitectura general del proyecto, qué módulos tiene, etcétera.
* Módulo N: Una sección por módulo, que puede ser una aplicación, explicando más en detalle los ítems a continuación
	- Descripción general
	- Clases: Breve descripción de cada una que incluya responsabilidad y métodos principales, como mínimo
	- Diagramas UML: De clases como mínimo, en lo posible diagramas de secuencia para operaciones más complejas
	- Descripción de archivos y protocolos: Formato de archivos y protocolos de red utilizados, si son compartidos por varias aplicaciones pueden ponerlo en una sección aparte de este manual y hacer referencia a esa sección en cada módulo que lo use
* Programas intermedios y de prueba: Programas ‘intermedios’ que hayan usado para probar porciones del tp
* Código Fuente


### Manual de Usuario

* Instalación
	- Requerimientos de software: OS, bibliotecas y herramientas necesarias para instalar el programa
	- Requerimientos de hardware
	- Proceso de Instalación: Eventualmente puede requerir también la compilación
* Configuración: Archivos de configuración y configuración general de la aplicación)
* Forma de uso: A criterio del alumno, debe explicar como usar la aplicación de forma completa y desde la perspectiva del usuario final, incluyendo capturas de pantalla
* Apéndice de errores: Si la aplicación tiene códigos de error, poner aquí su descripción, posible causa y posible solución

* Instalación y uso
* Archivo de Configuración (detalles)
