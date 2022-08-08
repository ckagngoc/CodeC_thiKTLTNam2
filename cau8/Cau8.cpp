#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAXSIZE 100000
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
void trimDuplicateElement(point*,point*);
void BuildTest();
void readConsole(int*);
void readFile(int*);
void PrintList(point,point);
void Run();

int main()
{
    BuildTest();
    Run();
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

void trimDuplicateElement(point*first,point*last)
{
    Node *temp,*temp1;
    temp1=*first;
    while(temp1->next->next!=NULL)
    {
        if(temp1->data==temp1->next->data)
        {
            temp=temp1->next;
            (temp->next)->previous=temp1;
            temp1->next=temp->next;
            free(temp);
        }
        else temp1=temp1->next;
    }
    if(temp1->data==temp1->next->data) deleteAtLast(first,last);
}

void BuildTest()
{
	FILE *f1;
    f1= fopen("input.txt","w");
    if(f1==NULL)
	{
    	printf("Khong mo duoc tep!");
    	return;
    }
    int n,N,i,j,tg;
	printf("Nhap vao so luong phan tu cua list: "); scanf("%d",&n);
	printf("Nhap vao khoang sinh ngau nhien: ");scanf("%d",&N);
	int x[MAXSIZE];
	for(i=0;i<n;i++)
	{
	    x[i]= rand() % N;
	}
	fprintf(f1,"%d\n",n);
	
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(x[i]>x[j])
	{
		tg=x[i]; x[i]=x[j]; x[j]=tg;
	}
	
	for(i=0;i<n;i++) 
		{
			fprintf(f1,"%d\t",x[i]);
		}
	fclose(f1);
	printf("Tao tep input thanh cong");
}

void ReadConsole(int* opt)
{
	while((*opt)!=0)
	{
		system("cls");
		point first=NULL;
        point last=NULL;
		int n,i,j,tg,val;
	    printf("Nhap so phan tu cua danh sach: "); scanf("%d",&n);
		int x[MAXSIZE];
		for(i=0;i<n;i++)
	    {
	    	printf("\nNhap phan tu thu %d: ",i+1);
	        scanf("%d",&x[i]);
	    }
	    for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		if(x[i]>x[j])
		{
			tg=x[i]; x[i]=x[j]; x[j]=tg;
	    }
    	for(i=0;i<n;i++)
    	{        
        	insertAtLast(&first,&last,x[i]);
    	}
    	PrintList(first,last);
    	trimDuplicateElement(&first,&last);
		PrintList(first,last);
		printf("\n________________");
		printf("\n1 - Thuc hien lai.");
		printf("\n0 - Tro ve.\n");
		scanf("%d",&(*opt));
	}
}

void ReadFile(int* opt)
{
	while((*opt)!=0)
	{
		system("cls");
		point first=NULL;
        point last=NULL;
		int n,i;
    	FILE *f1,*f2;
	    f1= fopen("input.txt","r"); f2= fopen("output.txt","w");
    	fscanf(f1,"%d",&n);
    	int x;
    	for(i=0;i<n;i++)
    	{
        	fscanf(f1,"%d",&x);
            insertAtLast(&first,&last,x);
    	}
		trimDuplicateElement(&first,&last);
		fprintf(f2,"%d\n",n);
		point temp=first;
		while(temp!=NULL)
		{
			fprintf(f2,"<-%d->",temp->data);
			temp=temp->next;
		}
		fclose(f1); fclose(f2);
		printf("\n________________");
		printf("\n1 - Thuc hien lai.");
		printf("\n0 - Tro ve.\n");
		scanf("%d",&(*opt));
	}
}

void PrintList(point first,point last)
{
	point temp=first;
	while(temp!=NULL)
	{
		printf("<-%d-> ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void Run()
{
	int opt;
	do
	{
		system("cls");
		printf("1 - Nhap tu ban phim.\n");
		printf("2 - Nhap tu tep.\n");
		printf("3 - Thoat\n");
		scanf("%d",&opt);
		switch (opt)
		{
		case 1: 
			ReadConsole(&opt);	
			break;
		case 2:	
			ReadFile(&opt);			
			break;
		case 3:
			return;
		default:
			system("cls");			
		}    
	} 
	while ( opt > 0 || opt < 4);
}
