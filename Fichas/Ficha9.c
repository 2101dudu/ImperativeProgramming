#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;



ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc(sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; 
        a->esq = e; 
        a->dir = d;
    }
    return a;
}




//1.

//a)

int max(int a, int b) {
    if (a>b) return a;
    else return b;
}


int altura (ABin a) {
    if (a == NULL) return 0;
    int valorMax = max(altura (a->esq),altura(a->dir));
    return (1+valorMax);
}


//b)

int nFolhas (ABin a) {
    if (a == NULL) return 0;
    if (a->esq == NULL && a->dir == NULL) return 1;
    return (nFolhas(a->esq) + nFolhas(a->dir));
}


//c)

ABin maisEsquerda (ABin a) {
    if (a->esq == NULL) return a;
    return maisEsquerda(a->esq);
}


//d)

void imprimeNivel (ABin a, int l) {
    if (a != NULL){
        if (l == 0) {
            printf("%d ",a->valor);
        } else {
            imprimeNivel(a->esq,l-1);
            imprimeNivel(a->dir,l-1);
        }
    }
}


//e)

int procuraE (ABin a, int x) {
    if (a == NULL) return 0;
    if (a->valor == x) return 1;
    return max(procuraE(a->esq,x),procuraE(a->dir,x));
}




//2.

//f)

struct nodo *procura (ABin a, int x) {
    if (a == NULL) return NULL;
    if (a->valor == x) return a;
    if (a->valor > x) return procura(a->esq,x);
    return procura(a->dir,x); 
}


//g)

int nivel (ABin a, int x) {
    if (procura(a,x) == NULL) return -1;
    if (a->valor == x) return 0;
    if (a->valor > x) return (1 + nivel(a->esq,x));
    else return (1 + nivel(a->dir,x));
}

    //NAO RECURSIVA

int nivel_2 (ABin a, int x) {
    int contador = 0;
    while (a != NULL && a->valor != x) {
        a = (a->valor > x ? a->esq : a->dir);
        contador++;
    }
    return (a == NULL ? -1 : contador);
}


//h)

void imprimeAte (ABin a, int x) {
    if (a!=NULL) {
        if (a->valor >= x) imprimeAte(a->esq,x);
        else {
            imprimeAte(a->esq,x);
            printf("%d ",a->valor);
            imprimeAte(a->dir,x);
        }
    }
}





int main () {
    //1.

    ABin avBin4 = newABin(4,NULL,NULL);
    ABin avBin3 = newABin(3,avBin4,NULL);
    ABin avBin2 = newABin(2,NULL,avBin4);
    ABin avBin  = newABin(1,avBin2,avBin3);


    printf("\nExercício 1:\n\n");

    printf("a)  A altura da árvore é: %d\n",altura(avBin));

    printf("b)  O número de folhas da árvore é: %d\n",nFolhas(avBin));

    ABin aux = maisEsquerda(avBin);
    printf("c)  O nodo mais à esquerda da árvore é: %d\n",aux->valor);

    printf("d)  ");
    imprimeNivel(avBin,1);
    putchar('\n');

    int valor = 5;
    printf("e)  O valor %d econtra-se na árvore: %d (1 para verdadeiro, 0 para falso)\n",valor,procuraE(avBin,valor));



    //2.

    ABin avBinP3 = newABin(3,NULL,NULL);
    ABin avBinP4 = newABin(4,avBinP3,NULL);
    ABin avBinP1 = newABin(1,NULL,NULL);
    ABin avBinP  = newABin(2,avBinP1,avBinP4);


    printf("\n\nExercício 2:\n\n");

    ABin temp = procura(avBinP,5);
    if (temp != NULL) printf("f)  Este é o valor do nodo da árvore devolvida: %d\n",temp->valor);
    else printf("f)  Valor não existe na árvore\n");

    int valor2 = 5;
    int nNivel = nivel(avBinP,valor2);
    if (nNivel != -1) printf("g)  O valor %d encontra-se no nível: %d\n",valor2,nNivel);
    else printf("g)  O valor %d não se encontra na árvore\n", valor2);

    printf("h)  ");
    imprimeAte(avBinP,3);
    printf("\n\n");

    return 1;
}
