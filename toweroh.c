#include<stdio.h>
void toh(int ndisk,char source,char temp,char dest)
{
      if(ndisk==1)
      {
            printf("Move disk %d from %c-->%c\n",ndisk,source,dest);
            return;
      }
      toh(ndisk-1,source,dest,temp);
      printf("Move disk %d from %c-->%c\n",ndisk,source,dest);
      toh(ndisk-1,temp,source,dest);
}
int main()
{
      int ndisk=3;
      char source='A';
      char temp='B';
      char dest='C';
      toh(ndisk,source,temp,dest);
}