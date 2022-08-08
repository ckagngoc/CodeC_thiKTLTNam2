#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef float type;
struct Node{
	type data;
	Node* next;
};

typedef Node* Stack;
typedef Node* point;

int isEmpty(Stack);
void push(Stack*,type);
type pop(Stack*,type*);
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

float caculatePostfix(char postfix[]){
    point stack = NULL;
    stack = new(Node);
    float num1,num2;
    int i = 0;
    while(i<strlen(postfix)){
        if(postfix[i] == ' '){
            i++;
        } else{
            if(postfix[i]>='0' && postfix[i]<='9'){
                float num = 0;
                while('0' <= postfix[i] and postfix[i] <= '9'){
                    num = num * 10 + postfix[i] - '0';
                    i++;
                }
                push(&stack,num);
            } else{
                num2 = pop(&stack);
                num1 = pop(&stack);
                float ketqua;
                switch (postfix[i])
                {
                case '-':
                    /* code */
                    ketqua = num1-num2;
                    break;
                case '+':
                    ketqua = num1+num2;
                    break;
                case '*':
                    ketqua = num1*num2;
                    break;
                case '/':
                    if(num2!=0){
                        ketqua = num1/num2;
                        break;
                    } else{
                        return INFINITY;
                    }
                }
                push(&stack,ketqua);
            }
            i++;
        }
    }
    return pop(&stack);
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
            fprintf(f2,"\nRESULT: ");
            if(caculatePostfix(x)!=INFINITY){
                fprintf(f2,"%f",caculatePostfix(x));
            } else{
                fprintf(f2,"Error math !!!");
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
	while(key != 2){
		system("cls");
		printf("CONVERT DAO NGUOC DANH SACH");
		printf("\n1 - Doc tu file");
		printf("\n2 - thoat");
		printf("\n------------------------------");
		printf("\nLua chon cua ban la: ");
		scanf("%d",&key);
		switch(key){
			case 1:
				readFile(&key);
				break;
			case 2:
				return;
		}
	}
}