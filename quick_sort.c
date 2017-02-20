#include <stdio.h>
#include <stdlib.h>

int partition(int*,int,int);
void quicksort(int*,int,int);
void swap(int*,int*);

void swap(int* a,int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int start,int end)
{
    int pivot;
    int pindex;
    int i;
    
    pindex = start;
    pivot = a[end];
    
    for (i = start; i < end; i++) {
        
        if (a[i] <= pivot) {
            
            swap(&a[i],&a[pindex]);
            pindex = pindex + 1;
            
        }
    }
    
    swap(&a[end],&a[pindex]);
    return pindex;
}

void quicksort(int a[],int start,int end)
{
    if (start < end) {
        
        int pindex;
        
        pindex = partition(a,start,end);
        quicksort(a,start,pindex-1);
        quicksort(a,pindex+1,end);
        
    }
}

int main()
{
    int i;
    int n;
    
    scanf("%d",&n);
    
    int a[n];
    
    for (i = 0; i < n; i++) {
        
        scanf("%d",&a[i]);
        
    }
    
    quicksort(a,0,n-1);
    
    printf("The Sorted is :-\n");
    
    for (i = 0; i < n; i++) {
        
        printf("%d\n",a[i]);
        
    }
    
    return 0;
}