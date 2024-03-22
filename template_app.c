
#include <furi_hal.h>
#include <gui/modules/widget.h>
#include <gui/scene_manager.h>
#include "app.h"
#include "scenes/scenes.h"
#include "view.h"

#define RECORD_GUI "gui"
#define TAG "diagnostics_tool"

static Application* app_alloc();
static void app_free(Application*);

void* template_main(void* p) {
    UNUSED(p);
    Application* app = app_alloc();
    Gui* gui = furi_record_open(RECORD_GUI);
    furi_assert(gui);

    view_dispatcher_attach_to_gui(app->view_dispatcher, gui, ViewDispatcherTypeFullscreen);
    scene_manager_next_scene(app->scene_manager, Scene_MainPage);
    view_dispatcher_run(app->view_dispatcher);
    FURI_LOG_I(TAG, "EXIT");

    app_free(app);
    furi_record_close(RECORD_GUI);
    return 0;
}

static Application* app_alloc() {
    Application* new_app = malloc(sizeof(Application));

    new_app->scene_manager = scene_manager_alloc(&diagnostics_scene_event_handlers, new_app);

    new_app->view_dispatcher = view_dispatcher_alloc();
    view_dispatcher_enable_queue(new_app->view_dispatcher);

    view_dispatcher_set_event_callback_context(new_app->view_dispatcher, new_app);
    view_dispatcher_set_custom_event_callback(new_app->view_dispatcher, app_custom_callback);
    view_dispatcher_set_navigation_event_callback(
        new_app->view_dispatcher, app_back_button_handler);

    new_app->main_widget = widget_alloc();
    furi_assert(new_app->main_widget);
    view_dispatcher_add_view(
        new_app->view_dispatcher, View_MainWidgetPage, widget_get_view(new_app->main_widget));

    new_app->warning_popup = popup_alloc();
    view_dispatcher_add_view(
        new_app->view_dispatcher, View_WarningPagePopup, popup_get_view(new_app->warning_popup));

    new_app->connection_popup = popup_alloc();
    view_dispatcher_add_view(
        new_app->view_dispatcher,
        View_SuccessfulConnectionPopup,
        popup_get_view(new_app->connection_popup));

    return new_app;
}
static void app_free(Application* app) {
    view_dispatcher_remove_view(app->view_dispatcher, View_MainWidgetPage);

    view_dispatcher_free(app->view_dispatcher);
    scene_manager_free(app->scene_manager);

    widget_free(app->main_widget);
    free(app);
}