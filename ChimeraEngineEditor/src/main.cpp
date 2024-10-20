#include <string>
#include <iostream>

#include "Application.hpp"
#include "APIContextPicker.hpp"

int main(int argc, char* argv[]) {
    
    auto api_context = std::move(ChimeraEngineCore::APIContextPicker::getAPIContext(argc, argv));
    auto application = std::make_unique<ChimeraEngineCore::Application>(std::move(api_context));
    application->start();
    return 0;
    
}
