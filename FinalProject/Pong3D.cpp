#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
    glm::vec4 pos;
    glm::vec4 col;

    Vertex()
    {
        memset(this, 0x0, sizeof(struct Vertex));
    }

    Vertex(glm::vec4 position, glm::vec4 color)
    {
        pos = position;
        col = color;
    }
};

struct Transform
{
    glm::mat4 translate;
    glm::mat4 scale;
    glm::mat4 rotation;
};

class Camera {
    // ���� �������� (0, 0, 0)�� ī�޶� ��ġ glm::vec3(0,0,1), // Z������ ���� glm::vec3(0,1,0) // �Ӹ��� ���� �ִ� );
    glm::mat4 View = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.f, 0.f, 1.f), glm::vec3(0.f, 1.0f, 0.f));
    
    //�þ߰� 45�� / ��Ⱦ�� 4:3 / near plane 0.1f / far plane 100.0f
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
        
    Transform transform;

    void Init()
    {

    }
    void Update()
    {

    }
    void Render()
    {
        
    }
    glm::mat4 getMatrix()
    {
        return View * Projection;
    }
};

class PlayerPad {
    Transform transform;

    void Init()
    {

    }
    void Update()
    {

    }
    void Render()
    {

    }
};

class Stage {
public:
    Transform transform;

    vector<Vertex> VB;

    Stage()
    {
        Init();
    }
    ~Stage()
    {
        Init();
    }
    void Init()
    {
        VB.clear();

        //����
        VB.push_back(Vertex(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
        VB.push_back(Vertex(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
        VB.push_back(Vertex(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb

        VB.push_back(Vertex(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
        VB.push_back(Vertex(glm::vec4(-1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
        VB.push_back(Vertex(glm::vec4( 1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb

        //������
        VB.push_back(Vertex(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
        VB.push_back(Vertex(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
        VB.push_back(Vertex(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb

        VB.push_back(Vertex(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
        VB.push_back(Vertex(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
        VB.push_back(Vertex(glm::vec4(1.0f, -1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb

    }
    void Update()
    {

    }
    void Render()
    {        
        //���β�
        glLineWidth(1.0f);

        glBegin(GL_TRIANGLES);

        for (int i = 0; i < VB.size(); i++)
        {
            glColor4f(VB[i].col.r, VB[i].col.g, VB[i].col.b, VB[i].col.a);
            glVertex4f(VB[i].pos.x, VB[i].pos.y, VB[i].pos.z, VB[i].pos.w);
        }

        glEnd();
    }
};

class Ball {
    Transform transform;

    void Init()
    {

    }
    void Update()
    {

    }
    void Render()
    {

    }
};



Vertex star[5];             // static mesh
Vertex transformedStar[5];  //ȭ�鿡 �׸� ������
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // ȭ�鿡 �׷��� ��

Transform transform;  //world ����� �� transform

Stage *g_stage;
Camera *g_camera

//<����>////////�������� ���°�////////////////////////////////////////////////////////////




 //////////////////////////////////////////////////////////////////////////////////////////

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();

      

    //Ʈ������ �ʱ�ȭ (�⺻�� ����)
    transform.translate = glm::mat4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
    transform.rotation = glm::mat4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
    transform.scale = glm::mat4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );

    g_stage = new Stage();
}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
   


        

        

    
}
void Render()
{
    //�� �ʱ�ȭ
    glClearColor(.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    g_stage->Render();

    //vector<Vertex> VB;
    //VB.clear();
    //VB.push_back(Vertex(glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
    //VB.push_back(Vertex(glm::vec4(-1.0f, 1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb
    //VB.push_back(Vertex(glm::vec4( 1.0f,-1.0f, 1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f))); //pos , rgb


    ////���β�
    //glLineWidth(1.0f);

    //glBegin(GL_TRIANGLES);

    //for (int i = 0; i < VB.size(); i++)
    //{
    //    glColor4f(VB[i].col.r, VB[i].col.g, VB[i].col.b, VB[i].col.a);
    //    glVertex4f(VB[i].pos.x, VB[i].pos.y, VB[i].pos.z, VB[i].pos.w);
    //}


    //glEnd();
    
    
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{  

    Init();

    while (!glfwWindowShouldClose(window))  //���ӷ���
    {
        Update();
        Render();

        //ȭ�� ����
        glfwSwapBuffers(window);
        glfwPollEvents();

        //�����ð� ����
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        double fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {        
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;

    }

    Release();

    exit(EXIT_SUCCESS);
}