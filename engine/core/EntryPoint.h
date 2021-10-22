#pragma once

#ifdef __linux__

extern BenzEngine::Application* BenzEngine::CreateApplication();

int main(int argc, char** argv){
    std::cout << "Welcome to Ben's Engine!" << std::endl;
    BenzEngine::Log::Init();
    BE_CORE_WARN("initialized core log");
    int a = 5;
    BE_INFO("initialized client log, Var={0}", a);

    auto app = BenzEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif
