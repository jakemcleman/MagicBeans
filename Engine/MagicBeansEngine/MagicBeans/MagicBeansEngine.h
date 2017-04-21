#pragma once

#include <string>
#include "WindowManager.h"

#include "GameObject.h"

namespace Beans
{
  // This is an example of a class exported from the MagicBeansEngine.lib
  class MagicBeansEngine
  {
  public:
    MagicBeansEngine(const std::string& gamename);

    void RunGameLoop();

  private:
    void UpdateStep();
    void DrawStep();

    double timeElapsed_;
    WindowManager gameWindow_;
    std::string gameName_;

    GameObject* cameraObject_;
  };

}