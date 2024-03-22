#pragma once
#include <furi.h>
#include <gui/scene_manager.h>

// Let the view controll this operations

static bool app_back_button_handler(void* context) {
    furi_assert(context);
    Application* app = context;
    return scene_manager_handle_back_event(app->scene_manager);
}

static bool app_custom_callback(void* context, uint32_t custom_event) {
    furi_assert(context);
    Application* app = context;
    return scene_manager_handle_custom_event(app->scene_manager, custom_event);
}