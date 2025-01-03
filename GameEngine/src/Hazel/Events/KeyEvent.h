#pragma once
#include"Event.h"

namespace Hazel
{
	class HAZEL_API KeyEvent :public Event
	{
	public:
		inline int GetKeyCode() const{ return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard|EventCategoryInput)
	protected:
		KeyEvent(int keycode) :m_KeyCode(keycode){}

		int m_KeyCode;
	};

	class HAZEL_API KeyPressedEvent :public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatcount) :KeyEvent(keycode), m_RepeatCount(repeatcount){}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_KeyCode << "(" << m_RepeatCount << "repeats)\n";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class HAZEL_API KeyReleasedEvent :public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode, int repeatcount) :KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent\n";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}