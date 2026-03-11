/*11>.queue is a linear list in which element can be inserted only at one end rear of the queue delete at other end called front of the queue.
Queue is work on FIFO rule(Frist In Frist Out)
we know that when queue is implemented as an array ,insertion is not possibles after the reachest the last position of array.
their may be backend position in the array but they can not be utilized
To over come this limitation we use the concept the circular queue.
Now after the (n-1)th position, 0th position occurs.if we want to insert an element, it can be inserted at 0th position
We have to take care of 2 thing----
if value of rear is max-1,then the insted the incrementing rear we will make it and then perform insertion
similarly when the value of front becomes max-1,it will not be increased but will be reset zero(0)
1.the circular queue will be empty in three situation.
   --when initillay front is equal =-1
   --when front becomes rear=rear+1
   --when front is =0 & rear is=max-1.
the overflow condition in circular queue has
overflow occcur only when all the array position are ocupied that when the array is full.
 --when front is=0.
 --rear is=max-1.
   or front is =rear+1.
*/
#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int rear=-1;
int front=-1;
void insert(int item);
int del();
int isfull();
int isempty();
void count();
void display();
void peak();
int main()
{
      int item,choice;
      while(1)
      {
            printf("1.For insert data in Queue..\n");
            printf("2.For deleting data in queue..\n");
            printf("3.For exit..\n");
            printf("4.For display..\n");
            printf("5.count the total number in queue\n");
            printf("6.Find the peak element\n");
            printf("7.Enter your choice..\n");
            scanf("%d",&choice);
            switch(choice)
            {
                  case 1:
                         printf("Enter a data in the queue..\n");
                         scanf("%d",&item);
                         insert(item);
                         break;
                  case 2:
                        item=del();
                        printf("Deleted item=%d\n",item);
                        break;
                  case 3:
                        exit(1);
                  case 4:
                        display();
                        break;
                  case 5:
                         count();
                         break;
                  case 6:
                         peak();
                         break;
            }
      }
      return 0;

}
void insert(int item)
{
      int a;
      if(isfull())
      {
            printf("\nQueue is overflow..\n\n");
           return;
      }
      if(front==-1)
      {
      front=0;
      }
      for(a=0;a<=rear;a++)
      {
            if(queue[a]==item)
          {
            printf("This element is exist..\nEnter another elment..\n\n");
            return;
           }
      }
      rear=rear+1;
      queue[rear]=item;
}
int isfull()
{
      if(rear==max-1)
      {
            return 1;
      }
      else{
            return 0;
      }
}
int del()
{
      int item;
      if(isempty())
      {
            printf("Queue is underflow..\n");
           return 0;
      }
      item=queue[front];
       front=front+1;
      return item;
}
void count()
{
      int a;
      if(isempty())
      {
            printf("List is empty\n");
           return;
      }
      int count=0;
       for(a=0;a<=rear;a++)
      {
           count++;
      }
      printf("Total number number is =[%d]\n",count);
}
int isempty()
{
      if(front==-1||rear==-1||front>rear)
      return 1;
      else
      return 0;
}
void display()
{
      int i;
      if(isempty())
      {
            printf("Queue is empty..\n");
            exit(1);
      }
      printf("first queue element is..\n");
      for(i=front;i<=rear;i++)
      {
           printf("%d\t",queue[i]);
      }
      printf("\n");
}
void peak()
{
      printf("the peak item is=[%d]\n",queue[rear]);
}
