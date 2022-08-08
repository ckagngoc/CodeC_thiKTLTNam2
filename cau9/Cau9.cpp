#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef int Data;
struct Node{
    Data data;
    Node* next;
};
typedef Node* point;

void push(point*,Data);
void pop(point*,Data*);
void peek(point,Data*);
void ReadConsole(int*);
void ReadFile(int*);
void PrintList(point);
void Run();

int main(){
    Run();
    return 0;
}

void push(point* first,Data v){
    point t;
    t = new(Node);
    t->data = v;
    t->next = *first;
    *first = t;
}

void pop(point* first,Data* v){
    if(*first!=NULL){
        *v = (*first)->data;
        *first = (*first)->next;
    } else return;
}

void peek(point first,Data* v){
    if(first!=NULL){
        *v = first->data;
    } else return;
}

void ReadConsole(int* opt)
{
	while((*opt)!=0)
	{
		system("cls");
		point first=NULL;
		int n,i,x;
	    printf("Nhap so phan tu cua stack: "); scanf("%d",&n);
		for(i=0;i<n;i++)
	    {
	    	printf("\nNhap phan tu thu %d: ",n-i);
	        scanf("%d",&x);
            push(&first,x);
	    }
    	printf("Stack ban da nhap la: \n");
		PrintList(first);
        //--------------------Test here--------------
        push(&first,900);
        int value;


        /* pop(&first,&value);
        printf("Gia tri pop ra la: %d\n",value); */

        
        peek(first,&value);
        printf("Gia tri peek ra la: %d\n",value);
        //-------------------------------------------
        printf("Stack sau test la: \n");
		PrintList(first);
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
		int n,i;
    	FILE *f1,*f2;
	    f1= fopen("input.txt","r"); 
        f2= fopen("output.txt","w");
    	fscanf(f1,"%d",&n);
    	int x;
    	for(i=0;i<n;i++)
    	{
        	fscanf(f1,"%d",&x);
            push(&first,x);
    	}
		printf("Stack ban da nhap tu File la: \n");
		PrintList(first);
        //--------------------Test here--------------
        push(&first,900);
        int value;


        /* pop(&first,&value);
        fprintf(f2,"Gia tri pop ra la: %d\n",value); */


        peek(first,&value);
        fprintf(f2,"Gia tri peek ra la: %d\n",value);
        //-------------------------------------------
		point temp=first;
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

void PrintList(point first)
{
	point temp=first;
	while(temp!=NULL)
	{
		printf("%d-> ",temp->data);
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
