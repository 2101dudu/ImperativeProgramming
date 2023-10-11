#include <stdio.h>


void f (int a, int n) {

    while (n>0) {
        putchar (' '); 
        n -= 1;
    }

    while (a>0) {
        putchar ('#');
        a -= 1;
    }

    putchar ('\n');
}


void horizontal (int n) {
    int i;
    int b = n;
    for (i=1;i<n*2;i+=2) {
        f(i,b);
        b-=1;
    }

}

