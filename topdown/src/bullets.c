

#include "bullets.h"

static void fireDonkUzi(void);
static void fireDonkShotgun(void);
static void fireDonkPistol(void);

static SDL_Texture *donkBullet;

void initBullets(void)
{
	donkBullet = loadTexture("gfx/donkBullet.png");
}

void fireDonkBullet(void)
{
	switch (player->weaponType)
	{
		case WPN_UZI:
			fireDonkUzi();
			break;
			
		case WPN_SHOTGUN:
			fireDonkShotgun();
			break;
			
		default:
			fireDonkPistol();
			break;
	}
}

static void fireDonkUzi(void)
{
	Entity *b;
	
	b = malloc(sizeof(Entity));
	memset(b, 0, sizeof(Entity));
	stage.bulletTail->next = b;
	stage.bulletTail = b;
	
	b->x = player->x;
	b->y = player->y;
	b->texture = donkBullet;
	b->health = FPS * 2;
	b->angle = player->angle;
	
	calcSlope(app.mouse.x, app.mouse.y, b->x, b->y, &b->dx, &b->dy);
	
	b->dx *= 16;
	b->dy *= 16;
	
	player->reload = 4;
}

static void fireDonkShotgun(void)
{
	Entity *b;
	int i, destX, destY;
	float dx, dy;
	
	calcSlope(app.mouse.x, app.mouse.y, player->x, player->y, &dx, &dy);
	
	dx = player->x + (dx * 128);
	dy = player->y + (dy * 128);
	
	for (i = 0 ; i < 8 ; i++)
	{
		b = malloc(sizeof(Entity));
		memset(b, 0, sizeof(Entity));
		stage.bulletTail->next = b;
		stage.bulletTail = b;
		
		b->x = player->x + rand() % 16 - rand() % 16;
		b->y = player->y + rand() % 16 - rand() % 16;
		b->texture = donkBullet;
		b->health = FPS * 2;
		b->angle = player->angle;
		
		destX = dx + (rand() % 24 - rand() % 24);
		destY = dy + (rand() % 24 - rand() % 24);
		
		calcSlope(destX, destY, b->x, b->y, &b->dx, &b->dy);
		
		b->dx *= 16;
		b->dy *= 16;
	}
	
	player->reload = FPS * 0.75;
}

static void fireDonkPistol(void)
{
	Entity *b;
	
	b = malloc(sizeof(Entity));
	memset(b, 0, sizeof(Entity));
	stage.bulletTail->next = b;
	stage.bulletTail = b;
	
	b->x = player->x;
	b->y = player->y;
	b->texture = donkBullet;
	b->health = FPS * 2;
	b->angle = player->angle;
	
	calcSlope(app.mouse.x, app.mouse.y, b->x, b->y, &b->dx, &b->dy);
	
	b->dx *= 16;
	b->dy *= 16;
	
	player->reload = 16;
}

void doBullets(void)
{
	Entity *b, *prev;
	
	prev = &stage.bulletHead;
	
	for (b = stage.bulletHead.next ; b != NULL ; b = b->next)
	{
		b->x += b->dx;
		b->y += b->dy;
		
		if (--b->health <= 0)
		{
			if (b == stage.bulletTail)
			{
				stage.bulletTail = prev;
			}
			
			prev->next = b->next;
			free(b);
			b = prev;
		}
		
		prev = b;
	}
}

void drawBullets(void)
{
	Entity *b;
	
	for (b = stage.bulletHead.next ; b != NULL ; b = b->next)
	{
		blitRotated(b->texture, b->x, b->y, b->angle);
	}
}
