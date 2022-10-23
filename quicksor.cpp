#include <iostream>
using namespace std;

void Quicksrot(int* arr, int izq, int der)

{
 int i=izq, j = der,tmp;
 int p= arr[(izq+der)/2];
 
 while(i<=j)
   {

      while (arr[i]< p) i++;
      while(arr[j] > p) j--;
      if(i<=j)
      {
          tmp= arr[i];
          arr [i] =arr[j];
          arr[j] =tmp;
          i++;j--;
       }   
   }   
   if (izq<j)
           Quicksrot(arr,izq, j);
           if (i<der)
               Quicksrot(arr,i,der);

}

int main()
{

 cout<<"Este es el Metodo QuickSort\n\n";
 cout<<"Este es el vector a ordenar\n";
 cout<<"20,45,25,68,45,24,35,48,6,48,86,88,6,69,-33,98,23,5,45,24,2,48,4,25,458,4,5,0,12,100\n\n";
 cout<<"Vector ordenado : \n\n";
 int arreglo[30]={ 20,45,25,68,45,24,35,48,6,48,86,88, 6, 69,
  -33, 98,  23, 5,45,24,2,48,4,25,458,4,5, 0,12, 100}; 

 
 
 Quicksrot (arreglo,0,29);
 
 for(int i=0; i<30; i++)
    cout<<arreglo[i]<<" ";
    
    system ("pause");
    return 0;
 }