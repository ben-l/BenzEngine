#include <BenzEngine.h>
#include <imgui.h>

class ExampleLayer : public BenzEngine::Layer
{
    public:
        ExampleLayer() : Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
        {
        	m_VertexArray.reset(BenzEngine::VertexArray::Create());

        	 // Index Buffer
        	float vertices[3 * 7] = {
        	    -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
        	    0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
        	    0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f 
        	};

        	std::shared_ptr<BenzEngine::VertexBuffer> vertexBuffer;
        	vertexBuffer.reset(BenzEngine::VertexBuffer::Create(vertices, sizeof(vertices)));
			BenzEngine::BufferLayout layout = {
        	    { BenzEngine::ShaderDataType::Float3, "a_Position" },
        	    { BenzEngine::ShaderDataType::Float4, "a_Color" }
        	};

        	vertexBuffer->SetLayout(layout);
        	m_VertexArray->AddVertexBuffer(vertexBuffer);

        	uint32_t indices[3] = { 0, 1, 2};
        	std::shared_ptr<BenzEngine::IndexBuffer> indexBuffer;
        	indexBuffer.reset(BenzEngine::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        	m_VertexArray->SetIndexBuffer(indexBuffer);

        	m_SquareVA.reset(BenzEngine::VertexArray::Create());

        	float squareVertices[3 * 4] = {
        	   -0.75f,-0.75f, 0.0f,
        	    0.75f,-0.75f, 0.0f, 
        	    0.75f, 0.75f, 0.0f,
        	   -0.75f, 0.75f, 0.0f
        	};

        	std::shared_ptr<BenzEngine::VertexBuffer> squareVB; 
        	squareVB.reset(BenzEngine::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

			BenzEngine::BufferLayout squareVBLayout = {
        	    { BenzEngine::ShaderDataType::Float3, "a_Position" }
        	};

        	squareVB->SetLayout(squareVBLayout);
        	m_SquareVA->AddVertexBuffer(squareVB);

        	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0};
        	std::shared_ptr<BenzEngine::IndexBuffer> squareIB;
        	squareIB.reset(BenzEngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
        	m_SquareVA->SetIndexBuffer(squareIB);

        	std::string vertexSrc = R"(
        	    #version 330 core

        	    layout(location = 0) in vec3 a_Position;
        	    layout(location = 1) in vec4 a_Color;

        	    uniform mat4 u_ViewProjection;

        	    out vec3 v_Position;
        	    out vec4 v_Color;

        	    void main(){
        	        v_Position = a_Position + 0.5;
        	        v_Color = a_Color;
        	        gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
        	    }
        	)";

        	std::string fragmentSrc = R"(
        	    #version 330 core
        	    layout(location = 0) out vec4 color;

        	    in vec3 v_Position;
        	    in vec4 v_Color;

        	    void main(){
        	        color = vec4(v_Position * 0.5 + 0.5, 1.0);
        	        color = v_Color;
        	    }
        	)";

        	m_Shader.reset(new BenzEngine::Shader(vertexSrc, fragmentSrc));

        	std::string vertexSrc2 = R"(
        	    #version 330 core

        	    layout(location = 0) in vec3 a_Position;

        	    uniform mat4 u_ViewProjection;

        	    out vec3 v_Position;

        	    void main(){
        	        v_Position = a_Position + 0.5;
        	        gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
        	    }
        	)";

        	std::string fragmentSrc2 = R"(
        	    #version 330 core
        	    layout(location = 0) out vec4 color;

        	    in vec3 v_Position;

        	    void main(){
        	        color = vec4(0.2, 0.3. 0.8, 1.0);
        	    }
        	)";

        	m_Shader2.reset(new BenzEngine::Shader(vertexSrc2, fragmentSrc2));
        }

        void OnUpdate() override
        {
			if (BenzEngine::Input::IsKeyPressed(BE_KEY_LEFT))
				m_CameraPosition.x -= m_CameraMoveSpeed;

			else if (BenzEngine::Input::IsKeyPressed(BE_KEY_RIGHT))
				m_CameraPosition.x += m_CameraMoveSpeed;

			if (BenzEngine::Input::IsKeyPressed(BE_KEY_UP))
				m_CameraPosition.y += m_CameraMoveSpeed;

			else if (BenzEngine::Input::IsKeyPressed(BE_KEY_DOWN))
				m_CameraPosition.y -= m_CameraMoveSpeed;

			if (BenzEngine::Input::IsKeyPressed(BE_KEY_A))
				m_CameraRotation += m_CameraRotationSpeed;

			if (BenzEngine::Input::IsKeyPressed(BE_KEY_D))
				m_CameraRotation -= m_CameraRotationSpeed;

			BenzEngine::RenderCommand::SetClearColor({0.89, 0.47, 0.20, 1});
			BenzEngine::RenderCommand::Clear();

            m_Camera.SetPosition(m_CameraPosition);
            m_Camera.SetRotation(m_CameraRotation);

            BenzEngine::Renderer::BeginScene(m_Camera);

            BenzEngine::Renderer::Submit(m_Shader2, m_SquareVA);
            BenzEngine::Renderer::Submit(m_Shader, m_VertexArray);

            BenzEngine::Renderer::EndScene();

        }

        virtual void OnImGuiRender() override
		{
        }

        void OnEvent(BenzEngine::Event& event) override
        {
        }
		
	private:
        std::shared_ptr<BenzEngine::Shader> m_Shader;
        std::shared_ptr<BenzEngine::VertexArray> m_VertexArray;

        std::shared_ptr<BenzEngine::Shader> m_Shader2;
        std::shared_ptr<BenzEngine::VertexArray> m_SquareVA;

		BenzEngine::OrthographicCamera m_Camera;
		glm::vec3 m_CameraPosition;
		float m_CameraMoveSpeed = 0.1f;

		float m_CameraRotation = 0.0f;
		float m_CameraRotationSpeed = 2.0f;
};

class Sandbox : public BenzEngine::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }
    ~Sandbox()
    {
    }
};

BenzEngine::Application* BenzEngine::CreateApplication()
{
    return new Sandbox();
}
