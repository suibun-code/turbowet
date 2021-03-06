#pragma once

#include "FSM.h"
#include "Engine.h"
#include "ConsoleIO.h"

class SettingsState : public State
{
private:
	std::vector<Button*> m_v_buttons;
	std::vector<Image*> m_v_images;
	enum btn { go_back };

	template <class T>
	void clean_vector(std::vector<T> vec);

public:
	SettingsState() : State("Settings") {}
	void enter();
	void update(float deltaTime);
	void render();
	void resume() {}
	void exit();
};

template<class T>
inline void SettingsState::clean_vector(std::vector<T> vec)
{
	for (int i = 0; i < (int)vec.size(); i++)
	{
		delete vec[i];
		vec[i] = nullptr;
	}
	vec.clear();
	vec.shrink_to_fit();
}

