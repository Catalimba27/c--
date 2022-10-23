/*Realice un Programa en C++ que implemente la búsqueda binaria de un elemento
determinado dentro de un array (ordenado en formato descendente) de N elementos.*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void mostrarArreglo(const int[], int); //prototipo de funcion que recibe un arreglo constante 

int busquedaBinaria(const int[], int, int); //arreglo, tamano, clave
void ordenarArreglo(int[], int); //prototipo que modifica y ordena el arreglo
void intercambiar(int&, int&); //prototipo, intercambia los valores de dos elementos

int main()
{
  int clave =0;
  const int tamano = 15;
  int arreglo[tamano] = {25,17,13,16,41,32,12,115,95,84,54,63,78,21,10};
  //ordenamos el arreglo para que funcione la busquedaBinaria
  ordenarArreglo(arreglo,tamano);
  cout << "Elementos del arreglo: " << endl;
  mostrarArreglo(arreglo,tamano);
  cout << "Indique un valor a buscar y se le devolvera el indice: " << endl;
  cin >> clave;
  cout<< "\nSu valor se encuentra en arreglo["<<busquedaBinaria(arreglo,tamano,clave)<<"]" << endl;
  cout << "Fin del programa :)" << endl;
  return 0;
}//fin de main
void mostrarArreglo(const int arreglo[], int tamano)
{
  for (int i = 0 ; i < tamano ; i++)
    cout << "arreglo[" << i << "]=" << arreglo[i] << endl;
}
int busquedaBinaria(const int arreglo[], int tamano, int clave)
{
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro] == clave)
 return Icentro;
      else
 if (clave < arreglo[Icentro])
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}
void ordenarArreglo(int arreglo[], int tamano)
{
  for (int i = 0; i< tamano -1 ; i++)
    for (int j = 0; j< tamano -1 ; j++)
      if (arreglo[j] > arreglo[j+1])
 intercambiar(arreglo[j],arreglo[j+1]);
}
void intercambiar(int &a, int &b)
{
  int tmp = b;
  b = a;
  a = tmp;
}