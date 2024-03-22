#pragma once

#include <furi.h>
#include <gui/scene_manager.h>
#include "scenes/scene.h"
#include "app.h"

#ifndef TAG
#define TAG "DIAGNOSTIC"
#endif

extern bool (*const diagnostic_scene_on_event_handlers[])(void*, SceneManagerEvent);
extern void (*const diagnostic_scene_on_exit_handlers[])(void*);
extern void (*const diagnostic_scene_on_enter_handlers[])(void*);

static const SceneManagerHandlers ev_handler = {
  .on_enter_handlers = canutils_scene_on_enter_handlers,
  .on_event_handlers = canutils_scene_on_event_handlers,
  .on_exit_handlers  = canutils_scene_on_exit_handlers,
  .scene_num         = ViewScene_Total
};

void diagnostic_scene_main_menu_callback_handler(void* contenxt, const uint32_t index){
    FURI_LOG_T(TAG, "diagnostics main menu");

    const Application *app = (Application*)context;


    switch(index){
        case Select_Config:
            scene_manager_handle_custom_event(app->scene_manager, Event_Config);
            break;
    }
}