#include"hzpch.h"

#include "Application.h"
#include"Events/ApplicationEvent.h"
#include "Log.h"

namespace Hazel
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		WindowResizedEvent e(1200, 900);
		HZ_TRACE(e);
		while (true)
		{

		}
	}
}