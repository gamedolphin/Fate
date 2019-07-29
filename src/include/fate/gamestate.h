#pragma once
#include "window.h"
#include "renderer.h"
#include "input.h"

namespace Fate {

  struct GameState {
    bool isRunning = false;
    WindowState windowState;
    InputState inputState;
    RenderState renderState;
  };
}
