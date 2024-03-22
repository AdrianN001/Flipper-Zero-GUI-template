#pragma once
#include <gui/scene_manager.h>

#include "main_page.h"
#include "warning_page.h"
#include "happy_page.h"
#include "views.h"

typedef enum {
  Scene_MainPage,
  Scene_WarningPage,
  Scene_SuccessfulConnection,

  Scene_count
} ApplicationScene;

static void (*const diagnostic_scene_on_enter_handlers[])(void*) = {
    main_page_scene_on_enter,
    warning_page_scene_on_enter,
    connected_page_scene_on_enter};

static bool (*const diagnostic_scene_on_event_handlers[])(void*, SceneManagerEvent) = {
    main_page_scene_on_event,
    warning_page_scene_on_event,
    connected_page_scene_on_event};

static void (*const diagnostic_scene_on_exit_handlers[])(
    void*) = {main_page_scene_on_exit, warning_page_scene_on_exit, connected_page_scene_on_exit};

/** collection of all on_enter, on_event, on_exit handlers */
static SceneManagerHandlers diagnostics_scene_event_handlers = {

    .on_enter_handlers = diagnostic_scene_on_enter_handlers,
    .on_event_handlers = diagnostic_scene_on_event_handlers,
    .on_exit_handlers = diagnostic_scene_on_exit_handlers,
    .scene_num = Scene_count};
