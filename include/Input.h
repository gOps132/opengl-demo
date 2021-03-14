#ifndef __EVENT_H__
#define __EVENT_H__

#include <GLFW/glfw3.h>
#include <utility>

class Input {
public:
	static bool key_pressed(int keycode);
	static bool mouse_btn_pressed(int button);
	static std::pair<float, float> get_mouse_pos();
	static float get_mouse_x();
	static float get_mouse_y();
private:
	static Input* s_input;
};

#endif // __EVENT_H__