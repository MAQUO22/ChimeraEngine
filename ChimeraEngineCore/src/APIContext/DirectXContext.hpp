#include "APIContext.hpp"

namespace ChimeraEngineCore
{
	class DirectXContext : public APIContext
	{
	public:
		DirectXContext();
		~DirectXContext() = default;

		std::unique_ptr<Window> createWindow(const std::string& title, const int width, const int height) override;
		void initializeAPI(void* window) override;
		void render() override;
	private:
		struct _Impl;
		std::unique_ptr<_Impl> _impl;
	};
}