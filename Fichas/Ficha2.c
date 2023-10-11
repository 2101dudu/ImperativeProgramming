#include <stdio.h>

float multInt1 (int n, float m) {
    int r = 0;

    while (n>0) {
        r += m;
        n--;
    }

    return r;
}



float multInt2 (int n, float m) {
    int r = 0;
    int contador = 0;

    while (n>0) {
        if (n%2 == 1) {
            r += m;
            contador++;
        }

        m = m*2;
        n = n/2;
    }
    
    printf ("Número de operações: %d\n",contador);
    return r;
}



int mdc1 (int a, int b) {
    int n;
    int r;

    if (a >= b) {
        n = a;

        while (n>0) {
            if (a%n == 0 && b%n == 0) {
                r = n;
                break;
            }
        n--;

        }

    } else {
        n = b;

        while (n>0) {
            if (b%n == 0 && a%n == 0) {
                r = n;
                break;
            }
        n--;
        
        }

    }

    return r;
}








int main () {

  //  int v = multInt1 (50,4);
  //  int v = multInt2 (81,423);
  //  int v = mdc1 (6,15);  
  //  int v = mdc2 (6,15);   

    printf ("%d\n",v);
    return 0;
}
