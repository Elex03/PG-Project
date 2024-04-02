#pragma once
#include <cstdint>
namespace GL
{
	class Window
	{
	public: 
		Window(const char* name, uint32_t width, uint32_t height);
		virtual ~Window();

		Window(const Window& other) = delete;
		Window operator==(const Window& other) = delete;
			
		inline bool Runner() const { return m_Runner; };
		inline void Close() { m_Runner = false; };
		void GetEnvents();
	private:
		void* m_WindowHandle = nullptr;
		bool m_Runner = true;

	};
}

