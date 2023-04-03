#include <stdio.h>
#include <stdlib.h>


int main(){

    int * myArray;

    int size;
    printf("Kac sayi girmek istiyorsunuz ?\n");
    scanf("%d",&size);

    myArray = (int*)malloc(size*sizeof(int));
    int i;
    for(i = 0;i< size ; ++i){
        printf("Sayiyi giriniz: \n");
        scanf("%d",&myArray[i]);        
    }

    for(i = 0; i< size; ++i){
        printf("%p adresindeki deger : %d\n",&myArray[i],myArray[i]);
    }
    
    free(myArray);
    return 0;

}