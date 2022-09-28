#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int valor;
    struct no *proximo;

}No;

void ler_valor(No *no){

    printf("\nDigite um Valor: ");
    scanf("%d", &no->valor);
}

int ler_valor_remover(){

    int valor;

    printf("\nDigite um Valor para Remover: ");
    scanf("%d", &valor);

    return valor;
}

void inserir(No **lista){

    No *novo = malloc(sizeof(No));

    // novo->valor = 100;
    ler_valor(novo);

    // novo->proximo = lista;
    novo->proximo = *lista;

    *lista = novo;
}

void inserir_ordenado(No **lista){

    No *aux, *novo = malloc(sizeof(No));

    ler_valor(novo);

    // 10 -> NULL
    // Não Existe Ninguem
    if(*lista == NULL){

        novo->proximo = NULL;

        *lista = novo;
    }
    else if(novo->valor < (*lista)->valor){

        // 10 -> 50 -> 100 -> NULL
        novo->proximo = *lista;

        *lista = novo;
    }
    else{

        aux = *lista;

        // 10 -> 50 -> 60 -> 100 -> NULL
        while(aux->proximo != NULL && novo->valor > aux->proximo->valor){

            aux = aux->proximo;
        }

        novo->proximo = aux->proximo;

        aux->proximo = novo;
    }
}

void concatenar_listas(No **lista_1, No **lista_2){

    No *aux;

    if(lista_1 != NULL){

        aux = *lista_1;

        // aux->proximo = NULL;
        while(aux->proximo != NULL){

            aux = aux->proximo;
        }

        aux->proximo = *lista_2;
    }
}

No* remover_no(No **lista, int valor){

    No *aux, *rem = NULL;

    if(*lista != NULL){

        // 10 = 10
        if((*lista)->valor == valor){

            // rem = 10 -> 20 -> NULL
            rem = *lista;

            // 20 -> NULL
            *lista = rem->proximo;
        }
        else{

            aux = *lista;

            // 10 -> 20 -> 30 -> NULL
            while(aux->proximo != NULL && aux->proximo->valor != valor){

                aux = aux->proximo;
            }

            if(aux->proximo != NULL){

                // 30 -> NULL
                rem = aux->proximo;

                // 10 -> 20 -> NULL
                aux->proximo = rem->proximo;
            }
        }
    }

    return rem;
}

void remover_ocorrencias(No **lista, int valor){

    No *aux;

    if(*lista != NULL){

        aux = *lista;

        while(aux != NULL){

            if(aux->valor == valor){

                remover_no(lista, valor);
            }

            aux = aux->proximo;
        }
    }
}

void imprimir(int valor){

    printf("%d -> ", valor);
}

void imprimir_lista(No *lista){

    printf("\n\t------------------------------------------------\n\t");

    if(lista != NULL){

        while(lista != NULL){

            imprimir(lista->valor);

            lista = lista->proximo;
        }
    }

    printf("NULL");

    printf("\n\t------------------------------------------------\n");
}

int main(){

    No *remover, *lista_1 = NULL;
    No *lista_2 = NULL;
    int opcao;

    do{
        printf("\n\t1 - Inserir Lista_1\n\t2 - Inserir Lista_2\n");
        printf("\t3 - Concatenar\n\t4 - Remover\n\t5 - Remover Ocorrencias\n");
        printf("\t6 - Inserir Ordenado Lista_1\n\t7 - Inserir Ordenado Lista_2\n\t8 - Imprimir\n\t0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 0:
            printf("\n\tSAINDO...\n");
            break;
        case 1:

            inserir(&lista_1);

            break;
        case 2:

            inserir(&lista_2);

            break;
        case 3:

            concatenar_listas(&lista_1, &lista_2);

            break;
        case 4:

            remover = remover_no(&lista_1, ler_valor_remover());

            if(remover != NULL){

                printf("\n\tValor Encontrado: %d\n", remover->valor);
            }
            else{
                printf("\n\tELEMENTO NAO ENCONTRADO!\n");
            }

            break;
        case 5:

            remover_ocorrencias(&lista_1, ler_valor_remover());

            break;
        case 6:

            inserir_ordenado(&lista_1);

            break;
        case 7:

            inserir_ordenado(&lista_2);

            break;
        case 8:

            printf("\tLista 1");
            imprimir_lista(lista_1);
            printf("\n\tLista 2");
            imprimir_lista(lista_2);

            break;
        default:

            if(opcao != 0){
                printf("\n\tOpcao Invalida!\n");
            }
        }

    }while(opcao != NULL);

    return 0;
}
