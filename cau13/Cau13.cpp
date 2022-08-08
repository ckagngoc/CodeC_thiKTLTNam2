#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int type;
struct Node{
	type data;
	Node* next;
};

typedef Node* Stack;
typedef Node* point;

int isEmpty(Stack);
void push(Stack*,type);
void pop(Stack*,type*);
void insertAtFirst(point*,int);
void readConsole(int*);
void readFile(int*);
void run();

int main(){
	run();
	return 0;
}

int isEmpty(Stack first){
	if(first == NULL) return 1;
	else return 0;
}

void push(Stack*first,type value){
	Stack t;
	t = new(Node);
	t->data = value;
	t->next = *first;
	*first = t;
}

type pop(Stack*first){
	if(*first != NULL){
		type x;
		x = (*first)->data;
		*first = (*first)->next;
		return x;
	}
}

void insertAtFirst(point *first,int info){
  point temp;
  temp=(Node*)malloc(sizeof(Node));
  temp->data=info;
  temp->next=(*first);
  (*first)=temp;
}

void readConsole(int*key){
	while(*key!=0){
		system("cls");
		int *x,n;
		Stack first = NULL;
		printf("Moi nhap so phan tu: ");
		scanf("%d",&n);
        x = (int*)calloc(n,sizeof(int));
		for(int i=0;i<n;i++){
            scanf("%d",x + i);
            push(&first,*(x+i));
        }
		printf("\nConvert: ");
		for(int i=0;i<n;i++){
            printf("%d ",pop(&first));
        }
		printf("\n--------------------------------");
		printf("\n1 - Try again !!!");
		printf("\n0 - Exit");
		printf("\nLua chon cua ban la: ");
		scanf("%d",key);
	}
}

void readFile(int*key){
	while(*key!=0){
		FILE *f1 = fopen("input.txt","r");
		FILE *f2 = fopen("output.txt","w");
		int *x,n;
        fscanf(f1,"%d",&n);
        x = (int*)calloc(n,sizeof(int));
		Stack first = NULL;
		while(feof(f1) == 0){
		    for(int i=0;i<n;i++){
                fscanf(f1,"%d",x + i);
                push(&first,*(x+i));
            }
		    fprintf(f2,"\nConvert: ");
		    for(int i=0;i<n;i++){
                fprintf(f2,"%d ",pop(&first));
            }
            fprintf(f2,"\n--------------------------------");
		}
		fclose(f1);
		fclose(f2);
		system("cls");
		printf("\n--------------------------------");
		printf("\n1 - Try again !!!");
		printf("\n0 - Exit");
		printf("\nLua chon cua ban la: ");
		scanf("%d",key);
	}
}

void run(){
	int key;
	while(key != 3){
		system("cls");
		printf("CONVERT DAO NGUOC DANH SACH");
		printf("\n1 - Doc tu man hinh");
		printf("\n2 - Doc tu file");
		printf("\n3 - thoat");
		printf("\n------------------------------");
		printf("\nLua chon cua ban la: ");
		scanf("%d",&key);
		switch(key){
			case 1:
				readConsole(&key);
				break;
			case 2:
				readFile(&key);
				break;
			case 3:
				return;
		}
	}
}