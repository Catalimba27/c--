void SortArray (int array[],int first,int last)
{
    int i,j,p,t;

    // i se hace igual al índice del primer elemento
    i= first;
    // y j igual al índice del último elemento
    j= last;
    // p se hace igual al elemento pivote del arreglo
    p= array[(first+last)/2];

    do { 
        // se hace la partición del arreglo
        while (array[i]<p) i++; 
        while (p<array[j]) j--;
        if (i<=j) {

                // se intercambian los elementos i-esimo y j-esimo del arreglo
                t= array[i]; 
                array[i]= array[j]; 
                array[j]= t; 
                i++; j--;
            }
    } while (i<=j); 
    if (first<j) SortArray(array,first,j); 
    if (i<last) SortArray(array,i,last); 
}  