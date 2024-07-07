#include "route_pyramid.h"

const int LEVELS = 3;

void printYDSRoute(struct YDSRoute* startRoute){
    printf("5.%d%s\n", startRoute->baseGrade, (char*) &startRoute->suffix);
}

struct YDSRoute* subYDSRoute(struct YDSRoute* startRoute, int decSize) {
    int charSuffix = (int ) (startRoute->suffix) - 97;

    int baseGradeDecrease = 1 + ((decSize - charSuffix) / 5);
    int newBaseGrade = startRoute->baseGrade - baseGradeDecrease;
    char newCharSuffix = (char)((((charSuffix - decSize) % 4 + 4) % 4) + 97);

    struct YDSRoute* newRoute = malloc(sizeof(YDSRoute));
    newRoute->baseGrade = newBaseGrade;
    newRoute->suffix = newCharSuffix;

    return newRoute;
}

struct YDSRoute** getRoutePyramid(struct YDSRoute* startRoute){
    int routes = 1;
    for (int i = 1; i < LEVELS; i++){
        routes += 3 * i;
    }

    struct YDSRoute** pyramid = malloc(sizeof(YDSRoute) * routes);
    pyramid[0] = startRoute;
    for (int i = 1; i < LEVELS; i++){
        int curr_level = 3 * i;
        for (int j = 0; j < curr_level; j++){
            pyramid[1 + (3 * (i - 1)) + j] = subYDSRoute(startRoute, i);
        }
    }

    return pyramid;
}


void printPyramid(struct YDSRoute** pyramid){
    printf("| 5.%d%s |\n", pyramid[0]->baseGrade, (char*) &pyramid[0]->suffix);

    for (int i = 1; i < LEVELS; i++){
        int curr_level = 3 * i;
        int last_level = 1 + (3 * (i - 1));
        for (int j = 0; j < curr_level; j++){
            printf("| 5.%d%s |", pyramid[last_level + j]->baseGrade, (char*) &pyramid[last_level + j]->suffix);
        }
        printf("\n");
    }
}

