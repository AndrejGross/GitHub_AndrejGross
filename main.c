#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct inzeraty
{
    char kategoria[51];
    char znacka[51];
    char predajca[101];
    int cena;
    int rok_vyroby;
    char stav_vozidla[201];
    struct inzeraty *dalsi;
};

int main()
{
    char c;
    int pocet_zaznamov=0;

    FILE *file=NULL;

    struct inzeraty *prvy;
    struct inzeraty *act;

    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {
             case('n'): prvy = n(&file,&pocet_zaznamov,prvy,act);break;
        }
    }
    return 0;
}
