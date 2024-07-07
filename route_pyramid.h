#ifndef ROUTE_PYRAMID_H_
#define ROUTE_PYRAMID_H_


#include <stdio.h>
#include <stdlib.h>


struct YDSRoute {
    int baseGrade;
    char suffix;
};
typedef struct YDSRoute YDSRoute;
void printYDSRoute(struct YDSRoute* startRoute);
void printPyramid(struct YDSRoute** pyramid);
struct YDSRoute* subYDSRoute(struct YDSRoute* startRoute, int decSize);
struct YDSRoute** getRoutePyramid(struct YDSRoute* startRoute);


#endif