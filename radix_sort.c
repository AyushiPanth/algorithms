#include <stdio.h>
#include <stdlib.h>

void counting(int *,int,int,int);

void counting(int a[],int size,int k,int exp)
{
    int count[k];
    int output[size];
    int i;
    
    for (i = 0; i < k; i++) {
        
        count[i] = 0;
    }
    
    for (i = 0; i < size; i++) {
        
        count[(a[i]/exp)%k]++;
    }
    
    for (i = 1; i < k; i++) {
        
        count[i] = count[i] + count[i-1];
    }
    
    for (i = size - 1; i >= 0; i--) {
        
        output[count[(a[i]/exp)%k]-1] = a[i];
        count[(a[i]/exp)%k]--;
    }
    
    for (i = 0; i < size; i++) {
        
        a[i]  = output[i];
        
    }
}

int main()
{
    int i;
    int n;
    int max;
    
    scanf("%d",&n);
    
    int a[n];
    
    for (i = 0; i < n; i++) {
        
        scanf("%d",&a[i]);
    }
    
    max = a[0];
    
    for (i = 1; i < n; i++) {
        
        if (a[i] > max) {
            
            max = a[i];			//Find max to get Maximum No. of Digits
        }	
    }
    
    for (i = 1; max/i > 0; i = i*10) {
        
        counting(a,n,10,i);			//At Each Pass Apply CountingSort from LSB To MSB		
    }
    
    printf("After Sorting\n");
    
    for (i = 0; i < n; i++) {
        
        printf("%d\n",a[i]);
    }
    
    return 0;
}