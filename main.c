#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

typedef struct Aresta{
    int vi;
    int vj;
    int peso;
}Aresta;

void calcular_grau();
FILE* gerar_arquivo();
int main() {
    FILE *arquivo;
    int opcao;
    if(arquivo = fopen("arquivo.txt","r+") == NULL){
          arquivo =gerar_arquivo();
    }
    else{
        printf("arquivo.txt existe, deseja criar um novo arquivo? (Sim = 1) ou (Não = 0): \n");
        scanf("%d",&opcao);
        while(opcao != 0 || opcao!=1){
            if(opcao == 0 || opcao ==1){
                break;
            }
            scanf("%d",&opcao);
        }
        if(opcao==1){
            arquivo = gerar_arquivo();
        }
    }
    if(arquivo = fopen("arquivo.txt","r+") == NULL){
        printf("Erro ao abrir o arquivo");
        return 0;
    }

    do{
        printf("-------MENU-------\n");
        printf("Digite uma opcao: \n");
        scanf("%d",&opcao);
        switch(opcao){
            case 0:
                break;
            case 1:
                break;
            case 2:
                calcular_grau();
                break;
        }
    }while(opcao!=0);



    return 0;
}

FILE* gerar_arquivo(){
    FILE *arquivo;
    arquivo = fopen("arquivo.txt","w");
    int num_vertices,num_arestas,valorado;
    char tipo;
    int i;
    printf("---Gerar Arquivo---\n");
    printf("Numero de Vertices: \n");
    scanf("%d",&num_vertices);
    printf("Numero de Arestas: \n");
    scanf("%d",&num_arestas);
    printf("Tipo do Grafo (Dirigido = D, Nao Dirigido = G): \n");
    scanf(" %c",&tipo);
    tipo = toupper(tipo);
    switch(tipo){
        case 'D':
            break;
        case 'G':
            break;
        default:
            do {
                printf("Insira o tipo novamente: \n");
                scanf(" %c", &tipo);
                tipo = toupper(tipo);
                if(tipo =='G' || tipo =='D'){
                    break;
                }
            }while(tipo !='G' || tipo !='D');
            break;
    }
    printf("O grafo e valorado (nao valorado = 0,valorado=1): \n");
    scanf("%d",&valorado);
    switch(valorado){
        case 0:
            break;
        case 1:
            break;
        default:
            do {
                printf("Insira novamente: \n");
                scanf("%d", &valorado);
                if(valorado ==0|| valorado ==1){
                    break;
                }
            }while(valorado !=0 || valorado !=1);
            break;
    }
    fprintf(arquivo,"%d %d %c %d\n",num_vertices,num_arestas,tipo,valorado);
    Aresta *arestas;
    int peso = 1;
    arestas = malloc(num_arestas * sizeof(Aresta));
    if(valorado ==0){
        for(i=0;i<num_arestas;i++){
            printf("Inserir vi: \n");
            scanf("%d",&arestas[i].vi);
            printf("Inserir vj: \n");
            scanf("%d",&arestas[i].vj);
            arestas[i].peso = peso;
            fprintf(arquivo,"%d %d %d\n",arestas[i].vi,arestas[i].vj,arestas[i].peso);
        }
    }
    else{
        for(i=0;i<num_arestas;i++){
            printf("Inserir vi: \n");
            scanf("%d",&arestas[i].vi);
            printf("Inserir vj: \n");
            scanf("%d",&arestas[i].vj);
            printf("Inserir peso: \n");
            scanf("%d",& arestas[i].peso);
            fprintf(arquivo,"%d %d %d\n",arestas[i].vi,arestas[i].vj,arestas[i].peso);
        }
    }
    fclose(arquivo);
    return arquivo;
}
void calcular_grau() {
    FILE *arquivo;
   arquivo =fopen("arquivo.txt","r");

    char tipo;
    int vertices, arestas, valorado;
    fscanf(arquivo,"%d %d %c %d",&vertices,&arestas,&tipo,&valorado);
    fclose(arquivo);

}

