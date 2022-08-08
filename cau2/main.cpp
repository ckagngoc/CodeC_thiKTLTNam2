#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 999999
typedef int type;

void quick_sort(type*,int,int);
void swap(type*,type*);
int searchBinary(type*,int,int,type);
void printFile(type*, type, FILE*);

int main(){


    return 0;
}

void swap(type*a,type*b){
    type t;
    t = *a;
    *a = *b;
    *b = t;
}

void quick_sort(type a[],int l,int r){
    int vitri = (l+r)/2;
    type x = a[vitri]; //gan x bang gia tri o giua
    int i = l; //gan i = left
    int j = r; //gan j  = right
    do{
        while(a[i] < x) i++; // tim phan tu lon hon x
        while(a[j] > x) j--; // tim phan tu nho hon x
        if(i <= j){
            swap(&a[i], &a[j]);
            i++;
            j--;
        } 
    } while(i <= j);
    if(l < j) quick_sort(a,l,j);
    if(i < r) quick_sort(a,i,r);

int searchBinary(type a[],int l,int r, type x){
    if(l>r) return -1;
    else{
        int vitri=(l+r)/2;
        int key=a[vitri];
        if(key==x) return vitri;
        else if(key>x) searchBinary(a,l,vitri-1,x);
        else searchBinary(a,vitri+1,r,x);
    }
}