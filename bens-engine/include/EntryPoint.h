#pragma once

#ifdef __linux__

extern BensEngine::Application* BensEngine::CreateApplication();


int main(int argc, char** argv){
    std::cout << "Welcome to Ben's Engine!" << std::endl;
    auto app = BensEngine::CreateApplication();
    app->Run();
    delete app;
}


#endif
