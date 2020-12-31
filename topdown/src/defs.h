

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define STRNCPY(dest, src, n) strncpy(dest, src, n); dest[n - 1] = '\0'
#define PI 3.14159265358979323846

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

#define MAX_NAME_LENGTH        32
#define MAX_LINE_LENGTH        1024

#define FPS 60

#define GRID_SIZE 64

#define MAX_KEYBOARD_KEYS 350
#define MAX_MOUSE_BUTTONS	6

#define MAX_SND_CHANNELS 16

#define PLAYER_SPEED 6

#define GLYPH_WIDTH  18
#define GLYPH_HEIGHT 29

enum
{
	TEXT_LEFT,
	TEXT_CENTER,
	TEXT_RIGHT
};

enum
{
	WPN_PISTOL,
	WPN_UZI,
	WPN_SHOTGUN,
	WPN_MAX
};

enum
{
	SIDE_NONE,
	SIDE_PLAYER,
	SIDE_ENEMY
};
