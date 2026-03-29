//Program of sorting using selection sort/
//* Program of sorting using bubble sort */
/*#include <stdio.h>
#define MAX 20
int main()
{
	int arr[MAX],i,j,k,temp,n,xchanges;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Unsorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	 printf("\n");
	for (i = 0; i < n-1 ; i++)
	{
		xchanges=0;
		for (j = 0; j <n-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				xchanges++;
			}
		}
		if(xchanges==0) 
			break;
		printf("After Pass %d elements are :  ",i+1);
		for (k = 0; k < n; k++)
			printf("%d ", arr[k]);
		printf("\n");
	}
	printf("Sorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}*/
#include<stdio.h>
# define max 20
int main()
{
	int i,j,k,n,arr[max],tmp,xchanges;
	printf("enter number u want that\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter elemets%d:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
      printf("\n");
	for(i=0;i<n-1;i++)
	{
		xchanges=0;
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				xchanges++;
			}
			
		}
            if(xchanges==0)
            break;
            printf("after pass =%d elements are:",i+1);
	for(k=0;k<n;k++)
		printf("%d\t",arr[k]);
	printf("\n");
	}
	printf("after sorting\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
      printf("\n");
}
/*#include<stdio.h>
#define max 20
int main()
{
      int i,j,k,n,arr[max],tmp,smallest;
      printf("enter elements u want that\n");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
            printf("enter elemetns u enter that%d:",i+1);
            scanf("%d",&arr[i]);
      }
      printf("unsorted elements are:");
      for(i=0;i<n;i++)
      {
            printf("%d",arr[i]);
      }
      printf("\n");
      for(i=0;i<n-1;i++)
      {
            smallest=i;
            for(k=i+1;k<n;k++)
            {
                  if(arr[smallest]>arr[k])
                  smallest=k;
            }
                  if(k!=smallest)
                  {
                        tmp=arr[i];
                        arr[i]=arr[smallest];
                        arr[smallest]=tmp;
                  }
            
             printf("after pass %d elemrnts are:",i+1);
                  for(j=0;j<n;j++)
                  {
                        printf("%d",arr[j]);
                  }
                  printf("\n");
      }
       printf("after sorting\n");
                  for(i=0;i<n;i++)
                  {
                        printf("%d",arr[i]);
                  }
                  printf("\n");
}*/