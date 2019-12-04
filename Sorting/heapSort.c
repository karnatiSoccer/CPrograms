#include<stdio.h>
#include<stdlib.h>

void create(int []);
void heapify(int [],int);

int main()
{
	int *heap,n,i,last,temp;

	printf("Enter no. of elements:");
	scanf("%d",&n);
	
	heap = malloc((n+1)*sizeof(int));
	printf("\nEnter elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&heap[i]);

	//create a heap
	heap[0]=n;//storing heapsize in index 0;
	create(heap); //create max heap

	//sorting
	while(heap[0] > 1)
	{
		last=heap[0];
		//swap heap[1] and heap[last]		
		temp=heap[1];
		heap[1]=heap[last];
		heap[last]=temp;
		heap[0]--; // reduce heap size as root node(max) is moved to sort position
		heapify(heap,1);
	}

	//print sorted data
	printf("\nArray after sorting:\n");
	for(i=1;i<=n;i++)
		printf("%d ",heap[i]);

	return 0;
}

void create(int heap[])
{
	int i,n;
	n=heap[0]; //no. of elements

	for(i=n/2;i>=1;i--)
		heapify(heap,i);
}

void heapify(int heap[],int i)
{
	int j,temp,n,flag=1;
	n=heap[0];

	while(2*i<=n && flag==1)
	{
		j=2*i;    //j points to left child
		if(j+1<=n && heap[j+1] > heap[j])
			j=j+1;
		if(heap[i] > heap[j])
			flag=0;
		else
		{
			temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
			i=j;//Heapify the sub heap below it.
		}
	}
}