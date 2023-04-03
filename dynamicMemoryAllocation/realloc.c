#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int *myArray;
    int ammount,newAmmount;
    char answer;

    printf("Kac sayi girmek istiyorsunuz ?\n");
    scanf("%d",&ammount);
    myArray = (int*)malloc(ammount*sizeof(int));

    int i;
    for(i = 0;i< ammount; ++i){
        printf("Sayiyi giriniz: \n");
        scanf("%d",&myArray[i]); 
        if(i == ammount-1){
            printf("Kota doldu buyutmek ister misiniz?(y/n)\n");
            
            scanf(" %c",&answer);
            if('y'==answer){
                printf("Kac tane daha girmek istiyorsunuz ?\n");
                scanf("%d",&newAmmount);
                ammount += newAmmount;
                myArray = realloc(myArray,sizeof(myArray)+newAmmount*sizeof(int));

            }
        }
    }


    for(i=0; i< ammount;++i){
        printf("%p adresindeki deger : %d\n",&myArray[i],myArray[i]);
    }

    free(myArray);

    return 0;
}