Enunciado: El desafío consistía en resolver una serie de operaciones que se iban combinando unas con otras, partiendo de unos parámetros iniciales x… e y… con valores 0 o 1. El objetivo final es conseguir obtener los valores de las diferentes z…, para después, al ordenarlos, obtener un número binario que, al pasarlo a decimal, nos dé la solución del problema. 

Solución implementada: Se diseña una solución usando una estructura de árbol binario de ordenación y búsqueda. Tras varias ideas, decidimos ordenar todos los nodos en un mismo árbol de manera alfabética, considerando esta opción como la más óptima para resolver el problema usando estructuras de árboles binarios. 

Detalles técnicos: 

    Estructuras usadas: 

    TreeNode: Para definir la estructura del nodo de un árbol, con todas las variables necesarias. 

    Mejoras de eficiencia: 

    Al utilizar un árbol binario de búsqueda, ordenando los nodos alfabéticamente, resulta sencillo buscar los operadores que se necesitan para cada operación concreta y es una manera eficiente de solucionar el problema planteado. 

    Dificultades y soluciones: 

    Problemas con el resultado del código: no se ha conseguido obtener el resultado final del problema correctamente, debido a un problema en el código que no hemos conseguido arreglar.  
    En algún lugar de este, posiblemente en la función calcularValor, se está colando en las operaciones el valor con el que se inicializan los nodos(-1 en este caso), afectando al resultado final. Esto se puede comprobar cuando tenemos una operación XOR en alguna de las operaciones, ya que en la salida imprime valores negativos. Además, si se da un valor inicial de los nodos distinto de -1, vemos como imprime distintos valores, por tanto, el problema está definitivamente relacionado a esta causa. 
    Por lo demás, el código ordena, recorre, y busca en el árbol perfectamente, habiéndolo comprobado visualizando el correcto funcionamiento de cada función clave mediante cout’s en cada una de estas. 
    
  Estrategia inicial descartada: 
Se intentó abordar el problema realizando un árbol distinto para cada nodo “z…”, de manera que hubiese tantos árboles como nodos “z”, pero al final, a pesar de ser una manera más sencilla de visualizar, ya que iba recorriendo las distintas operaciones combinadas desde los parámetros iniciales “x” e “y” hasta el resultado final “z”, no resultó ser una solución óptima. Por tanto, se decidió buscar la solución empleando un único árbol con un orden concreto, en este caso, alfabético, en el que fuese más sencillo buscar un nodo concreto que se necesitase. 

Motivo de descarte: La opción de tener un árbol por cada nodo “z” no resultó ser una solución óptima por varias razones. Por ejemplo, había nodos que estaban implicados en varias operaciones, además, al no haber un orden definido en el árbol era complicado buscar en él, y finalmente, no era buena opción una solución en la que hubiese una cantidad tan grande de árboles (por ejemplo, en el input dado habría 45 árboles). 
