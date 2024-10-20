#pragma once

#include "APIContext.hpp"

namespace ChimeraEngineCore
{
    enum class  APIType
    {
        OpenGL,
        Vulkan,
        DirectX,
        Unknown
    };

    inline APIType parseAPIType(const std::string& arg)
    {
        if (arg == "OpenGL" || arg == "GL")
            return APIType::OpenGL;
        else if (arg == "Vulkan" || arg == "VK")
            return APIType::Vulkan;
        else if (arg == "DirectX" || arg == "DX")
            return APIType::DirectX;
        else
            return APIType::Unknown;
    }

	class APIContextPicker
	{
	public:
        APIContextPicker() = delete;
        
        static std::unique_ptr<APIContext> getAPIContext(int argc, char* argv[]);
	};
}