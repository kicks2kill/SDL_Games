
#include "stage.h"

static void logic(void);
static void draw(void);
static void drawGrid(void);
static void drawHud(void);
static void drawWeaponInfo(char *name, int type, int x, int y);

static SDL_Texture *targetterTexture;
static SDL_Texture *gridTexture;

void initStage(void)
{
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	
	stage.entityTail = &stage.entityHead;
	stage.bulletTail = &stage.bulletHead;
	
	targetterTexture = loadTexture("gfx/targetter.png");
	gridTexture = loadTexture("gfx/grid.png");
	
	initPlayer();
}

static void logic(void)
{
	doPlayer();
	
	doEntities();
	
	doBullets();
}

static void draw(void)
{
	drawGrid();
	
	drawEntities();
	
	drawBullets();
	
	drawHud();
	
	blit(targetterTexture, app.mouse.x, app.mouse.y, 1);
}

static void drawHud(void)
{
	drawText(10, 10, 255, 255, 255, TEXT_LEFT, "HEALTH:%d", player->health);
	
	drawText(250, 10, 255, 255, 255, TEXT_LEFT, "SCORE:%05d", 0);
	
	drawWeaponInfo("PISTOL", WPN_PISTOL, 550, 10);
	
	drawWeaponInfo("UZI", WPN_UZI, 800, 10);
	
	drawWeaponInfo("SHOTGUN", WPN_SHOTGUN, 1050, 10);
}

static void drawWeaponInfo(char *name, int type, int x, int y)
{
	int r, g, b;
	
	if (player->weaponType == type)
	{
		r = b = 0;
		g = 255;
	}
	else
	{
		r = g = b = 255;
	}
	
	drawText(x, y, r, g, b, TEXT_LEFT, "%s:%03d", name, stage.ammo[type]);
}

static void drawGrid(void)
{
	int x, y;
	
	for (y = 0 ; y < SCREEN_HEIGHT ; y += GRID_SIZE)
	{
		for (x = 0 ; x < SCREEN_WIDTH ; x += GRID_SIZE)
		{
			blit(gridTexture, x, y, 0);
		}
	}
}
