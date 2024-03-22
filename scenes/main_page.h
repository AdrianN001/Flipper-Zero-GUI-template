#ifndef MAIN_PAGE
#define MAIN_PAGE

#include <furi.h>
#include <gui/modules/widget.h>
#include <gui/scene_manager.h>
#include <gui/icon_i.h>
#include <gui/elements.h>
#include "views.h"

static void main_page_scene_on_enter(void* context) {
    furi_assert(context);

    Application* app = (Application*)context;
    Widget* page_widget = app->main_widget;
    widget_reset(page_widget);

    // top indicator
    widget_add_string_element(page_widget, 36, 10, AlignCenter, AlignTop, FontSecondary, "test");

    view_dispatcher_switch_to_view(app->view_dispatcher, View_MainWidgetPage);
}

static bool main_page_scene_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return 0;
}

static void main_page_scene_on_exit(void* context) {
    furi_assert(context);

    Application* app = (Application*)context;
    widget_reset(app->main_widget);
}

#endif