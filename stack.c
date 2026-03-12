#include <stdio.h>
#include <stdlib.h>
#define max 5
int stackarr[max];
int stackar[max];
int stackar1[max];
int top = -1;
int pot = -1;
void push(int item);
void push1(int item);
int pop();
int isfull();
int isfull1();
int isempty();
int isempty1();
void display();
void peak();
void odd();
void count();
int main()
{
      int item, choice;
      while (1)
      {
            printf("\n1.For insert data in stack..\n");
            printf("2.For deleting data in stack..\n");
            printf("3.For exit..\n");
            printf("4.For display..\n");
            printf("5.find peak element\n");
            printf("6.count the node\n");
            printf("7.find odd number in stack \n");
            printf("8.create sencond stack list..\n");
            printf("Enter your choice..\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                  printf("Enter a data in the stack..\n");
                  scanf("%d", &item);
                  push(item);
                  break;
            case 2:
                  item = pop();
                  printf("Deleted item=%d\n\n", item);
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
            case 7:
                  odd();
                  break;
            case 8:
                  printf("Enter a data in the stack..\n");
                  scanf("%d", &item);
                  push1(item);
                  break;
            }
      }
      return 0;
}
void push(int item)
{
      int a;
      if (isfull())
      {
            printf("stack is overflow...\n");
            return;
      }
      top = top + 1;
      for (a = top; a >= 0; a--)
      {
            if (stackarr[a] == item)
            {
                  printf("This element is exist..\nEnter another element..\n\n");
                  return;
            }
      }
      stackarr[top] = item;
}
void push1(int item)
{
      int a;
      if (isfull1())
      {
            printf("stack is overflow...\n");
            return;
      }
      pot = pot + 1;
      for (a = pot; a >= 0; a--)
      {
            if (stackar[a] == item)
            {
                  printf("This element is exist..\nEnter another element..\n\n");
                  return;
            }
      }
      stackar[pot] = item;
}
int isfull()
{
      if (top == max - 1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
int isfull1()
{
      if (pot == max - 1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
int pop()
{
      int item;
      if (isempty())
      {
            printf("stack is undefined...\n");
            exit(1);
      }
      item = stackarr[top];
      top = top - 1;
      return item;
}
int isempty()
{
      if (top == -1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
int isempty1()
{
      if (pot == -1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}
void display()
{
      int list, a;
      printf("enter which stack to display..\n");
      scanf("%d", &list);
      switch (list)
      {
      case 1:
            if (isempty())
            {
                  printf("stack is empty..\n");
                  return;
            }
            for (a = top; a >= 0; a--)
            {
                  printf("%d\t", stackarr[a]);
            }
            printf("\n");
            break;
      case 2:
            if (isempty1())
            {
                  printf("stack is empty..\n");
                  return;
            }
            for (a = pot; a >= 0; a--)
            {
                  printf("%d\t", stackar[a]);
            }
            printf("\n");
            break;
      }
}
void peak()
{
      int n;
      if (isempty())
      {
            printf("stack is empty");
      }
      printf("the peak element is=%d", stackarr[top]);
      printf("\n");
}
void count()
{
      int count = 0, a;
      if (isempty())
      {
            printf("stack is empty");
      }
      for (a = top; a >= 0; a--)
      {
            count++;
      }
      printf("the element in stack=%d", count);
      printf("\n");
}
void odd()
{
      int a, i = 0, n;
      printf("Enter that which list find odd number\n");
      scanf("%d", &n);
      switch (n)
      {
      case 1:
            for (a = top; a >= 0; a--)
            {
                  if (stackarr[a] % 2 != 0)
                  {
                        stackar1[++i] = stackarr[a];
                  }
            }
            printf("Odd number are..\n");
            while (i > 0)
            {
                  printf("%d\t", stackar1[i--]);
            }
            break;
      case 2:
            for (a = pot; a >= 0; a--)
            {
                  if (stackar[a] % 2 != 0)
                  {
                        stackar1[++i] = stackar[a];
                  }
            }
            printf("Odd number are..\n");
            while (i > 0)
            {
                  printf("%d\t", stackar1[i--]);
            }
            break;
      }
}
/*implement  a stack in a array such that the stack start from the last position of array that is insillay the top is at the last position of array,
and it move to words the begning of the array as the element are pushed*/
