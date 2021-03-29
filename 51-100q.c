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
    while (*l && (*l)->valor < x) l = &((*l)->prox);
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

LInt parteAmeio(LLig *l) {
    int len = 0;
    LInt pt, y, ant;
    pt = y = ant = *l;
    while (pt) {
        len++;
        pt = pt->prox
    }
    int meio = len / 2;
    while (meio) {
        ant = *l;
        l = &((*l)->prox);
        meio--;
    }
    ant->prox = NULL return y;
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
                pt = &((*pt)->pt);
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
}