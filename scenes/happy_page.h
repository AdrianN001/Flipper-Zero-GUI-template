#ifndef HAPPY_SCREEN
#define HAPPY_SCREEN

#include <furi.h>
#include <gui/scene_manager.h>

static void connected_page_scene_on_enter(void* context) {
    UNUSED(context);
}

static bool connected_page_scene_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return 0;
}

static void connected_page_scene_on_exit(void* context) {
    UNUSED(context);
}

#endif