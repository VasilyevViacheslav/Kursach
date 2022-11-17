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
    float x_CenterOfMass = ((x1 + x2 + x3) / 3);
    float y_CenterOfMass = ((y1 + y2 + y3) / 3);
    float height = 2 * S / d12;
    float mInertia = d12 * pow(height, 3) / 12;
    
};
class Kit_Triangle
{
    float mInertia = 0;
    float Kit_Mass = 0;
    float SOfAllTriangles = 0;
    float AverageDesttiny = 0;
    float CenterMassKit_x = 0;
    float CenterMassKit_y = 0;

    std::vector<Triangle> Massive_Of_TRiangle;
    Kit_Triangle(Triangle tr)
    {
        Massive_Of_TRiangle.push_back(tr);
        CenterMassKit_x += (tr.x_CenterOfMass * tr.mass + CenterMassKit_x * Kit_Mass) / (Kit_Mass + tr.mass);
        CenterMassKit_y += (tr.y_CenterOfMass * tr.mass + CenterMassKit_y * Kit_Mass) / (Kit_Mass + tr.mass);
        Kit_Mass += tr.mass;
        SOfAllTriangles += tr.S;
        AverageDesttiny = Kit_Mass / SOfAllTriangles;
        mInertia += tr.mInertia;
    }
    ~Kit_Triangle()
    {
        Massive_Of_TRiangle.clear();
    }
public:
    void add_Triangle(Triangle tr)
    {
        Massive_Of_TRiangle.push_back(tr);
        SOfAllTriangles += tr.S;
        AverageDesttiny = Kit_Mass / SOfAllTriangles;
        CenterMassKit_x += (tr.x_CenterOfMass * tr.mass + CenterMassKit_x * Kit_Mass) / (Kit_Mass + tr.mass);
        CenterMassKit_y += (tr.y_CenterOfMass * tr.mass + CenterMassKit_y * Kit_Mass) / (Kit_Mass + tr.mass);
        Kit_Mass += tr.mass;
    }
};

int main()
{
    
}