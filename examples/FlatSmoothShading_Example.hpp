#ifndef FLAT_SMOOTH_SHADING_EXAMPLE_HPP
#define FLAT_SMOOTH_SHADING_EXAMPLE_HPP

#include <Utils/GlfwOpenGlWindow.hpp>
#include <Rigid3D/Rigid3D.hpp>

#include <glm/gtc/reciprocal.hpp>
#include <vector>
#include <memory>

using std::unordered_map;

using namespace Rigid3D;
using namespace glm;
using namespace std;

/**
 * @brief Demo Instructions
 *
 * Shading Type:
 * Press F1 for flat shading.
 * Press F2 for smooth shading.
 *
 * Mesh Type:
 * Numbers 1 through 4 change the mesh type.
 *
 * Object Movement Keys:
 * a, s, d, w, r, f move the mesh object.
 *
 * Light Movement Keys:
 * up, down, left, right, p, l move the light source.
 */
class FlatSmoothShading_Example : public GlfwOpenGlWindow {

public:
    ~FlatSmoothShading_Example() { }

    static shared_ptr<GlfwOpenGlWindow> getInstance();

private:
    // Mesh and Batch Containers
    MeshConsolidator meshConsolidator;
    unordered_map<const char *, BatchInfo> batchInfoMap;

    enum class MeshType {CUBE, SPHERE, TORUS, SUSAN};
    enum class ShadingType {FLAT, SMOOTH};

    MeshType renderTarget;
    ShadingType shadingType;

    // Shader Program Data
    ShaderProgram shaderProgram;
    mat4 modelMatrix;
    mat4 viewMatrix;
    mat4 modelViewMatrix;
    mat3 normalMatrix;

    struct LightSource {
        vec3 position;      // Light position in eye coordinate space.
        vec3 rgbIntensity;  // Light intensity for each RGB component.
    };
    LightSource lightSource;

    struct MaterialProperties {
        vec3 emission;  // Emission light intensity from material for each RGB component.
        vec3 Ka;        // Coefficients of ambient reflectivity for each RGB component.
        vec3 Kd;        // Coefficients of diffuse reflectivity for each RGB component.
        float Ks;       // Coefficient of specular reflectivity, uniform across each RGB component.
        float shininessFactor;   // Specular shininess factor.
    };
    MaterialProperties material;

    bool pauseLightSource = false;

    GLuint vao;
    GLuint vbo_vertices;
    GLuint vbo_normals;

    FlatSmoothShading_Example(); // Singleton, prevent direct construction.

    virtual void init();
    virtual void logic();
    virtual void draw();
    virtual void keyInput(int key, int action, int mods);
    virtual void cleanup();

    void setupShaders();
    void setupGLBuffers();
    void setupMatrices();
    void updateMatrices();
    void updateUniformData();
    void rotateLightSource();

};

#endif /* FLAT_SMOOTH_SHADING_EXAMPLE_HPP */
