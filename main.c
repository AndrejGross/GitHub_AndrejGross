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

    FILE *file=NULL; //zadefinovanie s�boru

    //zadefinovanie pointrov na �trukt�ru
    struct inzeraty *prvy;
    struct inzeraty *act;

    while(1) //nekone�n� cyklus
    {
        scanf("%c",&c); //na��tavanie znaku pre volanie funkcie
        switch(c)       //switch pre vyberanie funkcie
        {
             case('n'): prvy = n(&file,&pocet_zaznamov,prvy,act);break;      //na��tanie z�znamov zo s�bora
        }
    }
    return 0;
}
