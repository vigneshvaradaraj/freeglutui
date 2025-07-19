#include "statemachine.h"


state_t current_state = IDLE_STATE;
state_t previous_state = IDLE_STATE;

f_t state_handler_array[STATE_MAX][EVENT_MAXIMUM] = 
{
    [IDLE_STATE] = {NULL,idle_button_SC_ev_handler,idle_state_display,idle_entry,idle_exit},
    [SETTINGS_STATE] = {settings_button_SC_ev_handler,NULL,settings_state_disply,settings_entry,settings_exit}
};

void post_event(event_t event)
{
    state_t temp_state_to_exit = current_state;
    if(NULL != state_handler_array[current_state][event])
    {
        state_handler_array[current_state][event]();
    }
    if(current_state != previous_state)
    {
        if(NULL != state_handler_array[temp_state_to_exit][EXIT_EVENT])
        {
            state_handler_array[temp_state_to_exit][EXIT_EVENT]();
        }
        if(NULL != state_handler_array[current_state][ENTRY_EVENT])
        {
            state_handler_array[current_state][ENTRY_EVENT]();
        }
        previous_state = current_state;
    }
}

static void displayText(float x, float y, const char* text) 
{
    glRasterPos2f(x, y); // Set position in window
    for (int i = 0; i < strlen(text); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void idle_state_display(void)
{
    printf("idle_state_display executed!\n");
    glColor3f(0.0f, 0.0f, 1.0f);//set text color
    displayText(-0.8f, 0.9f, "idle_state");
    button_idle.draw();
}
void settings_state_disply(void)
{
    printf("settings_state_disply executed!\n");
    glColor3f(0.0f, 0.0f, 1.0f);//set text color
    displayText(-0.8f, 0.9f, "settings_state");
    button_settings.draw();
}

void idle_button_SC_ev_handler(void)
{
    printf("idle_button_SC_ev_handler executed!\n");
    current_state = SETTINGS_STATE;
}
void idle_entry(void)
{
    printf("idle_entry executed!\n");
}
void idle_exit(void)
{
    printf("idle_exit executed!\n");
}
void settings_button_SC_ev_handler(void)
{
    printf("settings_button_SC_ev_handler executed!\n");
    current_state = IDLE_STATE;
}
void settings_entry(void)
{
    printf("settings_entry executed!\n");
}
void settings_exit(void)
{
    printf("settings_exit executed!\n");
}