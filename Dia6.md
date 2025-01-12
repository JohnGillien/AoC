Problema del Día 6 
 Enunciado: El desafío consistía en detectar patrones dentro de secuencias de caracteres o bloques de texto, para verificar estados y evitar duplicados. El uso de tablas hash permite hacer estas verificaciones de forma eficiente y ordenada. 

Solución implementada: Diseñamos una clase GridTraversal que utiliza una tabla hash personalizada, la cual,  almacena los nodos visitados y gestiona su acceso de forma óptima. Cada posición (nodo) en la cuadrícula se almacena en unordered_set para permitir una verificación rápida de los elementos previamente visitados, evitando la repetición, y optimizando el algoritmo en tiempo lineal. 

Detalles técnicos: 

    Estructuras usadas: 

    unordered_set: Para almacenar las posiciones de la cuadrícula visitadas y garantizar la unicidad de los nodos. 

    unordered_map: Para facilitar el manejo y la búsqueda eficiente en un espacio de datos clave-valor. 

Mejoras de eficiencia: 

    Al utilizar un hash personalizado para almacenar las posiciones de la cuadrícula, logramos verificar rápidamente si una posición ya ha sido visitada. 

Dificultades y soluciones: 

    Problemas con la definición de direcciones: Inicialmente, el recorrido no esta  definido de forma clara para todas las direcciones posibles, pero el uso de una lista con las direcciones permitió manejar todos los casos. 

    Manejo de datos duplicados: debemos asegurarnos de no visitar los mismos nodos múltiples veces, para ello, se usa una tabla hash que prevendrá esta duplicación. 
Estrategia inicial descartada: 
   Se intentó abordar el problema utilizando programación dinámica. Para ello intenté analizar sobresaltados y sacar una solución a base de estos. Sin embargo, al revisar el problema más a fondo, me di cuenta de que esto no era necesario, ya que no existía una subestructura que pudiera resolverse de forma óptima mediante este enfoque. 

Motivo de descarte: 
      La programación dinámica, al ser una solución que necesita dividir el problema en subproblemas y almacenar subresultados, introducía una complejidad innecesaria para este caso específico. En su lugar, una solución basada en tablas hash fue más eficiente y directa 		para resolver la tarea de verificar la unicidad y gestionar el estado de forma dinámica. Así, se 	optó por emplear hash en lugar de acumular y gestionar valores parciales. 

 Reflexión: Este problema me enseñó la importancia de emplear estructuras de datos eficientes, especialmente las tablas hash, para poder detectar patrones en datos y optimizar operaciones. El uso de un hash personalizado permitió evitar redundancias y mejorar significativamente la eficiencia en la verificación de patrones en secuencias.     
