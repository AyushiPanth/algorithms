#include <stdio.h>
#include <stdlib.h>

void merge(int*,int*,int*,int,int);
void mergeSort(int*,int);

void mergeSort(int a[],int n)
{
    if (n < 2) {
        
        return;
        
    } else  {
        
        int mid;
        int i;
        
        mid = n/2;
        int left[mid];
        int right[n-mid];
        
        for (i = 0; i < mid; i++) {
            
            left[i] = a[i];
        }
        
        for (i = mid; i < n; i++) {
            
            right[i - mid] = a[i];
        }
        
        mergeSort(left,mid);
        mergeSort(right,n-mid);
        merge(a,left,right,mid,n-mid);
    }
}

void merge(int a[],int left[],int right[],int nl,int nr)
{
    int i;
    int j;
    int k;
    
    i = j = k = 0;
    
    while (i < nl && j < nr) {
        
        if (left[i] <= right[j]) {
            
            a[k++] = left[i++];
            
        } else if (right[j] < left[i]) {
            
            a[k++]  = right[j++];
        }
    }
    
    while (i < nl) {
        
        a[k++] = left[i++];
    }
    
    while (j < nr) {
        
        a[k++] = right[j++];
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
    
    mergeSort(a,n);
    printf("The Sorted is\n");
    
    for (i = 0; i < n; i++) {
        
        printf("%d\n",a[i]);
    }
    
    return 0;
}