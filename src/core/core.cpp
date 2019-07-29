#include "fate/core.h"
#include "fate/gamestate.h"
#include "fate/log.h"

namespace Fate {

  Game::Game() {

  }

  void Game::Run(GameState& state) {

    state.isRunning = true;

    window.CreateWindow(state.windowState);
    renderer.InitializeRenderer(state.windowState, state.renderState);

    while(state.isRunning) {
      state.inputState = input.ReadInput(state.inputState);
      if(state.inputState.eventType == EventType::QUIT) {
        state.isRunning = false;
      }
    }


    window.ShutdownWindow(state.windowState);
  }
};
