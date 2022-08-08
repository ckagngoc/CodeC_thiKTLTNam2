#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Sach{
    char Ten_sach[100];
    char NXB[100];
    float gia;
};

typedef Sach* point;

void swap(point,point);
void sort(Sach*,int);
void printSach(Sach*,int,FILE*);
void run();

int main(){
    run();
    return 0;
}

void swap(point a,point b){
    Sach t;
    t = *a;
    *a = *b;
    *b = t;
}

void sort(Sach a[],int n){
    for(int i  = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(a[i].gia < a[j].gia) swap(&a[i],&a[j]);
        }
    }
}


void printSach(Sach books[],int n,FILE*f2){
    char info[255];
    char gia[100];
    for(int i = 0;i<n;i++){
        fprintf(f2,books[i].Ten_sach);
    }
}
void run(){
    FILE *f1 = fopen("input.txt","r");
    FILE*f2 = fopen("output.txt","w");
    char findNXB[100];
    int n = 0;
    int i = 0;
    int count = 0;
    printf("Nhap ten NXB can tim kiem: ");
    gets(findNXB);
    strcat(findNXB,"\n");
    fscanf(f1,"%d\n",&n);
    point books;
    books = (point)calloc(n,sizeof(Sach));
    for(i = 0;i<n;i++){
        point temp;
        temp = (point)malloc(sizeof(Sach));
        fgets(temp->Ten_sach,100,f1);
        fgets(temp->NXB,100,f1);
        fscanf(f1,"%f\n",&(temp->gia));
        *(books + i) = *temp;
    }
    fclose(f1);
    for(i = 0;i<n;i++){
        if(strcmp((books + i)->NXB,findNXB) == 0) count++;
    }
    fprintf(f2,"So sach cua NXB da nhap la: %d\n",count);
    sort(books,n);
    printSach(books,n,f2);
    fclose(f2);
}