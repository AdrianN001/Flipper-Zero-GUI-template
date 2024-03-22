#ifndef WARNING_PAGE
#define WARNING_PAGE

#include <furi.h>
#include <gui/scene_manager.h>

static void warning_page_scene_on_enter(void* context) {
    UNUSED(context);
}

static bool warning_page_scene_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return 0;
}

static void warning_page_scene_on_exit(void* context) {
    UNUSED(context);
}

#endif