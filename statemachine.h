#include <stdio.h>
typedef void (*f_t)(void);

typedef enum
{
	SETTINGS_BUTTON_EVENT,
	IDLE_BUTTON_EVENT,
	ENTRY_EVENT,
	EXIT_EVENT,
	EVENT_MAX
} event_t;

typedef enum
{
	IDLE_STATE = 0,
	SETTINGS_STATE = 1,
	
	STATE_MAX
}state_t;

extern state_t current_state;

void idle_button_SC_ev_handler(void);
void idle_entry(void);
void idle_exit(void);
void settings_button_SC_ev_handler(void);
void settings_entry(void);
void settings_exit(void);
void post_event(event_t event);