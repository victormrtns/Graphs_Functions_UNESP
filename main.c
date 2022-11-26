#include <stdio.h>
#include <ctype.h>
FILE* gerar_arquivo();
int main() {
    FILE *arquivo;
    int opcao;
    if(arquivo = fopen("arquivo.txt","r+") == NULL){
          arquivo =gerar_arquivo();
    }
    else{}
    return 0;
}

FILE* gerar_arquivo(){
    FILE *arquivo;
    arquivo = fopen("arquivo.txt","w");
    int num_vertices,num_arestas,valorado;
    char tipo;
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
    fprintf(arquivo,"%d %d %c %d",num_vertices,num_arestas,tipo,valorado);


}

