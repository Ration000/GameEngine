#pragma once

#include"Hazel\Core.h"

#include<iostream>
#include<string>
#include<functional>

namespace Hazel
{
	enum class EventType
	{
		None = 0,
		WindowClose,WindowResizes,WindowFocus,WindowLostFocus,WindowMoved,
		AppTick,AppUpdate,AppRender,
		KeyPressed,KeyReleased,
		MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled
	};

	enum EventCategory
	{
		None=0,
		EventCategoryApplication =BIT(0),
		EventCategoryInput =BIT(1),
		EventCategoryKeyboard =BIT(2),
		EventCategoryMouse =BIT(3),
		EventCategoryMouseButton =BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::type;}/*返回type的EventType类型的值，如EventType::KeyPressed*/\
								virtual EventType GetEventType()const override{return GetStaticType();}\
								virtual const char* GetName() const override{return #type;}/*返回type的string类型的值，如"KeyPressed"*/

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}
	
	class HAZEL_API Event //base class of events
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;//获取Event的类型，因为Event为基类，通过基类指针引用的Event需要判断Event类型
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); };

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event): m_Event(event)
		{

		}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType)
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, Event& e)
	{
		return os << e.ToString();
	}
}