#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* f1 = fopen("input.txt","w");

    long int i,n,N,j;
    char str[] = "123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzquot";
    char result;

    printf("Nhap so dong muon tao: ");
    scanf("%ld",&n);

    printf("Nhap gioi han String: ");
    scanf("%ld",&N);

    for(i=0;i<n;i++){
        for(j=0;j<N;j++){
            result = str[rand() % (sizeof(str)-1)];
            fprintf(f1,"%c",result);
        }
        fprintf(f1,"\n");
    }
    return 0;
}