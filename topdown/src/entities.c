
#include "entities.h"

void doEntities(void)
{
	Entity *e;
	
	for (e = stage.entityHead.next ; e != NULL ; e = e->next)
	{
		e->x += e->dx;
		e->y += e->dy;
		
		e->reload = MAX(e->reload - 1, 0);
		
		if (e == player)
		{
			e->x = MIN(MAX(e->x, e->w / 2), SCREEN_WIDTH - e->w / 2);
			e->y = MIN(MAX(e->y, e->h / 2), SCREEN_HEIGHT - e->h / 2);
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
