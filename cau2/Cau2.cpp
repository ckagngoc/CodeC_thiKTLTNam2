#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000000
typedef long int type;

void quick_sort(type*,type,type);
void swap(type*,type*);
type searchBinary(type*, type, type, type);
void printFile(type*, type, FILE*);

int main(){
    FILE *f1,*f2;
    f1 = fopen("input.txt","r");
    f2 = fopen("output.txt","w");
    if(f1 == NULL){
        printf("Can not open file !!!");
        return 0;
    }
    type i,n,x;
    if(n>MAXSIZE){
        printf("Memory overflow");
        return 0;
    }
    fscanf(f1,"%ld",&n);
    type a[n];
    for(i = 0;i < n;i++) fscanf(f1,"%ld",&a[i]);
    //----------------------------sort------------------------------------------------
    quick_sort(a,0,n-1);
    //----------------------------search-----------------------------------------------
    printf("Nhap phan tu can tim: ");
    scanf("%ld",&x);
    fprintf(f2,"\nPhan tu can tim la %ld o vi tri %ld ",x,searchBinary(a,0,n-1,x));
    printFile(a,n,f2);
    fclose(f1);
    fclose(f2);
    return 0;
}
//-----------swap-----------------------
void swap(type *a, type *b){
    type temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//------------quick sort----------------
void quick_sort(type a[], type l, type r){
    int vitri = (l+r)/2;
    type x = a[vitri]; //gan x bang gia tri ngoai cung
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
}
//----------searchBinary-------------------
type searchBinary(type a[], type l, type r, type x){
    type vitri = 0;
    if(l>r) return -1;
    vitri = (l+r)/2;
    if(a[vitri] == x) return vitri+1;
    else if(a[vitri] > x) searchBinary(a,l,vitri-1,x);
        else searchBinary(a,vitri+1,r,x);
}
//--------------printFile---------------------
void printFile(type a[], type lenght, FILE *f2){
    type i;
    fprintf(f2,"\n");
    for(i = 0;i < lenght;i++){
        fprintf(f2,"%ld ",a[i]);
    }
}
