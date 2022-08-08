#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100000
typedef int Data;
struct Node{
  Data data;
  Node *next;
  Node *previous;
};
typedef Node* point;

void BuildTest();
void PrintList(point,point);
void insertAtFirst(point*,point*,int);
void insertAtLast(point*,point*,int);
void insertToSortedList(point*,point*,int);
void ReadConsole(int*);
void ReadFile(int*);
void Run();

int main()
{
	BuildTest();
	Run();
	return 0;	
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

void PrintList(point first,point last)
{
	point temp=first;
	while(temp!=NULL)
	{
		printf("<- %d -> ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void insertAtFirst(point *first,point *last,int info){
    if(*first == NULL && *last == NULL){
        point temp=(Node*)malloc(sizeof(Node));
        temp->data=info;
        temp->next=NULL;
        temp->previous=NULL;
        *first=temp;
        *last=temp; 
    }
    else
    {
        Node *temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->data=info;
        temp->next=*first;
        *first=temp;
    }
}

void insertAtLast(point *first,point* last,int info)
{ 
	if(*first==NULL && *last==NULL)
	{
		insertAtFirst(first,last,info);
		return;
	}
	else
	{
		point temp=(Node*)malloc(sizeof(Node));
        temp->next=NULL;
        temp->data=info;
        temp->previous=*last;
        (*last)->next = temp;
        *last=temp; 
	}
}

void insertToSortedList(point *first,point *last,int info)
{
    if (*first==NULL && *last==NULL)
    {
        insertAtFirst(first,last,info);
	    return;
    }
    point x;
    x=(Node*)malloc(sizeof(Node));
    x->data=info;
    if (info<=(*first)->data)
    {
        insertAtFirst(first,last,info);
        return;
    }
    point temp1,temp;
    temp=*first;
    temp1=*first;
    while((temp!=NULL)&&(temp->data<=info))
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=x;
	x->next=temp;
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
    	printf("Nhap gia tri can them: "); scanf("%d",&val);
		insertToSortedList(&first,&last,val);
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
		PrintList(first,last);
		int val;
		printf("Nhap gia tri can them: "); scanf("%d",&val);
		insertToSortedList(&first,&last,val);
		PrintList(first,last);
		fprintf(f2,"%d\n",n+1);
		point temp=first;
		while(temp!=NULL)
		{
			fprintf(f2,"<- %d ->",temp->data);
			temp=temp->next;
		}
		fclose(f1); fclose(f2);
		printf("\n________________");
		printf("\n1 - Thuc hien lai.");
		printf("\n0 - Tro ve.\n");
		scanf("%d",&(*opt));
	}
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


