#include <stdio.h>

int getYesNo (char* question) {
    printf ("%s [Y/N] ", question);
    char answer [128];
    scanf ("%s", answer);
    if (answer [0] == 'y')
        return 1;
    return 0;
}

void func () {
    int b=getYesNo ("Yes or no?");
    if (b==1)
    {
        puts ("yes yes");
    }
}

int main(int argc, char *argv[])
{
    int a = getYesNo ("Est' problemi?");
    if (a==1)
    {
        int c=getYesNo("Ti tut zameshan?");
        if (c==1)
            puts("Ne stoilo etogo delat'");
        else {
            int f=getYesNo("Na tebya eto povesili?");
            int count =0;
            while (count == 0) {


                if (f==1) {
                puts ("U menya dlya tebya plohie novosti");
                int h=getYesNo("Mojesh svalit' vinu na drugogo?");
                if (h==1) {
                    puts("Net problem");
                    count =1;
                }
                else {
                    count =0;
                }

                }

                else {
                puts ("Sidi tiho");
                puts ("Net problem!");

                }

            }
        }
        int d=getYesNo("Kto-nibud ob etom znaet?");
        if (d==1) {
            puts ("U menya dlya tebya plohie novosti...");
            int g=getYesNo("Mojesh svalit' venu na drugogo?");
            if (g==1) {
                puts("Net problem");
            }
            else {
                //cikl while
            }
        }
    }
    else {
        puts("Ne stoit bespokoitsya");
        puts("Net problem");
    }
    printf ("%d\n", a);
    return 0;
}


