Problema del Día 5 

Enunciado: El desafío consiste en procesar un conjunto de datos representados por un grafo, construir conexiones entre nodos y verificar si las relaciones cumplen ciertos criterios de validez, en su mayoría relacionadas con la existencia de ciclos o conflictos entre nodos previamente procesados. 

Solución implementada: La solución consiste en desarrollar una clase llamada Cola, esta procesa las relaciones entre nodos mediante un map<int, vector<int>> el cual, almacenará las conexiones entre nodos. Cada línea de entrada es analizada para determinar si está generando una relación válida o si presenta un conflicto que debe ser descartado. Si no hay conflictos, se suman los nodos centrales al resultado final. 

Detalles técnicos: 

Estructuras usadas: 

    map<int, vector<int>>: Representa el grafo como un conjunto de nodos con sus aristas. Esta estructura permite agregar nuevas conexiones de manera eficiente. 

    set<int>: Utilizada para registrar los nodos procesados en cada iteración y evitar duplicados. 

Mejoras de eficiencia: 

    Utilizar map permite realizar búsquedas rápidas y manejar dinámicamente los nodos y conexiones. 

    Con el uso de set, aseguramos que cada nodo se procese solo una vez en cada iteración y se eviten duplicados. 

Dificultades y soluciones: 

    Manejo de entradas erróneas: Algunas líneas contienen caracteres incorrectos. Este problema lo resolvimos utilizando assert para validar que solo se procesaran números y delimitadores válidos. 

    Validación de ciclos: Para evitar ciclos, se verifican las conexiones de los nodos antes de agregarlos a las aristas, asegurando que no existan relaciones conflictivas. 
