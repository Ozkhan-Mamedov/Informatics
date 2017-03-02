#include <stdio.h>

int getYesNo (char* question) {
    printf ("%s [Y/N] ", question);
    char answer [128];
    scanf ("%s", answer);
    if (answer [0] == 'y')
        return 1;
    return 0;
}

void cycle () {
    int indicator = 0;
    while (indicator == 0) {
        puts ("U menya dlya tebya plohie novosti");
        int answer4 = getYesNo("Mojesh svalit vinu na drugogo?");
        if (answer4==1) {
            indicator = 1;
        }
        else {
            indicator = 0;
        }
    }
}

void func1 () {
    puts("Ne stoilo etogo delat");
    int answer3 = getYesNo ("Kto-nibud ob etom znaet?");
    if (answer3==1) {
        cycle ();
    }
    else {
        puts("Ne govori nikomu");
    }
}

void func2 () {
    int answer5 = getYesNo("Na tebya eto povesili?");
    if (answer5==1) {
        cycle();
    }
    else {
        puts ("Sidi tiho");
    }
}

int main(int argc, char *argv[]) {
    int answer1 = getYesNo ("Yest problemi?");
    if (answer1==1) {
        int answer2 = getYesNo ("Ti tut zameshan?");
        if (answer2==1) {
            func1();
        }
        else {
            func2();
        }
    }
    else {
        puts ("Ne stoit bespokoitsya");
    }
    puts ("Net problem!");
}