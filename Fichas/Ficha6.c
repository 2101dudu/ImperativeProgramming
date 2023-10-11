#include <stdio.h>

#define Max 10

typedef struct staticStack {
int sp;
int values [Max];
} STACK, *SStack;


typedef struct dinStack {
int size; 
int sp;
int *values;
} *DStack;





//1.a)

void SinitStack (SStack s) {
    s->sp = 0;
}


//1.a)_2

void SinitStack2 (DStack s) {
    s->sp = 0;
    s->size = 20;
    s->values = malloc(s->size*sizeof(int));
}






//1.b)

int SisEmpty (SStack s) {
    return (s->sp==0);
}





//1.c)  

int Spush (SStack s, int x) {
    if (s->sp >= Max) return 1; 
    else {
        s->values[s->sp]=x;
        s->sp++;
        return 0;
    }
}

//1.c)  

int Spush (DStack s, int x) {
    if (s->sp >= s->size) {
        if (malloc(s->size*sizeof(int)*2) == NULL) return 1;
        int *aux = malloc(s->size*sizeof(int)*2);
        for (int i=0;i<s->size;i++) {
            aux[i] = s->values[i];
        }
        s->size*=2;
        free(s->values);
        s->values = aux; 
    } 
    s->values[s->sp]=x;
    s->sp++;
    return 0;
}





//1.d)

int Spop (SStack s, int *x) {
    if (s->sp-1 >= Max || s->sp==0) return 1;
    else {
        *x=s->values[s->sp-1];
        s->sp--;
        return 0;
    } 
}



//1.e)

int Stop (SStack s, int *x) {
    if (s->sp==0) return 1;
    else {
        *x = s->values[s->sp-1];
        return 0;
    }
}





int main () {
    STACK stack;
    SStack s=&stack;
    int x;
    
    SinitStack (s);
    printf("sp:%d ",s->sp);
    
    printf("O valor lógico é: %d",SisEmpty(s));

    Spush (s, 5);
    Spop (s, &x);



    return 0;
}
