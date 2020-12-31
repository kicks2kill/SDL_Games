

#include "entities.h"

static void touchOthers(void);

void doEntities(void)
{
	Entity *e, *prev;
	
	prev = &stage.entityHead;
	
	for (e = stage.entityHead.next ; e != NULL ; e = e->next)
	{
		self = e;
		
		if (e->tick)
		{
			e->tick();
		}
		
		e->x += e->dx;
		e->y += e->dy;
		
		if (e->touch)
		{
			touchOthers();
		}
		
		e->reload = MAX(e->reload - 1, 0);
		
		if (e == player)
		{
			e->x = MIN(MAX(e->x, e->w / 2), SCREEN_WIDTH - e->w / 2);
			e->y = MIN(MAX(e->y, e->h / 2), SCREEN_HEIGHT - e->h / 2);
		}
		
		if (e->health <= 0)
		{
			if (e->die)
			{
				e->die();
			}
			
			if (e == stage.entityTail)
			{
				stage.entityTail = prev;
			}
			
			prev->next = e->next;
			free(e);
			e = prev;
		}
		
		prev = e;
	}
}

static void touchOthers(void)
{
	Entity *e;
	int distance;
	
	for (e = stage.entityHead.next ; e != NULL ; e = e->next)
	{
		if (e != self)
		{
			distance = getDistance(self->x, self->y, e->x, e->y);
			
			if (distance < e->radius + self->radius)
			{
				self->touch(e);
			}
		}
	}
}

void drawEntities(void)
{
	Entity *e;
	
	for (e = stage.entityHead.next ; e != NULL ; e = e->next)
	{
		blitRotated(e->texture, e->x, e->y, e->angle);
	}
}
