#include <stdio.h>
#include <stdlib.h>


int main () {

   srand(time(NULL));
   int matriz [9][9];
   int numX, numY, numX2, numY2, options, sum = 0, turns, counter, error, q, nPlayers, p = 0, nRow = 0, cantRow = 3, d = 0, c = 0;
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

    //Creacion del espacio para la matriz junto con los numeros random.
   
    printf("--------------------------------------------------------------------\n\n");

    for (int i = 0; i <3; i++){
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

  if (nRow == 1) { 
        
    if (c < 6) {
        printf("Desea agregar una fila? s/n:");
        scanf(" %c", &cRow);
        printf("\n"); 
        
      } else {

        printf("Ya no puede agregar filas.\n\n");
        cRow = 'n';

      }

    if (cRow == 's' || cRow == 'S') {

          c++;
          cantRow++;          
          d = 0;

        for (int i = 0; i <cantRow; i++) {
        for (int j = 0; j<9; j++) {

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf("\t");

          } else {
          sum += matriz[i][j];

            if (d<9) {
  
          printf("|%d|\t", matriz[i][j]);
          matriz[cantRow-1][d] = matriz[i][j];
          d++;
          
          } else {

          printf("|%d|\t", matriz[i][j]);

            }
          }
        }
        printf("\n\n");
      }

        
    } else {

        printf("Escoja la primera posicion Vertical:");
        scanf("%d", &numY);
        printf("\n");
        printf("Escoja la primera posicion Horizontal:");
        scanf("%d", &numX);
        printf("\n");
        printf("Escoja la segunda posicion Vertical:");
        scanf("%d", &numY2);
        printf("\n");
        printf("Escoja la segunda posicion Horizontal:");
        scanf("%d", &numX2);
        printf("\n\n"); 

      if (matriz[numY][numX] + matriz[numY2][numX2] == 10) {

        matriz[numY][numX] = 0;
        matriz[numY2][numX2] = 0;

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf("\t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

     } else if (matriz[numY][numX] == matriz[numY2][numX2]) {

      matriz[numY][numX] = 0;
      matriz[numY2][numX2] = 0;

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf("\t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }
      
    } else {

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf("\t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

    }
    
      p+= 1;
      if (p == nPlayers){ p = 0; }

    }       
} else {

        printf("Escoja la primera posicion Vertical:");
        scanf("%d", &numY);
        printf("\n");
        printf("Escoja la primera posicion Horizontal:");
        scanf("%d", &numX);
        printf(")\n");
        printf("Escoja la segunda posicion Vertical:");
        scanf("%d", &numY2);
        printf("\n");
        printf("Escoja la segunda posicion Horizontal:");
        scanf("%d", &numX2);
        printf("\n\n"); 

      if (numX == numX2 && numY == numY2){

        printf("** Usted ha seleccionado la misma posicion, vuelvalo a intentar. **\n\n");

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf("\t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

    p --;
    nRow -= 2;

     } else if (matriz[numY][numX] + matriz[numY2][numX2] == 10) {

        matriz[numY][numX] = 0;
        matriz[numY2][numX2] = 0;

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf("\t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

     } else if (matriz[numY][numX] == matriz[numY2][numX2]) {

      matriz[numY][numX] = 0;
      matriz[numY2][numX2] = 0;

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf("\t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }
      
     } else {

      printf("Uno o ambos de los valores ingresados son incorrectos, vuelvalo a intentar\n\n");

      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

          if (matriz[i][j] == 0) {
            sum += matriz[i][j];
            printf("\t");

          } else {
          sum += matriz[i][j];
          printf("|%d|\t", matriz [i][j]);
          
          }

        }
        printf("\n\n");
      }

    p --;
    nRow -= 2;

    }
      
        
      

    




/**
//Reinicia los contadores que ayudan a verificar las parejas en el loop y evitar eliminar mas numeros sin necesidad.
        options = 0;
        counter = 0;
        error = 0;

//Verifica las parejas ingresadas y trabaja dependiendo del caso
  
      for (int i = 0; i <cantRow; i++){
        for (int j = 0; j<9; j++){

//El options == 2 verifica si en el loop ya se han eliminado 2 numeros, para evitar que se eliminen los casos repetidos y si la posicion no contiene 0 escribe el numero correspondiente a la casilla
            if (options == 2 && matriz [i][j] != 0) {

                sum += matriz[i][j];
                printf("|%d|\t", matriz[i][j]);

//Si options == 2 y el numero en la casilla corresponde a 0 entonces imprime solo el espacio, para dar la sensacion de estar eliminado
            } else if (options == 2 && matriz [i][j] == 0){
                
                sum += matriz[i][j];
                printf("\t");

//Si en la posicion seleccionada existe un 0 y el contador vale 1, entonces le agrega un numero a options e imprime un espacio, esto sirve para confirmar que se encontro la segunda pareja 
            } else if (matriz [i][j] == 0 && counter == 1){ 

                options++;
                sum += matriz[i][j];
                printf("\t");

            } else if (matriz [i][j] == 0){
                
                sum += matriz[i][j];
                printf("\t");
                
                //Este codigo sirve para verificar las parejas de manera horizontal
            } else if (matriz [i][j] == num && matriz [i][j+1] == num1 ){
                  
                  //Verifica si la suma de las parejas da igual a 10, de ser verdadero les asigna a cada posicion un 0, imprime solo un espacio y le agrega a options un valor para llevar control de los numeros utilizados en el loop y counter para confirmar que ya se encontro el primer numero del loop.
                  if (num + num1 == 10) {
                  matriz [i][j] = 0;
                  matriz [i][j+1] = 0;
                  sum += matriz[i][j];
                  printf("\t");
                  options++;
                  counter++;
                  player[p] += 1;
                  
                    //Verifica si las parejas son el mismo numero
                } else if(num == num1) {

                    matriz [i][j] = 0;
                  matriz [i][j+1] = 0;
                  sum += matriz[i][j];
                  printf("\t");
                  options++;
                  counter++;
                  player[p] += 1;

                } else {

                    sum += matriz[i][j];void command();
                  matriz [i+1][j] = 0;
                  sum += matriz[i][j];
                  printf("\t");
                  options++;
                  counter++;
                  player[p] += 1;

                } else if(num == num1) {

                    matriz [i][j] = 0;
                  matriz [i+1][j] = 0;
                  sum += matriz[i][j];
                  printf("\t");
                  options++;
                  counter++;
                  player[p] += 1;

                } else {

                    sum += matriz[i][j];
                    printf("|%d|\t", matriz[i][j]);

                }

            //Verificacion diagonal hacia la izquierda
            } else if (matriz [i][j] == num && matriz [i+1][j-1] == num1 ){

                if (num + num1 == 10) {
                  matriz [i][j] = 0;
                  matriz [i+1][j-1] = 0;
                  sum += matriz[i][j];
                  printf("\t");
                  options++;
                  counter++;

                } else if(num == num1) {

                    matriz [i][j] = 0;
                  matriz [i+1][j-1] = 0;
                  sum += matriz[i][j];
                  printf("\t");
                  options++;
                  counter++;

                } else {

                    sum += matriz[i][j];
                    printf("|%d|\t", matriz[i][j]);

                }

                //Verificacion diagonal hacia la derecha
            } else if (matriz [i][j] == num && matriz [i+1][j+1] == num1 ){

                if (num + num1 == 10) {
                  matriz [i][j] = 0;
                  matriz [i+1][j+1] = 0;
                  sum += matriz[i][j];
                  printf("\t");
                  options++;
                  counter++;

                } else if(num == num1) {

                  matriz [i][j] = 0;
                  matriz [i+1][j+1] = 0;
                  sum += matriz[i][j];
                  printf("\t");
                  options++;
                  counter++;

                } else {

                    sum += matriz[i][j];
                    printf("|%d|\t", matriz[i][j]);

                }

                //Verificacion diagonal hacia la izquierda
            } else {

                sum += matriz[i][j];
                printf("|%d|\t", matriz[i][j]);
                
                }
        }

            printf("\n\n");
            turns+= 1;
            

            
            
        }

        nRow++;
        p+= 1;
        if (p == nPlayers){ p = 0; }

      //Condicion de prueba, falta designar la condicion correcta.
        }
        **/
       nRow++;
      }
    
      p++;
      if (p == nPlayers){ p = 0; }

    } while ( sum != 0); 

  printf("--------Resultados--------\n\n");

  for (int l = 0; l<nPlayers; l++ ){
  
  printf("Jugador %d: %d\n\n", l+1, player[l]);
  
  }
        return 0;
    }
