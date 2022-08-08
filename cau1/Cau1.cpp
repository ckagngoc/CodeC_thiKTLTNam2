#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXSIZE 100000
#define SELECTION_SORT 1
#define BUBBLE_SORT 2
#define INSERTION_SORT 3
typedef int type;

void readFile(FILE*,type*,type*);
void sxChon(type*,type);
void sxNoiBot(type*,type);
void sxChen(type*,type);
void thoiGianSX(type* ,type,FILE*,int);

int main(){
    FILE *f1,*f2;
    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");

    type n,i;
    fscanf(f1,"%ld",&n);
    type *a,*b,*c;
    a = (type*)calloc(n,sizeof(type));
    b = (type*)calloc(n,sizeof(type));
    c = (type*)calloc(n,sizeof(type));
    for(i = 0;i<n;i++){
        fscanf(f1,"%ld",a+i);
    }
    fclose(f1);
    memcpy(c,a,n*sizeof(type));
    memcpy(b,a,n*sizeof(type));
    thoiGianSX(a,n,f2,SELECTION_SORT);
    thoiGianSX(b,n,f2,BUBBLE_SORT);
    thoiGianSX(c,n,f2,INSERTION_SORT);

    for(i = 0;i<n;i++){
        fprintf(f2,"%ld ",*(a+i));
    }
    fclose(f2);
    return 0;
}

void swap(type*a,type*b){
    type t;
    t = *a;
    *a = *b;
    *b = t;
}

void sxChon(type a[],type n){
    for(type i  = 0;i<n-1;i++){
        for(type j = i+1;j<n;j++){
            if(a[i]>a[j]) swap(&a[i],&a[j]);
        }
    }
}

void sxNoiBot(type a[],type n){
    bool haveSwap = false;
    for(type i = 0;i<n - 1;i++){
        for(type j = 0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                haveSwap = true;
            }
        }
        if(haveSwap == false) break;
    }
}

void sxChen(type a[],type n){
    type t,j;
    for(type i  = 1;i<n;i++){
        t = a[i];
        j = i-1;
        while(j>=0 && a[j]>t){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
}

void thoiGianSX(type a[],type n,FILE*f2,int key){
    if(key == SELECTION_SORT){
        clock_t startChon = clock();
        sxChon(a,n);
        clock_t finishChon = clock();
        double thoiGianSXC = (double) (finishChon - startChon)/CLOCKS_PER_SEC;
        fprintf(f2,"Thoi gian cua sx Chon la: %lf giay\n",thoiGianSXC);
    } else if(key == BUBBLE_SORT){
        clock_t startNoiBot = clock();
        sxNoiBot(a,n);
        clock_t finishNoiBot = clock();
        double thoiGianSXNB = (double) (finishNoiBot - startNoiBot)/CLOCKS_PER_SEC;
        fprintf(f2,"Thoi gian cua sx Noi bot la: %lf giay\n",thoiGianSXNB);
    } else {
        clock_t startChen = clock();
        sxChen(a,n);
        clock_t finishChen = clock();
        double thoiGianSXChen = (double) (finishChen - startChen)/CLOCKS_PER_SEC;
        fprintf(f2,"Thoi gian cua sx Chen la: %lf giay\n",thoiGianSXChen);
    }
}