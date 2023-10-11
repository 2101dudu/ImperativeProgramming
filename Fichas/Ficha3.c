#include <stdio.h>

// 2.

void swapM (int *x, int*y) {
    int z;

    z = *x;
    *x = *y;
    *y = z; 
}


void swap (int v[], int i, int j) {
    int z = v[i];

    v[i] = v[j];
    v[j] = z;
}



int soma (int v[], int N) {
    int i, a = 0;

    for (i=0;i<N;i++) {
        a += v[i];
    }

    return a;
}



void inverteArray (int v[], int N) {
    int i;
    int a = N-1;

    for (i=0;i < N/2;i++,--a) {
        swap (v,i,a);
    } 
}


void inverteArray2 (int v[], int N) {
    int a = N-1;

    for (int i=0;i < N/2;i++,--a) {
        swapM (&v[i],&v[a]);
    } 
}



int maximum (int v[], int N, int *m) {
    int aux=0;
    
    if (N<0) {
        return 1;
    }

    for (int i=0;i<N;i++) {
        if (v[i]>aux) {
            aux=v[i];
        }
    }

    *m=aux;

    return 0;
}


void quadrados (int q[], int N) {

    for (int i=0;i<N;i++) {
        if (i>=1) {
            q[i] = q[i-1] + 2*(i-1) + 1;
        } else {
            q[i] = 0;
        }
            printf ("%d ",q[i]);
    }
}



void pascal (int v[], int N) {
    int aux[N];

    for (int i=0;i<N;i++) {
        for (int j=0;j<=i;j++) {
            if (i<=1) {
                v[j] = 1;
                aux[j] = 1;
            } else if (j == 0 || j == i) {
                v[j] = 1;   
                aux[j] = 1;
            } else {
                v[j] = aux[j-1] + aux[j];
            }
        }

        for (int j=0;j<=i;j++) {
            aux[j] = v[j];  
        }
        
    }

    for (int i=0;i<N;i++) {
        printf("%d ", v[i]);
    }
}




void pascal2 (int v[], int N) {
    int aux[N];

    for (int i=0;i<N;i++) {
        for (int j=0;j<=i;j++) {
            if (i<=1) {
                v[j] = 1;
                aux[j] = 1;
            } else if (j == 0 || j == i) {
                v[j] = 1;   
                aux[j] = 1;
            } else {
                v[j] = aux[j-1] + aux[j];
            }

            printf("%d ", v[j]);

        }

        for (int j=0;j<=i;j++) {
            aux[j] = v[j];  
        }

        putchar ('\n');

    }

}




int main () {
    int x = 1, y = 4, m = 0;
    int v[] = {0,1,2,3,4,5,6};
    int v2[600];

  //  swapM (&x, &y);
  //  swap (v,x,y);

    
   // for (i=0;i<5;i++){
   //     printf("%d", v[i]);
   // }
   //
   // putchar ('\n');

   // printf ("%d \n", soma (v,10));

    //printf("Inverte Array pela função swap: "); 
    //inverteArray (v,6);
    //for (int i=0;i<6;i++){
    //    printf("%d", v[i]);
    //}
    //
    //
    //putchar ('\n');
    //
    //
    //printf("Inverte Array pela função swapM: ");
    //inverteArray2 (v2,6);
    //for (int i=0;i<6;i++){
    //    printf("%d", v2[i]);
    //}
   
    //maximum (v,6,&m);
    //printf ("%d",m);

    //quadrados (v2,6);

    //pascal (v2,6);

    pascal2 (v2,20);
    
    //putchar ('\n');

    return 0;
}

