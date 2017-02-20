# include <stdio.h>
# include <stdlib.h>

int check_MAX_heap(int *,int,int);
void build_MAX_heap(int *,int, int);
int extract_MAX(int *,int, int);
void insert(int *,int,int,int);
void change(int *,int,int,int,int);
void restoreDown(int *, int , int , int );
                                         
int main()
{
  char ch=' ';
  int *arr,n,k,i,new;
  scanf("%d",&k);
  printf("val of k=%d\n",k);
  scanf("%d",&n); /* To have anything non-trivial, n should be >2*n*k*/
   printf("val of n=%d\n",n);
  arr = (int *)malloc(2*n*sizeof(int));
  for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
  if(!check_MAX_heap(arr,n,k))
    build_MAX_heap(arr,n,k);
    printf("max heap is built\n");
  do
    {
      while(getchar()!='\n'); /* To clear the buffer of any leftover characters*/
      ch=getchar();
      switch(ch)
	{
	case 'i':
	  scanf("%d",&new);
	  insert(arr,n,k,new);
	  n++;
	  break;
	case 'd':
	  printf("%d",extract_MAX(arr,n,k));
	  n--;
	  break;
	case 'c':
	  scanf("%d",&i);
	  scanf("%d",&new);
	  change(arr,n,k,i,new);
	  break;
	}
    }while(ch!='q');
  return 0;
}

int check_MAX_heap(int arr[],int n,int k)
{
  /* The function returns 0 if arr is NOT a k-ary MAX-heap.*/
  int j;
  int i=n/k;
  for(i;i>=0;i--)
  {
	int largest=arr[i],large=i;
	int j=k*i + 1;
	for(j;j<k*i+ k+1 && j<n;j++)
	{ 
		
		if(arr[j]>largest)
		{
			largest=arr[j];
			large=j;
		}
	  
	}
	if(large!=i)
	{
		return 0;
	}

  }
}

void build_MAX_heap(int arr[],int n,int k)
{
        printf("building\n");
	int i;
  /* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
	for ( i= (n-1)/k; i>=0; i--)
        restoreDown(arr, n, i, k);

}

void insert(int arr[],int n,int k,int new)
{
  
    arr[n] = new;
 
    
    n = n+1;
    int index=n-1;
   
    int parent = (index-1)/k;
 
    
    while (parent>=0)
    {
        if (arr[index] > arr[parent])
        {
            int temp=arr[index];
	    arr[index]= arr[parent];
	    arr[parent]=temp;
            index = parent;
            parent = (index -1)/k;
        }
 
        
        else
            break;
    }
}

int extract_MAX(int arr[],int n,int k)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
	 // Stores the key of root node to be returned
    printf("inside d\n");
    int max = arr[0];
 
    
    arr[0] = arr[n-1];
 
    
    n = n-1;
    int len=n,index=0;
    // or  call the restoreDown() function to restore the correct place of root node
    int child[k+1];
 
    while (1)
    {
        int i;
        for ( i=1; i<=k; i++)
            child[i] = ((k*index + i) < len) ?
                    (k*index + i) : -1;
 
       
        int max_child = -1, max_child_index ;
 
        
        for ( i=1; i<=k; i++)
        {
            if (child[i] != -1 &&
                arr[child[i]] > max_child)
            {
                max_child_index = child[i];
                max_child = arr[child[i]];
            }
        }
 
        
        if (max_child == -1)
            break;
 
        
        if (arr[index] < arr[max_child_index])
            {
		int temp=arr[index];
		arr[index]=arr[max_child_index];
		arr[max_child_index]=temp;
	     } 
        index = max_child_index;
    }
 
    return max;
}

void change(int arr[],int n,int k,int i,int new)
{
  /* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
  arr[i-1]=new;
  build_MAX_heap(arr,n,k);
}
void restoreDown(int arr[], int len, int index,
                                        int k)
{
    // child array to store indexes of all
    // the children of given node
    int child[k+1];
     int i;
    while (1)
    {
        // child[i]=-1 if the node is a leaf
        // children (no children)
        for (i=1; i<=k; i++)
            child[i] = ((k*index + i) < len) ?
                    (k*index + i) : -1;
 
        // max_child stores the maximum child and
        // max_child_index holds its index
        int max_child = -1, max_child_index ;
 
        // loop to find the maximum of all
        // the children of a given node
        for ( i=1; i<=k; i++)
        {
            if (child[i] != -1 &&
                arr[child[i]] > max_child)
            {
                max_child_index = child[i];
                max_child = arr[child[i]];
            }
        }
 
        // leaf node
        if (max_child == -1)
            break;
 
        // swap only if the key of max_child_index
        // is greater than the key of node
        if (arr[index] < arr[max_child_index])
           {
		int temp=arr[index]; arr[index]= arr[max_child_index];
		arr[max_child_index]=temp;
 	    }
        index = max_child_index;
    }
}

