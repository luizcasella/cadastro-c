#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nCad = 0;

struct info{  
    char marca[15];
    char modelo[25];
    int ano;
    char placa[6];
    int km;
    int NPorta;
    char ArCond;
}*carro[1];

void inserircad(){
    FILE *arq;
    arq = fopen("carros.txt", "r");
    if (arq == NULL){
        printf("\nERRO!\nNao foi possivel abrir o arquivo!");
    }

    carro[nCad] = (struct info *)malloc(sizeof(struct info));


    int anoARQ, kmARQ, NportaARQ, checar = 0;
    char arCondARQ, marcaARQ[15], modeloARQ[25], placaARQ[6];

    carro[nCad]->ano = -1;
    carro[nCad]->km = -1;
    carro[nCad]->NPorta = -1;

    printf("\nInforme a marca do carro: ");
    scanf("%s", carro[nCad]->marca);

    printf("\nInforme o modelo do carro: ");
    scanf("%s", carro[nCad]->modelo);

    printf("\nInforme o ano do carro: ");
    scanf("%d", &carro[nCad]->ano);
    while (carro[nCad]->ano == -1){
        printf("ERRO! digite um numero!.\n");
        fflush(stdin);
        scanf("%d", &carro[nCad]->ano);
    }

    printf("\nInforme a placa do carro: ");
    scanf("%s", carro[nCad]->placa);

    printf("\nInforme a quilometragem do carro: ");
    scanf("%d", &carro[nCad]->km);
    while (carro[nCad]->km == -1){
        printf("ERRO! digite um numero!.\n");
        fflush(stdin);
        scanf("%d", &carro[nCad]->km);
    }

    printf("\nInforme o numero de portas do carro: ");
    scanf("%d", &carro[nCad]->NPorta);
    while (carro[nCad]->NPorta == -1){
        printf("ERRO! digite um numero!.\n");
        fflush(stdin);
        scanf("%d", &carro[nCad]->NPorta);
    }

    printf("\nInforme se o carro possui ar condicionado[S/N]: ");
    scanf(" %c", &carro[nCad]->ArCond);

    while ( fscanf ( arq, "%s %s %d %s %d %d %c", marcaARQ, modeloARQ, &anoARQ, placaARQ, &kmARQ, &NportaARQ, &arCondARQ) != EOF ){

        if (strcmp(placaARQ, carro[nCad]->placa) == 0){
            checar = 1;
        }
    }

    fclose(arq);

    if (checar == 0){
        arq = fopen("carros.txt", "a");
        if (arq == NULL){
            printf("\nERRO!\nNao foi possivel abrir o arquivo!");
        }
        fprintf(arq, " %s ", carro[nCad]->marca);
        fprintf(arq, " %s ", carro[nCad]->modelo);
        fprintf(arq, " %d ", carro[nCad]->ano);
        fprintf(arq, " %s ", carro[nCad]->placa);
        fprintf(arq, " %d ", carro[nCad]->km);
        fprintf(arq, " %d ", carro[nCad]->NPorta);
        fprintf(arq, " %c ", carro[nCad]->ArCond);
        fclose(arq);
    }
    else{
        printf("ERRO! Placa ja cadastrada\n");
    }

    nCad += 1;
}

void alterarcad(){
    FILE *arq, *arq1;
    int ano = -1, km = -1, Nporta = -1, esc = -1;
    char arCond, marca[15], modelo[25], placa[6], buscaplaca[6];
    int anoARQ, kmARQ, NportaARQ;
    char arCondARQ, marcaARQ[15], modeloARQ[25], placaARQ[6];

    arq = fopen("carros.txt", "r");
    if (arq == NULL){
        printf("\nERRO!\nNao foi possivel abrir o arquivo!\n");
    }
    arq1 = fopen("carrosAUXILIAR.txt", "w");
    if (arq1 == NULL){
        printf("\nERRO!\nNao foi possivel abrir o arquivo!\n");
    }

    printf("Informe a placa que deseja buscar: ");
    scanf("%s", buscaplaca);

    mostrarcad(buscaplaca);

    while ( fscanf ( arq, "%s %s %d %s %d %d %c", marcaARQ, modeloARQ, &anoARQ, placaARQ, &kmARQ, &NportaARQ, &arCondARQ) != EOF ) {

        if (strcmp(placaARQ, buscaplaca) == 0){
            while(esc != 7){
                printf("--------------------------------------------\n");
                printf("(1) Marca\n");
                printf("(2) Modelo\n");
                printf("(3) Ano de fab.\n");
                printf("(4) Quilometragem\n");
                printf("(5) Num. portas\n");
                printf("(6) Possui ar condicionado?[s/n]\n");
                printf("(7) Fim da alteracao\n");
                printf("--------------------------------------------\n");
                printf("Informe qual dado deseja alterar: ");
                scanf("%d", &esc);
                if (esc == -1 || esc > 7 || esc < 1){
                    printf("ERRO! Opcao invalida, digite uma opcao valida!.\n");
                    fflush(stdin);
                }
                if (esc == 1){
                    printf("Digite a nova marca: ");
                    scanf("%s", marca);
                    fprintf ( arq1, " %s %s %d %s %d %d %c", marca, modeloARQ, anoARQ, placaARQ, kmARQ, NportaARQ, arCondARQ);
                }
                if (esc == 2){
                    printf("Digite o novo modelo: ");
                    scanf("%s", modelo);
                    fprintf ( arq1, " %s %s %d %s %d %d %c", marcaARQ, modelo, anoARQ, placaARQ, kmARQ, NportaARQ, arCondARQ);
                }
                if (esc == 3){
                    printf("Digite o novo ano de fab.: ");
                    scanf("%d", &ano);
                    while (ano == -1){
                        printf("ERRO! digite um numero!.\n");
                        fflush(stdin);
                        scanf("%d", &ano);
                    }
                    fprintf ( arq1, " %s %s %d %s %d %d %c", marcaARQ, modeloARQ, ano, placaARQ, kmARQ, NportaARQ, arCondARQ);
                }
                if (esc == 4){
                    printf("Digite a nova quilometragem: ");
                    scanf("%d", &km);
                    while (km == -1){
                        printf("ERRO! digite um numero!.\n");
                        fflush(stdin);
                        scanf("%d", &km);
                    }
                    fprintf ( arq1, " %s %s %d %s %d %d %c", marcaARQ, modeloARQ, anoARQ, placaARQ, km, NportaARQ, arCondARQ);
                }
                if (esc == 5){
                    printf("Digite o novo num. de portas: ");
                    scanf("%d", &Nporta);
                    while (Nporta == -1){
                        printf("ERRO! digite um numero!.\n");
                        fflush(stdin);
                        scanf("%d", &Nporta);
                    }
                    fprintf ( arq1, " %s %s %d %s %d %d %c", marcaARQ, modeloARQ, anoARQ, placaARQ, kmARQ, Nporta, arCondARQ);

                }
                if (esc == 6){
                    printf("Digite se o carro possui Ar cond[S/N]: ");
                    scanf("%c", &arCond);
                    fprintf ( arq1, " %s %s %d %s %d %d %c", marcaARQ, modeloARQ, anoARQ, placaARQ, kmARQ, Nporta, arCondARQ);
                }
                if (esc == 7){
                    break;
                }
            }    
        }
        
        else{
            fprintf ( arq1, "%s %s %d %s %d %d %c", marcaARQ, modeloARQ, anoARQ, placaARQ, kmARQ, NportaARQ, arCondARQ);
        }
    }

    fclose(arq);
    fclose(arq1);

    arq = fopen("carros.txt", "w");
    if (arq == NULL){
        printf("\nERRO!\nNao foi possivel abrir o arquivo 0!\n");
    }
    arq1 = fopen("carrosAUXILIAR.txt", "r");
    if (arq1 == NULL){
        printf("\nERRO!\nNao foi possivel abrir o arquivo 1!\n");
    }

    while ( fscanf ( arq1, "%s %s %d %s %d %d %c", marcaARQ, modeloARQ, &anoARQ, placaARQ, &kmARQ, &NportaARQ, &arCondARQ) != EOF ) {
        fprintf ( arq, " %s %s %d %s %d %d %c", marcaARQ, modeloARQ, anoARQ, placaARQ, kmARQ, NportaARQ, arCondARQ);
    }

    fclose(arq);
    fclose(arq1);
}

int mostrarcad(char buscaplaca[6]){
    int ano, km, Nporta;
    char arCond, marca[15], modelo[25], placa[6];

    FILE *arq;
    arq = fopen("carros.txt", "r");
    if (arq == NULL){
        printf("ERRO! Nao foi possivel abrir o arquivo!\n");
    }
    else{
        while(fscanf(arq, "%s %s %d %s %d %d %c", marca, modelo, &ano, placa, &km, &Nporta, &arCond) != EOF){

            if (strcmp(placa, buscaplaca) == 0){
                printf("-------------------------------------------------\n");
                printf("Os dados do veiculo com placa %s:\n", placa);
                printf("Marca: %s\n", marca);
                printf("Modelo: %s\n", modelo);
                printf("Ano de Fab.: %d\n", ano);
                printf("Quilometragem: %d\n", km);
                printf("Num. de portas: %d\n", Nporta);
                printf("Ar condicionado[s/n]: %c\n", arCond);
                printf("-------------------------------------------------\n");
            }
        }
        fclose(arq);
    }
    return 0;
}

void apagarcad(){
    FILE *arq, *arq1;
    int ano, km, Nporta, esc = -1;
    char arCond, marca[15], modelo[25], placa[6], buscaplaca[6];
    int anoARQ, kmARQ, NportaARQ;
    char arCondARQ, marcaARQ[15], modeloARQ[25], placaARQ[6];

    arq = fopen("carros.txt", "r");
    if (arq == NULL){
        printf("\nERRO!\nNao foi possivel abrir o arquivo!\n");
    }
    arq1 = fopen("carrosAUXILIAR.txt", "w");
    if (arq1 == NULL){
        printf("\nERRO!\nNao foi possivel abrir o arquivo!\n");
    }

    printf("Informe a placa que deseja buscar: ");
    scanf("%s", buscaplaca);

    while ( fscanf ( arq, "%s %s %d %s %d %d %c", marcaARQ, modeloARQ, &anoARQ, placaARQ, &kmARQ, &NportaARQ, &arCondARQ) != EOF ) {
        if (strcmp(placaARQ, buscaplaca) == 0){
            printf("Dados APAGADOS!\n");
        }
        else{
            fprintf ( arq1, "%s %s %d %s %d %d %c", marcaARQ, modeloARQ, anoARQ, placaARQ, kmARQ, NportaARQ, arCondARQ);
        }
    }

    fclose(arq);
    fclose(arq1);

    arq = fopen("carros.txt", "w");
    if (arq == NULL){
        printf("\nERRO!\nNao foi possivel abrir o arquivo 0!\n");
    }
    arq1 = fopen("carrosAUXILIAR.txt", "r");
    if (arq1 == NULL){
        printf("\nERRO!\nNao foi possivel abrir o arquivo 1!\n");
    }

    while ( fscanf ( arq1, "%s %s %d %s %d %d %c", marcaARQ, modeloARQ, &anoARQ, placaARQ, &kmARQ, &NportaARQ, &arCondARQ) != EOF ) {
        fprintf ( arq, " %s %s %d %s %d %d %c", marcaARQ, modeloARQ, anoARQ, placaARQ, kmARQ, NportaARQ, arCondARQ);
    }

    fclose(arq);
    fclose(arq1);
}

int main(){

    printf("-------------------------------------------------\n");
    printf("Programa INICIADO\n");
    printf("-------------------------------------------------\n");
    while (1){
        int escolha = -1;
        char buscaplaca[6];

        printf("(1) Inserir novo cadastro\n");
        printf("(2) Alterar cadastro\n");
        printf("(3) Mostrar os dados de um veiculo\n");
        printf("(4) Apagar registro\n");
        printf("(5) Sair\n");
        printf("Digite opcao desejada: ");
        scanf(" %d", &escolha);

        if (escolha == -1 || escolha > 5 || escolha < 1){
            printf("ERRO! Opcao invalida, digite uma opcao valida!.\n");
            fflush(stdin);
        }
        if (escolha == 1){
            inserircad();
        }
        if (escolha == 2){
            alterarcad();
        }
        if (escolha == 3){
            printf("Informe a placa que deseja buscar: ");
            scanf("%s", buscaplaca);
            mostrarcad(buscaplaca);
        }
        if (escolha == 4){
            apagarcad();
            
        }
        if (escolha == 5){
            break;
            free(*carro);
        }
    } 

    printf("Programa FINALIZADO!.");
}  
