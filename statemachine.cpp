#include "statemachine.h"

state_t current_state = IDLE_STATE;
state_t previous_state = IDLE_STATE;

f_t state_handler_array[STATE_MAX][EVENT_MAX] = 
{
    {NULL,idle_button_SC_ev_handler,idle_entry,idle_exit},
    {settings_button_SC_ev_handler,NULL,settings_entry,settings_exit}
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

void idle_button_SC_ev_handler(void)
{

}
void idle_entry(void)
{

}
void idle_exit(void)
{

}
void settings_button_SC_ev_handler(void)
{

}
void settings_entry(void)
{

}
void settings_exit(void)
{
    
}