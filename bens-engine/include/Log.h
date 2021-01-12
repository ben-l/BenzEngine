#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace BensEngine {
 
    class BENS_ENGINE_API Log {
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
#define BE_CORE_TRACE(...) ::BensEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BE_CORE_INFO(...) ::BensEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BE_CORE_WARN(...) ::BensEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BE_CORE_ERROR(...) ::BensEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BE_CORE_CRITICAL(...) ::BensEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define BE_TRACE(...)    ::BensEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BE_INFO(...)     ::BensEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define BE_WARN(...)     ::BensEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BE_ERROR(...)    ::BensEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define BE_CRITICAL(...) ::BensEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
