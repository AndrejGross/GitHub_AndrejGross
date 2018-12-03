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

    while(1)
    {
        scanf("%c",&c);
        switch(c)
        {

        }
    }
    return 0;
}
