#pragma once

#include <memory>

#include "APIContext.hpp"

namespace ChimeraEngineCore
{
	class OpenGLContext : public APIContext
	{
	public:
		OpenGLContext();
		~OpenGLContext() = default;

		std::unique_ptr<Window> createWindow(const std::string& title, const int width, const int height) override;
		void initializeAPI(void* window) override;
		void render() override;
	private:
		struct _Impl;
		std::unique_ptr<_Impl> _impl;
	};
}