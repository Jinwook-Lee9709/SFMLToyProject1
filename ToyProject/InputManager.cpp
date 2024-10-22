#include "stdafx.h"

std::unordered_map<sf::Keyboard::Key, KeyState> InputManager::keyState;
std::unordered_map<sf::Mouse::Button, KeyState> InputManager::btnState;

void InputManager::Clear()
{
	for (auto& pair : keyState) {
		pair.second.pressed = false;
		pair.second.released = false;
	}
	for (auto& pair : btnState) {
		pair.second.pressed = false;
		pair.second.released = false;
	}
}

void InputManager::UpdateEvent(const sf::Event ev)
{
	sf::Keyboard::Key keyCode = ev.key.code;
	sf::Mouse::Button btnCode = ev.mouseButton.button;
	switch (ev.type) {
		
		case sf::Event::KeyPressed:
		{
			if (!keyState[keyCode].held) {
				keyState[keyCode].held = true;
				keyState[keyCode].pressed = true;
			}
			break;
		}
		case sf::Event::KeyReleased:
		{
			keyState[keyCode].held = false;
			keyState[keyCode].released = true;
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (!btnState[btnCode].held) {
				btnState[btnCode].held = true;
				btnState[btnCode].pressed = true;
			}
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			btnState[btnCode].held = false;
			btnState[btnCode].released = true;
			break;
		}
	}
}

bool InputManager::GetKeyPressed(sf::Keyboard::Key key)
{
	return keyState[key].pressed;
}

bool InputManager::GetKeyHeld(sf::Keyboard::Key key)
{
	return keyState[key].held;
}
bool InputManager::GetKeyReleased(sf::Keyboard::Key key)
{
	return keyState[key].released;
}


bool InputManager::GetBtnPressed(sf::Mouse::Button btn) {
	return btnState[btn].pressed;
}
bool InputManager::GetBtnHeld(sf::Mouse::Button btn)
{
	return btnState[btn].held;
}
bool InputManager::GetBtnReleased(sf::Mouse::Button btn)
{
	return btnState[btn].released;
}

sf::Vector2f InputManager::GetMousePos()
{
	return sf::Vector2f(sf::Mouse::getPosition());
}
sf::Vector2f InputManager::GetMousePosWindow(sf::RenderWindow* window)
{
	return sf::Vector2f(sf::Mouse::getPosition(*window));
}

