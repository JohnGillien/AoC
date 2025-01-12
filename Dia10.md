Algoritmo empleado-> Memodira dinamica
El problema se esogio debido a que era uno de los nos parecia mas adecuado para este algoritmo y poder practicarlo

Se eligio el algoritmo de memoria dinámica ya que al ser un reoccrido es el mas eficiente para saber los caminos que ya se han recorrido y no tener que volver a recorrer el mismo camino. 

Como se ha solucionado:
  A traves de la memoria dinamica hemos planteado 4 posibles caminos: arriba, abajo, derecha e izqueirda. Se ha implementado mediante un for para que pudiera recorrer los 4 caminps posibles. Una vez llegara a la celda ese camino obtenia un id para poder disinguirse de otros camino si se juntaban o separaban. Por tanto a este id se iba arastrando hasta el final y obteniendo las salidas a 9. 

El problema es aplicable al ejercico de prueba, ya que a la hora de copilarlo usando el mapa grande este no obtiene el valor deseado.

Se propuso intentar hacerlo sin el uso de las ids pero al no emplearse los caminos no se distingue y en caso de que un camino se separe pero se vuelva a juntar estos se sumaban.

