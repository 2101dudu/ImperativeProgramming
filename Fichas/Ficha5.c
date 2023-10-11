#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;



//1.

int nota (Aluno a) {
    float final = 0, contador=0;
    final = a.teste*0.8;

    for (int i=0;i<6;i++) {
        contador+=a.miniT[i];
    }
    final += (contador/6)*0.2*10;

    return final;
}



//2.

int procuraNum (int num, Aluno t[], int N) {
    for (int i=0;i<N;i++) {
        if (t[i].numero == num) {
            return i;
        }
        if (t[i].numero > num) {
            return -1;
        }
    }
    return -1;
}



//3.

void ordenaPorNum (Aluno t[], int N) {
    for (int i=N;i>0;i--) {
        for (int j=0;j<i;j++) {
            if (t[j].numero > t[j+1].numero) {
                Aluno aux = t[j];
                t[j] = t[j+1];
                t[j+1] = aux;
            }
        }
    }
}



//4.

void criaIndPorNum (Aluno t[], int N, int ind[]) {
    for (int k=0;k<N;k++) {
        ind[k] = k;
    }
    for (int i=0;i<N;i++) {
        for (int j=i;j<N;j++) {
            if (t[ind[i]].numero > t[ind[j]].numero) {
                int aux = ind[j];
                ind[j] = ind[i];
                ind[i] = aux;
            }
        }
    }
}



//5.

void imprimeTurma (int ind[], Aluno t[], int N) {
    for (int i=0;i<N;i++) {
        printf("Numero: %d  |  Nome: %s  |  Nota: %d\n",t[ind[i]].numero,t[ind[i]].nome,nota(t[ind[i]]));
    }
}



//6.

int procuraNomeInd (int num, Aluno t[], int ind[], int N) {
    for (int i=0;i<N;i++) {
        if (num == t[ind[i]].numero) {
            return ind[i];
        }
        if (num < t[ind[i]].numero) {
            return -1;
        }
    }
    return -1;
}



//7.

void criaIndPorNome (Aluno t[], int N, int ind[]) {
    for (int k=0;k<N;k++) {
        ind[k] = k;
    }
    for (int i=0;i<N;i++) {
        for (int j=i;j<N;j++) {
            if (strcmp(t[ind[i]].nome,t[ind[j]].nome) > 0) {
                int aux = ind[j];
                ind[j] = ind[i];
                ind[i] = aux;
            }
        }
    }
}






int main () {
    Aluno Eduardo = {104353,"Eduardo de Oliveira Sousa Faria",{2,2,2,2,2,2},18};
    Aluno array_alunos[4] = {{4444, "Andre", {2,1,0,2,2,2}, 10.5},{2222, "Joana", {2,2,2,1,0,0}, 14.5},{7777, "Maria", {2,2,2,2,2,1}, 18.5},{3333, "Paulo", {0,0,2,2,2,1}, 8.7}};
    int ind[4];

    //printf("Nota final: %d\n",nota(Eduardo));

    //printf("O aluno %s encontra-se no índice: %d\n",Eduardo.nome,procuraNum(Eduardo.numero,array_alunos,3));
   
    //ordenaPorNum (array_alunos, 4);
    //for (int i=0;i<4;i++) {
    //    printf("%s -- ",array_alunos[i].nome);
    //}
    //putchar('\n');

    //criaIndPorNum (array_alunos, 4,ind);
    //for (int i=0;i<4;i++) {
    //    printf("%d -- ",ind[i]);
    //}
    //putchar('\n');

    //criaIndPorNum (array_alunos, 4,ind);
    //imprimeTurma(ind,array_alunos,4);

    //criaIndPorNum (array_alunos, 4,ind);
    //printf("O aluno %s encontra-se no índice: %d\n",Eduardo.nome,procuraNomeInd(Eduardo.numero,array_alunos,ind,4));

    //criaIndPorNome   (array_alunos, 4,ind);
    //for (int i=0;i<4;i++) {
    //    printf("Numero: %d  |  Nome: %s  |  Nota: %d\n",array_alunos[ind[i]].numero,array_alunos[ind[i]].nome,nota(array_alunos[ind[i]]));
    //}
    




    return 0;
}
