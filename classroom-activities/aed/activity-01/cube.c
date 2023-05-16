#include <stdio.h>
#include <stdlib.h>

#include "cube.h"

float getCubeProp(Cube *cube, CubeProps prop) {
    switch (prop) {
        case side: return cube->side;
        case area: return cube->area;
        case volume: return cube->volume;
    }
}

void setCubeSide(Cube *cube, float value) {
    cube->side = value;
    cube->area = value * value * 6;
    cube->volume = value * value * value;
}

void showCube(Cube *cube) {
    printf("\n\nCube props\n");

    printf("\nSide = %.2f cm", getCubeProp(cube, side));
    printf("\nArea = %.2f cm2", getCubeProp(cube, area));
    printf("\nSide = %.2f cm3", getCubeProp(cube, volume));
}

Cube * createCube(float side) {
    Cube *cube = malloc(sizeof(Cube));

    cube->side = side;
    cube->area = side * side * 6;
    cube->volume = side * side * side;

    return cube;
}