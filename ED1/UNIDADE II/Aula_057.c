#include <stdio.h>

int estoquecristais(int cristais[],int tamanho,int indice){
    int atualpositivo;
    if(indice==tamanho){
        return 0;
    }
    if(cristais[indice]>0){
        atualpositivo=1;
    }else{
        atualpositivo=0;
    }
    return atualpositivo+estoquecristais(cristais,tamanho,indice+1);
}
int main(){
    int n,i;
    int totalpositivos;
    printf("Informe quantos cristais possui no seu inventario: ");
    scanf("%d",&n);
    if(n<=0){
        printf("0\n");
        return 0;
    }
    int inventario[n];
    for(i=0;i<n;i++){
        printf("Carga do cristal %d: ",i+1);
        scanf("%d",&inventario[i]);
    }
    totalpositivos=estoquecristais(inventario,n,0);
    printf("Mago ainda consegue lancar %d cristais!\n",totalpositivos);
    return 0;
}