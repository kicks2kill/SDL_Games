
#include "common.h"

extern void blitRotated(SDL_Texture *texture, int x, int y, float angle);
extern void calcSlope(int x1, int y1, int x2, int y2, float *dx, float *dy);
extern SDL_Texture *loadTexture(char *filename);

extern App app;
extern Entity *player;
extern Stage stage;
