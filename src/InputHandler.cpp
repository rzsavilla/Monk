#include "InputHandler.h"

InputHandler::InputHandler()
{
	// Initialisation
	bUp = false;
	bDown = false;
	bLeft = false;
	bRight = false;
	bEsc = false;
	bLeftClick = false;
	bRightClick = false;
	bMiddleClick = false;
}

void InputHandler::updateKeyPress(sf::Keyboard::Key key, bool isPressed) {
	switch (key)
	{
	case sf::Keyboard::Unknown:
		break;
	case sf::Keyboard::A:
		break;
	case sf::Keyboard::B:
		break;
	case sf::Keyboard::C:
		break;
	case sf::Keyboard::D:
		break;
	case sf::Keyboard::E:
		break;
	case sf::Keyboard::F:
		break;
	case sf::Keyboard::G:
		break;
	case sf::Keyboard::H:
		break;
	case sf::Keyboard::I:
		break;
	case sf::Keyboard::J:
		break;
	case sf::Keyboard::K:
		break;
	case sf::Keyboard::L:
		break;
	case sf::Keyboard::M:
		break;
	case sf::Keyboard::N:
		break;
	case sf::Keyboard::O:
		break;
	case sf::Keyboard::P:
		break;
	case sf::Keyboard::Q:
		break;
	case sf::Keyboard::R:
		break;
	case sf::Keyboard::S:
		break;
	case sf::Keyboard::T:
		break;
	case sf::Keyboard::U:
		break;
	case sf::Keyboard::V:
		break;
	case sf::Keyboard::W:
		break;
	case sf::Keyboard::X:
		break;
	case sf::Keyboard::Y:
		break;
	case sf::Keyboard::Z:
		break;
	case sf::Keyboard::Num0:
		break;
	case sf::Keyboard::Num1:
		break;
	case sf::Keyboard::Num2:
		break;
	case sf::Keyboard::Num3:
		break;
	case sf::Keyboard::Num4:
		break;
	case sf::Keyboard::Num5:
		break;
	case sf::Keyboard::Num6:
		break;
	case sf::Keyboard::Num7:
		break;
	case sf::Keyboard::Num8:
		break;
	case sf::Keyboard::Num9:
		break;
	case sf::Keyboard::Escape:
		bEsc = isPressed;
		break;
	case sf::Keyboard::LControl:
		break;
	case sf::Keyboard::LShift:
		break;
	case sf::Keyboard::LAlt:
		break;
	case sf::Keyboard::LSystem:
		break;
	case sf::Keyboard::RControl:
		break;
	case sf::Keyboard::RShift:
		break;
	case sf::Keyboard::RAlt:
		break;
	case sf::Keyboard::RSystem:
		break;
	case sf::Keyboard::Menu:
		break;
	case sf::Keyboard::LBracket:
		break;
	case sf::Keyboard::RBracket:
		break;
	case sf::Keyboard::SemiColon:
		break;
	case sf::Keyboard::Comma:
		break;
	case sf::Keyboard::Period:
		break;
	case sf::Keyboard::Quote:
		break;
	case sf::Keyboard::Slash:
		break;
	case sf::Keyboard::BackSlash:
		break;
	case sf::Keyboard::Tilde:
		break;
	case sf::Keyboard::Equal:
		break;
	case sf::Keyboard::Dash:
		break;
	case sf::Keyboard::Space:
		break;
	case sf::Keyboard::Return:
		break;
	case sf::Keyboard::BackSpace:
		break;
	case sf::Keyboard::Tab:
		break;
	case sf::Keyboard::PageUp:
		break;
	case sf::Keyboard::PageDown:
		break;
	case sf::Keyboard::End:
		break;
	case sf::Keyboard::Home:
		break;
	case sf::Keyboard::Insert:
		break;
	case sf::Keyboard::Delete:
		break;
	case sf::Keyboard::Add:
		break;
	case sf::Keyboard::Subtract:
		break;
	case sf::Keyboard::Multiply:
		break;
	case sf::Keyboard::Divide:
		break;
	case sf::Keyboard::Left:
		bLeft = isPressed;
		break;
	case sf::Keyboard::Right:
		bRight = isPressed;
		break;
	case sf::Keyboard::Up:
		bUp = isPressed;
		break;
	case sf::Keyboard::Down:
		bDown = isPressed;
		break;
	case sf::Keyboard::Numpad0:
		break;
	case sf::Keyboard::Numpad1:
		break;
	case sf::Keyboard::Numpad2:
		break;
	case sf::Keyboard::Numpad3:
		break;
	case sf::Keyboard::Numpad4:
		break;
	case sf::Keyboard::Numpad5:
		break;
	case sf::Keyboard::Numpad6:
		break;
	case sf::Keyboard::Numpad7:
		break;
	case sf::Keyboard::Numpad8:
		break;
	case sf::Keyboard::Numpad9:
		break;
	case sf::Keyboard::F1:
		break;
	case sf::Keyboard::F2:
		break;
	case sf::Keyboard::F3:
		break;
	case sf::Keyboard::F4:
		break;
	case sf::Keyboard::F5:
		break;
	case sf::Keyboard::F6:
		break;
	case sf::Keyboard::F7:
		break;
	case sf::Keyboard::F8:
		break;
	case sf::Keyboard::F9:
		break;
	case sf::Keyboard::F10:
		break;
	case sf::Keyboard::F11:
		break;
	case sf::Keyboard::F12:
		break;
	case sf::Keyboard::F13:
		break;
	case sf::Keyboard::F14:
		break;
	case sf::Keyboard::F15:
		break;
	case sf::Keyboard::Pause:
		break;
	case sf::Keyboard::KeyCount:
		break;
	default:
		break;
	}
}

void InputHandler::updateMousePress(sf::Mouse::Button button, bool isPressed) {
	switch (button)
	{
	case sf::Mouse::Left:
		bLeftClick = isPressed;
		break;
	case sf::Mouse::Right:
		bRightClick = isPressed;
		break;
	case sf::Mouse::Middle:
		bMiddleClick = isPressed;
		break;
	case sf::Mouse::XButton1:
		break;
	case sf::Mouse::XButton2:
		break;
	case sf::Mouse::ButtonCount:
		break;
	default:
		break;
	}
}

void InputHandler::updateMousePos(sf::Vector2i position) {
	mousePos = position;
}