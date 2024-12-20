#pragma once
#include"Event.h"

#include<sstream>

namespace Hazel
{
	class HAZEL_API WindowResizedEvent :public Event
	{
	public:
		WindowResizedEvent(unsigned int width,unsigned int height):m_Width(width),m_Height(height)
		{

		}

		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Handled; }

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent\n";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResizes)
	private:
		unsigned int m_Width, m_Height;
	};

	class HAZEL_API WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent()
		{

		}

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent\n";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};

	class HAZEL_API WindowTickEvent :public Event
	{
	public:
		WindowTickEvent()
		{

		}

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "WindowTickEvent\n";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)
	};

	class HAZEL_API WindowUpdateEvent :public Event
	{
	public:
		WindowUpdateEvent()
		{

		}

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "WindowUpdateEvent\n";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)
	};

	class HAZEL_API WindowRenderEvent :public Event
	{
	public:
		WindowRenderEvent()
		{

		}

		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "WindowRenderEvent\n";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRender)
	};
}