#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* f1 = fopen("input.txt","w");

    int i,n,N,j,gioihan;

    printf("Nhap so dong muon tao: ");
    scanf("%ld",&n);

    printf("Nhap so phan tu day: ");
    scanf("%ld",&N);
    fprintf(f1,"%d\n",N);

    printf("Nhap so gioi han day: ");
    scanf("%ld",&gioihan);

    for(i=0;i<n;i++){
        for(j=0;j<N;j++){
            fprintf(f1,"%d ",rand()%gioihan);
        }
        fprintf(f1,"\n");
    }
    return 0;
}