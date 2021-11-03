#include <stdio.h>
#include <stdlib.h>

int main () {

   srand(time(NULL));
   int matriz [3][9];
   int num, num1, options, sum = 0, turns, counter, error, q, nPlayers, p = 0;

    //instrucciones del juego

    printf("\n");
    printf("--------------------------- Match-10 -----------------------------------------\n\n"
    "Match-10 es un juego que consiste en encontrar parejas de numeros, que sumados den = 10 o que sean el mismo numero.\n"
    "Las parejas pueden formarse con numeros adyacentes (Horizontal, Vertical o Diagonal). Cada pareja encontrada suma puntos\n"
    "segun la tabla a continuacion.\n\n"
    
    "Puntos\t Tipo de pareja\n"
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
       printf("Escoja el primer numero:");
        scanf("%d", &num);
        printf("\n");
        printf("Escoja el segundo numero:");
        scanf("%d", &num1);
        printf("\n");

        printf("\n");

//Reinicia los contadores que ayudan a verificar las parejas en el loop y evitar eliminar mas numeros sin necesidad.
        options = 0;
        counter = 0;
        error = 0;

//Verifica las parejas ingresadas y trabaja dependiendo del caso
      for (int i = 0; i <3; i++){
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

                    sum += matriz[i][j];
                    printf("|%d|\t", matriz[i][j]);

                }

            //Este codigo sirve para verificar las parejas de manera Vertical, de ser verdadero les asigna a cada posicion un 0, imprime solo un espacio y le agrega a options un valor para llevar control de los numeros utilizados en el loop y counter para confirmar que ya se encontro el primer numero del loop.
            } else if (matriz [i][j] == num && matriz [i+1][j] == num1){

                if (num + num1 == 10) {
                  matriz [i][j] = 0;
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

        p+= 1;
        if (p == nPlayers){ p = 0; }

      //Condicion de prueba, falta designar la condicion correcta.
    } while ( sum != 0); 

  printf("--------Resultados--------\n\n");

  for (int l = 0; l<nPlayers; l++ ){
  
  printf("Jugador %d: %d\n\n", l+1, player[l]);
  
  }
        return 0;
    }