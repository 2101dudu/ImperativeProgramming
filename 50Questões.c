#include <stdio.h>

//gcc -Wall -Wextra -pedantic -O2 50Questões.c -lm

//1.

void maior() {
    int num,aux=0;
    while (1) {
        if (scanf("%d",&num)) {}
        if (num==0) break;
        if (num>aux) {
            aux = num;
        }
    }
    printf("Este é o valor maior: %d\n",aux);
}



//2.

void media() {
    int num,aux=0,total=0;
    while (1) {
        if (scanf("%d",&num)) {}
        if (num==0) break;
        aux++;
        total += num;
    }   
    float media = total/aux;
    printf("Este é o valor da média: %.5f\n",media);
}



//3.

void segundoMaior() {
    int num,aux=0,aux2=0;
    while (1) {
        if (scanf("%d",&num)) {}
        if (num==0) break;
        if (num>aux) {
            aux2 = aux;
            aux = num;
        } else if (num>aux2) {
            aux2 = num;
        }
    }

    printf("Este é o segundo maior valor: %d\n",aux2);

}



//4.

int bitsUm(unsigned int n) {
    int contador=0;

    while (n>0) {
        if (n%2==1) {
            contador++;
        }
        n/=2;
    }
    return contador;
}



//5.

int elevado(int a,int b) {
    int k=a;

    if (b==0) {
        return 1;
    } else if (a==0) {
        return 0;
    } else if (b==1) {
        return a;
    } else if (b>0) {
        for (int i=1;i<b;i++) {
            k*=a;
        }
    } else if (b<0) {
        for (int i=1;i<(-b);i++) {
            k*=a;
        }
        k=1/k;
    }

    return k;
}

int trailingZ (unsigned int n) {
    int contador=0,aux=n;

    while (n>0) {
        contador++;
        n/=2;
    }

    while (aux%(elevado(2,contador))!=0){
        contador--;
    }

    return contador;
}



//6.

int qDig (unsigned int n) {
    int contador=0;
    while (n>0) {
        contador++;
        n=n/10;
    }
    return contador;
}



//7.

char *strcat2 (char s1[], char s2[]) {
    int i,j;
    for (i=0;s1[i]!='\0';i++);
    for (j=0;s2[j]!='\0';j++) {
        s1[i+j] = s2[j];
    }
    s1[i+j] = '\0';

    return s1;
}



//8.

char *strcpy2 (char *dest, char source[]) {
    int i;
    for (i=0;source[i]!='\0';i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
    return dest;
}



//9.

int strcmp2 (char s1[], char s2[]) {
    int i;
    for (i=0;s1[i] && s1[i]==s2[i];i++);
    return s1[i]-s2[i];
}   



//10.

char *strstr2 (char s1[], char s2[]) {
    for (int i=0;s1[i];i++) {
        int flag = 1;
        for (int j=0;s2[j] && flag;j++) {
            if (s1[i+j] != s2[j]) {
                flag = 0;
            }
        }
        if (flag) {
            return s1+i;
        } 
    }
    return NULL;
}



//11.

void strrev (char s[]) {
    int i;
    for (i=0;s[i];i++);
    char aux[i];
    for (int j=i-1,w=0;j>=0;j--,w++) {
        aux[w] = s[j];
    }
    for (int k=0;aux[k];k++) {
        s[k] = aux[k];
    }
}



//12.

void strnoV (char s[]) {
    int i;
    for (i=0;s[i];i++);
    char aux[i];
    int w=0;
    for (int j=0;j<i;j++) {
        if (s[j]!='A' && s[j]!='E' && s[j]!='I' && s[j]!='O' && s[j]!='U' && s[j]!='a' && s[j]!='e' && s[j]!='i' && s[j]!='o' && s[j]!='u') {
            aux[w] = s[j];
            w++;
        }
    }
    aux[w] = '\0';
    int k=0;
    for (;aux[k];k++) {
        s[k] = aux[k];
    }
    s[k] = '\0';
}



//13.

void truncW (char t[], int n) {
    int contador=1,j;
    for (j=0;t[j];j++) {
        if (t[j]==' ') {
            contador++;
        }
    }

    char aux[contador][j];
    int f=0,k=0;
    for (int i=0;t[i];i++) {
        if (t[i]!=' ' && t[i] != '\n') {
            aux[f][k] = t[i];
            k++;
        } else {
            f++;
            k=0;
        }
    }

    int d=0;
    for (int w=0;w<contador;w++,d++) {
        for (int m=0;m<n && aux[w][m];m++,d++) {
            t[d] = aux[w][m]; 
        }
        t[d] = ' ';
    }
    t[d] = '\0';
}



//14.

char charMaisfreq (char s[]) {
    if (!s[0]) return 0;
    int aux=0,valorIndice=0;
    for (int i=0;s[i];i++) {
        int contador = 0;
        for (int j=i;j<s[i];j++) {
            if (s[i] == s[j]) {
                contador++;
            }
        }
        if (contador>aux) {
            aux = contador;
            valorIndice=i;
        }
    }
    return s[valorIndice];
}



//15.

int iguaisConsecutivos (char s[]) {
    int aux=0;
    for (int i=0;s[i];i++) {
        int contador=0,flag=1;
        for (int j=i;s[j] && flag;j++) {
            if (s[i]!=s[j]) {
                flag = 0;
            } else {
                contador++;
            }
        }
        if (contador>aux) {
            aux = contador;
        }
    }
    return aux;
}



//16.

int difConsecutivos (char s[]) {
    int aux=0,contador=1;
    for (int i=0;s[i+1];i++) {
        if (s[i]!=s[i+1]) {
            contador++;
        } else {
            contador=1;
        }
        if (contador>aux) {
            aux = contador;
        }
    }
    return aux;
}



//17.

int maiorPrefixo (char s1[], char s2[]) {
    int i;
    for (i=0;s1[i]==s2[i];i++);
    return i;
}



//18.

int maiorSufixo (char s1[], char s2[]) {
    int tamanho1,tamanho2,i=0;
    for (tamanho1=0;s1[tamanho1+1];tamanho1++);
    for (tamanho2=0;s2[tamanho2+1];tamanho2++);
    for (;tamanho1>=0 && tamanho2>=0 && s1[tamanho1]==s2[tamanho2];tamanho1--,tamanho2--,i++);
    return i;
}



//19.

int sufPref (char s1[], char s2[]) {
    int aux=0;
    for (int i=0;s1[i];i++) {
        int j=i;
        int contador=0;
        for (int w=0;s1[j] && s2[w];j++,w++) {
            if(s1[j]==s2[w]) {
                contador++;
            } else {
                contador=0;
            }
        }
        if(contador>aux && !s1[j]) {
            aux=contador;
        }
    }
    return aux;
}



//20.

int contaPal (char s[]) {
    int contador=1;
    for (int i=0;s[i];i++) {
        if (s[i]==' ' && s[i+1]!=' ' && s[i+1]!='\0') {
                contador++;
        }
    }
    return contador;
}



//21.

int contaVogais (char s[]) {
    int contador=0;
    for (int i=0;s[i];i++) {
        if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
            contador++;
        }
    }
    return contador;
}



//22.

int contida (char a[], char b[]) {
    for (int i=0;a[i];i++) {
        int flag=0;
        for (int j=0;b[j] && !flag;j++) {
            if (a[i]==b[j]) {
                flag=1;
            } 
        }
        if (!flag) return 0;
    }
    return 1;
}



//23.

int palindorome (char s[]) {
    int i=0,flag=1;
    for (;s[i];i++);
    for (int w=0,j=i-1;j>=i/2 && flag;j--,w++) {
        if (s[w]!=s[j]) {
            flag = 0;
        }
    }
    return flag;
}



//24.

int remRep (char x[]) {
    char j=0,k=0;
    for (;x[k];k++);
    char aux[k];
    for (int i=0;x[i];i++) {
        if (x[i]!=x[i+1]) {
            aux[j] = x[i];
            j++;
        }
    }
    int w=0;
    for (;aux[w];w++) {
        x[w] = aux[w];
    }
    x[w] = '\0';
    return j+1;
}



//25.

int limpaEspacos (char t[]) {
    int j=0,k=0;
    for (;t[j];j++);
    char aux[j];
    for (int i=0;t[i+1];i++) {
        if (t[i]==' ' && t[i+1]==' ') {} 
        else {
            aux[k]=t[i];
            k++;
        }
    }
    aux[k] = '\0';
    int l=0;
    for (;aux[l];l++) {
        t[l] = aux[l];
    }
    t[l] = '\0';
    return k+1;
}


//26.

void insere (int v[], int N, int x) {
    int j=0,i=0,flag=1,w=0;
    for (;v[j];j++);
    int aux[j];
    for (;i<N && flag;i++) {
        if (x<v[i]) {
            for (int k=i;k<j;k++,w++) {
                aux[w] = v[k];
            }
            v[i] = x;
            flag = 0;
        }
    }
    for (int l=0;l<w;l++,i++) {
        v[i] = aux[l];
    }
}



//27.

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



//28.

int crescente (int a[], int i, int j) {
    int flag = 1;
    for (;i<=j && flag;i++) {
        for (int w=i+1;w<=j && flag;w++) {
            if (a[i]>a[w]) {
                flag = 0;
            }
        } 
    }
    return flag;
}



//29.

int retiraNeg (int v[], int N) {
    int aux[N],j=0;
    for (int i=0;i<N;i++) {
        if (v[i]>=0) {
            aux[j] = v[i];
            j++;
        } 
    }
    for (int w=0;w<j;w++) {
        v[w] = aux[w];
    }
    return j;
}



//30.

int menosFreq (int v[], int N) {
    int aux=N,valorIndice;
    for (int i=0;i<N;i++) {
        int contador=1,flag=1,n=i;
        for (int j=i+1;j<N && flag;j++) {
            if (v[i] == v[j]) {
                contador++;
            } else {
                flag = 0;
                i=j-1;
            }
        }
        if (contador<aux) {
            aux = contador;
            valorIndice = n;
        }
    }
    return valorIndice;
}



//31.

int maisFreq (int v[], int N) {
    int aux=0,valorIndice;
    for (int i=0;i<N;i++) {
        int flag=1,contador=0,n=i;
        for (int j=i+1;j<N && flag;j++) {
            if (v[i] == v[j]) {
                contador++;
            } else {
                flag=0;
                i=j-1;
            }
        }
        if (contador>aux) {
            aux = contador;
            valorIndice = n;
        }
    }
    return valorIndice;
}



//32.

int maxCresc (int v[], int N) {
    int aux=0,contador=1;
    for (int i=0;i<N-1;i++) {
        if (v[i]<v[i+1]) {
            contador++;
        } else {
            contador=1;
        }
        if (contador>aux) {
            aux = contador;
        }
    }
    return aux;
}



//33.

int elimRep (int v[], int n) {
    int aux[n],w=0;
    for (int i=0;i<n;i++) {
        int flag=1;
        for (int j=0;j<w && flag;j++) {
            if (aux[j] == v[i]) {
                flag = 0;
            }
        }
        if (flag) {
            aux[w] = v[i];
            w++;
        }
    }
    for (int k=0;k<w;k++) {
        v[k] = aux[k];
    }
    return w;
}



//34.

int elimRepOrd (int v[], int n) {
    int aux[n],j=0;
    v[n] = v[0];
    for (int i=0;i<n;i++) {
        if (v[i] != v[i+1]) {
            aux[j] = v[i];
            j++;
        }
    }
    for (int k=0;k<j;k++) {
        v[k] = aux[k];
    }
    return j;
}



//35.

int comunsOrd (int a[], int na, int b[], int nb) {
    int valorIndice=0,contador=0;
    for (int i=0;i<na;i++) {
        int flag = 1;
        for (int j=valorIndice;j<nb && flag;j++) {
            if (a[i] == b[j]) {
                contador++;
                valorIndice=j+1;
                flag = 0;
            }
        }
    }
    return contador;
}



//36.

int comuns (int a[], int na, int b[], int nb) {
    int aux[nb],contador=0;
    for (int i=0;i<nb;i++) {
        aux[i] = i;
    }
    for (int j=0;j<na;j++) {
        int flag=0,flag2=0;
        for (int l=0;l<nb && !flag2;l++) {
            int k=0;
            for (;k<nb && !flag;k++) {
                if (aux[k]==l) {
                    flag = 1;
                }
            }
            if (flag && a[j] == b[l]) {
                contador++;
                flag2=1;
                int h=0;
                for (int m=0;m<nb;m++) {
                    if (aux[m]!=l) {
                        aux[h] = aux[m];
                        h++;
                    }
                }
            }
        }
    }
    return contador;
}



//37.

int minInd (int v[], int n) {
    int guardaIndice;
    int valorMenor = v[0];
    for (int i=0;i<n;i++) {
        if (v[i]<valorMenor) {
            guardaIndice = i;
            valorMenor = v[i];
        }
    }
    return guardaIndice;
}



//38.

void somasAc (int v[], int Ac [], int N) {
    int contador=0;
    for (int i=0;i<N;i++) {
        contador+=v[i];
        Ac[i]=contador;
    }
}



//42.

int unionSet (int N, int v1[N], int v2[N], int r[N]) {
    for (int i=0;i<N;i++) {
        if (v1[i] == 1 || v2[i] == 1) {
            r[i] = 1;
        } else {
            r[i] = 0;
        }
    }
    return 0;
} 



//43.

int intersectSet (int N, int v1[N], int v2[N],int r[N]) {
    for (int i=0;i<N;i++) {
        if (v1[i] == 1 && v2[i] == 1) {
            r[i] = 1;
        } else {
            r[i] = 0;
        }
    }
    return 0;
}



//44.

int intersectMset (int N, int v1[N], int v2[N], int r[N]) {
    for (int i=0;i<N;i++) {
        if (v1[i]<v2[i]) {
            r[i] = v1[i];
        } else {
            r[i] = v2[i];
        }
    }
    return 0;
}



//45.

int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
    for (int i=0;i<N;i++) {
        if (v1[i]>v2[i]) {
            r[i] = v1[i];
        } else {
            r[i] = v2[i];
        }
    }
    return 0;
}



//46.

int cardinalMSet (int N, int v[N]) {
    int contador=0;
    for (int i=0;i<N;i++) {
        contador+=v[i];
    }
    return contador;
}

int main() {
    //1.
    //maior();
    
    //2.
    //media();

    //3.
    //segundoMaior();

    //4.
    //int n = bitsUm(7);
    //printf("Este é o número de 1s: %d\n",n);

    //5.
    //int l = 6;
    //int n = trailingZ(l);
    //printf("Este é o número de 0s seguidos no final da representação em binário do numero %d: %d\n",l,n);

    //6.
    //int n = 440;
    //printf("Este é o número de dígitos necessários para escrever %d na base 10: %d\n",n,qDig(n));
    
    //7.
    //char s1[20] = "TESTEATESTEB",s2[20] = "helloworld!";
    //strcat2(s1,s2);
    //for (int i=0;s1[i]!='\0';i++) {
    //    printf("%c",s1[i]);
    //}
    //putchar('\n');

    //8.
    //char s1[2],s2[20] = "helloworld!";
    //strcpy2 (s1,s2);
    //for (int i=0;s1[i]!='\0';i++) {
    //    printf("%c",s1[i]); 
    //}
    //putchar('\n');

    //9.
    //char a[20] = "aaaa", b[20] = "z";
    //int valor = strcmp2 (a,b);
    //printf("Valor:%d\n",valor);

    //10.
    //char a[20] = "PROGRAMAÇÃO", b[20] = "ABCDE";
    //printf("%s\n",strstr2(a,b));

    //11.
    //char a[20] = "ABCDEFGHIJ";
    //strrev(a);
    //printf("%s\n",a);

    //12.
    //char a[20] = "EEEDUUAAARRRDOO";
    //strnoV(a);
    //printf("%s\n",a);
     
    //13.
    //char a[40] = "PROGRAMACAOOO IMPERATIVAHAHAH TESTE"; 
    //truncW (a,4);
    //printf("%s\n",a);

    //14.
    //char a[40] = "AAABBBBBBBCCCCC";
    //printf("%c\n",charMaisfreq(a));

    //15.
    //char a[40] = "ABBBBBBBCCCCCAAAACCCCCCCCCCC";
    //printf("%d\n",iguaisConsecutivos(a));

    //16.
    //char a[40] = "AAEDUARRDEFGHIJOOABCDEFGHI";
    //printf("%d\n",difConsecutivos(a));

    //17.
    //char a[20] = "BANDEIRA", b[20] = "BANANA";
    //printf("%d\n",maiorPrefixo (a,b));

    //18.
    //char a[20] = "ANDORRA", b[20] = "PORRA";
    //printf("%d\n",maiorSufixo (a,b));

    //19.
    //char a[20] = "AAAA", b[20] = "AAAA";
    //printf("%d\n",sufPref (a,b));

    //20.
    //char a[40] = "OLA    ISTO É UM TESTE ";
    //printf("%d\n",contaPal (a));

    //21.
    //char a[40] = "ALEMANHAAUOI";
    //printf("%d\n",contaVogais (a));

    //22.
    //char a[20] = "Braga", b[40] = "Bracara augusta";
    //printf("%d\n",contida(a,b));

    //23.
    //char a[20] = "TACOCAT";
    //printf("%d\n",palindorome(a));

    //24.
    //char a[20] = "aaaabbbbaaaaabbb";
    //rintf("%d   %s\n",remRep(a),a);

    //25.
    //char a[40] = "ISTO    E UM    TESTE  ";
    //printf("%d    %s\n",limpaEspacos(a),a);

    //26.
    //int a[30] = {1,2,3,4,5,6,7,7,8,9};
    //insere (a,7,3);
    //for (int i=0;a[i];i++) {
    //    printf("%d\n",a[i]);
    //}

    //27.
    //int a[20] = {1,3,5,7,9}, b[20] = {0,2,4,6,8,8,10,12,24},r[10];
    //int na=5,nb=9;
    //merge (r,a,b,na,nb);
    //for (int i=0;i<na+nb;i++) {
    //    printf("%d ",r[i]);
    //}
    //putchar('\n');

    //28.
    //int a[20] = {1,2,3,4,56,6,7,8,9,10};
    //printf("%d\n",crescente(a,9,5));

    //29.
    //int a[20] = {1,2,-3,4,-56,-6,-7,-8,9,10};
    //int valor = retiraNeg (a,10);
    //printf("Número retirado: %d\n",valor);
    //for (int i=0;i<valor;i++) {
    //    printf("%d ",a[i]);
    //}
    //putchar('\n');

    //30.
    //int a[20] = {1,1,1,1,1,2,2,3,3,4,5,6,7,8,8,8,9};
    //printf("%d\n",menosFreq(a,17));

    //31.
    //int a[20] = {1,1,1,2,2,2,2,3,3,4,5,6,8,8,8,8,9};
    //printf("%d\n",maisFreq(a,17));

    //32.
    //int a[20] = {1,2,3,4,5,0,2,3,4,34,23,12,13,14,15,16};
    //printf("%d\n",maxCresc(a,17));

    //33.
    //int a[10] = {3,3,3,6,6,0,0,1,3};
    //int valor = elimRep (a,9);
    //printf("Número retirado: %d\n",valor);
    //for (int i=0;i<valor;i++) {
    //    printf("%d ",a[i]);
    //}
    //putchar('\n');

    //34.
    //int a[20] = {1,1,1,2,2,2,2,3,3,4,5,6,8,8,8,8,9};
    //int valor = elimRepOrd (a,17);
    //printf("Número de elementos no novo array: %d\n",valor);
    //for (int i=0;i<valor;i++) {
    //    printf("%d ",a[i]);
    //}
    //putchar('\n');

    //35.
    //int a[20] = {1,1,1,2,2,2,2,3,3,4,5,6,8,8,8,8,9}, b[20] = {1,2,3,4,5,6,7,7,8,9};
    //printf("Número de elementos iguais: %d\n",comunsOrd(a,17,b,10));

    //36.
    //int a[6] = {2,7,4,1,6,9}, b[5] = {6,5,8,2,9};
    //printf("Número de elementos iguais: %d\n",comuns(a,6,b,5));

    //37.
    //int a[6] = {5,3,6,1,4,2};
    //printf ("%d\n",minInd(a,6));

    //38.
    //int v[5] = {1, 2, 3, 4, 5};
    //int Ac[5];
    //somasAc(v, Ac, 5);
    //for (int i=0;i<5;i++) {
    //    printf("%d ",Ac[i]);
    //}
    //putchar('\n');
    
    //42.
    //int v1[8] = {0, 1, 0, 0, 1, 0, 0, 1}, v2[8] = {1, 0, 0, 1, 1, 0, 1, 0}, r[8];
    //unionSet (8,v1,v2,r);
    //printf("Resultado do array: ");
    //for (int i=0;i<8;i++) {
    //    printf("%d ",r[i]);
    //}
    //putchar('\n');

    //43.
    //int v1[8] = {0, 1, 0, 0, 1, 0, 0, 1}, v2[8] = {1, 0, 0, 1, 1, 0, 1, 0}, r[8];
    //intersectSet (8,v1,v2,r);
    //printf("Resultado do array: ");
    //for (int i=0;i<8;i++) {
    //    printf("%d ",r[i]);
    //}
    //putchar('\n');

    //44.
    //int v1[8] = {0, 2, 0, 0, 1, 0, 0, 3}, v2[8] = {1, 1, 3, 0, 0, 1, 0, 2}, r[8];
    //intersectMset (8,v1,v2,r);
    //printf("Resultado do array: ");
    //for (int i=0;i<8;i++) {
    //    printf("%d ",r[i]);
    //}
    //putchar('\n');

    //45.
    //int v1[8] = {0, 2, 0, 0, 1, 0, 0, 3}, v2[8] = {1, 1, 3, 0, 0, 1, 0, 2}, r[8];
    //unionMSet(8, v1, v2, r);   
    //printf("Resultado do array: ");
    //for (int i  =0;i<8;i++) {
    //    printf("%d ",r[i]);
    //}
    //putchar('\n');

    //46.
    //int v[8] = {0, 2, 0, 0, 1, 0, 0, 3};
    //int valor = cardinalMSet(8, v);
    //printf ("Número de elementos: %d\n",valor);



    return 0;
}
