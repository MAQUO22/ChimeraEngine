#include "APIContextPicker.hpp"
#include "VulkanContext.hpp"
#include "DirectXContext.hpp"
#include "OpenGLContext.hpp"

namespace ChimeraEngineCore
{

    std::unique_ptr<APIContext> APIContextPicker::getAPIContext(int argc, char* argv[])
    {
        APIType api_type = APIType::Vulkan;
        std::unique_ptr<APIContext> api = std::make_unique<VulkanContext>();

        if (argc > 3)
        {
            std::cerr << "Usage only one API: OpenGL, Vulkan or DirectX" << std::endl;
        }
        else if (argc == 2)
        {
            api_type = parseAPIType(argv[1]);

            switch (api_type)
            {
            case APIType::OpenGL:
                api = std::make_unique<OpenGLContext>();
                break;
            case APIType::Vulkan:
                api = std::make_unique<VulkanContext>();
                break;
            case APIType::DirectX:
                api = std::make_unique<DirectXContext>();
                break;
            default:
                std::cerr << "Invalid API type specified!" << std::endl;
                break;
            }
        }

        return api;
    }
}
