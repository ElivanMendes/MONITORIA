#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lerValores(float *a, float *b, float *c){

    do{
        printf("Digite o Valor de A: ");
        scanf("%f", &*a);

        if(*a == 0){

            printf("\n\tDigite um Valor Diferente de 0!\n\n");
        }

    }while(*a == 0);

    printf("Digite o Valor de B: ");
    scanf("%f", &*b);
    printf("Digite o Valor de C: ");
    scanf("%f", &*c);
}

int raizes(float a, float b, float c, float *x1, float *x2){

    float delta, x;

    delta = (b * b) - (4.0 * a * c);

    if(delta < 0){

        return 0;
    }
    else if(delta == 0){

        x = -b / (2.0 * a);

        *x1 = x;
        *x2 = x;

        return 1;
    }
    else{

        delta = sqrt(delta);

        *x1 = (-b + delta) / (2.0 * a);
        *x2 = (-b - delta) / (2.0 * a);

        return 2;
    }
}

void imprimir(int quantR, float x1, float x2){

    if(quantR == 0){

        printf("\n\tNAO EXISTE RAIZ REAL!\n");
    }

    if(quantR == 1){

        printf("\n\tEXISTE UMA RAIZ REAL:\n\n\tX: %.2f\n", x1);
    }

    if(quantR == 2){

        printf("\n\tEXISTE DUAS RAIZES REAIS:\n\n\tX1: %.2f\tX2: %.2f\n", x1, x2);
    }
}

int main(){

    float a, b, c, x1, x2;
    int quantR;

    lerValores(&a, &b, &c);

    quantR = raizes(a, b, c, &x1, &x2);

    imprimir(quantR, x1, x2);

    return 0;
}
