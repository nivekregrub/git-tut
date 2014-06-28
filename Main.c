/***************************************************************************************************
 * FILE: Main.c
 **************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CtoF.h"
#include "FtoC.h"
#include "FtoK.h"

#define streq(s1, s2)  (strcmp((s1), (s2)) == 0)
#define strneq(s1, s2) (strcmp((s1), (s2)) != 0)

static void Help(int pExitCode, char *pExitMsg);
static double StrToDouble(char *pNumber);

static void Help(int pExitCode, char *pExitMsg)
{
    printf("tempc(%d): %s\n", pExitCode, pExitMsg);
    printf("Usage: tempc -f|-c number\n");
    printf("Options:\n");
    printf("    -f   Convert temperature from Fahr to Cels and Kelvin.\n");
    printf("    -c   Convert temperature from Cels to Fahr.\n");
    exit(pExitCode);
}

int main(int pArgc, char *pArgv[])
{
    if (pArgc != 3) Help(-1, "Incomplete command line.");
    if (strneq(pArgv[1], "-f") && strneq(pArgv[1], "-c")) {
        Help(-2, "Invalid option on command line.");
    }
    double temp = StrToDouble(pArgv[2]);
    if (streq(pArgv[1], "-f")) printf("%.3lf C, %.3lf K\n", FtoC(temp), FtoK(temp));
    else printf("%.3lf\n", CtoF(temp));
    return 0;
}

static double StrToDouble(char *pNumber)
{
    double number;
    if (streq(pNumber, "0") || streq(pNumber, "0.") || streq(pNumber, "0.0")) return 0;
    number = atof(pNumber);
    if (number == 0) Help(-3, "Invalid numeric temperature.");
    return number;
}
