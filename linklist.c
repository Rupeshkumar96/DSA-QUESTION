#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *createlist(struct node *start, int data);
struct node *addatbegin(struct node *start, int data);
void display(struct node *start);
struct node *addatend(struct node *start, int data);
struct node *addatafter(struct node *start, int data, int item);
struct node *addatbefore(struct node *start, int data, int item);
struct node *addatposition(struct node *start, int data, int pos);
void search(struct node *start, int item);
void count(struct node *start);
void numberofsearched(struct node *start, int item);
struct node *deletefirstnode(struct node *start);
struct node *deletefirstposition(struct node *start);
struct node *deleteatend(struct node *start);
struct node *deleteatchoice(struct node *start, int item);
void sortinglist(struct node *start);
void gratestsamllest(struct node *start);
struct node *addmanynode(struct node *start, int data);
// struct node *deleteallnode(struct node *start,int item);
struct node *movetoend(struct node *start);
struct node *movetofirst(struct node *start);
void sumofnode(struct node *start);
void reversenumber(struct node *start);
void swap(struct node *start);
struct node *sumoftwobignumber(struct node *start);
struct node *sorting(struct node *start, int data);
int main()
{
	int choice, data, item, pos, i, n;
	struct node *start = NULL;
	while (1)
	{
		printf("1.Create list...\n");
		printf("2.Add data at begining of the list...\n");
		printf("3.Display list...\n");
		printf("4.Add data at the end of the list...\n");
		printf("5.Add number after any number in list\n");
		printf("6.Add number before no. ina a list\n");
		printf("7.Add a number at given position\n");
		printf("8.Searched number in a list\n");
		printf("9. count the node in list\n");
		printf("10.searched nubmer how many times\n");
		printf("11.Delete first node at list\n");
		printf("12.Delete node at first position\n");
		printf("13.Delete the end nodes\n");
		printf("14.Delete the any node \n");
		printf("15. Delete all node\n");
		printf("16.swap two node...\n");
		printf("17.sorting the linked list...\n");
		printf("18.Find greatest and smallest in list.\n");
		printf("19.To create many node at a time...\n");
		printf("20.Find greatest number and move in end...\n");
		printf("21.Find smallest number and move in first...\n");
		printf("22.Sum of all node...\n");
		printf("23.reverse all element...\n");
		printf("24.Adding two greatest number...\n");
		printf("25.For enter element in sorting...\n");
		printf("26.For exit...\n");
		printf("Enter your choice..\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter data to inserted in list..\n");
			scanf("%d", &data);
			start = createlist(start, data);
			break;
		case 2:
			printf("Enter data to inserted in list..\n");
			scanf("%d", &data);
			start = addatbegin(start, data);
			break;
		case 3:
			display(start);
			break;
		case 4:
			printf("Enter data to inserted in list..\n");
			scanf("%d", &data);
			start = addatend(start, data);
			break;
		case 5:
			printf("select  a number after u enter that\n");
			scanf("%d", &item);
			printf("enter a number u enter that\n");
			scanf("%d", &data);
			start = addatafter(start, data, item);
			break;
		case 6:
			printf("select that number enter u before that\n");
			scanf("%d", &item);
			printf("enter a number u enter that\n");
			scanf("%d", &data);
			start = addatbefore(start, data, item);
			break;
		case 7:
			printf("enter a given position\n ");
			scanf("%d", &pos);
			printf("enter a number u enter that\n");
			scanf("%d", &data);
			start = addatposition(start, data, pos);
			break;
		case 8:
			printf("enter a number u searched that\n");
			scanf("%d", &item);
			search(start, item);
			break;
		case 9:
			count(start);
			break;
		case 10:
			printf("enter a number u searched that\n");
			scanf("%d", &item);
			numberofsearched(start, item);
			break;
		case 11:
			start = deletefirstnode(start);
			break;
		case 12:
			start = deletefirstposition(start);
			break;
		case 13:
			start = deleteatend(start);
			break;
		case 14:
			printf("enter a number u delete that=\n");
			scanf("%d", &item);
			start = deleteatchoice(start, item);
			break;
		case 15:
			printf("enter a number=\n");
			scanf("%d", &item);
		case 16:
			swap(start);
			break;
		case 17:
			sortinglist(start);
			break;
		case 18:
			gratestsamllest(start);
			break;
		case 19:
			printf("Enter a number which u want to create a node at a time..\n");
			scanf("%d", &n);
			for (i = 1; i <= n; i++)
			{
				printf("enter a data to be inserted[%d]=", i);
				scanf("%d", &data);
				start = addmanynode(start, data);
			}
			break;
		case 20:
			movetoend(start);
			break;
		case 21:
			movetofirst(start);
			break;
		case 22:
			sumofnode(start);
			break;
		case 23:
			reversenumber(start);
			break;
		case 24:
			sumoftwobignumber(start);
			break;
		case 25:
			printf("Enter a number which u want to create a node at a time..\n");
			scanf("%d", &n);
			for (i = 1; i <= n; i++)
			{
				printf("enter a data to be inserted[%d]=", i);
				scanf("%d", &data);
				start = sorting(start, data);
			}
			break;
		case 26:
			exit(1);
		}
	}
	return 0;
}
struct node *addmanynode(struct node *start, int data)
{
	struct node *tmp, *p;
	tmp = (struct node *)malloc(sizeof(struct node));
	if (start == NULL)
	{
		tmp->info = data;
		tmp->link = NULL;
		start = tmp;
		return start;
	}
	p = start;
	while (p->link != NULL)
	{
		p = p->link;
	}
	tmp->info = data;
	p->link = tmp;
	tmp->link = NULL;
	return start;
}
struct node *createlist(struct node *start, int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = NULL;
	start = tmp;
	return start;
}
struct node *addatbegin(struct node *start, int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = start;
	start = tmp;
	return start;
}
void display(struct node *start)
{
	struct node *p;
	if (start == NULL)
	{
		printf("list is empty..\n");
		return;
	}
	p = start;
	while (p != NULL)
	{
		printf("%d\t", p->info);
		p = p->link;
	}
	printf("\n");
}
struct node *addatend(struct node *start, int data)
{
	struct node *tmp, *p;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	p = start;
	while (p->link != NULL)
	{
		p = p->link;
	}
	p->link = tmp;
	tmp->link = NULL;
	return start;
}
struct node *addatafter(struct node *start, int data, int item)
{
	struct node *temp, *p;
	p = start;
	while (p != NULL)
	{
		if (p->info == item)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
	printf("%d this no. not found in list");
	return start;
}
struct node *addatbefore(struct node *start, int data, int item)
{
	struct node *temp, *p;
	if (start == NULL)
	{
		printf("list is empty\n\n");
		return start;
	}
	if (start->info == item)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = start;
		start = temp;
		return start;
	}
	p = start;
	while (p->link != NULL)
	{
		if (p->link->info == item)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
	printf("%d the data is not present");
	return start;
}
struct node *addatposition(struct node *start, int data, int pos)
{
	struct node *tmp, *p;
	int i;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	if (pos == 1)
	{
		tmp->link = start;
		start = tmp;
		return start;
	}
	p = start;
	for (i = 1; i < pos - 1 && p != NULL; i++)
	{
		p = p->link;
	}
	if (p == NULL)
	{
		printf("This position is not avaliable %d \n", pos);
		return start;
	}
	else
	{
		tmp->link = p->link;
		p->link = tmp;
	}
	return start;
}
void search(struct node *start, int item)
{
	struct node *p;
	int pos = 1;
	p = start;
	while (p != NULL)
	{
		if (p->info == item)
		{
			printf("item %d found at position %d\n", item, pos);
			return;
		}
		p = p->link;
		pos++;
	}
	printf("item %d not found in the list\n", item);
}
void count(struct node *start)
{
	struct node *p;
	int count = 0;
	p = start;
	while (p != NULL)
	{
		p = p->link;
		count++;
	}
	printf(" the number of node =%d\n", count);
	return;
}
void numberofsearched(struct node *start, int item)
{
	struct node *p;
	int pos = 1;
	p = start;
	while (p != NULL)
	{
		if (p->info == item)
		{
			printf("item=[%d]\nfound at position =%d\n\n", item, pos);
			if (p->link == NULL)
			{
				return;
			}
		}
		p = p->link;
		pos++;
		printf("item %d not found in the list\n\n", item);
		return;
	}
}
struct node *deletefirstnode(struct node *start)
{
	struct node *temp;
	temp = start;
	printf("the delete item is=%d\n", start->info);
	start = start->link;
	free(temp);
	return start;
}
struct node *deletefirstposition(struct node *start)
{
	struct node *temp;
	temp = start;
	printf("the delete item is=%d\n", start->info);
	start = start->link;
	free(temp);
	return start;
}
struct node *deleteatend(struct node *start)
{
	struct node *p, *temp;
	p = start;
	while (p->link != NULL)
	{
		temp = p;
		p = p->link;
	}
	// free(temp->link);
	// temp->link=NULL;
	temp->link = NULL;
	printf("the delete item is=%d\n", p->info);
	free(p);
	return start;
}
struct node *deleteatchoice(struct node *start, int item)
{
	struct node *p, *temp;
	if (start == NULL)
	{
		printf("list is empty\n");
		return start;
	}
	if (start->info == item)
	{
		temp = start;
		start = start->link;
		free(temp);
		return start;
	}
	p = start;
	while (p->link != NULL)
	{
		if (p->link->info == item)
		{
			temp = p->link;
			p->link = temp->link;
			free(temp);
			return start;
		}
		p = p->link;
	}
	printf("item %d not found in the list\n", item);
	return start;
}
// struct node *deleteallnode(struct node *start,int item)
// {
// 	struct node *p;
// 	p=start;
// 	while(p->info==item)
// 	{
// 	}
// 	p=p->link;
// }
/*void swap(struct node *start)
{
	struct node *p;
	int tmp;
	p=start;
	while(p->link!=NULL)
	{
		  p=p->link;
	}
	    tmp=p->info;
	    p->info=start->info;
	    start->info=tmp;
	    //return start;
}*/
void sortinglist(struct node *start)
{
	struct node *p, *q;
	int tmp;
	p = start;
	for (p = start; p->link != NULL; p = p->link)
	{
		for (q = p->link; q != NULL; q = q->link)
		{
			if (p->info > q->info)
			{
				tmp = p->info;
				p->info = q->info;
				q->info = tmp;
			}
		}
	}
}
void gratestsamllest(struct node *start)
{
	struct node *tmp, *p;
	int gratest, smallest;
	p = start;
	gratest = p->info;
	smallest = p->info;
	for (p = start; p->link != NULL; p = p->link)
	{
		if (p->info < smallest)
		{
			smallest = p->info;
		}
		if (p->info > gratest)
		{
			gratest = p->info;
		}
	}
	printf("the smallest no=%d\nthe greatest no.=%d\n", smallest, gratest);
}
struct node *movetoend(struct node *start)
{
	struct node *p, *q, *u;
	int tmp, great;
	p = start;
	great = p->info;
	while (p->link != NULL)
	{
		if (p->info >= great)
		{
			great = p->info;
			q = p;
		}
		p = p->link;
		u = p;
	}
	if (q == u)
	{
		return start;
	}
	tmp = p->info;
	p->info = q->info;
	q->info = tmp;
	return start;
}
struct node *movetofirst(struct node *start)
{
	struct node *p, *q;
	int tmp, small;
	p = start;
	small = p->info;
	while (p->link != NULL)
	{
		if (p->info <= small)
		{
			small = p->info;
			q = p;
		}
		p = p->link;
	}
	if (q == start)
	{
		return start;
	}
	tmp = p->info;
	p->info = q->info;
	q->info = tmp;
	return start;
}
void sumofnode(struct node *start)
{
	int sum = 0;
	struct node *p;
	p = start;
	while (p != NULL)
	{
		sum = sum + p->info;
		p = p->link;
	}
	printf("The sum of all node is :=%d\n", sum);
}
void reversenumber(struct node *start)
{
	struct node *p, *q;
	int n, r;
	p = start;
	while (p != NULL)
	{
		while (p->info)
		{
			r = p->info;
			p->info = p->info;
			p->info = p->info;
		}
		p = p->link;
	}
}
struct node *sumoftwobignumber(struct node *start)
{
	struct node *p;
	int tmp, item, great;
	p = start;
	great = p->info;
	while (p != NULL)
	{
		if (p->info < great)
		{
			great = p->info;
		}
		p = p->link;
	}
	printf("The greatest number is [%d]", great);
}
struct node *sorting(struct node *start, int data)
{
	struct node *p, *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	if (start == NULL || start->info > data)
	{
		tmp->link = start;
		start = tmp;
		return start;
	}
	else
	{
		p = start;
		while (p->link != NULL && p->link->info < data)
		{
			p = p->link;
		}
		tmp->link = p->link;
		p->link = tmp;
	}
	return start;
	/*while(p!=NULL)
	{
	   if(p->link->info<=tmp->info)
	   {
		   p=p->link;
	   }
	   else
	{
	   tmp->link=p->link;
	   p->link=tmp;
	   return start;
	}*/
}
void swap(struct node *start)
{
	struct node *p,*q;
	int tmp;
	// int tmp;
	p = start;
	q = start;
	while (p->link != NULL)
	{
		p = p->link;
	}
	tmp = p->info;
	p->info = q->info;
	q->info = tmp;
}