#include "route_pyramid.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]) {

    const char* usageStr = "Usage: pyramid 5.X (YDS Grade)";

    if (argc != 2) {
        fprintf(stderr, "Too few arguments.\n");
        fprintf(stderr, "%s", usageStr);
        exit(EXIT_FAILURE);
    }

    if (argv[1][0] != '5' && argv[1][1] != '.') {
        fprintf(stderr, "Please use YDS.\n");
        fprintf(stderr, "%s", usageStr);
        exit(EXIT_FAILURE);
    }


    struct YDSRoute* startRoute = malloc(sizeof(YDSRoute));
    char baseGradeStr[2];
    memcpy(baseGradeStr, (char*)(argv[1] + 2), 2);
    char suffix = '\0';
    if (!isdigit(baseGradeStr[1])) { 
        baseGradeStr[1] = '\0'; 
        suffix = argv[1][3];
    }
    else {
        if (strlen(argv[1]) == 5){
            suffix = argv[1][4];
        }
        else {
            suffix = 'a';
        }
    }
    startRoute->baseGrade = atoi(baseGradeStr);
    if ( startRoute->baseGrade < 3 || startRoute->baseGrade > 15){
        fprintf(stderr, "Please use YDS.\n");
        fprintf(stderr, "%s", usageStr);
        exit(EXIT_FAILURE);
    }
    startRoute->suffix = suffix;

    // printYDSRoute(subYDSRoute(startRoute, 1));
    // printYDSRoute(subYDSRoute(startRoute, 4));
    // printYDSRoute(subYDSRoute(startRoute, 5));

    struct YDSRoute** pyramid = getRoutePyramid(startRoute);
    printPyramid(pyramid);

    return 0;
}