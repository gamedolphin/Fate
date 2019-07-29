#include "fate/window.h"
#include "fate/gamestate.h"
#include "fate/log.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <memory>
#include <functional>

namespace Fate {
  void WindowManager::CreateWindow(WindowState &state) {
    LogMessage("Initializing window");
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
      LogMessage( "SDL could not initialize!");
    }
    else {
      state.windowHandle = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 200, 0);
      if( state.windowHandle == nullptr ) {
        LogMessage( "Window could not be created!");
      }
      else {
        LogMessage("Window ready!");
      }
    }
  }

  SDL_SysWMinfo GetPlatformInfo(SDL_Window* window) {
    SDL_SysWMinfo wmi;
    SDL_VERSION(&wmi.version);
    SDL_GetWindowWMInfo(window, &wmi);
    return wmi;
  }

  void* GetDisplayType(WindowState& windowState) {
    auto info = GetPlatformInfo(static_cast<SDL_Window*>(windowState.windowHandle));
    return info.info.x11.display;
  }

  void* GetWindowHandle(WindowState& windowState) {
    auto info = GetPlatformInfo(static_cast<SDL_Window*>(windowState.windowHandle));
    return (void*)static_cast<uintptr_t>(info.info.x11.window);
  };

  void WindowManager::ShutdownWindow(WindowState &state) {
    LogMessage("Shutting down window");
    if(state.windowHandle != nullptr) {
      SDL_DestroyWindow(state.windowHandle);
    }
    LogMessage("Window shutdown");
  }

  WindowManager::~WindowManager() {
     SDL_Quit();
  }
};