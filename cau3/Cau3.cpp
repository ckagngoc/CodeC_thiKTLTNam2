#include <stdio.h>
#define MAXSIZE 10000

struct List{
	int len;
	int array[MAXSIZE];
};

int newList(List*list);
bool isEmpty(List list);
bool isFullList(List list);
void makeEmpty(List*list);
void insertAtFirst(List*,int);
void insertAtLast(List*,int);
void insertAtPos(List*,int,int);
void sort(List*);
int search(List,int);
void deleteAtFirst(List*);
void deleteAtLast(List*);
void deleteAtPos(List*,int);

int main(){
	FILE *f1 = fopen("input.txt","r");
	FILE *f2 = fopen("output.txt","w");
	int i;
	List list;
	fscanf(f1,"%d",&list.len);
	for(i = 0;i<list.len;i++){
		fscanf(f1,"%d",&list.array[i]);
	}
	fclose(f1);

	/* insertAtFirst(&list,8);
	insertAtLast(&list,2004);*/
	//printf("%d",list.len);
	sort(&list);
	/* deleteAtLast(&list); */
	insertAtPos(&list,9000,2);
	deleteAtPos(&list,2);

	for(i = 0;i<list.len;i++){
		fprintf(f2,"%d ",list.array[i]);
	}
	fclose(f2);
	return 0;
}

int newList(List*list){
	list->len = -1;
}

bool isEmpty(List list){
	if(list.len == -1) return true;
	else return false;
}

bool isFullList(List list){
	if(list.len >= MAXSIZE-1) return true;
	else return false; 
}

void makeEmpty(List*list){
	list->len = -1;
}

void insertAtFirst(List*list,int v){
	if(isFullList(*list) == false){
		int n = list->len;
		for(int i = n+1;i>0;i--){
			list->array[i] = list->array[i-1];
		}
		list->len++;
		list->array[0] = v;
	}
}

void insertAtLast(List*list,int v){
	if(!isFullList(*list)){
		list->array[list->len] = v;
		list->len++;
	}
}

void insertAtPos(List*list,int v,int p){
	if(p>=0 && p < list->len && !isFullList(*list)){
		for(int i = list->len+1;i>p;i--){
			list->array[i] = list->array[i-1];
		}
		list->len++;
		list->array[p] = v;
	} else {
		printf("Khong them duoc !!!\n");
	}
}

int search(List list,int v){
	for(int i = 0;i<list.len;i++){
		if(list.array[i] == v) return i;
	}
	return -1;
}

void sort(List*list){
	int t;
	for(int i = 0;i<list->len-1;i++){
		for(int j = i+1;j<list->len;j++){
			if(list->array[i] > list->array[j]){
				t = list->array[i];
				list->array[i] = list->array[j];
				list->array[j] = t;
			}
		}
	}
}

void deleteAtLast(List*list){
	if(!isEmpty(*list)) list->len--;
}

void deleteAtFirst(List*list){
	if(!isEmpty(*list)){
		for(int i = 0;i<list->len-1;i++){
			list->array[i] = list->array[i+1];
		}
		list->len--;
	}
}

void deleteAtPos(List*list,int p){
	if(!isEmpty(*list)){
		for(int i = p;i<list->len-1;i++){
			list->array[i] = list->array[i+1];
		}
		list->len--;
	}
}
