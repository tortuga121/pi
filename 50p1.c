#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

void ex1()
{
    int i;
    int max = INT32_MIN; // numero menor com 32 bits

    printf("Insira uma sequencia: \n");

    do
    {
        scanf("%d", &i);
        if (max < i && i)
            max = i;
    } while (i != 0);

    printf("Maximo %d", max);
}
void ex2()
{
    int i, soma, contador;
    soma = 0;
    contador = 0;

    printf("Insira uma sequencia: \n");

    do
    {
        scanf("%d", &i);
        soma += i;
        if (i != 0)
            contador++;
    } while (i != 0);

    printf("Media =   %d", soma / contador);
}

void ex3()
{
    int i, max1, max2;
    max1 = INT32_MIN;
    max2 = INT32_MIN;
    i = 1; // apenas para o i nao ser igual a zero

    printf("Insira uma sequencia: \n");

    while (i != 0)
    {
        scanf("%d", &i);
        if (i > max1 && i)
            max1 = i;
        else if (i > max2 && i)
            max2 = i;
    }

    printf("2º maior elemento =   %d", max2);
}

int bitsUm(unsigned int n)
{
    int bits = 0;

    while (n > 0)
    {
        bits += n % 2;
        n /= 2;
    }
    return bits;
}

int trailingZ(unsigned int n)
{
    return 0;
}

int qDig(unsigned int n)
{
    int n_algarismos = 1;
    while (n / 10 > 0)
    {
        n_algarismos++;
        n /= 10;
    }
    return n_algarismos;
}

char *mystrcat(char s1[], char s2[])
{
    int i, len;
    for (len = 0; s1[len]; len++)
        ;
    for (i = 0; s2[i]; i++)
        s1[len + i] = s2[i];
    s1[len + i] = '\0';
    return s1;
}

char *mystrcpy(char *dest, char source[]) // m
{
    int i;
    for (i = 0; source[i] != '\0'; i++)
        dest[i] = source[i];
    dest[i] = '\0';
    return dest;
}

int mystrcmp(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i] && s2[i]; i++)
        ;
    return s1[i] - s2[i];
}
char *mystrstr(char s1[], char s2[])
{
    int i;
    int j;
    for (i = 0; s1[i] != s2[0] && s1[i]; i++) // chegar a posicao onde s2 começa em s1
        ;

    for (j = 0; s2[j] == s1[i] && s1[i] && s2[j]; j++, i++)
        ;
    if (s2[j] == '\0')
        return (s1 + (i - j));
    return NULL;
}

void mystrrev(char s[])
{
    int i, j;
    char temp_char;
    int len = (strlen(s));
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp_char = s[i];
        s[i] = s[j];
        s[j] = temp_char;
    }
}

int check_vowel(char ch)
{
    if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
        return 1;
    return 0;
} // auxiliar strnoV

void remove_index_char(char s[], int n)
{
    int j;
    for (j = n; s[j]; j++)
        s[j] = s[j + 1];

} // auxiliar

void strnoV(char s[])
{
    int i, j;
    for (i = 0; s[i]; i++)
    {
        if (check_vowel(s[i]))
        {
            remove_index_char(s, i);
            i--;
        }
    }
}

void truncW(char t[], int n)
{
    int comprimento = 0;
    int i = 0;
    while (t[i])
    {
        if (t[i] == ' ' || t[i] == '\n' || t[i] == '\t')
        {
            i++;
            comprimento = 0;
        }
        else
        {
            if (comprimento < n)
            {
                comprimento++;
                i++;
            }
            else
                remove_index_char(t, i);
        }
    }
}

char charMaisfreq(char s[])
{
    int acc[257];
    int max = 0;
    int i;
    char max_char;

    for (i = 0; i < 257; i++)
        acc[i] = 0;

    for (i = 0; s[i]; i++)
        acc[s[i]]++;

    for (i = 0; i < 257; i++)
    {
        if (acc[i] >= max)
        {
            max = acc[i];
            max_char = i;
        }
    }
    return max_char;
}

int iguaisConsecutivos(char s[])
{
    int i;
    int contador = 1;
    int maior_seq = 0;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == s[i + 1])
            contador++;
        else
        {
            if (contador >= maior_seq)
                maior_seq = contador;
            contador = 1;
        }
    }
    return maior_seq;
}
int difConsecutivos(char s[])
{
    int i = 1;
    int contador = 0;
    int ans = 0;

    while (s[i])
    {
        if (s[i - 1] != s[i])
            contador++;
        else
        {
            if (contador > ans)
                ans = contador;
            contador = 0;
        }
    }

    return ans;
}

int maiorPrefixo(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] == s2[i]; i++)
        ;
    return i;
}

int maiorSufixo(char s1[], char s2[])
{
    int i; // = srtlen(s1) - 1;
    int j; // = srtlen(s2) - 1;
    int ans = 0;

    for (i = 0; s1[i]; i++)
        ;
    for (j = 0; s2[j]; j++)
        ;

    i--;
    j--;

    while (s1[i] == s2[j])
    {
        i--;
        j--;
        ans++;
    }
    return ans;
}

int sufPref(char s1[], char s2[])
{
    return 0;
}

int contaPal(char s[])
{
    int i;
    int inside_wrd = 0;
    int n_wrds = 0;
    for (i = 0; s[i]; i++)
    {
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
            inside_wrd = 1;
        else if (inside_wrd)
        {
            n_wrds++;
            inside_wrd = 0;
        }
    }
    if (inside_wrd)
        n_wrds++;
    return n_wrds;
}

int contaVogais(char s[])
{
    int i, ans = 0;
    for (i = 0; s[i]; i++)
    {
        if (check_vowel(s[i]))
            ans++;
    }
    return ans;
}

int contida(char a[], char b[])
{
    int i, j;
    int contem;
    for (i = 0; a[i]; i++)
    {
        contem = 0;

        for (j = 0; b[j]; j++)
        {
            if (a[i] == b[j])
                contem = 1;
        }

        if (contem == 0)
            return 0;
    }
    return 1;
}

int palindroma(char s[])
{
    int i, j;
    int ans = 1;
    for (j = 0; s[j]; j++)
        ;
    j--;
    for (i = 0; s[i]; i++)
        if (s[i] != s[j - i])
            ans = 0;
    return ans;
}

int remRep(char x[])
{
    if (!x[0])
        return 0;

    int i = 1;
    char prev_char = x[0];

    while (x[i])
    {
        if (x[i] == prev_char)
            remove_index_char(x, i);
        else
        {
            prev_char = x[i];
            i++;
        }
    }
    return i;
}

int limpaEspacos(char t[])
{
    if (!t[0])
        return 0;

    int i = 1;
    char prev_char = t[0];

    while (t[i])
    {
        if (prev_char == ' ' && t[i] == ' ')
            remove_index_char(t, i);
        else
        {
            prev_char = t[i];
            i++;
        }
    }
    return i;
}

void insere(int v[], int N, int x)
{
    int i, posicao;
    for (posicao = 0; v[posicao] < x; posicao++)
        ;
    for (i = N + 1; i > posicao; i--)
        v[i] = v[i - 1];
    v[posicao] = x;
}

void merge(int r[], int a[], int b[], int na, int nb)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < na + nb)
    {
        if ((b[k] < a[j] && k < nb) || j >= na)
            r[i++] = b[k++];
        else
            r[i++] = a[j++];
    }
}

int crescente(int a[], int i, int j)
{
    int k;
    int ans = 1;
    for (k = i; k < j; k++)
        if (a[k] > a[k + 1])
        {
            ans = 0;
            break;
        }
    return ans;
}

int retiraNeg(int v[], int N)
{
    int i = 0, j;
    while (i < N)
    {
        if (v[i] < 0)
        {
            for (j = i; j < N; j++)
                v[j] = v[j + 1];
            N--;
        }
        else
            i++;
    }
    return N;
}

int menosFreq(int v[], int N)
{
    int i;
    int freq = 1;
    int min = N;
    int ans = v[0];
    for (i = 1; i < N; i++)
    {
        if (v[i] == v[i - 1])
            freq++;
        else
        {
            if (freq < min)
            {
                min = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    if (freq < min)
        ans = v[i - 1];
    return ans;
}

int maisFreq(int v[], int N)
{
    int i;
    int freq = 1;
    int max = 0;
    int ans = v[0];

    for (i = 1; i < N; i++)
    {
        if (v[i] == v[i - 1])
            freq++;
        else
        {
            if (freq > max)
            {
                max = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    if (freq > max)
        ans = v[i - 1];
    return ans;
}

int maxCresc(int v[], int N)
{
    int i;
    int acc;
    int max = 0;
    int freq = 1;

    for (i = 1; i < N; i++)
    {
        if (v[i] >= v[i - 1])
            freq++;
        else
        {
            if (freq > max)
                max = freq;
            freq = 1;
        }
    }
    if (freq > max)
        max = freq;
    return max;
}

int elimRepOrd(int v[], int n)
{
    int j, i = 1;

    while (i < n)
    {
        if (v[i] == v[i - 1])
        {
            for (j = i; j < n; j++)
                v[j] = v[j + 1];
            n--;
        }
        else
            i++;
    }
    return n;
}

int elimRep(int v[], int n)
{
    return 0;
}

int comunsOrd(int a[], int na, int b[], int nb)
{
    int i = 0;
    int j = 0;
    int comuns = 0;

    while (i < na && j < nb)
    {
        if (a[i] == b[j])
        {
            comuns++;
            i++;
            j++;
        }
        else if (a[i] > b[j])
            j++;
        else
            i++;
    }
    return comuns;
}

int comuns(int a[], int na, int b[], int nb)
{
    int i, j, comuns = 0;

    for (i = 0; i < na; i++)

        for (j = 0; j < nb; j++)
            if (a[i] == b[j])
            {
                comuns++;
                break;
            }
    return comuns;
}

int minInd(int v[], int n)
{
    int i, ans = 0;

    for (i = 1; i < n; i++)
        if (v[i] < v[ans])
            ans = i;

    return ans;
}

void somasAc(int v[], int Ac[], int N)
{
    int i, j;

    for (i = 0; i < N; i++)
        Ac[i] = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j <= i; j++)
            Ac[i] += v[j];
    }
}

int triSup(int N, float m[N][N])
{
    int i;
    int j;
    for (i = 0; i < N; i++)
        for (j = 0; j < i; j++)
            if (m[i][j] != 0)
                return 0;

    return 1;
}

void transposta(int N, float m[N][N])
{
    int i, j, temp;
    for (i = 0; i < N; i++)
        for (j = 0; j < i; j++)
        {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
}

void addTo(int N, int M, int a[N][M], int b[N][M])
{
    int i;
    int j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            a[i][j] += b[i][j];
}

int unionSet(int N, int v1[N], int v2[N], int r[N])
{
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] || v2[i];
    return 0;
}

int intersectSet(int N, int v1[N], int v2[N], int r[N])
{
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] && v2[i];
    return 0;
}
int intersectMSet(int N, int v1[N], int v2[N], int r[N])
{
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] < v2[i] ? v1[i] : v2[i];
    return 0;
}
int unionMSet(int N, int v1[N], int v2[N], int r[N])
{
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] > v2[i] ? v1[i] : v2[i];
    return 0;
}

int cardinalMSet(int N, int v[N])
{
    int i;
    int r = 0;
    for (i = 0; i < N; i++)
        r += v[i];
    return r;
}
int main()
{
    ex3();
    return 0;
}