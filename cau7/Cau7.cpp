#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100000
typedef int Data;
struct Node{
  Data data;
  Node *next;
};
typedef Node* point;

void BuildTest();
void PrintList(point);
void insertAtFirst(point*,int);
void insertAtLast(point*,int);
void trimDuplicateElement(point*);
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

void PrintList(point first)
{
	point temp=first;
	while(temp!=NULL)
	{
		printf("%4d -> ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void insertAtFirst(point *first,int info){
  point temp;
  temp=(Node*)malloc(sizeof(Node));
  temp->data=info;
  temp->next=(*first);
  (*first)=temp;
}

void insertAtLast(point *first, int info)
{ 
	if(*first==NULL)
	{
		insertAtFirst(first, info);
		return;
	}
	else
	{
		point temp, temp1;
		temp1 = *first;
		while ( temp1->next != NULL)
		    temp1 = temp1->next;
		temp = (Node*)malloc(sizeof(Node));
		temp->data = info;
		temp1->next = temp;
		temp->next = NULL;
	}
}

void trimDuplicateElement(point* first)
{	
	point temp1,temp2;
	temp1=*first;
	temp2=*first;
	while(temp2->next!=NULL)
	{
		temp1=temp2;
		while(temp1->data==temp2->next->data&&temp2->next->next!=NULL)
			{	
				point temp=temp2->next;
				temp2->next=temp2->next->next;
				free(temp);
			}		
		temp2=temp2->next;	
		if(temp2->next==NULL&&temp1->data==temp2->data)	
		{
			temp1->next=NULL;
			free(temp2);
		}
	}	
}

void ReadConsole(int* opt)
{
	while((*opt)!=0)
	{
		system("cls");
		point L=NULL;
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
        	insertAtLast(&L,x[i]);
    	}
    	PrintList(L);
    	trimDuplicateElement(&L);
		PrintList(L);
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
		point L=NULL;
		int n,i;
    	FILE *f1,*f2;
	    f1= fopen("input.txt","r"); f2= fopen("output.txt","w");
    	fscanf(f1,"%d",&n);
    	int x;
    	for(i=0;i<n;i++)
    	{
        	fscanf(f1,"%d",&x);
            insertAtLast(&L,x);
    	}
		trimDuplicateElement(&L);
		fprintf(f2,"%d\n",n);
		point temp=L;
		while(temp!=NULL)
		{
			fprintf(f2,"%d->",temp->data);
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


