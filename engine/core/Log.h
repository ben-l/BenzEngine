#pragma once
#include <Core.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace BenzEngine {
 
    class BENZ_ENGINE_API Log {
        public:
           static void Init();

           inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { 
               return s_CoreLogger; 
           }
           inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { 
               return s_ClientLogger; 
           }
        private:
           static std::shared_ptr<spdlog::logger> s_CoreLogger;
           static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core Log Macros
#define BE_CORE_TRACE(...) ::BenzEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BE_CORE_INFO(...) ::BenzEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BE_CORE_WARN(...) ::BenzEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BE_CORE_ERROR(...) ::BenzEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BE_CORE_CRITICAL(...) ::BenzEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define BE_TRACE(...)    ::BenzEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BE_INFO(...)     ::BenzEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define BE_WARN(...)     ::BenzEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BE_ERROR(...)    ::BenzEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define BE_CRITICAL(...) ::BenzEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
