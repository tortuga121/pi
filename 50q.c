
#include <stdio.h>
void ex1() {
    int r;
    scanf("%d", &r);
    int max = r;
    while (r) {
        scanf("%d", &r);
        if (r > max) max = r;
    }
    printf("Maior numero: %d", max);
}

void ex2() {
    int r, i;
    float total;
    scanf("%d", &r);
    total = 0;
    i = 1;
    while (r) {
        total += r;
        scanf("%d", &r);
        i++;
    }
    printf("A media é: %f", total / i);
}

int bitsUm(unsigned int n) {
    int n_bits = 0;
    while (n) {
        if (n % 2 == 1) n_bits++;
        n /= 2;
    }
    return n_bits;
}

int trailingZ(unsigned int n) {
    if (n == 0) return 32;
    int i = 0;
    while (n && n % 2 == 0) {
        i++;
        n /= 2;
    }
    return i;
}

int qDig(unsigned int n) {
    int r = 1;
    while (n / 10) {
        r++;
        n /= 10;
    }
    return r;
}

char *mystrcat(char s1[], char s2[]) {
    int len, i;
    for (len = 0; s1[len]; len++)
        ;

    for (i = 0; s2[i]; i++)
        s1[len + i] = s2[i];
    s1[len + i] = '\0';
    return s1;
}

char *mystrcpy(char *dest, char source[]) {
    int i;
    for (i = 0; source[i]; i++)
        dest[i] = source[i];
    dest[i] = '\0';
    return dest;
}

int mystrcmp(char s1[], char s2[]) {
    int r = 0;
    int i = 0;
    while (s1[i] && s2[i] && r == 0) {
        if (s1[i] != s2[i])
            r = s1[i] < s2[i] ? -1 : 1;
        i++;
    }

    if (!s1[i] && s2[i])
        r = -1;
    else if (s1[i] && !s2[i])
        r = 1;

    return r;
}

char *mystrstr(char s1[], char s2[]) {
    int i, j;
    if (!*s2) return s1;
    for (i = 0; s1[i]; i++)
        for (j = 0; s1[i + j] && s2[j] && s1[i + j] == s2[j]; j++);
        if (!s2[j]) return s1 + i;
    return NULL;
}

void strrev(char s[]) {
    int len, i;
    for (len = 0; s[len]; len++)
        ;
    len--;
    for (i = 0; i < len; i++, len--) {
        char aux;
        aux = s[i];
        s[i] = s[len];
        s[len] = aux;
    }
}

void strnoV(char s[]) {
    int j, i = 0;
    while (s[i]) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            for (j = i; s[j]; j++)
                s[j] = s[j + 1];
        else
            i++;
    }
}

void truncW(char t[], int n) {
    int i = 0, j;
    int inside = 1;
    int contador = 1;
    while (t[i]) {
        if (t[i] == ' ' || t[i] == '\n' || t[i] == '\t') {
            contador = 1;
            i++;
        } else if (contador > n)
            for (j = i; t[j]; j++) t[j] = t[j + 1];
        else {
            contador++;
            i++;
        }
    }
}

char charMaisfreq(char s[]) {
    int acc[257];
    int max = 0;
    int i;
    char max_char;

    for (i = 0; i < 257; i++) acc[i] = 0;

    for (i = 0; s[i]; i++) acc[s[i]]++;

    for (i = 0; i < 257; i++)
        if (acc[i] >= max) {
            max = acc[i];
            max_char = i;
        }

    return max_char;
}

int iguaisConsecutivos(char s[]) {
    int max = 0;
    char last = s[0];
    int n_consec = 0;
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] == last)
            n_consec++;
        else {
            last = s[i];
            if (n_consec > max) max = n_consec;
            n_consec = 1;
        }
    }
    return n_consec > max ? n_consec : max;
}

int dif(char *s, int j) {
    int i;
    for (i = 0; i < j && s[i] != s[j]; i++)
        ;
    return i == j;
}

int difConsecutivos(char s[]) {
    int max = 0;
    int i, j;
    for (i = 0; s[i]; i++) {
        for (j = i; s[j] && dif(s + i, j - i); j++)
            ;
        if (j - i > max) max = j - i;
    }
    return max;
}
int maiorPrefixo(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i]) i++;
    return i;
}

int maiorSufixo(char s1[], char s2[]) {
    int len1, len2;
    len1 = len2 = 0;
    while (s1[len1]) len1++;
    while (s2[len2]) len2++;
    len2--;
    len1--;
    int tam = 0;
    while (len1 >= 0 && len2 >= 0 && s1[len1] == s2[len2]) {
        len1--;
        len2--;
        tam++;
    }
    return tam;
}

int sufPref(char s1[], char s2[]) {
    int i = 0, j;
    int max = 0;
    while (s1[i]) {
        if (s1[i] == s2[0]) {
            for (j = 0; s1[i + j] && s2[j] && s1[i + j] == s2[j]; j++)
                ;
            if (j > max && !s1[i + j]) max = j;
        }
        i++;
    }
    return max;
}

int contaPal(char s[]) {
    int i;
    int pal = 0;
    int inside = 0;
    for (i = 0; s[i]; i++) {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
            if (inside) pal++;
            inside = 0;
        } else
            inside = 1;
    }
    return inside ? pal + 1 : pal;
}

int contaVogais(char s[]) {
    int i;
    int n_vogais = 0;
    for (i = 0; s[i]; i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            n_vogais;
    return n_vogais;
}

int contida(char a[], char b[]) {
    int i, j;
    int contida = 1;
    for (i = 0 : a[i] && contida; i++) {
        for (j = 0; b[j] && a[i] != b[j]; j++)
            ;
        contida = a[i] == b[j];
    }
    return contida;
}

int palindroma(char s[]) {
    int len = 0;
    int iguais = 1;
    while (s[len]) len++;
    len--;
    int i;
    for (i = 0; i < len && iguais; i++, len--)
        iguais = s[i] == s[len];
    return iguais;
}

int remRep(char x[]) {
    if (!*x) return 0;
    int i = 1;
    int j;
    char last = x[0];
    while (x[i]) {
        if (x[i] == last)
            for (j = i; x[j]; j++)
                x[j] = x[j + 1];
        else
            last = x[i++];
    }
    return i;
}
int limpaEspacos(char t[]) {
    int i = 0, j;
    int last_espaco = 0;
    while (t[i])
        if (t[i] == ' ')
            if (last_espaco) {
                for (j = i; t[j]; j++)
                    t[j] = t[j + 1];
                last_espaco = 1;
            } else {
                last_espaco = 1;
                i++;
            }
        else {
            last_espaco = 0;
            i++;
        }
    return i;
}

int limpaEspacos(char t[]) {
    if (!*t) return 0;
    int i = 1, j;
    char last = t[0];
    while (t[i])
        if (t[i] == ' ' && t[i] == last)
            for (j = i; t[j]; j++)
                t[j] = t[j + 1];
        else
            last = t[i++];
    return i;
}

void insere(int v[], int N, int x) {
    int i, j;
    for (i = 0; i < N && v[i] <= x; i++)
        ;
    for (j = N; j > i; j--)
        v[j] = v[j - 1];
    v[i] = x;
}

void merge(int r[], int a[], int b[], int na, int nb) {
    int i, j, k : i = j = k = 0;
    while (i < na + nb)
        r[i++] = ((b[k] < a[j] && k < nb) || j >= na) ? b[k++] : a[j++];
}

int crescente(int a[], int i, int j) {
    int k;
    for (k = i; k < j; k++)
        if (a[k] > a[k + 1]) return 0;
    return 1;
}

int retiraNeg(int v[], int N) {
    int i = 0;
    int k;
    while (i < N) {
        if (a[i] < 0) {
            for (k = i; k < N; k++)
                v[k] = v[k + 1];
            N--;
        } else
            i++;
    }
    return N;
}

int menosFreq(int v[], int N) {
    int i, min, count, last, r;
    count = 1;
    min = N;
    last = v[0];
    r = last;
    for (i = 1; i < N; i++) {
        if (v[i] == last)
            count++;
        else {
            if (count < min) {
                min = count;
                r = last;
            }
            count = 1;
            last = v[i];
        }
    }
    if (count < min) {
        min = count;
        r = last;
    }
    return r;
}

int maisFreq(int v[], int N) {
    int i, count, max, r, last;
    max = 0;
    count = 1;
    last = v[0];
    r = last;
    for (i = 1; i < N; i++) {
        if (v[i] == last)
            count++;
        else {
            if (count > max) {
                max = count;
                r = last;
            }
            count = 1;
            last = v[i];
        }
    }
    if (count > max) {
        max = count;
        r = last;
    }
    return r;
}

int maxCresc(int v[], int N) {
    int i, max, seq, last;
    seq = 1;
    max = 0;
    last = v[0];
    for (i = 1; i < N; i++) {
        if (v[i] >= last)
            seq++;
        else {
            max = seq > max ? seq : max;
            seq = 1;
        }
        last = v[i];
    }
    return max = seq > max ? seq : max;
}

int elimRepOrd(int v[], int n) {
    int i, last, k;
    last = v[0];
    i = 1;
    while (i < n) {
        if (v[i] == last) {
            for (k = i; k < n; k++)
                v[k] = v[k + 1];
            n--;
        } else
            last = v[i++];
    }
    return n;
}

int comuns(int a[], int na, int b[], int nb) {
    int i, j, comuns = 0;

    for (i = 0; i < na; i++) {
        for (j = 0; j < nb && a[i] != b[j]; j++)
            ;
        comuns += j < nb && a[i] == b[j];
    }
    return comuns;
}

int minInd(int v[], int n) {
    int min, min_ind, i;
    min = v[0];
    min_ind = 0;
    for (i = 1; i < n; i++)
        if (v[i] < min) {
            min = v[i];
            min_ind = i;
        }
    return min_ind;
}

void somasAc(int v[], int Ac[], int N) {
    int i;
    int ac = 0;
    for (i = 0; i < N; i++) {
        ac += v[i];
        Ac[i] = ac;
    }
}

int triSup(int N, float m[N][N]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < i; j++)
            if (m[i][j] != 0) return 0;
    return 1;
}

void transposta(int N, float m[N][N]) {
    int i, j, temp;
    for (i = 0; i < N; i++)
        for (j = 0; j < i; j++) {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
}

void addTo(int N, int M, int a[N][M], int b[N][M]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            a[i][j] += b[i][j];
}

int unionSet(int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] || v2[i];
    return 0;
}

int intersectSet(int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] && v2[i];
    return 0;
}

int intersectMSet(int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
    return 0;
}

int unionMSet(int N, int v1[N], int v2[N], int r[N]) {
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] > v2[i] ? v1[i] : v2[i];
    return 0;
}

int cardinalMSet(int N, int v[N]) {
    int i;
    int r = 0;
    for (i = 0; i < N; i++)
        r += v[i];
    return r;
}

typedef enum movimento { Norte,
                         Oeste,
                         Sul,
                         Este } Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

Posicao posFinal(Posicao inicial, Movimento mov[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (mov[i] == Norte)
            inicial.y++;
        else if (mov[i] == Sul)
            inicial.y--;
        else if (mov[i] == Este)
            inicial.x++;
        else
            inicial.x--;
    }
    return inicial;
}

int caminho(Posicao inicial, Posicao final, Movimento mov[], int N) {
    int i;

    for (i = 0; i < N && inicial.x != final.x || inicial.y != final.y; i++)
        if (inicial.y < final.y) {
            inicial.y++;
            mov[i] = Norte;
        } else if (inicial.y > final.y) {
            inicial.y--;
            mov[i] = Sul;
        } else if (inicial.x < final.x) {
            inicial.x++;
            mov[i] = Este;
        } else if (inicial.x > final.x) {
            inicial.x--;
            mov[i] = Oeste;
        }
    return i == N && (inicial.x != final.x || inicial.y != final.y) ? -1 : i;
}

int maiscentral(Posicao pos[], int N) {
    int min, posmin, i;
    min = pos[0].x * pos[0].x + pos[0].y * pos[0].y;
    posmin = 0;
    for (i = 1; i < N; i++) {
        int dist = pos[i].x * pos[i].x + pos[i].y * pos[i].y;
        if (dist < min) {
            posmin = i;
            min = dist;
        }
    }
    return posmin;
}

int vizinhos(Posicao p, Posicao pos[], int N) {  //50 (0,0) adjacentes  (0,1) (0,-1) (1,0) (-1,0)
    int viz = 0;
    int i;
    for (i = 0; i < N; i++)
        if ((abs(p.x - pos[i].x) == 1 && pos[i].y == p.y) || (abs(pos[i].y - p.y) == 1 && pos[i].x == p.x))
            viz++;
    return viz;
}
