#include <stdio.h>

void f (int a) {
    while (a >= 0) {
        putchar ('#');
        a -= 1;
    }

    putchar ('\n');
}




void vertical (int n) {
    int i;
    for (i=0;i<n;i++){
        f (i);
    }
    for (i=(n-2);i>-1;i--){
        f (i);
    }

}


