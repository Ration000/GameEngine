#pragma once
#include"Event.h"

#include<sstream>

namespace Hazel
{
	class HAZEL_API MouseMovedEvent: public Event
	{
	public:
		MouseMovedEvent(float x, float y) :m_MouseX(x), m_MouseY(y)
		{

		}

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent\n";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		EVENT_CLASS_TYPE(MouseMoved)
	private:
		float m_MouseX;
		float m_MouseY;
	};

	class HAZEL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y):m_XOffset(x),m_YOffset(y)
		{

		}

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent\n";
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		EVENT_CLASS_TYPE(MouseScrolled)
	private:
		float m_XOffset, m_YOffset;
	};

	class HAZEL_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse|EventCategoryInput)
	protected:
		MouseButtonEvent(int button) :m_Button(button)
		{

		}
		int m_Button;
	};

	class HAZEL_API MousePressedEvent :public MouseButtonEvent
	{
	public:
		MousePressedEvent(int button) :MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MousePressedEvent\n";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseReleasedEvent :public MouseButtonEvent
	{
	public:
		MouseReleasedEvent(int button) :MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseReleasedEvent\n";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}