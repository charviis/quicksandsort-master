# include <stdio.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int pole[], int low, int high)
{
    int pivot = pole[high];  // select pivotu 
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
         // pole je menší nebo rovno pivotu 

        if (pole[j] <= pivot)
        {
            i++;    // inkrementace
            swap(&pole[i], &pole[j]);
        }
    }
    swap(&pole[i + 1], &pole[high]);
    return (i + 1);
}
 
// a[] = pole , p = počáteční bod, r = konečný bod

void quicksort(int a[], int p, int r)    
{
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}


// zobrazí pole
void printarray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int pole[] = {919524, 760901, 856236, 305877, 740420, 709523, 903800};
    int n = sizeof(pole)/sizeof(pole[0]);
// inicializace algoritmu
    quicksort(pole, 0, n-1);
    
    printarray(pole, n);
    return 0;
}