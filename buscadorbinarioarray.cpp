/*Se dispone de un arbol de elementos de tipo entero. Escriba funciones que calculen:
a) La suma de sus elementos.
b) La suma de sus elementos que son multiplos de 3. */

#include <stdio.h>
 #include <iostream>
 #include <stdlib.h>

 struct nodoArbol {
        struct nodoArbol *Izq; /* apuntador al subárbol izquierdo */
        int dato; /* valor del nodo */
        struct nodoArbol *Der; /* apuntador al subárbol derecho */
 };


void insertaNodo(struct nodoArbol **ptrArbol, int valor )
 {
 if ( *ptrArbol == NULL ) {  // si el árbol está vacío
        *ptrArbol = new(nodoArbol);
                ( *ptrArbol )->dato = valor;
                ( *ptrArbol )->Izq = NULL;
                ( *ptrArbol )->Der = NULL;
 }
 else { // el árbol no está vacío

        if ( valor < ( *ptrArbol )->dato ) // el dato a insertar es menor que el dato en el nodo actual
                insertaNodo( &( ( *ptrArbol )->Izq ), valor );

        else if ( valor > ( *ptrArbol )->dato ) // el dato a insertar es mayor que el dato en el nodo actual
                insertaNodo( &( ( *ptrArbol )->Der ), valor );

        else  // ignora el valor duplicado del dato
                printf( "duplicado \n\n" );
 }
 }

 void inorden(struct nodoArbol *ptrArbol )
 {
 if ( ptrArbol != NULL ) {
 inorden( ptrArbol->Izq );
 printf( "%d -->", ptrArbol->dato );
 inorden( ptrArbol->Der );
 }
 }

int suma (nodoArbol *ptrArbol){
 int s;
 if(ptrArbol==NULL){
  s = 0;
 }
 else
 s = ptrArbol->dato + suma(ptrArbol->Der) + suma(ptrArbol->Izq);
 return s;
}

int sumamultiplo( nodoArbol *ptrArbol, int c){
 int s;
 if (ptrArbol==NULL){
  s = 0;
 }
 else {
  if ((ptrArbol->dato)%c == 0){
   s = ptrArbol->dato + sumamultiplo(ptrArbol->Der,c) + sumamultiplo(ptrArbol->Izq,c);
  }
  else {
   s = sumamultiplo(ptrArbol->Der,c) + sumamultiplo(ptrArbol->Izq,c);
  }
 }
 return s;
}

 int main(){
 int i,n,y,x,w,c;
 struct nodoArbol *ptrRaiz = NULL, *p=NULL; /* árbol inicialmente vacío */
 do{
        printf("\n\tTEMA ARBOLES: \n\n");
        printf("\t    MENU\n\n");
        printf("\t1) Insertar valores al arbol: \n");
        printf("\t2) Mostrar el Arbol de forma Inorden. \n");
  printf("\t3) Suma de sus elementos \n");
  printf("\t4) La suma de sus elementos multiplos de ___ : \n");      
  printf("\t0) SALIR. \n");
        printf("\n\t    >>Ingrese una opcion:");
        scanf("%d",&n);
        switch(n)
        {
        case 0: exit(0);
          break;
          
        case 1: printf("\n\nIngrese la cantidad de datos que desea insertar en el arbol:\n");
          scanf("%d",&y);
          printf("\nLos datos son: ");
                for ( i = 1; i <= y; i++ ) {
                 printf("\nIngrese el dato %d : ",i);
                 scanf("%d",&x);
                    insertaNodo( &ptrRaiz, x );
                }
                break;
             
        case 2: if(ptrRaiz!=NULL){
    printf( "\n\nSe muestra en forma inorden el arbol:\n\t\t" );
                inorden( ptrRaiz );
    printf("\n");}
                else{
                 printf("\nEL ARBOL ESTA VACIO...\n");
    }
                break;
         
        case 3: if(ptrRaiz!=NULL){
    w = suma(ptrRaiz);
          printf("\nLa suma de los elementos del arbol es : %d \n",w);}
          else{
           printf("\nComo no ha ingresado datos la suma es : 0\n");
    }
          break;
          
        case 4: if(ptrRaiz!=NULL){
    printf("\nIngrese el numero del cual debe ser multiplo:");
          scanf("%d",&c);
    w = sumamultiplo(ptrRaiz,c);
          printf("\nLa suma de los elementos multiplos de %d es : %d \n\n",c,w);}
          else {
           printf("\nNo hay datos en el arbol...\n");
    }
          break;

  default :
     printf("\n\nIngrese otra opcion...\n");
 }
 system("pause");
 system("cls");
 } while(n!=0);
 return 0;
 }