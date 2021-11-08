#include <stdio.h>
#include <stdlib.h>


int main () {

   srand(time(NULL));
   int matriz [9][9];
   int numX, numY, numX2, numY2, sum = 0, turns, counter = 6, gameover = 1, q, nPlayers, p = 0, cantRow = 3, d = 0, c = 0, space, y, x, z, empty, yF = 0, xF = 0, again = 1, complete = 1, next, emptyRow, nRow, stop = 0, 
   zero, cantZ, plus = 0, lastFirst, firstLast, h, exit1 = 0, n , zeroCounter = 0, thisRow = -1, y1 = 0, y2 = 0;
   char cRow ;
   

    //instrucciones del juego

    printf("\n");
    printf("--------------------------- Match-10 -----------------------------------------\n\n"
    "Match-10 es un juego que consiste en encontrar parejas de numeros, que sumados den como resultado 10 o que sean el mismo numero.\n"
    "Las parejas pueden formarse con numeros adyacentes (Horizontal, Vertical o Diagonal). Cada pareja encontrada suma puntos\n"
    "segun la tabla a continuacion.\n\n"
    "Cada jugador debe de elegir las coordenadas de los numeros que desea eliminar\n"
    "primero se elige la posicion vertical y luego la horizontal.\n\n"


    "--------------------- Coordenadas del tablero ----------------------\n\n");

    for (int i = 0; i <3; i++){
        for (int j = 0; j<9; j++){
          printf("(%d,%d)\t", i, j);
        }
    printf("\n\n");
     }

    printf("--------------------------------------------------------------------\n");
    printf("\n"

    "-----------------------------------------------------------\n"
    "Puntos\t |\t Tipo de pareja\n"
    "-----------------------------------------------------------\n"
    "1\t *Por encontrar una pareja de números con valores \n"
    "\t iguales en celdas adyacentes. \n\n"
    "\t *Por encontrar una pareja de números con valores\n"
    "\t que sumen 10 en celdas adyacentes. \n"
    "-----------------------------------------------------------\n"
    "2\t *Por encontrar un pareja de números con valores \n"
    "\t iguales, de los cuales uno se encuentra al final \n"
    "\t de una línea y el otra al comienzo de la línea \n"
    "\t siguiente iguales en celdas adyacentes. \n\n"
    "\t *Por encontrar un pareja de números con valores \n"
    "\t que sumen 10, de los cuales uno se encuentra al \n"
    "\t final de una línea y el otra al comienzo de la \n"
    "\t línea siguiente. \n"
    "-----------------------------------------------------------\n"
    "4\t *Por encontrar parejas de números con valores \n"
    "\t iguales separados por celdas vacías por encontrar \n"
    "\t parejas de números con valores diferentes que \n"
    "\t sumen 10 separados por celdas vacías. \n\n"
    "\t Por encontrar una pareja de números con valores \n"
    "\t iguales, de los cuales uno se encuentra al final \n"
    "\t de una línea y el otra al comienzo de la línea \n"
    "\t siguiente y que están separados por celdas vacías. \n\n"
    "\t Por encontrar un pareja de números con valores \n"
    "\t que sumen 10, de los cuales uno se encuentra al \n"
    "\t final de una línea y el otra al comienzo de la \n"
    "\t línea siguiente y que están separados por celdas \n"
    "\t vacías. \n"
    "-----------------------------------------------------------\n"
    "10\t *Por eliminar una línea de números. \n"
    "-----------------------------------------------------------\n"
    "150\t *Por encontrar todas las parejas en el tablero. \n"
    "-----------------------------------------------------------\n\n");

   //seleccion de cuantos jugadores tendra el juego

   printf("Seleccione el numero de jugadores: ");
   scanf("%d", &nPlayers);

   printf("\n\n");

   printf("--------------------------------------------------------------------\n");

int player [nPlayers];

   printf("\n");

while (gameover != 0) {

    c = 0;

    printf("------------------------- Tablero [%d]: -----------------------------\n\n", complete);   

    //Creacion del espacio para la matriz junto con los numeros random.
   
    printf("--------------------------------------------------------------------\n\n");

    for (int i = 0; i < cantRow; i++){
        for (int j = 0; j<9; j++){
            matriz [i][j] = (rand()%(9-1+1))+1;
            printf("|%d|\t", matriz [i][j]);
        }
    printf("\n\n");
     }
  
    printf("--------------------------------------------------------------------\n\n");

  //Loop 
  do {

    sum = 0;

      //Aqui el usuario elije las parejas que desea eliminar
    
      printf("Turno del jugador: %d\n\n", p+1);

     //Orden para agregar filas   
    if (cantRow < 9) {
        printf("Desea agregar una fila? [%d] s/n:", counter);
        scanf(" %c", &cRow);
        printf("\n\n"); 
        
      } else { // Si el usuario ya agrego todas las filas posibles

        printf("Ya no puede agregar filas.\n\n");
        cRow = 'n';

      }
    

    if (cRow == 's' || cRow == 'S') { //Si el usuario desea una nueva fila

          counter--;
          c++;         
          d = 0;
          next = 0;
          zero = 0;
          cantZ = 0;

        for (int i = 0; i < cantRow; i++) {
          for (int j = 0; j<9; j++) {

            if (matriz[i][j] == 0) { 

              sum+= matriz[i][j];
              zero++ ;

            } else {
              
              if (next < 9) {  

              matriz[cantRow + d][next] = matriz [i][j]; 
              next++;
            
              } else { 
              
              next = 0; d++; 
              matriz[cantRow + d][next] = matriz [i][j]; 
              next++;

              } 

            } 
          }
        }

        printf("%d\n", zero);
        cantRow += (d+1);
        printf("%d\n", cantRow) ;
        if (zero > 2) {

          zero = (zero / (plus+1));

          }

        printf("%d\n", zero);

        if (cantRow > 9) {

          cantRow = 9;

        }

       for (int i = 0; i <cantRow; i++) {
          for (int j = 0; j<9; j++) {

            
            if (matriz[i][j] == 0) {

              if (cantZ < zero) {
                    sum += matriz[i][j];
                    printf(" * \t");
                    cantZ++;
              } else {
                  sum+= 0;

                }

            } else if (matriz[i][j] < 10) {
              sum += matriz[i][j]; 
              printf("|%d|\t", matriz[i][j]);
              
            } 
      
         }
        
          printf("\n\n");

        }
        
    plus++; //Identifica si se ha usado anadir fila en el anterior turno
      

        
    } else if (cRow == 'R'){// Para forzar los resultados

      exit1 = 1;  

    } else {

        plus = 0;
        space = 0;
        y = 0;
        x = 0;
        h = 0; //evalua los 0 entre ultima y primera fila
        n = 0; // evalua los 0 entre adyacentes

        //Ordenes del usuario
        printf("Escoja la primera posicion Vertical:");
        scanf("%d", &numY);
        printf("\n");
        printf("Escoja la primera posicion Horizontal:");
        scanf("%d", &numX);
        printf("\n");
        printf("Usted ha escogido el numero: |%d| posicion: (%d,%d) \n\n", matriz[numY][numX], numY, numX);
        printf("Escoja la segunda posicion Vertical:");
        scanf("%d", &numY2);
        printf("\n");
        printf("Escoja la segunda posicion Horizontal:");
        scanf("%d", &numX2);
        printf("\n");
        printf("Usted ha escogido el numero: |%d| posicion: (%d,%d) \n\n\n", matriz[numY2][numX2], numY2, numX2);

      
    if (numX == numX2 && numY == numY2){ //Verificacion si las posiciones seleccionadas son iguales, por ende da error, pero permite volver a intentarlo.

        printf("** Usted ha seleccionado la misma posicion, vuelvalo a intentar. **\n\n");

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf(" * \t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

    p --;

    } else if ((matriz[numY][numX] && matriz[numY2][numX2]) == 0){ //Verifica si se ingreasaron 0.

      printf("*** Usted ha seleccionado valores vacios. ***\n\n\n");

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf(" * \t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

      p --;
     
    
    } else if (matriz[numY][numX] == matriz[numY2][numX2]) {  //Verifica si las parejas son del mismo valor  
      
      firstLast = 0;
      h = 0;

      if(numY2 < numY) { //Verifica el orden en el que se eligieron los numeros. 
        y1 = numY2;
        y2 = numY;
      } else { 
        y1 = numY;
        y2 = numY2;
        }

      for (int i = y1; i < y2 ; i++) { //Verifica si se puede entre ultimo de una fila y primero de la siguiente.
         for (int k = numX; k < 9; k++) {

         if (i == y1 && k == numX ){
           firstLast += matriz[i][k];
         } else if (matriz[i][k] == 0) {
           h++;
         } else {

           firstLast += matriz[i][k];
           
         }

        }             
     }

     for (int i = y2; i < (y2+1); i++ ) {
       for (int j = 0; j < (numX2 + 1); j++) {

         if (i == y2 && j == numX2 ){
           firstLast += matriz[i][j];

         } else if (matriz[i][j] == 0) {
           h++;
         } else {

           firstLast += matriz[i][j];
           
         }
       }
     }

     printf("%d\n", firstLast);
     printf("h = %d\n\n", h);

     if (numY == numY2 || numX == numX2) { // Si estan en la misma fila o columna

        if (numY < numY2 || numX < numX2) {//Vertical y Horizontal (Derecha y Abajo)

          for (int i = numY; i<= numY2; i++) {
            for(int j = numX; j <= numX2; j++) {

              if (matriz[i][j] == 0){
                space += 0;
                n++;
              } else {
                space += matriz[i][j];
              }

            }
          }

        } else {//Vertical y Horizontal (Izquierda y Arriba)

          for (int i = numY2; i <= numY; i++) {
            for(int j = numX2; j <= numX; j++) {

              if (matriz[i][j] == 0){
                space += 0;
                n++;
              } else {
                space += matriz[i][j];
              }

            }
          }

        }
        
      } else { //Si estan diagonales

        if (numY < numY2 && numX < numX2) { //Diagonal inferior hacia la Derecha

          y = numY;
          x = numX;

          while(y <= numY2 && x <= numX2) {

            if(matriz[y][x] == 0){

              space += 0;

            } else {

              space += matriz[y][x];

            }

            y++;
            x++;

          }

        } else if (numY < numY2 && numX > numX2) { //Diagonal inferior hacia la Izquierda

          y = numY;
          x = numX;

          while(y <= numY2 && x >= numX2) {

            if(matriz[y][x] == 0){

              space += 0;
              n++;

            } else{

              space += matriz[y][x];

            }

            y++;
            x--;

          }  

        } else if (numY2 < numY && numX2 < numX) { //Diagonal superior hacia la Izquierda

          y = numY;
          x = numX;

          while(y >= numY2 && x >= numX2) {

            if(matriz[y][x] == 0){

              space += 0;
              n++;

            } else{

              space += matriz[y][x];

            }

            y--;
            x--;

          }    

        } else if (numY2 < numY && numX2 > numX) { //Diagonal superior hacia la Derecha

          y = numY;
          x = numX;

          while(y >= numY2 && x <= numX2) {

            if (matriz[y][x] == 0){

              space += 0;
              n++;

            } else {

              space += matriz[y][x];

            }

            y--;
            x++;

          }      
        }

      }
     
     

      if (n > 0) {

        player[p] += 3;

      }

      player[p]++;

      if ((firstLast / 2) == matriz[numY][numX]) { // Verifica si se encontro un numero entre filas
        space = firstLast;

        if (y1 < y2) {
        player[p] += 2;
        }

        if (h>0) { //Verifica si hubieron 0 de por medio.
          player[p] ++;
          }
        }
      

      if (space / 2 == matriz[numY][numX]){ //Comprobacion si se eligio bien. 

        matriz[numY][numX] = 0;
        matriz[numY2][numX2] = 0;

        for (int i = 0; i < cantRow; i++) { //Verifica si hay una fila completa de 0
          for (int j = 0; j < 9 ; j++) {
            if (matriz [i][j] == 0) {
             zeroCounter++;
             if (zeroCounter == 9) {

               thisRow = i;
               player[p] += 9; //Puntos por borrar una fila.

             }
            }
          }

          zeroCounter = 0;
        }

      if (thisRow > -1) {
        for (int i = thisRow; i < (cantRow-1); i++) { //Remueve la fila si tiene solo ceros
          for (int j = 0; j < 9 ; j++) {      
             
              matriz[i][j] = matriz[i+1][j];
          
          }

        }

        cantRow--;
      }


      printf("%d puntos\n\n", player[p] );

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf(" * \t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

    } else {

      printf("**** Los numeros ingresados SI son iguales, pero tienen obstaculos de por medio. Vuelvalo a intentar ****\n\n");

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf(" * \t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }
    p--;
    }
    } else if (matriz[numY][numX] + matriz[numY2][numX2] == 10) { //Verifica si la suma de los numeros seleccionados da 10
      

     firstLast = 0;
      h = 0;

      if(numY2 < numY) { //Verifica el orden en el que se eligieron los numeros. 
        y1 = numY2;
        y2 = numY;
      } else { 
        y1 = numY;
        y2 = numY2;
        }

      for (int i = y1; i < y2 ; i++) { //Verifica si se puede entre ultimo de una fila y primero de la siguiente.
         for (int k = numX; k < 9; k++) {

         if (i == y1 && k == numX ){
           firstLast += matriz[i][k];
         } else if (matriz[i][k] == 0) {
           h++;
         } else {

           firstLast += matriz[i][k];
           
         }

        }             
     }

     for (int i = y2; i < (y2+1); i++ ) {
       for (int j = 0; j < (numX2 + 1); j++) {

         if (i == y2 && j == numX2 ){
           firstLast += matriz[i][j];

         } else if (matriz[i][j] == 0) {
           h++;
         } else {

           firstLast += matriz[i][j];
           
         }
       }
     }

     printf("%d\n", firstLast);


      
      if(numY == numY2 || numX == numX2) { // Si estan en la misma fila o columna

        if (numY < numY2 || numX < numX2) {//Vertical y Horizontal (Derecha y Abajo)

          for (int i = numY; i<= numY2; i++) {
            for(int j = numX; j <= numX2; j++) {

              if (matriz[i][j] == 0){
                space += 0;
                n++;
              } else {
                space += matriz[i][j];
              }

            }
          }

        } else {//Vertical y Horizontal (Izquierda y Arriba)

          for (int i = numY2; i <= numY; i++) {
            for(int j = numX2; j <= numX; j++) {

              if (matriz[i][j] == 0){
                space += 0;
                n++;
              } else {
                space += matriz[i][j];
              }

            }
          }

        }
        
      } else { //Si estan diagonales
          
        if (numY < numY2 && numX < numX2) { //Diagonal inferior hacia la Derecha

          y = numY;
          x = numX;

          while(y <= numY2 && x <= numX2) {

            if(matriz[y][x] == 0){

              space += 0;

            } else {

              space += matriz[y][x];

            }

            y++;
            x++;

          }
        

        } else if (numY < numY2 && numX > numX2) { //Diagonal inferior hacia la Izquierda

          y = numY;
          x = numX;

          while(y <= numY2 && x >= numX2) {

            if(matriz[y][x] == 0){

              space += 0;
              n++;

            } else{

              space += matriz[y][x];

            }

            y++;
            x--;

          }  

          

        } else if (numY2 < numY && numX2 < numX) { //Diagonal superior hacia la Izquierda

          y = numY;
          x = numX;

          while(y >= numY2 && x >= numX2) {

            if(matriz[y][x] == 0){

              space += 0;
              n++;

            } else{

              space += matriz[y][x];

            }

            y--;
            x--;

          }    

        } else if (numY2 < numY && numX2 > numX) { //Diagonal superior hacia la Derecha

          y = numY;
          x = numX;

          while(y >= numY2 && x <= numX2) {

            if (matriz[y][x] == 0){

              space += 0;

            } else {

              space += matriz[y][x];

            }

            y--;
            x++;

          }      
        }

      } 
     
      if (n > 0) {

        player[p] ++;

      }

      player[p]++;

      if (firstLast == 10) { //Verifica si la suma da 10
        space = 10;

        if (y1 < y2) {
        player[p] += 2;
        }

        if (h>0) { //Verifica si hubieron 0 de por medio.
          player[p] ++;
          }
      }
     

      if (space == 10){ //Comprobacion si se eligio bien. 

        matriz[numY][numX] = 0;
        matriz[numY2][numX2] = 0;

        for (int i = 0; i < cantRow; i++) { //Verifica si hay una fila completa de 0
          for (int j = 0; j < 9 ; j++) {
            if (matriz [i][j] == 0) {
             zeroCounter++;
             if (zeroCounter == 9) {

               thisRow = i;
               player[p] += 9; //Puntos por borrar una fila.

             }
            }
          }

          zeroCounter = 0;
        }

      if (thisRow > -1) {
        for (int i = thisRow; i < (cantRow-1); i++) { //Remueve la fila si tiene solo ceros
          for (int j = 0; j < 9 ; j++) {      
             
              matriz[i][j] = matriz[i+1][j];
          
          }

        }

        cantRow--;
      }

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf(" * \t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

    } else {

      printf("**** Los numeros ingresados SI suman 10, pero tienen obstaculos de por medio. Vuelvalo a intentar ****\n\n");

      player[p]--;

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf(" * \t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }
    p--;
    }        

    } else { //Verifica que el usuario ingreso parejas equivocadas.

      printf("*** Uno o ambos de los valores ingresados son incorrectos, vuelvalo a intentar ***\n\n\n");

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf(" * \t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

      p --;
      
    }
  

        }
    //comprobacion final

      again = 0;
      
     for (int i = 0; i < cantRow ; i++) { 
       emptyRow = 0;

       for (int j = 0; j < 9; j++) {
         for (int k = 1; k < 9; k++) {

             if ((matriz [i][j] == 0) && (matriz [i][j+k] == 0)) {

            empty += 0;
            emptyRow+= 0;
            nRow = i;

            } else if ((matriz [i][j] + matriz [i][j+k] == 10) && (empty == 0)){

              again++;
              emptyRow+= 1;

            } else if (((matriz [i][j] > 0) && ((matriz [i][j] + matriz [i][j+k]) / 2 == matriz [i][j])) && (empty == 0)) {

              again++;
              emptyRow+= 1;

            } else if ((matriz [i][j] + matriz [i+k][j] == 10) && (empty == 0)) {

              again++;
              emptyRow+= 1;

            } else if (((matriz [i][j] > 0) && ((matriz [i][j] + matriz [i+k][j]) / 2 == matriz [i][j])) && (empty == 0)) {

              again++;
              emptyRow+= 1;

            } else if ((matriz [i][j] + matriz [i+k][j+k] == 10) && (empty == 0)) {

              again++;
              emptyRow+= 1;

            } else if (((matriz [i][j] > 0) && ((matriz [i][j] + matriz [i+k][j+k]) / 2 == matriz [i][j])) && (empty == 0)) {

              again++;
              emptyRow+= 1;

            } else {

              empty ++;
              again += 0;
              emptyRow+= 1;

            }
         }

        empty = 0;

       }
     }   

    if (sum == 0 && again == 0) {

      complete++ ;
      cantRow = 3;
      player [p] += 150;
      

    } else if (sum != 0 && again == 0){

      sum = 0;
      gameover = 0;
      

    }       
    
      p++;
      if (p == nPlayers){ p = 0; } //reinicia el contador de jugadores

      if (exit1 == 1){
        sum = 0;
        gameover = 0;
      }
    


  } while ( sum != 0) ;

  


} // while 

  printf("--------Resultados--------\n\n");

  for (int l = 0; l < nPlayers; l++ ){
  
  printf("Jugador %d: %d\n\n", l+1, player[l]);
  
  }
        return 0;
    }


