#include <stdio.h>
// Letra A.
typedef struct
{
    int matricula;
    float nota;
    char nome[50];
} Alunos;

void cadastrar(int quantidade_alunos)
{
    FILE *arquivo = fopen("alunos.dat", "wb");
    Alunos aluno_lido;
    int index;
    printf("Informe os dados do alunos:\n");
    for (index = 0; index < quantidade_alunos; index++)
    {
        scanf("%d", &aluno_lido.matricula);
        scanf(" %[^\n]", aluno_lido.nome);
        scanf("%f", &aluno_lido.nota);
        fwrite(&aluno_lido, sizeof(Alunos), 1, arquivo);
    }
    fclose(arquivo);
}
// Letra B.
void imprimir(void)
{
    FILE *arquivo = fopen("alunos.dat", "rb");
    Alunos aluno_lido;

    while (fread(&aluno_lido, sizeof(Alunos), 1, arquivo))
    {
        printf("MATRICULA: %d\tNOME: %s\tNOTA: %.2f\n",
               aluno_lido.matricula, aluno_lido.nome, aluno_lido.nota);
    }
    fclose(arquivo);
}
// Letra C.
int registros(void)
{
    FILE *arquivo = fopen("alunos.dat", "rb");
    Alunos aluno_lido;
    long tamanho = ftell(arquivo);
    int total = tamanho / sizeof(Alunos);
    printf("Total: %d", total);
    fclose(arquivo);
}
//Letra D.
void busca(){}
int main(void)
{
    cadastrar(3);
    return 0;
}