typedef enum CubeProps { side, area, volume } CubeProps;

typedef struct Cube {
    float side;
    float area;
    float volume;
} Cube;

float getCubeProp(Cube *cube, CubeProps prop);
void setCubeSide(Cube *cube, float value);
void showCube(Cube *cube);

Cube * createCube(float side);