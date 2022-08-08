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
void pop(Stack*,type*);
void peek(Stack*,type*);
int BalancingAct(char*);
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

type peek(Stack*first){
	if(!isEmpty(*first)){
		type x;
		x = (*first)->data;
		return x;
	}
}

int balancingAct(char Input[]){
    Stack first = NULL;
	int len=strlen(Input);
	int i=0;
	while(i<len)
	{
		if(Input[i]=='('||Input[i]=='['||Input[i]=='{')	push(&first,Input[i]);
		if(Input[i]==')'||Input[i]==']'||Input[i]=='}')	
		{
			if(isEmpty(first))	return 0;
			else
				{
					switch (peek(&first))
					{
					case '(': 
						if(Input[i]!=')')	return 0;
						else pop(&first);
						break;
					case '[':	
						if(Input[i]!=']')	return 0;
						else pop(&first);
						break;
					case '{':
						if(Input[i]!='}')	return 0;
						else pop(&first);
						break;
					}    
				}
		}
		i++;
	}
	if(isEmpty(first))	return 1;
	else return 0;
}

void readConsole(int*key){
	while(*key!=0){
		system("cls");
		char x[255];
		printf("Moi nhap bieu thuc: ");
        fflush(stdin);
		gets(x);
		if(balancingAct(x)) printf("\nBieu thuc DUNG !!!");
        else printf("\nBieu thuc SAI !!!");
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
            fprintf(f2,"CHECK: ");
			if(balancingAct(x)) fprintf(f2,"\nBieu thuc DUNG !!!");
            else fprintf(f2,"\nBieu thuc SAI !!!");
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