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

    FILE *file=NULL; //zadefinovanie súboru

    //zadefinovanie pointrov na štruktúru
    struct inzeraty *prvy;
    struct inzeraty *act;

    while(1) //nekoneèný cyklus
    {
        scanf("%c",&c); //naèítavanie znaku pre volanie funkcie
        switch(c)       //switch pre vyberanie funkcie
        {
             case('n'): prvy = n(&file,&pocet_zaznamov,prvy,act);break;      //naèítanie záznamov zo súbora
        }
    }
    return 0;
}
