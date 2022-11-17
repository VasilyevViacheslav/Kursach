#pragma once
#include <GLFW/glfw3.h>
#include <vector>

struct Triangle
{
    float x1, y1, x2, y2, x3, y3;
    float mass;
    float d12 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    float d23 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    float d13 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    float P = d12 + d23 + d13;
    float S = sqrt((P / 2) * ((P / 2) - d12) * ((P / 2) - d23) * ((P / 2) - d13));
    float Destiny = mass / S;
    float xc = ((x1 + x2 + x3) / 3);
    float yc = ((y1 + y2 + y3) / 3);

};
class Kit_Triangle
{
    float Kit_Mass, SOfAllTriangles, AverageDesttiny;

    std::vector<Triangle> Massive_Of_TRiangle;
    Kit_Triangle(Triangle tr)
    {
        Massive_Of_TRiangle.push_back(tr);
        Kit_Mass += tr.mass;
        SOfAllTriangles += tr.S;
        AverageDesttiny = Kit_Mass / SOfAllTriangles;
    }
    ~Kit_Triangle()
    {
        Massive_Of_TRiangle.clear();
    }
public:
    void add_Triangle(Triangle tr)
    {
        Massive_Of_TRiangle.push_back(tr);
        Kit_Mass += tr.mass;
        SOfAllTriangles += tr.S;
        AverageDesttiny = Kit_Mass / SOfAllTriangles;
    }
    void erase_Triangle(uint16_t n)
    {
        Massive_Of_TRiangle.erase(Massive_Of_TRiangle.begin() + n);
        Kit_Mass -= Massive_Of_TRiangle[n].mass;
        SOfAllTriangles -= Massive_Of_TRiangle[n].S;
        AverageDesttiny = Kit_Mass / SOfAllTriangles;
    }




};




int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.0f, 0.5f);
        glVertex2f(0.5f, -1.5f);
        glVertex2f(-0.5f, 1.5f);
        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}