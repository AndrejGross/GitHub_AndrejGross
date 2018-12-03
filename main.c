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

    if((*file=fopen("auta.txt","r"))==NULL) //otvorenie súboru + kontrola
        return 0;

//počítanie záznamov na základe výskytu znaku $
    if (*file)
    {
        while(fscanf(*file,"%s",str)!=EOF)
            if(str[0]=='$')
                pocetZaznamov++;
    }
    *pocet_zaznamov=pocetZaznamov; //počet záznamov priradím smerníku

    rewind(*file); //na zažiatok súboru

    if((prvy=malloc(sizeof(struct inzeraty)))==NULL) //alokujem prvy záznam
        return 0;

    act=prvy;
    while(!feof(*file)) //po koniec súboru načítava hodnoty zo súbora do záznamov
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

        if((act->dalsi=malloc(sizeof(struct inzeraty)))==NULL) //alokujem miesto pre ďalši záznam
            return 0;

        act=act->dalsi; //posúvanie sa v medzi záznammi
    }
    printf("Nacitalo sa %d zaznamov\n",pocetZaznamov);

    return prvy; //vraciam smernik na prvý záznam
}

void v(FILE **file,int *pocet_zaznamov,struct inzeraty *prvy,struct inzeraty *act)
{
    int poradie=1;
    act=prvy;
    while(act!=NULL)
    {
        if(poradie==*pocet_zaznamov+1)
            break;
        printf("%d.\n",poradie);
        printf("kategoria: %s\n",act->kategoria);
        printf("znacka: %s\n",act->znacka);
        printf("predajca: %s\n",act->predajca);
        printf("cena: %d\n",act->cena);
        printf("rok_vyroby: %d\n",act->rok_vyroby);
        printf("stav_vozidla: %s\n",act->stav_vozidla);
        act=act->dalsi;
        poradie++;
    }
}

struct inzeraty* p(FILE **file,int *pocet_zaznamov,struct inzeraty *prvy,struct inzeraty *act,struct inzeraty *novy)
{
    int k,pocitadlo=0;
    scanf("%d",&k);
    if(k<=0)
        return 0;
    if(k>*pocet_zaznamov)
        k=*pocet_zaznamov+1;
    if((novy=malloc(sizeof(struct inzeraty)))==NULL)
       return 0;

    scanf("%*c");
    scanf("%[^\n]",novy->kategoria);
    scanf("%*c");
    scanf("%[^\n]",novy->znacka);
    scanf("%*c");
    scanf("%[^\n]",novy->predajca);
    scanf("%*c");
    scanf("%d",&novy->cena);
    scanf("%*c");
    scanf("%d",&novy->rok_vyroby);
    scanf("%*c");
    scanf("%[^\n]",novy->stav_vozidla);
    scanf("%*c");

    if(*pocet_zaznamov==0) //ak je počet záznamov 0, tak sa nový záznam uloží na prvné miesto
    {
        novy->dalsi=NULL;
        *pocet_zaznamov+=1;
        return novy;

    }
        act=prvy;
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
             case('n'): prvy = n(&file,&pocet_zaznamov,prvy,act);break;      //načítanie záznamov zo súbora
             case('v'): v(&file,&pocet_zaznamov,prvy,act);break;             //výpis záznamov
        }
    }
    return 0;
}
