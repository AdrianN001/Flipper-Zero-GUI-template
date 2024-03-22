#pragma once

#include <furi.h>
#include <furi_hal.h>

#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/widget.h>
#include <gui/modules/popup.h>

typedef struct app {
    // GUI
    SceneManager* scene_manager;
    ViewDispatcher* view_dispatcher;
    Widget* main_widget;
    Popup* warning_popup;
    Popup* connection_popup;

} Application;
