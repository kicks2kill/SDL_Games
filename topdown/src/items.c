

#include "items.h"

static void tick(void);
static void addHealthPowerup(int x, int y);
static void addUziPowerup(int x, int y);
static void addShotgunPowerup(int x, int y);
static void uziTouch(Entity *other);
static void shotgunTouch(Entity *other);
static void healthTouch(Entity *other);

static SDL_Texture *uziTexture;
static SDL_Texture *shotgunTexture;
static SDL_Texture *healthTexture;

void initItems(void)
{
	uziTexture = loadTexture("gfx/uzi.png");
	shotgunTexture = loadTexture("gfx/shotgun.png");
	healthTexture = loadTexture("gfx/health.png");
}

void addRandomPowerup(int x, int y)
{
	int r;
	
	r = rand() % 5;
	
	if (r == 0)
	{
		addHealthPowerup(x, y);
	}
	else if (r < 3)
	{
		addUziPowerup(x, y);
	}
	else
	{
		addShotgunPowerup(x, y);
	}
}

static Entity *createPowerup(int x, int y)
{
	Entity *e;
	
	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;
	
	e->x = x;
	e->y = y;
	e->health = FPS * 5;
	e->tick = tick;
	e->radius = 16;
	
	e->dx = -200 + (rand() % 400);
	e->dy = -200 + (rand() % 400);
	
	e->dx /= 100;
	e->dy /= 100;
	
	return e;
}

static void tick(void)
{
	self->health--;
	
	self->dx *= 0.98;
	self->dy *= 0.98;
}

static void addHealthPowerup(int x, int y)
{
	Entity *e;
	
	e = createPowerup(x, y);
	
	e->texture = healthTexture;
	e->touch = healthTouch;
}

static void addUziPowerup(int x, int y)
{
	Entity *e;
	
	e = createPowerup(x, y);
	
	e->texture = uziTexture;
	e->touch = uziTouch;
}

static void addShotgunPowerup(int x, int y)
{
	Entity *e;
	
	e = createPowerup(x, y);
	
	e->texture = shotgunTexture;
	e->touch = shotgunTouch;
}

static void uziTouch(Entity *other)
{
	if (other == player)
	{
		self->health = 0;
		
		stage.ammo[WPN_UZI] += 25;
	}
}

static void shotgunTouch(Entity *other)
{
	if (other == player)
	{
		self->health = 0;
		
		stage.ammo[WPN_SHOTGUN] += 4;
	}
}

static void healthTouch(Entity *other)
{
	if (other == player)
	{
		self->health = 0;
		
		player->health++;
	}
}
