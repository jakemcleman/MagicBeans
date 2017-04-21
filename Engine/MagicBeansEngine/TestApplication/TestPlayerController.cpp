#include "stdafx.h"
#include "TestPlayerController.h"

#include "Component.h"
#include "GameObject.h"

#include "Sprite.h"
#include "Transform.h"

#include "InputHandler.h"
#include "GLFW\glfw3.h"

INIT_REFLECTION(PlayerController)

PlayerController::PlayerController(GameObject * owner) : Component(owner)
{
  speed = 10;
  sprite_ = Owner->AddComponent<Sprite>();
  transform_ = Owner->AddComponent<Transform>();

  sprite_->Color = vec4(0, 0, 1, 1);
}

void PlayerController::Update(double dt)
{
  sprite_ = Owner->GetComponent<Sprite>();
  transform_ = Owner->GetComponent<Transform>();

  if (InputHandler::IsKeyDown(GLFW_KEY_LEFT))
  {
    transform_->position += vec3(-dt * speed , 0, 0);
  }
  if (InputHandler::IsKeyDown(GLFW_KEY_RIGHT))
  {
    transform_->position += vec3(dt * speed, 0, 0);
  }
  if (InputHandler::IsKeyDown(GLFW_KEY_UP))
  {
    transform_->position += vec3(0, dt * speed, 0);
  }
  if (InputHandler::IsKeyDown(GLFW_KEY_DOWN))
  {
    transform_->position += vec3(0, -dt * speed, 0);
  }
}

void PlayerController::UpdatePlayerControllers(double dt)
{
  for (auto& pc : GetList())
  {
    pc->Update(dt);
  }
}