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

struct inzeraty* n(FILE **file,int *pocet_zaznamov,struct inzeraty *prvy,struct inzeraty *act)
{
    int pocetZaznamov=0;
    char str[201];

    if((*file=fopen("auta.txt","r"))==NULL)
        return 0;

    if (*file)
    {
        while(fscanf(*file,"%s",str)!=EOF)
            if(str[0]=='$')
                pocetZaznamov++;
    }
    *pocet_zaznamov=pocetZaznamov;
    if((prvy=malloc(sizeof(struct inzeraty)))==NULL)
        return 0;
    rewind(*file);
    act=prvy;
    while(!feof(*file))
    {
        fscanf(*file,"%*c");
        fscanf(*file,"%*c");
        fscanf(*file,"%[^\n]",act->kategoria);
        fscanf(*file,"%*c");
        fscanf(*file,"%[^\n]",act->znacka);
        fscanf(*file,"%*c");
        fscanf(*file,"%[^\n]",act->predajca);
        fscanf(*file,"%*c");
        fscanf(*file,"%d",&act->cena);
        fscanf(*file,"%*c");
        fscanf(*file,"%d",&act->rok_vyroby);
        fscanf(*file,"%*c");
        fscanf(*file,"%[^\n]",act->stav_vozidla);
        fscanf(*file,"%*c");

        if((act->dalsi=malloc(sizeof(struct inzeraty)))==NULL)
            return 0;
        act=act->dalsi;
    }
    printf("Nacitalo sa %d zaznamov\n",pocetZaznamov);
    return prvy;
}

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
