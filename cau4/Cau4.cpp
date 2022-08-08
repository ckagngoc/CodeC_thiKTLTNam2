#include <stdio.h>
#include <conio.h>
#include <malloc.h>
typedef int Data;
struct Node{
    Data data;
    Node *next,*previous;
};
typedef Node* point;

void insertAtFirst(point*,point*, Data);
void insertAtLast(point*,point*, Data);
void insertAtPos(point*,point*,Data,int);
void deleteAtFirst(point*, point*);
void deleteAtLast(point*,point*);
void deleteAtPos(point*,point*,int );
void printList(point,point);

int main()
{
    point F=NULL, L=NULL;
    FILE *f1;
    f1=fopen("input.txt","r");
    if(f1==NULL)
	{
    	printf("Khong mo duoc tep!");
    	return 0;
    }
    int n,x,i;
    fscanf(f1,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(f1,"%d",&x);
        insertAtLast(&F,&L,x);
    }
   insertAtFirst(&F,&L,10);
//   insertAtFirst(&F,&L,20);
//   insertAtLast(&F,&L,30);
//   insertAtPos(&F,&L,50,2);
//   deleteAtFirst(&F,&L);
//   deleteAtLast(&F,&L);
//   deleteAtPos(&F,&L,2);
   deleteAtPos(&F,&L,1);
    printList(F,L);
    fclose(f1);
    getch();
    return 0;
}

void insertAtFirst(point *first,point *last, Data x)
{
    if((*first==NULL)&&(*last==NULL))
    {
        point temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->next=NULL;
        temp->previous=NULL;
        *first=temp;
        *last=temp;
    }
    else
    {
        point temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->previous=NULL;
        temp->next=*first;
        (*first)->previous=temp;
        *first=temp;
    }
}

void insertAtLast(point *first, point *last, Data x)
{
    if((*first==NULL)&&(*last==NULL))
        insertAtFirst(first,last,x);
    else
    {
        point temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->previous=*last;
        temp->next=NULL;
        (*last)->next=temp;
        *last=temp;
    }
}

void insertAtPos(point *first,point *last,Data x,int p)
{
    if((*first==NULL)&&(*last==NULL))
    {
        insertAtFirst(first,last,x);
        return;
    }
    int k=1;
    point temp,temp1;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    temp1=*first;
    while((temp1->next!=NULL)&&(k<p-1))
    {
        temp1=temp1->next;
        k++;
    }
    (temp1->next)->previous=temp;
    temp->next=temp1->next;
    temp->previous=temp1;
    temp1->next=temp;
}

void deleteAtFirst(point *first, point *last)
{
    if((*first==NULL)&&(*last==NULL)) return;
    Node *temp;
    temp=*first;
    (*first)=(*first)->next;
    (*first)->previous=NULL;
    free(temp);
}

void deleteAtLast(point *first,point *last)
{
    if((*first==NULL)&&(*last==NULL)) return;
    Node *temp;
    temp=*last;
    *last=(*last)->previous;
    (*last)->next=NULL;
    free(temp);
}

void deleteAtPos(point *first,point *last,int p)
{
    if((*first==NULL)&&(*last==NULL)) return;
    if(p==1)
    {
        deleteAtFirst(first,last);
        return;
    } 
    int k=1;
    Node *temp,*temp1;
    temp=temp1=*first;
    while((temp1->next!=NULL)&&(k<=p-1))
    {
        temp=temp1;
        temp1=temp1->next;
        k++;
    }
    (temp1->next)->previous=temp;
    temp->next=temp1->next;
    free(temp1);
}

void printList(point first,point last)
{
    FILE *f2;
    f2=fopen("output.txt","w");
    if(f2==NULL)
	{
    	printf("Khong mo duoc tep!");
    	return;
    }
    point temp;
    temp = first;
    while(temp!=NULL)
    {
        fprintf(f2,"%d\t",temp->data);
        temp=temp->next;
    }
    fclose(f2);
}
