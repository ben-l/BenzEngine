#pragma once
#include <Layer.h>

namespace BensEngine {
    class ImGuiLayer : public Layer {
        public:
            ImGuiLayer();
            ~ImGuiLayer();

            void OnAttach();
            void OnDetach();
            void OnUpdate();
            void OnEvent(Event& event);
        private:
            pass

    };
}


