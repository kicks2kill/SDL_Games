
#include "common.h"

extern void blit(SDL_Texture *texture, int x, int y, int center);
extern void doBullets(void);
extern void doEntities(void);
extern void doPlayer(void);
extern void drawBullets(void);
extern void drawEntities(void);
extern void drawText(int x, int y, int r, int g, int b, int align, char *format, ...);
extern void initPlayer(void);
extern SDL_Texture *loadTexture(char *filename);

extern App app;
extern Entity *player;
extern Stage stage;
