#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula *prox;
} *Palavras;




//1.

void libertaLista (Palavras l) {
    while (l!=NULL) {
        Palavras aux = l;
        l = l->prox;
        free(aux);
    }
}



//2.

int quantasP (Palavras l) {
    int contador=0;
    while (l!=NULL) {
        contador++;
        l=l->prox;
    }
    return contador;
}



//3.

void listaPal (Palavras l) {
    while (l!=NULL) {
        printf("%s  ->  %d\n",l->palavra,l->ocorr);
        l=l->prox;
    }
}



//4.

char *ultima (Palavras l) {
    Palavras aux;
    while (l!=NULL) {
        aux = l;
        l=l->prox;
    }
    return (aux->palavra);
}



//5.

Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras aux = malloc(sizeof(struct celula));
    aux->palavra = p;
    aux->ocorr = 1;
    aux->prox = l;
    return aux;
}



//6.

Palavras acrescentaFim (Palavras l, char *p) {
    Palavras aux = malloc(sizeof(struct celula));
    aux->palavra = p;
    aux->ocorr = 1;
    aux->prox = NULL;
    
    if (l==NULL) return aux;

    Palavras temporaria = l;
    while (temporaria->prox!=NULL) {
        temporaria = temporaria->prox;
    }
    temporaria->prox = aux;
    return l;
}



//7.

Palavras acrescenta (Palavras l, char *p) {
    Palavras temp = l;
    int flag = 0;

    while (temp!=NULL && flag==0) {
        if (!strcmp(temp->palavra,p)) {
            flag = 1;
        } else {
            temp=temp->prox;
        }
    }

    if (flag) {
        temp->ocorr++;
    } else {
        l = acrescentaInicio (l,p);
    }
        return l;

}



int main() {
    Palavras texto = malloc (sizeof(struct celula));
    texto->palavra = "Eu";
    texto->ocorr = 4;
    texto->prox = malloc (sizeof(struct celula));
    texto->prox->palavra = "Estou";
    texto->prox->ocorr = 2;
    texto->prox->prox = malloc (sizeof(struct celula));
    texto->prox->prox->palavra = "Aqui";
    texto->prox->prox->ocorr = 10;

    
    //1.
    //libertaLista(texto);

    //2.
    //printf("Número de Palavras: %d\n",quantasP(texto));

    //3.
    //listaPal(texto);

    //4.
    //printf("Última palavra do texto: %s\n",ultima(texto));

    //5.
    //Palavras aux = acrescentaInicio (texto,"Hoje");
    //printf("Palavra: %s     Ocorrência: %d\n",aux->palavra,aux->ocorr);

    //6.
    //Palavras aux = acrescentaFim (texto,"Hoje");
    //printf("Palavra: %s     Ocorrência: %d\n",aux->palavra,aux->ocorr);

    //7.
    Palavras aux = acrescenta (texto,"AquiA");
    listaPal (aux);


    return 0;
}
