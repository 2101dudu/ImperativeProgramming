#include <stdio.h>
#include <math.h>

//1.4

int main3 () {
    int x, y;
    x = 50; y = 100;
    x = x+y; y = x-y; x = x-y;
    printf ("%d %d\n", x, y);

    return 0;
}


//2.1

int main2 () {
    int i;
    for (i = 0; i < 10; i++)
    printf ("Hello World\n");

    return 0;
}


//2 c)

int main1 () {
    int i;
    for (i=0; (i<20) ; i++)
    if (i%2 == 0) putchar ('_');
    else putchar ('#');

    return 0;
}


//2 d)

void f (int n) {
    while (n>0) {
        if (n%2 == 0) putchar ('0');
        else putchar ('1');
        n = n/2;
    }

    putchar ('\n');
}

int maina () {
    float i;
    for (i=0;(i<16);i++)
    f (i);
return 0;
}



//3.1 a)

void quadrado (int n) {
    int i,j;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            putchar ('#');
        }
    putchar ('\n');
    }
     
}



//3.2 

void triangulo (int n) {
    int i,j;
    for (i=0;i<n;i++) {
        if (i%2 == 0)
            for (j=0;j<n;j++) {
                if (j%2 == 0) 
                    putchar ('#');
                else
                    putchar ('_');
            }
        else 
            for (j=0;j<n;j++) {
                if (j%2 == 0) 
                    putchar ('_');
                else
                    putchar ('#');
            }

    putchar ('\n');

    }
    
}



void circulo (int n) {
    int i,j;
    int largura = 2*n + 1;
    int contador = 0;



    for (i=0;i<largura;i+=2){
        for (j=0;j<largura;j++){
            float x = n - i;
            float y = n - j;

            if (sqrt (x*x + y*y) <= n) {
                printf ("#");
                contador++;
            } else {
                printf (" ");
            }
        }
        
        printf ("\n");
    }

    printf ("%d\n", contador);
}


int main () {

  //  quadrado (5);
  //  triangulo (5);
    circulo (500);
    return 0;
}