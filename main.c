/**
 * @file main.c
 * @author Rodrigo Alberto Nochez (00378021@uca.edu.sv) & Diego Sebastian Cuellar.
 * @version v.5.0
 * @date 2021-11-10
 * 
 * 
 * 
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int printBoard (int* matriz, int cantRow) ;
int cantZeros (int numY, int numX, int numY2, int numX2, int* matriz, int* firstLast, int* h) ;
int rowColumn (int numY, int numX, int numY2, int numX2, int* matriz, int* n, int* space) ;
int diagonalP (int numY, int numX, int numY2, int numX2, int* matriz, int* n, int* space) ;

int main () {

   srand(time(NULL));
   int matriz [9][9];
   int numX, numY, numX2, numY2, sum = 0, turns = 1, counter = 4, gameover = 1, p = 0, cantRow = 3, d = 0, space = 0, again = 1, complete = 1, next, zero, cantZ, firstLast, h, exit1 = 0, n , zeroCounter = 0, thisRow = -1, y1 = 0, y2 = 0, ok, r, r2, g;
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

   printf("\n\n");

   printf("--------------------------------------------------------------------\n");

   printf("\n");

while (gameover != 0) {

     turns = 1;

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
    thisRow = -1;

      //Aqui el usuario elije las parejas que desea eliminar
    
      printf("Turno #%d\n\n", turns);

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
          turns-- ;
          counter--;         
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

      
        cantRow += (d+1); //Agrega filas dependiendo del valor de d
    
        if (cantRow > 9) {

          cantRow = 9;

        }


printf("--------------------------------------------------------------------\n\n");
       for (int i = 0; i <cantRow; i++) {
          for (int j = 0; j<9; j++) {
            
            if (matriz[i][j] == 0) {

              if (cantZ < zero) {
                    sum += matriz[i][j];
                    printf(" * \t");
                    cantZ++;
              } else {
                  printf(" * \t");
                  sum+= 0;

                }

            } else if (matriz[i][j] < 10) {
              sum += matriz[i][j]; 
              printf("|%d|\t", matriz[i][j]);
              
            } else {

              matriz [i][j] = 0;
              printf(" * \t");

            }
      
         }
        
          printf("\n\n");

        }
        printf("--------------------------------------------------------------------\n\n");         

        
    } else if (cRow == 'R'){// Para forzar los resultados

      exit1 = 1;  

    } else {

        space = 0;
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

      
    if (numX == numX2 && numY == numY2){ //Verificacion si las posiciones seleccionadas son iguales.

        printf("** Usted ha seleccionado la misma posicion, vuelvalo a intentar. **\n\n");

      sum = printBoard ((int*) matriz, cantRow);

    

    } else if ((matriz[numY][numX] && matriz[numY2][numX2]) == 0){ //Verifica si se ingreasaron 0.

      printf("*** Usted ha seleccionado valores vacios. ***\n\n\n");

      sum = printBoard ((int*) matriz, cantRow);
       
    } else if (matriz[numY][numX] == matriz[numY2][numX2]) {  //Verifica si las parejas son del mismo valor  
      
      cantZeros (numY, numX, numY2, numX2, (int*) matriz, &firstLast, &h);

    if (numY2 < numY) {
      y1 = numY2;
      y2 = numY;
    } else {
      y1 = numY;
      y2 = numY2;
    }
      if ((numY == numY2) || (numX == numX2) ){

     rowColumn (numY, numX, numY2, numX2, (int*) matriz, &n, &space) ;

      } else {

     diagonalP (numY, numX, numY2, numX2, (int*) matriz, &n, &space) ;

      }
             
      if (n > 0) {

          p += 3;

      }

      p++ ;

      if ((firstLast / 2) == matriz[numY][numX]) { // Verifica si se encontro un numero entre filas
        space = firstLast;

        if (y1 < y2) {
        p++ ;
        }

        if (h > 0) { //Verifica si hubieron 0 de por medio.
          p += 2 ;
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
               p += 9; //Puntos por borrar una fila.

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

    sum = printBoard ((int*) matriz, cantRow);

      } else {

      printf("**** Los numeros ingresados SI son iguales, pero tienen obstaculos de por medio. Vuelvalo a intentar ****\n\n");

    sum = printBoard ((int*) matriz, cantRow);

      }
    } else if (matriz[numY][numX] + matriz[numY2][numX2] == 10) { //Verifica si la suma de los numeros seleccionados da 10
      

    cantZeros (numY, numX, numY2, numX2, (int*) matriz, &firstLast, &h);

    if (numY2 < numY) {
      y1 = numY2;
      y2 = numY;
    } else {
      y1 = numY;
      y2 = numY2;
    }

    if ((numY == numY2) || (numX == numX2) ){

     rowColumn (numY, numX, numY2, numX2, (int*) matriz, &n, &space) ;

      } else {

     diagonalP (numY, numX, numY2, numX2, (int*) matriz, &n, &space) ; 

      }

    if (n > 0) {

      p += 3;

    }

      p++;

      if (firstLast == 10) { //Verifica si la suma da 10
        space = 10;

        if (y1 < y2) {
        p++;
        }

        if (h>0) { //Verifica si hubieron 0 de por medio.
        p += 2;

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
               p += 9; //Puntos por borrar una fila.

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

      sum = printBoard ((int*) matriz, cantRow);

    } else {

      printf("**** Los numeros ingresados SI suman 10, pero tienen obstaculos de por medio. Vuelvalo a intentar ****\n\n");

       sum = printBoard ((int*) matriz, cantRow);

    }        

    } else { //Verifica que el usuario ingreso parejas equivocadas.

      printf("*** Uno o ambos de los valores ingresados son incorrectos, vuelvalo a intentar ***\n\n\n");

      sum = printBoard ((int*) matriz, cantRow); 
      
    }
  
    }
        
    //comprobacion final

      again = 0;
      ok = 0;
      
    for (int i = 0; i < cantRow ; i++) { //Verifica Filas
       for (int j = 0; j < 8; j++) {
         for (int k = 1; k < 9; k++) {
             

            if (matriz [i][j] + matriz [i][j+k] == 10) { //Verifica si alguna pareja en la misma fila forma 10

              r = (j+1);
              if (r > 7) {
                again+= 0;
              } else {
                while (r < j+k) {

                if (matriz[i][r] == 0) {
                  ok += 0;
                } else {
                  ok++ ;
                }

                r++;

              }
              
              if (ok == 0) { 
                
                again++;            
              
              } else {

                again+= 0;

              }
            }

              ok = 0;
              

            } else if ((matriz [i][j] > 0) && (matriz [i][j] == matriz [i][j+k])) { //Verifica si alguna pareja en la misma fila son el mismo numero (exceptuando el 0)

              r = (j+1);
                if (r > 7) {
                again+= 0;
              } else {
              while (r < j+k) {

                if (matriz[i][r] == 0) {
                  ok += 0;
                } else {
                  ok++ ;
                }

                r++;

              }
              
              if (ok == 0) { 
                
                again++;
              
              } else {

                again+= 0;

              } 
            }

              ok = 0;

              } else {

              again += 0;
              

            }
         }
       }   
     }

    for (int i = 0; i < (cantRow-1) ; i++) { //Verifica Columnas
       for (int j = 0; j < 9; j++) {
         for (int k = 1; k < cantRow; k++) {

           if (matriz [i][j] + matriz [i+k][j] == 10) { //Verifica si alguna pareja en la misma columna forma 10

              r = (i+1);
                if (r > cantRow) {
                again+= 0;
              } else {
              while (r < i+k) {

                if (matriz[r][j] == 0) {
                  ok += 0;
                } else {
                  ok++ ;
                }

                r++;

              }
              
              if (ok == 0) { 
                
                again++;
              
              } else {

                again+= 0;

              }
            } 

              ok = 0;

          } else if ((matriz [i][j] > 0) && (matriz [i][j] == matriz [i+k][j]))  { //Verifica si alguna pareja en la misma columna son el mismo numero (exceptuando el 0)

               r = (i+1);
                if (r > cantRow) {
                again+= 0;
              } else {
              while (r < i+k) {

                if (matriz[r][j] == 0) {
                  ok += 0;
                } else {
                  ok++ ;
                }

                r++;

              }
              
              if (ok == 0) { 
                
                again++;
              
              } else {

                again+= 0;

              }
            }

            ok = 0;

          } else {

              again += 0;
              

            }

         }
       }
      }

    for (int i = 0; i < (cantRow-1) ; i++) { //Verifica Diagonal 
       for (int j = 0; j < 8; j++) {
         for (int k = 1; k < cantRow; k++) {

           if (matriz [i][j] + matriz [i+k][j+k] == 10) { //Verifica si alguna pareja en la misma diagonal forma 10

               r = (i+1);
               r2 = (j+1);

              while (r < (i+k) && r2 < (j+k)) {

                if (matriz[r][r2] == 0) {
                  ok += 0;
                } else {
                  ok++ ;
                }

                r++;
                r2++;

              }
              
              if (ok == 0) { 
                
                again++;
              
              } else {

                again+= 0;

              }
              
              ok = 0;

            } else if ((matriz [i][j] > 0) && (matriz [i][j] == matriz [i+k][j+k])) { //Verifica si alguna pareja en la misma diagonal son el mismo numero (exceptuando el 0)

                r = (i+1);
               r2 = (j+1);

              while ((r+1) < (i+k) && (r2+1) < (j+k)) {

                if (matriz[r][r2] == 0) {
                  ok += 0;
                } else {
                  ok++ ;
                }

                r++;
                r2++;

              }
              
              if (ok == 0) { 
                
                again++;
              
              } else {

                again+= 0;

              }

              ok = 0;

            } else if (matriz [i][j] + matriz [i+k][j-k] == 10) { //Verifica si alguna pareja en la misma diagonal forma 10 (-)

               r = (i+1);
               r2 = (j-1);

              while (r2 > (j-k)) {

                if (matriz[r][r2] == 0) {
                  ok += 0;
                } else {
                  ok++ ;
                }

                r++;
                r2--;

              }
              
              if (ok == 0) { 
                
                again++;
              
              } else {

                again+= 0;

              }
              
              ok = 0;

            } else if ((matriz [i][j] > 0) && (matriz [i][j] == matriz [i+k][j-k])) { //Verifica si alguna pareja en la misma diagonal son el mismo numero (exceptuando el 0) (-)

                r = (i+1);
               r2 = (j-1);

              while (r2 > (j-k)) {

                if (matriz[r][r2] == 0) {
                  ok += 0;
                } else {
                  ok++ ;
                }

                r++;
                r2--;

              }
              
              if (ok == 0) { 
                
                again++;
              
              } else {

                again+= 0;

              }

              ok = 0;

          } else {

              again += 0;
              

            }
         }
       }
      }
   
    for (int i = 0; i < (cantRow-1); i++) { //Verifica ultimo y primeor de una fila
       for (int j = 0; j < 9; j++) {
         for (int k = 0; k < 9; k++) {

           if ((matriz[i][j] > 0) && (matriz[i][j] == matriz[i+1][k])) {


             r = (i+1);
             r2 = 0;
             g = (j+1);
             if (g > 8) {    
              g = -1 ;
             }

             while (r2 <= k) {

              if (g == -1) {

                if (matriz[r][r2] == 0) {
                 ok += 0;
                } else {
                 ok++ ;
                          
                }

                r2++ ;

              } else if (g < 9) {
                
                if (matriz[i][g] == 0) {
                  ok += 0;  
                } else {
                   ok++ ;
                }
                g++ ;
              } else {

                if (matriz[r][r2] == 0) {
                  ok += 0;              
                } else {
                  ok++ ;
                 }

                 r2++ ;
              }
              
             }

             if (ok == 0) { 
                
                again++;
              
              } else {

                again+= 0;

              }
              
              ok = 0;


           } else if ((matriz[i][j] + matriz[i+1][k]) == 10) {

             r = (i+1);
             r2 = 0;
             g = (j+1);
             if (g > 8) {    
              g = -1 ;
             }

             while (r2 <= k) {

              if (g == -1) {

                if (matriz[r][r2] == 0) {
                 ok += 0;
                } else {
                 ok++ ;
                          
                }

                r2++ ;

              } else if (g < 9) {
                
                if (matriz[i][g] == 0) {
                  ok += 0;  
                } else {
                   ok++ ;
                }
                g++ ;
              } else {

                if (matriz[r][r2] == 0) {
                  ok += 0;              
                } else {
                  ok++ ;
                 }

                 r2++ ;
              }
              
             }

             if (ok == 0) { 
                
                again++;
              
              } else {

                again+= 0;

              }
              
              ok = 0;


           } else {

             again += 0;


           }



         }      
       }
     }
                                   
    if (sum == 0 && again == 0) {

      complete++ ;
      cantRow = 3;
      p += 150; // Puntos por rellenar el tablero
      printf("\n\n");
      printf("###### Felicitaciones Usted a completado el tablero #########\n\n");
      

    } else if (sum != 0 && again == 0){

      sum = 0;
      gameover = 0;
      printf ("\n\n");
      printf("################ Ya no hay parejas que formar, gracias por jugar!. ################\n\n");
      

    }       
    
  if (exit1 == 1){ //Termina el juego al presionar R
        sum = 0;
        gameover = 0;
      }
    
    turns++;


  } while ( sum != 0) ;  

} // fin del while 

  printf("###--------Resultados--------###\n\n");

  
  
  printf("Puntaje final: %d\n\n", p);
  
        return 0;
    }


int printBoard (int* matriz, int cantRow) { //Funcion para imprimir matriz
  int total = 0;
  int stops = 0;
  printf("\n");
  printf("--------------------------------------------------------------------\n\n");
   for (int i = 0; i <((cantRow*9)); i++){
         
          if (matriz[i] == 0) {
            total += matriz[i];
            printf(" * \t");
            stops++ ;

          } else {
          total += matriz[i];
          printf("|%d|\t", matriz[i]);
          stops++ ;
          }

          if (stops == 9) {

            printf("\n\n");
            stops = 0;
          }
          
          

     
        
      }
printf("--------------------------------------------------------------------\n\n");

      return total;

}

int cantZeros (int numY, int numX, int numY2, int numX2, int* matriz, int* firstLast, int* h) { //Verifica finales e inicios de filas

       *firstLast = 0 ;
       *h = 0;
       int y1;
       int y2;
       int first;
       int last;

      if(numY2 < numY) { //Verifica el orden en el que se eligieron los numeros. 
        y1 = ((numY2*9) + numX2) ;
        y2 = (numY*9) + numX ;
        first = ((numY2*9) + numX2) ;
        last = (numY*9) + numX ;
      } else { 
        y1 = (numY*9) + numX ;
        y2 = ((numY2*9) + numX2) ;
        first = (numY*9) + numX ;
        last = ((numY2*9) + numX2) ;
      }

      while (y1 < (y2+1)) {

        if (matriz[y1] == 0) {

          *h += 3 ;

        } else if (matriz[y1] == first || matriz[y1] == last) {

          *firstLast += matriz[y1];

        } else {

          *firstLast += matriz[y1];

        }


        y1++;
      }

    

}

int rowColumn (int numY, int numX, int numY2, int numX2, int* matriz, int* n, int* space) {

  int y1;
  int y2;
  int first;
  int last;
  *space = 0;

    if((numY2 < numY) || (numX2 < numX)) { //Verifica el orden en el que se eligieron los numeros. 
        y1 = ((numY2*9) + numX2);
        y2 = (numY*9) + numX ;
        first = ((numY2*9) + numX2);
        last =(numY*9) + numX ;
       
    } else { 
        y1 = ((numY*9) + numX);
        y2 = ((numY2*9) + numX2) ;
        first = (numY*9) + numX ;
        last = ((numY2*9) + numX2);
        
    }
      
      if (numY == numY2) {

        while (y1 < (y2+1)) {
          if (matriz[y1] == 0){
            *space += 0;
            *n += 3;
          } else if (y1 == first || y1 == last){
            *space += matriz [y1];
          } else {
            *space += matriz[y1];
          }
            y1++ ;
          }

      } else {

        while (y1 < (y2+1)) {
          if (matriz[y1] == 0){
            *space += 0;
            *n += 3;
          } else if (y1 == first || y1 == last){
            *space += matriz [y1];
          } else {
            *space += matriz[y1];
          }
            y1 += 9;
          }

      }

  }
  
int diagonalP (int numY, int numX, int numY2, int numX2, int* matriz, int* n, int* space) {

  int y1;
  int y2;
  int first;
  int last;
  int diagon1;
  int diagon2;
  *space = 0;
  

    if(numY2 < numY) { //Verifica el orden en el que se eligieron los numeros. 
        y1 = ((numY2*9) + numX2);
        y2 = (numY*9) + numX ;
        first = ((numY2*9) + numX2);
        last = (numY*9) + numX ;
        diagon1 = numX2;
        diagon2 = numX;
        
        
        
    } else { 
        y1 = ((numY*9) + numX);
        y2 = ((numY2*9) + numX2) ;
        first = ((numY*9) + numX);
        last = ((numY2*9) + numX2) ;
        diagon1 = numX;
        diagon2 = numX2;
        
    }

      
      if (diagon1 < diagon2) {

        while (y1 < (y2+10)) {

        if (matriz[y1] == 0){
          *space += 0;
          *n += 3;
        } else if (y1 == first || y1 == last){
          *space += matriz[y1];
        } else {
          *space += matriz[y1];
        }

        y1 += 10;
        }

      } else {

        while (y1 < (y2 + 8)) {

        if (matriz[y1] == 0){
          *space += 0;
          *n += 3;
        } else if ((y1 == first) || (y1 == last)){
          *space += matriz[y1];
        } else {
          *space += matriz[y1];
        }

        y1 += 8;

        }
      }     
  }