#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef int type;
struct Node{
    type data;
    Node* next;
};
typedef Node* point;

void insertAtFirst(point*, type);
point lastElement(point*);
void get(point*, type*);
void Put(point*, type);
void peck(point*, type*);
void ReadFile(int* opt);
void PrintList(point first);
void Run();

int main(){
  Run();
  return 0;
}

void insertAtFirst(point* first, type v){
    point t;
    t = new(Node);
    t->data = v;
    t->next = *first;
    *first = t;
}
point lastElement(point* first){
    point t1;
    t1 = *first;
    while(t1->next->next != NULL){
        t1 = t1->next;
    }
    return t1;
}
void get(point* first, type* v){
    if(*first == NULL){
        *v = 0;
    } else{
        point t1;
        t1 = lastElement(first);
        *v = t1->next->data;
        t1->next = t1->next->next;
    }
}
void put(point* first, type v){
    insertAtFirst(first,v);
}
void peck(point* first, type* v){
    if(*first == NULL){
        *v = 0;
    } else{
        point t1;
        t1 = lastElement(first);
        *v = t1->next->data;
    }
}

void ReadFile(int* opt){
	while((*opt)!=0){
		system("cls");
		point first=NULL;
		int n,i;
    	FILE *f1,*f2;
	    f1= fopen("input.txt","r"); 
        f2= fopen("output.txt","w");
    	fscanf(f1,"%d",&n);
    	int x;
    	for(i=0;i<n;i++){
        	fscanf(f1,"%d",&x);
            put(&first,x);
    	}
		printf("Queues ban da nhap tu File la: \n");
		PrintList(first);
        //--------------------Test here--------------
        /* put(&first,900); */
        int value;


        /* get(&first,&value);
        fprintf(f2,"Gia tri get ra la: %d\n",value); */


        peck(&first,&value);
        fprintf(f2,"Gia tri peck ra la: %d\n",value);
        //-------------------------------------------
		point temp=first;
		while(temp!=NULL){
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

void PrintList(point first){
	point temp=first;
	while(temp!=NULL)
	{
		printf("%d-> ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void Run(){
	int opt;
	do
	{
		system("cls");
		printf("1 - Nhap tu tep.\n");
		printf("2 - Thoat\n");
		scanf("%d",&opt);
		switch (opt)
		{
		case 1:	
			ReadFile(&opt);			
			break;
		case 2:
			return;
		default:
			system("cls");			
		}    
	} 
	while ( opt > 0 || opt < 3);
}
