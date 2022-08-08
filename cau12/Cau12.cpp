#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

typedef char type;
struct Node{
	type data;
	Node* next;
};
typedef Node* Stack;

int isEmpty(Stack);
void push(Stack*,type);
type pop(Stack*);
type peek(Stack*);
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
	if(!isEmpty(*first)){
		type x;
		x = (*first)->data;
		*first = (*first)->next;
		return x;
	}
}

type peek(Stack*first){
	if(!isEmpty(*first)){
		type x;
		x = (*first)->data;
		return x;
	}
}

void readConsole(int*key){
	while(*key!=0){
		system("cls");
		char x[255];
		Stack first = NULL;
		printf("Moi nhap x: ");
        fflush(stdin);
		gets(x);
		for(int i=0;i<strlen(x);i++) push(&first,x[i]);
		printf("\nConvert: ");
		while(!isEmpty(first)){
			printf("%c",pop(&first));
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
		char x[255];
		Stack first = NULL;
		while(feof(f1) == 0){
			fgets(x,255,f1);
			fputs(x,f2);
			for(int i=0;i<strlen(x);i++) push(&first,x[i]);
            fprintf(f2,"convert: ");
			while(!isEmpty(first)){
				fprintf(f2,"%c",pop(&first));
			}
			fprintf(f2,"\n\n---------------------------------\n");
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
		printf("CONVERT DECIMAL TO BINARY");
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