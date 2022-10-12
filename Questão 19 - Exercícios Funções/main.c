#include <stdio.h>
#include <stdlib.h>

void imprimir_vetor(int *v, int tam){

    printf("\n\tVetor: ");

    for(int i = 0; i < tam; i++){

        printf("%d ", v[i]);
    }

    printf("\n");
}

void dividir_vetor(int *v, int *v_p, int *v_i, int tam_v, int *tam_par, int *tam_impar){

    int aux_p = *tam_impar;
    int aux_i = *tam_impar;

    for(int i = 0; i < tam_v; i++){

        if(v[i] % 2 == 0){

            v_p[aux_p] = v[i];

            aux_p++;
        }
    }

    *tam_par = aux_p;

    for(int i = 0; i < tam_v; i++){

        if(v[i] % 2 != 0){

            v_i[aux_i] = v[i];

            aux_i++;
        }
    }

    *tam_impar = aux_i;
}

int main(){

    int vetor[15] = {2, 3, 5, 8, 10, 1, 4, 6, 7, 9, 100, 15, 7, 80, 97};
    int vetor_par[15];
    int vetor_impar[15];
    int tam_par = 0, tam_impar = 0;

    imprimir_vetor(vetor, 15);

    dividir_vetor(vetor, vetor_par, vetor_impar, 15, &tam_par, &tam_impar);

    imprimir_vetor(vetor_par, tam_par);

    imprimir_vetor(vetor_impar, tam_impar);

    return 0;
}
