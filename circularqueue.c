/*11>.queue is a linear list in which element can be inserted only at one end rear of the queue delete at other end is called front of the queue.
Queue is work on FIFO rule(first In first Out)
we know that when queue is implemented as an array ,insertion is not possibles after the reachest the last position of array.
their may be backend position in the array but they can not be utilized.
To over come this limitation we use the concept of the circular queue.
Now after the (n-1)th position, 0th position occurs.if we want to insert an element, it can be inserted at 0th position
We have to take care of 2 thing----
if value of rear is max-1,then the insted the incrementing rear we will make it and then perform insertion
similarly when the value of front becomes max-1,it will not be increased but will be reset zero(0)
1.the circular queue will be empty in three situation.-----------
   --when initillay front is equal =-1.
   --when front becomes rear=rear+1.
   --when front is =0 & rear is=max-1.
the overflow condition in circular queue has 
overflow occcur only when all the array position are ocupied that when the array is full.-----
 --when front is=0.
 --rear is=max-1.
   or front is =rear+1.
*/

#include<stdio.h>
#include<stdlib.h>
#define max 5                                       
int queue[max];
int rear= -1;
int front = -1;
void insert(int item);
void del();
int isfull();
int isempty();
void display();
void peak();
void count();
int main()
{
	int item,choice;
	while(1)
	{
		printf("\n1. for insert data into queue \n");
		printf("2. for delete data into queue \n");
		printf("3. for EXIT \n");
		printf("4. for display the list\n");
		printf("5. find the peak value\n");
		printf("6.Count the total number\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data to be inserted into queue : ");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				del();
				break;
			case 3:
				exit(1);
			case 4:
				display();
				break;
			case 5:
			      peak();
				break;
			case 6:
				count();
				break;
			
	    }
	}
	return 0;
}
void insert(int item)
{
	int a;
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=item;
	}
	else if((rear+1)%max==front)
	{
		printf("queue is full\n");
	}
	else
	{
		 for(a=front;a!=rear;a=(a+1)%max)
		{
			if(queue[a]==item)
			{
			printf("\nThis number is already exist\nEnter another number\n\n");
			return;
			}
		}
		if(queue[rear]==item)
		{
			printf("\nThis number is already exist\nEnter another number\n\n");
			return;
		}
		rear=(rear+1)%max;
		queue[rear]=item;	
	}
}
void del()
{
	if(front==-1 && rear==-1)
	{
		printf("\nqueue is underflow...\n");
	}
	else if(front==rear)
	{
		printf("%d\t",queue[front]);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("%d\t",queue[front]);
		front=(front+1)%max;
	}	
}
void display()
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("\nqueue is empty\n");
	}
	while(i!=rear)
	{
		printf("%d\t",queue[i]);
		i=(i+1)%max;
	}
	printf("%d\t",queue[i]);
}
void peak()
{	
	printf("The peak element is=%d\n",queue[rear]);
}
void count()
{
	int count=0,i;
	i=front;
	while(i!=rear)
	{
		i=(i+1)%max;
		count++;
	}
	printf("The total number is=%d",++count);
}