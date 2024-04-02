#pragma once

#include "Window.h"

#include <memory>

class InterfaceGL
{
public: 
	inline static constexpr const char* Name = "Interface Test";
	inline static constexpr const uint32_t width = 800;
	inline static constexpr const uint32_t height = 600;
public:
	InterfaceGL() = default;
	virtual ~InterfaceGL() = default;

	InterfaceGL(const InterfaceGL& other) = delete;
	InterfaceGL& operator==(const InterfaceGL& other) = delete;

	void Run();

private:
	std::unique_ptr<GL::Window> m_Window{};
};
