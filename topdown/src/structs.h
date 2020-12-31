

typedef struct Texture Texture;
typedef struct Entity Entity;

typedef struct {
	void (*logic)(void);
	void (*draw)(void);
} Delegate;

struct Texture {
	char name[MAX_NAME_LENGTH];
	SDL_Texture *texture;
	Texture *next;
};

typedef struct {
	int x;
	int y;
	int button[MAX_MOUSE_BUTTONS];
	int wheel;
} Mouse;

struct Entity {
	int side;
	float x;
	float y;
	int w;
	int h;
	int radius;
	float dx;
	float dy;
	int health;
	int reload;
	int angle;
	int weaponType;
	SDL_Texture *texture;
	void (*tick)(void);
	void (*touch)(Entity *other);
	void (*die)(void);
	Entity *next;
};

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	Delegate delegate;
	int keyboard[MAX_KEYBOARD_KEYS];
	Mouse mouse;
	Texture textureHead, *textureTail;
} App;

typedef struct {
	int score;
	Entity entityHead, *entityTail;
	Entity bulletHead, *bulletTail;
	int ammo[WPN_MAX];
} Stage;
