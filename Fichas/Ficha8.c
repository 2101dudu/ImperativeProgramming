#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
int valor;
struct slist *prox;
} *LInt;


typedef LInt Stack;


typedef struct {
    LInt inicio,fim;
} Queue;


typedef LInt QueueC;


typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList front, back;
} Deque;



LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; 
        r->prox = xs;
    }
    return r;
}




//1.

void initStack (Stack *s) {
    *s = NULL;
}


int SisEmpty (Stack s) {
    return (s != NULL);
}


int push (Stack *s, int x) {
    *s = newLInt(x,*s);
    return ((*s)->valor);
}


int pop (Stack *s, int *x) {
    if (*s == NULL) return -1;
    Stack aux = *s;
    *x = (*s)->valor;
    *s = (*s)->prox;
    free(aux);
    return 0;
}


int top (Stack s, int *x) {
    if (s == NULL) return -1;
    *x = s->valor;
    return 0;
}




//2.

void initQueue (Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q) {
    return (q.inicio != NULL);
}


int enqueue (Queue *q, int x) {
    LInt aux = newLInt (x,NULL);
    if (q->inicio == NULL) {
        q->inicio = aux;
        q->fim = aux;
    } else {
        q->fim->prox = aux;
        q->fim = aux;
    }
    return 0;
}


int dequeue (Queue *q, int *x) {
    if (q->inicio == NULL) return -1;
    LInt aux = q->inicio;
    *x = q->inicio->valor;
    q->inicio = q->inicio->prox;
    free(aux);
    return 0;
}


int front (Queue q, int *x) {
    if (q.inicio == NULL) return -1;
    *x = q.inicio->valor;
    return 0;
}




//3.

void initQueueC (QueueC *q) {
    *q = NULL;
}


int QisEmptyC (QueueC q) {
    return (q != NULL);
}


int enqueueC (QueueC *q, int x) {
    if (*q == NULL) {
        (*q)->valor = x; 
        (*q)->prox = *q;
    } else {
        (*q)->prox = newLInt (x,(*q)->prox);
        (*q) = (*q)->prox;
    }
    return 0;
}








int dequeueC (QueueC *q, int *x) {
    if (*q == NULL) return -1;
    if ((*q)->prox == *q) {
        *x = (*q)->valor;
        free(*q);
    } else {
        QueueC aux = (*q)->prox;
        *x = aux->valor;
        (*q)->prox = aux->prox;
        free(aux);
    }
    return 0;
}


int dequeueC2 (QueueC *q, int *x) {
    if (*q == NULL) return -1;
    LInt aux = NULL;
    if ((*q)->prox == *q) {
        aux = *q;
        *q = NULL;
    } else {
        aux = (*q)->prox;
        (*q)->prox = aux->prox;
    }
    *x = temp->valor;
    free(aux);
    return 0;
}











int frontC (QueueC q, int *x) {
    if (q == NULL) return -1;
    *x = q->valor;
    return 0;
}




//4.

void initDeque (Deque *q) {
    q->front = NULL;
    q->back = NULL;
}


int DisEmpty (Deque q) {
    return (q.front != NULL);
}


int pushBack (Deque *q, int x) {
    DList aux = malloc (sizeof(DList));
    aux->valor = x;
    aux->prox = NULL;
    aux->ant = q->back;
    if (q->front == NULL) q->front = aux;
    else q->back->prox = aux;
    q->back = aux;
    return 0;
}


int pushFront (Deque *q, int x) {
    DList aux = malloc (sizeof(DList));
    aux->valor = x;
    aux->prox = q->front;
    aux->ant = NULL;
    if (q->front == NULL) q->back = aux;
    else q->front->ant = aux;
    q->front = aux;
    return 0;
}


int popBack (Deque *q, int *x) {
    if (q->front == NULL) return -1;
    DList aux = q->back;
    *x = aux->valor;
    q->back = aux->ant;
    free (aux);
    if (q->back == NULL) q->front = NULL;
    else q->back->prox = NULL;
    return 0;
}


int popFront (Deque *q, int *x) {
    if (q->front == NULL) return -1;
    DList aux = q->front;
    *x = aux->valor;
    q->front = aux->prox;
    free (aux);
    if (q->front == NULL) q->back = NULL;
    else q->front->ant = NULL;
    return 0;
}


int popMax (Deque *q, int *x) {

}


int back (Deque q, int *x) {
    if (q.front == NULL) return -1;
    *x = q.back->valor;
    return 0;
}

int front (Deque q, int *x) {
    if (q.front == NULL) return -1;
    *x = q.front->valor;
    return 0;
}






int main() {
    //LINT

    LInt t = newLInt(3,NULL);
    LInt m = newLInt(4,t);
    LInt s = newLInt(5,m);


    //ou

    LInt s2 = newLInt(5,NULL);
    s2->prox = newLInt(4,NULL);
    s2->prox->prox = newLInt(3,NULL);
    


    //QUEUE

    Queue q;
    q.inicio = newLInt (3,NULL);
    q.inicio->prox = newLInt (4,NULL);
    q.inicio->prox->prox = newLInt (5,NULL);

    q.fim = newLInt(5,NULL);


    //QUEUEC ????????

    LInt a1 = newLInt(1,NULL);
    LInt a2 = newLInt(2,a1);
    LInt a3 = newLInt(3,a2);
    a1->prox = a3;

    QueueC *qC = &a3;


    //DQUEUE








    
    //1.
    //initStack (&s);
    //printf("Primeiro argumento: %d\n",s->valor);
    
    //int valor = SisEmpty (s);
    //printf("Valor: %d\n",valor);

    
    //push (&s,10);
    //printf("Primeiro argumento: %d\n",s->valor);

    //int x;
    //pop(&s,&x);
    //printf("Argumento retirado: %d\n",x);




    //2.
    //initQueue (&q);
    //printf("Primeiro valor: %d\n",q.inicio->valor);

    //enqueue (&q,10);
    //printf("Valor adicionado: %d\n",q.fim->valor);

    //int x;
    //dequeue (&q,&x);
    //printf("Último valor: %d    Valor retirado: %d\n",q.fim->valor,x);

    //int x;
    //front(q,&x);
    //pritnf("Primeiro valor: %d\n",x);


    

    //3.



    //4.







    return 0;
}

