#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


unsigned int hash(int a, int b, int c);
int *gerador(int seed);

unsigned int hash(int a, int b, int c) {
    unsigned int hashValue = 0;
    hashValue = ((unsigned int)a * 31 + (unsigned int)b) * 31 + (unsigned int)c;
    return hashValue;
}

int *gerador(int seed) {
    int count = 30;
    int maximo = 99;

    int *valores = (int *)malloc(count * sizeof(int));
    int i, j, r;

    srand(time(NULL));

    for (i = 0; i < count; i++) {
        do {
            r = rand() % maximo + 1;
            for (j = 0; j < i; j++) {
                if (valores[j] == r)
                    break;
            }
        } while (j < i);
        valores[i] = r;
    }

    // for (i = 0; i < count; i++) {
    //     printf("v[%d] = %d\n", i, valores[i]);
    // }
    printf("\n");
    return valores;
}
