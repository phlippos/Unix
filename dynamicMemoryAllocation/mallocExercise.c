#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int* ptr; // Adresse des Zeigers
    int* ptr2; // Adresse des Zeigers
    int n, i;
 
    // [AUFGABE] a) Fragen Sie den Benutzer nach der Anzahl der zu erstellenden Elemente
    printf("Wie viele Elemente : ");
    scanf("%d",&n);
      printf("Sie haben eingegeben : %d\n",n);
    // [AUFGABE] a) Weisen Sie Arbeitsspeicher für ptr und ptr2 mit malloc(_size) dynamisch zu
    
   // //ptr = (int*)malloc(n*sizeof(int));
   // //ptr2 = (int*)malloc(n*sizeof(int));
    ptr = (int*)calloc(n,sizeof(int));
    ptr2 = (int*)calloc(n,sizeof(int));
    // [AUFGABE] a) Wenn Rückgabewert von malloc NULL ist, zeigen Sie einen Fehler und beenden Sie das Programm
    if (ptr == NULL || ptr2 == NULL) {
        printf("Speicher-Allokieren ist failed.\n");
        exit(1);
    }
    else { // [AUFGABE] a) Wenn nicht NULL ist, ist die Zuordnung erfolgreich. Zeigen Sie einen Text auf dem Terminal an

        printf("Speicher-Allokieren ist erfolgreich.\n");
        // [AUFGABE] a) Setzen Sie Array-Werte von 1 bis n (n = die Zahl, die der Benutzer eingegeben hat), mithilfe einer Schleife
		// array[0] = 1, array[1] = 2 etc.
		// Hinweis: Bitte verwenden Sie separate Schleifen für jedes Array.

        for(i = 0; i< n; ++i){
            ptr[i] = i+1;
        }

        for(i = 0; i< n; ++i){
            ptr2[i] = i+1;
        }



        printf("Die Elemente für ptr sind:");
        // [AUFGABE] a) Geben Sie nun jedes Element mit Schleifen an das Terminal aus. 
		// Hinweis: Bitte verwenden Sie separate Schleifen für jedes Array.
        for(i = 0; i< n; ++i){
             printf("%d,",ptr[i]);
        }
        printf("\nDie Elemente für ptr2 sind:");
        for(i = 0; i< n; ++i){
              printf("%d,",ptr2[i]);
        }


    }

    free(ptr);
    free(ptr2);
	
    return 0;
}