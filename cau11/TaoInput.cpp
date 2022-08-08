#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* f1 = fopen("input.txt","w");
    long int i,n,N;
    printf("Nhap so luong phan tu: ");
    scanf("%ld",&n);

    printf("Nhap gioi han input: ");
    scanf("%ld",&N);

    for(i=0;i<n;i++){
        fprintf(f1,"%ld  ",rand()%N);
    }
    return 0;
}