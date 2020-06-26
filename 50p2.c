#include "50p2.h"
#include <stdlib.h>
#include <stdio.h>

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}
//1
int length(LInt l) {
    int r = 0;
    while (l) {
        r++;
        l = l->prox;
    }
    return r;
}
//2
void freeL(LInt l) {
    LInt temp;
    while (l) {
        temp = l;
        l = l->prox;
        free(temp)
    }
}

//3
void imprimeL(LInt l) {
    while (l) {
        printf("%d ", l->valor);
        l = l->prox;
    }
    putchar('\n');
}

//4
LInt reverseL(LInt l) {

    LInt ant = NULL;
    LInt atual = l;
    LInt seg = l;

    while (atual) {
        seg = seg->prox;
        atual->prox = ant;
        ant = atual;
x       atual = seg;
    }

    return ant;
}

//5
void insertOrd (LInt *l, int n) {

    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = n;

    while(*l && (*l)->valor < n)
        l = &((*l)->prox);
    
    novo->prox = *l;
    *l = novo;
}
void insertOrd (LInt *l, int x){
    
  while(*l!=NULL && (*l)->valor < x){
    l=&((*l)->prox);  
  }
  LInt res=malloc(sizeof(struct lligada));
  res->valor=x;
  res->prox=*l;
  *l=res;
}
//6
int removeOneOrd (LInt *l, int x) {
    LInt ant = NULL;

    while(*l && (*l)->valor < x) l = &((*l)->prox);
    if(*l == NULL) return 1;
    else {
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
    } 
    return 0;
}

//7
void merge (LInt *r, LInt a, LInt b) {

    while(a || b) {

        if( !b  || (a && a->valor < b->valor)) {
           *r = newLInt(a->valor, NULL);
            a = a->prox;
        }else{
            *r = newLInt(b->valor, NULL);
            b = b->prox;
        }
        r = &((*r)->prox);
    }
}
//8 
void splitQS (LInt l, int x, LInt *mx, LInt *Mx)  {

    while(l) {
        if (l->valor < x){ 
            *mx = l;
            mx = &((*mx)->prox);
        }else{
            *Mx = l;
            Mx = &((*Mx)->prox);
        }
        l = l->prox;
    }  
    *mx = NULL;
}


LInt parteAmeio(LInt *l) {
    int len = length(*l)/2;
    LInt ant, y;
    ant = NULL;
    y = *l;
    while(len){
        ant = *l;
        (*l) = (*l)->prox;
        len--;
    }
    if(ant) ant->prox = NULL;
    else y = NULL;
    return y;
}

int removeAll (LInt *l, int x) {
    int r = 0;
    LInt ant = NULL;
    while(*l) {
        if ((*l)->valor == x){ 
            if (ant == NULL) (*l) = (*l)->prox;
            else ant->prox = (*l)->prox;
            r++;
        }else{
            ant = (*l);
            l = &((*l)->prox);
        }
    }
    return r;
}

int removeDups (LInt *l) {
    LInt pt, ant = NULL;
    int r = 0;
    while(*l) {
        ant = (*l);
        pt = (*l)->prox;
        while(pt) {
            if(pt->valor == (*l)->valor) {
                ant->prox = pt->prox;
                r++;
                pt = pt->prox;
            }else{ 
                ant = pt;
                pt = pt->prox;
            }
        }
        
     l = &((*l)->prox);
    }
    return r;
}


int removeMaiorL (LInt *l) {

    if (!(*l)) return 1;
    LInt pt = *l;
    int max = pt->valor;
    pt = pt->prox;

    while(pt) {
        if ((pt)->valor > max) 
             max = (pt)->valor;
        pt = pt->prox;
    }
    removeOneOrd(l,max);
    return 0;

}

void init (LInt *l) {

    while((*l)->prox) l = &((*l)->prox);
    *l = NULL;   
}

void appendL (LInt *l, int x) {

    LInt new = newLInt(x,NULL);
    if(!(*l)) *l = new;
    else {
        while ((*l)->prox) l = &((*l)->prox);
        (*l)->prox = new; 
    }
}

void concatL (LInt *a, LInt b) {
    for(;*a; a = &((*a)->prox));
    (*a) = b;
}

LInt cloneL (LInt l) {
   if(l == NULL) return NULL;
   LInt new = malloc(sizeof(struct lligada));
   new->valor = l->valor;
   new->prox = cloneL(l->prox);
   return new;
}


LInt cloneRev (LInt l) {
   return reverseL(cloneL(l));
}

int maximo (LInt l) {
    int max = l->valor;
    l = l->prox;
    for(;l;l = l->prox) if(l->valor > max) max = l->valor;
    return max;
}

int take (int n, LInt *l) {
    int len = 0;
    LInt pt = *l;
    while(pt) {pt = pt->prox; len++;}
    if(len < n) return len;
    int i = 0;
    while(*l && i < n){
        (*l) = (*l)->prox;
        i++;
    }
    *l = NULL;
    return len - i;
}
int take (int n, LInt *l) {
    int i;
    for(i = n; *l && i > 0; l = &((*l)->prox), --i);

    LInt temp;
    while(*l) {
        temp = (*l)->prox;
        free(*l);
        *l = temp;§
    }
    return n - i;
}

int drop (int n, LInt *l) {
    int i;
    LInt temp;
    for(i = n; *l && i; --i){
        temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return n-i;
}

LInt Nforward (LInt l, int N) {
    while(N){
        l = l->prox;
        --N;
    }
    return l;
}

int listToArray (LInt l, int v[], int N) {
    int i = 0;
    for(; l && i < N; l = l->prox, i++) 
        v[i] = l->valor;
    return (i);
}

LInt arrayToList (int v[], int N){
    int i;
    LInt ans = NULL;
    LInt *pt = &ans;
    for(i = 0;i < N; i++) {
        (*pt) = malloc(sizeof(struct lligada));
        (*pt)->valor = v[i];
        pt = &((*pt)->prox);
    }
    return ans;
}

LInt somasAcL (LInt l) {
    LInt somas, ans = NULL;
    LInt pt = l;
    int acc = 0;
    
    while(pt) { 
        acc += pt->valor;
        somas = newLInt(acc,NULL);
        if(!ans) ans = somas; 
        pt = pt->prox;
        somas = somas->prox;
    }
    return ans;
}

void remreps (LInt l) {
    if(!l) return;
    LInt temp;
    while(l->prox) {
        if (l->valor == l->prox->valor){
            temp = l->prox;
            l->prox = temp->prox;
            free(temp);
        }
        else l = l->prox;
    }
} 

LInt rotateL (LInt l) {
    if(!l || !(l->prox)) return l;

    LInt inicio = l->prox;
    LInt pt;
    l->prox = NULL;
    
    for(pt = inicio; pt && pt->prox; pt = pt->prox);

    if(pt) pt->prox = l;
    else inicio = l;
    return inicio;
}
LInt parte (LInt l) {
    int par = 0;
    LInt pares = NULL;
    LInt *pt = &pares;
    LInt ant = NULL;
    while(l) {
        if(par){
            *pt = l;
            ant->prox = l->prox;
            l = l->prox;
            pt = &((*pt)->prox);
            *pt = l ? l->prox : l;
        }else{ 
            ant = l;
            l = l->prox; 
        }
        par = par ? 0 : 1;
    }
    return pares;
}

////AB

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin

int altura (ABin a) {
    if(a == NULL) return 0;
    int h_esq = altura(a->esq);
    int h_dir = altura(a->dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

int altura (ABin a){
    if (a == NULL) return 0;
    else {
        int lef = altura(a->esq); 
        int rig = altura(a->dir); 
        if(rig>lef) return 1 + rig;
        else return 1 + lef;
    }
}

ABin cloneAB (ABin a) {
    if (a == NULL) return a;
    ABin nodo = malloc(sizeof(struct nodo));
    nodo->valor = a->valor;
    nodo->esq = cloneAB(a->esq);
    nodo->dir = cloneAB(a->dir);
    return nodo;
}

void mirror (ABin *a) {
    if(*a) {
        ABin temp;
        temp = (*a)->dir;
        (*a)->dir = (*a)->esq;
        (*a)->esq = temp;
        mirror(&(*a)->dir);
        mirror(&(*a)->esq);
    }
}

int depth (ABin a, int x) {
    if(a == NULL) return -1;
    if(a->valor == x) return 1;
    
    int d_esq = depth(a->esq, x);
    int d_dir = depth(a->dir, x);
     
    if (d_esq == -1 && d_dir == -1) return -1;
    if (d_esq == -1) return 1 + d_dir;
    if (d_dir == -1) return 1 + d_esq;
    return  1 + (d_esq < d_dir ? d_esq : d_dir);
}

int freeAB (ABin a) {
    if (a == NULL) return 0;
    ABin esq = a->esq;
    ABin dir = a->dir;
    free(a);
    return 1 + freeAB(esq) + freeAB(dir);
}

int pruneAB (ABin *a, int l) {
    if(*a == NULL) return 0;

    if (l > 0) return pruneAB(&(*a)->esq,l-1) + pruneAB(&(*a)->dir,l-1);
    
    ABin * esq = &((*a)->esq); 
    ABin * dir = &((*a)->dir); 
    *a = NULL;
    free(*a);
    return 1 + pruneAB(esq,0) + pruneAB(dir,0);   
}

int iguaisAB (ABin a, ABin b) {
    if (a && b) return a->valor == b->valor 
                        && iguaisAB(a->dir,b->dir) 
                        && iguaisAB(a->esq, b->esq);

    if (a == NULL && b == NULL) return 1;
    else return 0;
}
LInt nivelL (ABin a, int n) {
    if(n < 1 || a == NULL) return NULL; 
    if(n == 1) return newLInt(a->valor, NULL);
    else{  
        LInt esq = nivelL(a->esq, n-1);
        LInt dir = nivelL(a->dir, n-1);
        concatL(&esq, dir);
        return esq;
    }
}
int nivelV (ABin a, int n, int v[]) {
    if (n < 1 || a == NULL) return 0;
    if (n == 1) {*v = a->valor; return 1;}
    int esq = nivelV(a->esq, n-1, v);
    int dir = nivelV(a->dir, n-1, v+esq);
    return esq + dir;
}
//nas proximas 3 pode ter uns erros de piça que eu removi uma auxiliar 
//mas a essencia esta la
esq root dir 
void inorder (ABin a , LInt *l) {
    if(a) {
        inorder(a->dir, l);
        //criar nodo
        LInt nodo = malloc(sizeof(struct lligada));
        nodo->valor=a->valor;
        nodo->prox= *l;
        *l = nodo;

        inorder(a->esq,l);
 }
}


void preorder(ABin a, LInt *l){
    *l = NULL;
    preorderaux(a,l);
}
 void preorder_aux (ABin a , LInt *l) {
    if(a){
        preorder_aux(a->dir, l);
        preorder_aux(a->esq, l);
       LInt nodo=malloc(sizeof(struct lligada));
        nodo->valor=a->valor;
        nodo->prox=*l;
        *l=nodo;
    }
}

void posorder(ABin a, LInt * l) {
    *l = NULL;
    posorder_aux(a,l);
}

void posorder_aux (ABin a, LInt *l) {
    if(a) {
        LInt nodo=malloc(sizeof(struct lligada));
        nodo->valor=a->valor;
        nodo->prox=*l;
        *l=nodo;
        posorder_aux(a->dir, l);
        posorder_aux(a->esq, l);
    }
}

int dumpAbin (ABin a, int v[], int N) {
    if(a && N > 0){ 
        int esq = dumpAbin(a->esq,v, N);
        *v = a->valor;
        if(esq < N) { 
            int dir = dumpAbin(a->dir,v+esq+1, N-esq-1);
            return 1 + esq + dir;
        }
        return esq;
    }
    return 0;
}
//da para fazer sem axiliar mas acabei por fazer assim
int somaAcA_aux(ABin a) {
    if(a) return a->valor + somaAcA_aux(a->esq) + somaAcA_aux(a->dir);
    else return 0;
}

ABin somasAcA (ABin a) {
    if(a){ 
        ABin nodo = malloc(sizeof(struct nodo));
        nodo->valor = somaAcA_aux(a);
        nodo->esq = somasAcA(a->esq);
        nodo->dir = somasAcA(a->dir);
        return nodo;
    }
    return NULL;
   
}
int contaFolhas (ABin a) {
    if(a) 
        if(a->dir && a->esq) return contaFolhas(a->esq) + contaFolhas(a->dir);
        else if(a->dir || a->esq) return contaFolhas(a->esq ? a->esq : a->dir);
        else if (a->dir == NULL && a->esq == NULL) return 1;
    else return 0;
}

ABin cloneMirror (ABin a) {
    if(a == NULL) return NULL;
    ABin nodo = malloc(sizeof(struct nodo));
    nodo->valor = a->valor;
    nodo->esq = cloneMirror(a->dir);
    nodo->dir = cloneMirror(a->esq);
    return nodo;
}
int addOrd (ABin *a, int x){
    while(*a) {
        if((*a)->valor == x) return 1;
        a = (*a)->valor > x ? &(*a)->esq : &(*a)->dir; 
    }
    ABin nodo = malloc(sizeof(struct nodo));
    nodo->valor = x;
    nodo->dir = NULL;
    nodo->esq = NULL;
    *a = nodo;
    return 0;
}

int addOrdRec (ABin *a, int x) {
    if(*a == NULL){
        ABin nodo = malloc(sizeof(struct nodo));
        nodo->valor = x;
        nodo->dir = NULL;
        nodo->esq = NULL;
        *a = nodo;
        return 0;
    } 
    if((*a)->valor == x) return 1;
    if ((*a)->valor > x) addOrdRec(&(*a)->esq, x);
    else addOrdRec(&(*a)->dir, x);
}

int lookupAB(ABin a, int x) {
    while(a){
        if (a->valor == x) return 1;
        a = (a->valor > x ? a->esq : a->dir; 
    }
    return 0;
}
int lookupABRec(ABin a, int x) {
    if (a == NULL) return 0;
    if (a->valor == x) return 1;
    return lookupABRec(a->valor > x ? a->esq : a->dir, x);
}

int depthOrd (ABin a, int x) {
    if(a == NULL) return -1;
    if(a->valor == x) return 1;
    int res = depthOrd(a->valor > x ? a->esq : a->dir, x)
    return res == -1 ? -1 : res + 1;  
}

int maiorAB (ABin a) {
    if (a == NULL) return -1;
    while(a->dir) a = a->dir;
    return a->valor;
}

void removeMaiorA (ABin *a) {
    while(*a && (*a)->dir) a = &(*a)->dir; 
    ABin temp = *a;
    *a = *a ? (*a)->esq : NULL;
    free(temp);
}

int quantosMaiores (ABin a, int x) {
   if(a == NULL) return 0;
   return (a->valor > x) + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x);
}
void insere_tree(ABin *a, int x){
   while(*a) 
        a = (*a)->valor > x ? &(*a)->esq : &(*a)->dir; 
    ABin nodo = malloc(sizeof(struct nodo));
    nodo->valor = x;
    nodo->dir = NULL;
    nodo->esq = NULL;
    *a = nodo;
}
void listToBTree (LInt l, ABin *a) {
    while(l){
        insere_tree(a, l->valor);
        l = l->prox;
    }
}
int deProcura (ABin a) {
    if (a == NULL) return 1;
    if(a->dir && a->esq) return (a->valor > a->esq->valor) &&
                                 (a->valor < a->dir->valor) &&
                                 deProcura(a->dir) &&
                                 deProcura(a->esq);

    if(a->dir && (a->esq == NULL)) return (a->valor < a->dir->valor) &&
                                          deProcura(a->dir);
    if(a->esq && (a->dir == NULL)) return (a->valor > a->esq->valor) &&
                                          deProcura(a->esq);
    if((a->esq == NULL) && (a->dir == NULL)) return 1;
}



 
            