#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg_pac{
    char nome[30];
    char cpf[15];
    char nivel[15];
    struct reg_pac *proximo;
}Paciente;

typedef struct{
    Paciente *emergencia;
    Paciente *urgencia;
    Paciente *eletivo;
}Filas;

Filas *criar_filas(){

    Filas *filas = (Filas*)malloc(sizeof(Filas));

    filas->emergencia = NULL;
    filas->urgencia = NULL;
    filas->eletivo = NULL;

    return filas;
}

void ler_dados(Paciente *pac){
    printf("\n\tNome: ");
    scanf("%29[^\n]", &pac->nome);
    getchar();
    printf("\tCPF: ");
    scanf("%14[^\n]", &pac->cpf);
}

void imprimir_dados(Paciente pac){
    printf("\n\tNome: %s\n", pac.nome);
    printf("\tCPF: %s\n", pac.cpf);
    printf("\tNivel: %s\n", pac.nivel);
}

Paciente* criar_reg_pac(){

    Paciente *novo = (Paciente*)malloc(sizeof(Paciente));

    ler_dados(novo);

    novo->proximo = NULL;

    return novo;
}

void inserir_na_fila(Paciente **fila, Paciente *reg_pac){

    if(*fila == NULL){
        *fila = reg_pac;
    }
    else{

        Paciente *aux = *fila;

        while(aux->proximo != NULL){
            aux = aux->proximo;
        }

        aux->proximo = reg_pac;
    }
}

Paciente* remover_da_fila(Paciente **fila){

    Paciente *remover = *fila;

    *fila = remover->proximo;

    remover->proximo = NULL;

    return remover;
}

Paciente* next(Filas *filas){

    static int cont = 0;

    if(filas->emergencia != NULL){
        return remover_da_fila(&(filas)->emergencia);
    }

    if(cont != 3 && filas->urgencia != NULL){
        cont++;
        return remover_da_fila(&(filas)->urgencia);
    }

    if(filas->eletivo != NULL){
        cont = 0;
        return remover_da_fila(&(filas)->eletivo);
    }
}

void imprimir_filas(Paciente *fila, char *nome_fila){

    printf("\n\t\t%s\n", nome_fila);
    printf("\t------------------------------\n");

    while(fila != NULL){
        imprimir_dados(*(fila));
        fila = fila->proximo;
    }

    printf("\n\t------------------------------\n");
}

void menu_cadastro(Filas *filas){

    Paciente *novo_reg;
    int opc;

    while(1){
        printf("\n\tINFORME O NIVEL:\n");
        printf("\n\t1 - EMERGENCIA\n");
        printf("\t2 - URGENCIA\n");
        printf("\t3 - ELETIVO\n");

        printf("\n\tInforme a Opcao: ");
        scanf("%d", &opc);
        getchar();

        switch(opc){
        case 1:

            novo_reg = criar_reg_pac();
            strcpy(novo_reg->nivel, "EMERGENCIA");
            inserir_na_fila(&(filas)->emergencia, novo_reg);

            printf("\n\tCadastro Realizado com Sucesso.\n");

            return;
        case 2:

            novo_reg = criar_reg_pac();
            strcpy(novo_reg->nivel, "URGENCIA");
            inserir_na_fila(&(filas)->urgencia, novo_reg);

            printf("\n\tCadastro Realizado com Sucesso.\n");

            return;
        case 3:

            novo_reg = criar_reg_pac();
            strcpy(novo_reg->nivel, "ELETIVO");
            inserir_na_fila(&(filas)->eletivo, novo_reg);

            printf("\n\tCadastro Realizado com Sucesso.\n");

            return;
        default:
            printf("\n\tOpcao Invalida!\n");
            break;
        }
    }
}

int main(){

    Filas *filas = criar_filas();
    Paciente *pac_atendido;
    int opc;

    while(1){
        printf("\n\t1 - Cadastrar Paciente\n\t2 - Visualizar Pacientes\n");
        printf("\t3 - Proximo Paciente a ser Atendido\n\t0 - Sair\n");
        printf("\n\tInforme a Opcao: ");
        scanf("%d", &opc);
        getchar();

        switch(opc){
        case 0:
            printf("\n\tSAINDO...\n\n");
            exit(0);
            break;
        case 1:

            menu_cadastro(filas);

            break;
        case 2:

            imprimir_filas(filas->emergencia, "EMERGENCIA");
            imprimir_filas(filas->urgencia, "URGENCIA");
            imprimir_filas(filas->eletivo, "ELETIVO");

            break;
        case 3:

            if(filas->emergencia != NULL || filas->urgencia != NULL || filas->eletivo != NULL){

                pac_atendido = next(filas);

                printf("\n\tPaciente Atendido: %s\n", pac_atendido->nome);
                printf("\tNivel: %s\n", pac_atendido->nivel);

            }
            else{
                printf("\n\tNenhum Paciente na Fila.\n");
            }

            break;
        default:
            printf("\n\tOpcao Invalida!\n");
            break;
        }
    }

    return 0;
}
