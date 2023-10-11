#include <stdio.h>
#include <string.h>



//1.1.
int contaVogais (char *s) {
    int contador = 0;
    for (int i=0;s[i]!='\0';i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            contador++;
        } 
    }    
    
    return contador;
}



//1.2. v1
int retiraVogaisRep_v1 (char *s) {
    int contador=0,j=0;
    char aux[strlen(s)];

    for (int i=0;s[i] != '\0';i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            while (s[i] == s[i+1]) {
                contador++;
                i++;
            }
        } 
        aux[j] = s[i]; 
        j++;
    }

    int tamanho = strlen(s);
    for (int k=0;k<tamanho;k++) {
        s[k] = aux[k];
    }

    return contador;

}



//1.3.
int duplicaVogais (char s[]) {
    int contador=0,tamanho=strlen(s);
    for (int i=0;s[i];i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            for (int fim=tamanho;fim>i;fim--) {
                s[fim] = s[fim-1];
            }
            contador++;
            tamanho++;
            i++;
        }
    }
    return contador;
}



//2.1.
int ordenado (int v[], int N) {
    for (int i=0;i<N-1;i++) {
            if (v[i]>v[i+1]) {
                return 0;
            }
    }
    return 1;
}



//2.2.
void merge (int r[], int a[], int b[], int na, int nb) {
    int i=0,j=0,k=0;
    for (;i<na && j<nb;k++) {
        if (a[i]<b[j]) {
            r[k] = a[i];
            i++;
        } else {
            r[k] = b[j];
            j++;
        }
    }
    for (;i<na;i++,k++) {
        r[k] = a[i];
    }
    for (;j<nb;j++,k++) {
        r[k] = b[j];
    }
}



int main() {
    //1.1.
    //char palavra[7] = "EDUARDO";
    //printf("%d\n",contaVogais(palavra));

    //1.2.
    //char palavra[50] = "ESTAAA EE UMA STRINGGI AAAAAAAHAHAHAH";
    //int n = retiraVogaisRep_v1 (palavra);
    //int i=0;
//
    //printf ("Foram retiradas %d vogais: ",n);
    //while (palavra[i]!='\0') {
    //    printf ("%c",palavra[i]);
    //    i++;
    //}

    //1.3.
    //char palavra[50] = "ESTA E UMA STRINGI AAHAHAHAH";
    //int n = duplicaVogais (palavra);
    //printf ("Foram acrescentadas %d vogais: ",n);
    //for (int i=0;palavra[i];i++) {
    //    printf ("%c",palavra[i]);
    //}
    //putchar('\n');

    //2.1.
    //int array[10] = {1,2,3,4,3,4,5,6,9,10};
    //int valor = ordenado (array,10);
    //if (valor) {
    //    printf("O array está ordenado\n");
    //} else {
    //    printf("O array não está ordenado\n");
    //}

    //2.2.
    //int a[9] = {1,2,3,3,4,5,6,7,8}, b[12] = {1,1,1,2,2,4,5,6,7,8,9,9};
    //int r[21];
    //merge (r,a,b,9,12);
    //for (int i=0;i<21;i++) {
    //    printf("%d ",r[i]);
    //}
    //putchar('\n');

    return 0;
}
