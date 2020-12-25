#pragma once

#ifdef __linux__

extern BensEngine::Application* BensEngine::CreateApplication();

int main(int argc, char** argv){
    std::cout << "Welcome to Ben's Engine!" << std::endl;
    BensEngine::Log::Init();
    BE_CORE_WARN("initialized core log");
    int a = 5;
    BE_INFO("initialized client log, Var={0}", a);

    auto app = BensEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif
