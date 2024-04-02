#include "Inter.hpp"
namespace GL {
	void Interface::Run() {
		m_Window = std::make_unique<GL::Window>(Name, width, height);

		while (m_Window->Runner())
		{
			m_Window->GetEnvents();
		}
	}
}