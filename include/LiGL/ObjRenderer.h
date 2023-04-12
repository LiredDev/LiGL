#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
struct Vertex
{
    float x, y, z;
    float nx, ny, nz;
};
vector<Vertex> vertices;
vector<unsigned int> indices;
void LoadOBJ(const char *filename)
{
    ifstream objFile(filename);
    while (objFile)
    {
        std::string line;
        std::getline(objFile, line);
        istringstream iss(line);
        char trash;
        if (!line.compare(0, 2, "v "))
        {
            Vertex v;
            iss >> trash >> v.x >> v.y >> v.z;
            vertices.push_back(v);
        }
        else if (!line.compare(0, 2, "f "))
        {
            unsigned int index[3];
            iss >> trash;
            for (int i = 0; i < 3; i++)
            {
                iss >> index[i];
                index[i]--; // in OBJ, indices start at 1
            }
            indices.push_back(index[0]);
            indices.push_back(index[1]);
            indices.push_back(index[2]);
        }
    }
}
void DrawOBJ()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), &vertices[0].x);
    glNormalPointer(GL_FLOAT, sizeof(Vertex), &vertices[0].nx);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, &indices[0]);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
    DrawOBJ();
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OBJ Viewer");
    glEnable(GL_DEPTH_TEST);
    LoadOBJ("myobject.obj");
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}