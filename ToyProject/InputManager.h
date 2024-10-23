#pragma once
#include "stdafx.h"

struct KeyState {
	bool pressed = false;
	bool held = false;
	bool released = false;
};

class InputManager
{
private:
	static std::unordered_map<sf::Keyboard::Key, KeyState> keyState;
	static std::unordered_map<sf::Mouse::Button, KeyState> btnState;
public:
	static void Clear();
	static void UpdateEvent(const sf::Event ev);
	static bool GetKeyPressed(sf::Keyboard::Key key);
	static bool GetKeyHeld(sf::Keyboard::Key key);
	static bool GetKeyReleased(sf::Keyboard::Key key);
	static bool GetBtnPressed(sf::Mouse::Button btn);
	static bool GetBtnHeld(sf::Mouse::Button btn);
	static bool GetBtnReleased(sf::Mouse::Button btn);
	static sf::Vector2f GetMousePos();
	static sf::Vector2f GetMousePosWindow(sf::RenderWindow* window);
};
