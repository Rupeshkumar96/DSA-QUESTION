#include<stdio.h>
#include<stdlib.h>
struct node{
      float coeff;
      int expo;
      struct node *link;
};
struct node *create(struct node *head);
struct node *insert(struct node *head,float coeff,int expo);
void print(struct node *head);
struct node *add(struct node *head,struct node*head1);
struct node *start;
int main()
{
      struct node *head=NULL,*head1=NULL,*head2=NULL;
      printf("Enter first polynomial\n");
      head=create(head);
      printf("Enter second polynomial\n");
      head1=create(head1);
      print(head);
      printf("\n");
      print(head1);
      head2=add(head,head1);
      printf("After adding the polynomial..\n");
      print(head2);
      return 0;
}
struct node *create(struct node *head)
{
      int i,n;
      float coeff;
      int expo;
      printf("Enter number of terms\n");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
            printf("enter the cofficient for term %d=",i+1);
            scanf("%f",&coeff);
            printf("Enter the exponent of number=");
            scanf("%d",&expo);
            head=insert(head,coeff,expo);
      }
      return head;
}
struct node*insert(struct node *head,float coeff ,int expo)
{
      struct node *tmp;
      struct node *newp=malloc(sizeof(struct node));
      newp->coeff=coeff;
      newp->expo=expo;
      newp->link=NULL;
      if(head==NULL||expo>head->expo)
      {
            newp->link=head;
            head=newp;
      }
      else{
            tmp=head;
            while(tmp->link!=NULL&&tmp->link->expo>=expo)
            {
                  tmp=tmp->link;
            }
            newp->link=tmp->link;
            tmp->link=newp;
      }
      return head;
}
void print(struct node *head)
{
      struct node *p;
      p=head;
      if(head==NULL)
      {
            printf("list is empty\n"); 
            return;
      }
      while(p!=NULL)
      {
            printf("(%.1fx^%d) ",p->coeff,p->expo);
            p=p->link;
            if(p!=NULL)
            printf(" + ");
      }
      printf("\n");
}
struct node *add(struct node *head,struct node*head1)
{
      struct node *p,*q,*tmp,*head2=NULL;
      p=head;
      q=head1;
      if(head==NULL&&head1==NULL)
      {
            printf("add is not possible\n");
      }
      tmp=(struct node*)malloc(sizeof(struct node));
      head2=tmp;
      if(p->expo==q->expo)
      {
           tmp->coeff=p->coeff+q->coeff;
           tmp->expo=p->expo;
           p=p->link;
           q=q->link;
      }
      else if(p->expo>q->expo)
      {
            tmp->coeff=p->coeff;
            tmp->expo=p->expo;
            p=p->link;
      }
      else
      {
            tmp->coeff=q->coeff;
            tmp->expo=q->expo;
            q=q->link;
      }
      return head2;
}