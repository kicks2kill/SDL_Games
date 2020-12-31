

#include "enemies.h"

static void tick(void);
static void die(void);

void addEnemy(int x, int y)
{
	Entity *e;
	
	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;
	
	e->side = SIDE_ENEMY;
	e->texture = loadTexture("gfx/enemy01.png");
	e->health = 5;
	e->x = x;
	e->y = y;
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->radius = 32;
	
	e->tick = tick;
	e->die = die;
}

static void tick(void)
{
	self->angle = getAngle(self->x, self->y, player->x, player->y);
	
	calcSlope(player->x, player->y, self->x, self->y, &self->dx, &self->dy);
}

static void die(void)
{
	if (rand() % 2 == 0)
	{
		addRandomPowerup(self->x, self->y);
	}
	
	stage.score += 10;
}
