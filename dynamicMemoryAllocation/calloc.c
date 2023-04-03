#include <stdio.h>
#include <stdlib.h>


int main(){

    int *myArray;
    int ammount;

    printf("Kac tane sayi girmek istiyorsunuz ?\n");
    scanf("%d",&ammount);

    myArray = (int*)calloc(ammount,sizeof(int));

    int i;
    for(i = 0; i < ammount-1;++i){
        printf("Sayiyi giriniz: \n");
        scanf("%d",&myArray[i]);
    }

    for(i=0; i < ammount;++i ){
        printf("%p adresindeki değer : %d\n",&myArray[i],myArray[i]);
    }

    free(myArray);
    return 0;
}