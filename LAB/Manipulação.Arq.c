/*
MANIPULAÇÃO DE ARQUIVOS

dados.txt
fopen: Abre o arquivo.
fclose: Fecha o arquivo.
fprintf,fputc,fputs: Escreve no arquivo.
fscanf,fgetc,fgets,sscanf: Ler dados do arquivo.

dados.dat
fopen: Abre o arquivo.
fclose: Fecha o arquivo.
fwrite: Escreve no arquivo: fwrite(&var,tamanho,1,arquivo).
fread: ler do arquivo: fread(&var,tamanho,1,arquivo)
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int inteiro,conteudo;
    FILE * arquivo=fopen("dados.dat","wb");
    printf("Diigite um numero inteiro:\n");
    scanf("%d",&inteiro);
    //Escrita no arquivo.
    fwrite(&inteiro, sizeof(int), 1,arquivo);
    fclose(arquivo);
    //Ler.
    arquivo=fopen("dados.dat","rb");
    fread(&conteudo, sizeof(int), 1,arquivo);
    printf("Conteudo lido: %d",conteudo);
    fclose(arquivo);
    return 0;
}