#include <stdio.h>
#include "GL/freeglut.h"

#define BUTTON_IDLE_X  50
#define BUTTON_IDLE_Y  100
#define BUTTON_SETTINGS_X 200
#define BUTTON_SETTINGS_Y 100

#define BUTTON_PO_OFFSET 10

class Button {
public:
    int x, y, width, height;
    bool pressed;

    Button(int x_, int y_, int w, int h)
        : x(x_), y(y_), width(w), height(h), pressed(false) {}

    void draw() const {
        glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + width, y);
        glVertex2i(x + width, y + height);
        glVertex2i(x, y + height);
        glEnd();
    }

    bool isInside(int mx, int my) const {
        return (mx >= x && mx <= x + width && my >= y && my <= y + height);
    }
};

extern Button button_idle;
extern Button button_settings;

enum event_t
{
	SETTINGS_BUTTON_EVENT = 0,
	IDLE_BUTTON_EVENT = 1,
	DISPLAY_EVENT,
	ENTRY_EVENT,
	EXIT_EVENT,

	EVENT_MAXIMUM
};

typedef void (*f_t)(void);

enum state_t
{
	IDLE_STATE = 0,
	SETTINGS_STATE = 1,
	
	STATE_MAX
};

extern state_t current_state;

void idle_state_display(void);
void settings_state_disply(void);
void idle_button_SC_ev_handler(void);
void idle_entry(void);
void idle_exit(void);
void settings_button_SC_ev_handler(void);
void settings_entry(void);
void settings_exit(void);
void post_event(event_t event);

void drawText(const char* text, int x, int y);