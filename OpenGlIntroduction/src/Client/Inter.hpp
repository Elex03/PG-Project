#pragma once

#include "Window.h"

#include <memory>

namespace GL
{
	class Interface
	{
	public: 
		inline static constexpr const char* Name = "Interface Test";
		inline static constexpr const uint32_t width = 800;
		inline static constexpr const uint32_t height = 600;
	public:
		Interface() = default;
		virtual ~Interface() = default;

		Interface(const Interface& other) = delete;
		Interface& operator==(const Interface& other) = delete;

		void Run();

	private:
		std::unique_ptr<GL::Window> m_Window{};
	};
}