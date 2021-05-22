#include <stdlib.h>
typedef struct lligada {
    int valor;
    struct lligada *prox;
} * LInt;

int length(LInt l) {
    int i;
    for (i = 0; l; l = l->prox, i++)
        ;
    return i;
}

void freeL(LInt l) {
    LInt temp;
    while (l) {
        temp = l;
        l = l->prox;
        free(temp);
    }
}

LInt reverseL(LInt l) {
    LInt ant = NULL;
    LInt next;
    while (l) {
        next = l->prox;
        l->prox = ant;
        ant = l;
        l = next;
    }
    return ant;
}

void insertOrd(LInt *l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    while (*l && (*l)->valor < x) l = &((*l)->prox);
    new->prox = *l;
    *l = new;
}

int removeOneOrd(LInt *l, int x) {
    while (*l && (*l)->valor != x) l = &((*l)->prox);
    if (*l)
        *l = (*l)->prox;
    else
        return 1;
    return 0;
}

void merge(LInt *r, LInt a, LInt b) {
    while (a || b) {
        if (!b || (a && a->valor < b->valor)) {
            *r = a;
            a = a->prox;
        } else {
            *r = b;
            b = b->prox;
        }
        r = &((*r)->prox);
    }
}

void splitQS(LInt l, int x, LInt *mx, LInt *Mx) {
    while (l) {
        if (l->valor < x) {
            *mx = l;
            mx = &((*mx)->prox);
        } else {
            *Mx = l;
            Mx = &((*Mx)->prox);
        }
        l = l->prox;
    }
    (*mx) = NULL;
    (*Mx) = NULL;
}

LInt parteAmeio(LInt *l) {
    int tam = 0;
    LInt a;
    for (a = *l; a; a = a->prox, tam++)
        ;
    tam /= 2;
    if (tam == 0) return NULL;
    LInt inicio = *l;

    LInt *pt;
    for (pt = l; *pt && tam; pt = &((*pt)->prox), tam--)
        ;

    *l = *pt;
    *pt = NULL;
    return inicio;
}

int removeAll(LInt *l, int x) {
    int r = 0;
    while (*l) {
        if ((*l)->valor == x) {
            *l = (*l)->prox;
            r++;
        } else
            l = &((*l)->prox);
    }
    return r;
}

int removeDups(LInt *l) {
    while (*l) {
        int x = (*l)->valor;
        LInt *pt = &((*l)->prox);
        while (*pt)
            if ((*pt)->valor == x)
                *pt = (*pt)->prox;
            else
                pt = &((*pt)->prox);
        l = &((*l)->prox);
    }
}

int removeMaiorL(LInt *l) {
    int max = (*l)->valor;
    LInt *pt = l;
    l = &((*l)->prox);
    while (*l) {
        if ((*l)->valor > max) max = (*l)->valor;
        l = &((*l)->prox);
    }
    while (*pt && (*pt)->valor != max) pt = &((*pt)->prox);
    if (*pt) *pt = (*pt)->prox;
    return max;
}

void init(LInt *l) {
    while (*l && (*l)->prox) l = &((*l)->prox);
    if (*l) *l = (*l)->prox;
}

void appendL(LInt *l, int x) {
    while (*l) l = &((*l)->prox);
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    *l = new;
}
void concatL(LInt *a, LInt b) {
    while (*a) a = &((*a)->prox);
    *a = b;
}

LInt cloneL(LInt l) {
    if (!l) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = l->valor;
    new->prox = cloneL(l->prox);
    return new;
}

LInt cloneRev(LInt l) {
    LInt r, new;
    r = NULL;
    while (l) {
        new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = r;
        r = new;
    }
    return r;
}

int maximo(LInt l) {
    int max = l->valor;
    l = l->prox;
    while (l) {
        if (l->valor > max) max = l->valor;
        l = l->prox;
    }
    return max;
}

int take(int n, LInt *l) {
    int len = 0;
    while (*l && len < n) {
        l = &((*l)->prox);
        len++;
    }
    LInt pt = *l;
    while (len == n && pt) {
        LInt temp = pt;
        pt = pt->prox;
        free(temp);
    }
    *l = NULL;
    return len;
}

int drop(int n, LInt *l) {
    int r = 0;
    while (*l && r < n) {
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
        r++;
    }
    return r;
}

LInt NForward(LInt l, int N) {
    while (N) {
        l = l->prox;
        N--;
    }
    return l;
}

int listToArray(LInt l, int v[], int N) {
    int i;
    for (i = 0; i < N && l; l = l->prox, i++)
        v[i] = l->valor;
    return i;
}

LInt arrayToList(int v[], int N) {
    int i;
    LInt l = NULL;
    LInt new;
    for (i = N - 1; i >= 0; i--) {
        new = malloc(sizeof(struct lligada));
        new->valor = v[i];
        new->prox = l;
        l = new;
    }
    return l;
}

LInt somasAcL(LInt l) {
    LInt *r;
    LInt pt = *r;

    int acc = 0;
    while (l) {
        acc += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = acc;
        new->prox = NULL;
        pt = new;
        pt = pt->prox;
        l = l->prox;
    }
    return *r;
}
void remreps(LInt l) {
    if (!l) return;
    LInt temp;
    while (l->prox) {
        if (l->valor == l->prox->valor) {
            temp = l->prox;
            l->prox = temp->prox;
            free(temp);
        } else
            l = l->prox;
    }
}

LInt rotateL(LInt l) {
    if (!l || !l->prox) return l;
    int val = l->valor;
    LInt last = l;
    l = l->prox;
    last->prox = NULL;
    LInt pt;
    for (pt = l; pt && pt->prox; pt = pt->prox)
        ;
    if (pt)
        pt->prox = last;
    else
        l->prox = last;
    return l;
}

LInt parte(LInt l) {
    LInt *odd = &l;

    LInt res = NULL;
    int is_odd = 1;
    while (*odd) {
        if (is_odd)
            odd = &((*odd)->prox);
        else {
            LInt new = malloc(sizeof(struct lligada));
            new->valor = (*odd)->valor;
            new->prox = NULL;
            LInt *pt;
            for (pt = &res; *pt; pt = &((*pt)->prox))
                ;
            *pt = new;
            *odd = (*odd)->prox;
        }
        is_odd = is_odd ? 0 : 1;
    }
    return res;
}

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

int altura(ABin a) {
    if (a == NULL) return 0;
    int esq = 1 + altura(a->esq);
    int dir = 1 + altura(a->dir);
    return esq > dir ? esq : dir;
}

ABin cloneAB(ABin a) {
    if (a == NULL) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->dir = cloneAB(a->dir);
    new->esq = cloneAB(a->esq);
    return new;
}
void mirror(ABin *a) {
    if (*a == NULL) return;
    ABin tmp = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = tmp;
    mirror(&((*a)->dir));
    mirror(&((*a)->esq));
}

void inorder(ABin a, LInt *l) {
    if (!a) return;
    inorder(a->dir, l);
    LInt new = malloc(sizeof(struct lligada));
    new->valor = a->valor;
    new->prox = *l;
    *l = new;
    inorder(a->esq, l);
}

void preorder(ABin a, LInt *l) {
    *l = NULL;
    preorderaux(a, l);
}
void preorder_aux(ABin a, LInt *l) {
    if (a) {
        preorder_aux(a->dir, l);
        preorder_aux(a->esq, l);
        LInt nodo = malloc(sizeof(struct lligada));
        nodo->valor = a->valor;
        nodo->prox = *l;
        *l = nodo;
    }
}

void posorder(ABin a, LInt *l) {
    *l = NULL;
    posorder_aux(a, l);
}

void posorder_aux(ABin a, LInt *l) {
    if (a) {
        LInt nodo = malloc(sizeof(struct lligada));
        nodo->valor = a->valor;
        nodo->prox = *l;
        *l = nodo;
        posorder_aux(a->dir, l);
        posorder_aux(a->esq, l);
    }
}

int depth(ABin a, int x) {
    if (!a) return -1;
    if (a->valor == x) return 1;
    int esq = 1 + depth(a->esq, x);
    int dir = 1 + depth(a->dir, x);
    if (esq && dir) return esq > dir ? dir : esq;
    if(esq) return esq;
    if(dir) return dir;
    return -1;
}
int freeAB (ABin a) {
    if(!a) return 0;
    int r = freeAB(a->dir) + freeAB(a->esq);
    free(a);
    return 1+r;
}