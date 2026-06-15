OpenGLEngine
Overview

OpenGLEngine is a lightweight OpenGL rendering engine written in C++.

The purpose of the project is to provide a reusable foundation for future graphics and simulation projects by encapsulating common OpenGL functionality into well-defined classes.

Current implementation focuses on:
    Window management
    Shader management
    Mesh rendering
    Object transformations
    Keyboard input
    Basic rendering pipeline

Architecture:

    GLengine
    ├── Window
    ├── Render
    └── KeyboardInput

    Render
    └── Model

    Model
    ├── Mesh
    ├── Transform
    └── Shader

Class Responsibilities:

GLengine

    Central engine controller.

    Responsibilities:

    Manages engine subsystems
    Provides a simplified interface
    Coordinates rendering and window operations


Window

    Manages the application window and OpenGL context.

    Responsibilities:

    Initializes GLFW
    Creates OpenGL window
    Handles fullscreen mode
    Handles window events
    Swaps buffers


Render

    Controls rendering operations.

    Responsibilities:

    Clears frame buffer
    Activates shaders
    Sends uniforms
    Draws models

    Rendering flow:

        Render
          ↓
        Shader
          ↓
        Mesh
          ↓
        OpenGL


Model

    Represents a renderable object.

    Responsibilities:

    Owns geometry (Mesh)
    Owns transformation data (Transform)
    References a shader
    Stores object color
    Mesh

    Represents renderable geometry.

    Responsibilities:

    Stores vertex data
    Stores index data
    Stores OpenGL buffers
    Supports uniform color
    Supports per-vertex color
    Issues draw calls

    OpenGL objects:

    VAO
    VBO
    EBO


Transform

Represents an object's transformation in 3D space.

Responsibilities:

    Stores position
    Stores rotation
    Stores scale
    Generates model matrix

    Transformation order:

    Translation
        ↓
    Rotation X
        ↓
    Rotation Y
        ↓
    Rotation Z
        ↓
    Scale
    Shader

    Represents an OpenGL shader program.

    Responsibilities:

    Loads shader source files
    Compiles shaders
    Links shader program
    Activates shader program
    Sends uniforms to GPU

    Supported uniforms:

    setInt(...)
    setVec3(...)
    setMat4(...)



Current rendering sequence:
    main()
        ↓
    engine.draw(model)
        ↓
    render.draw(model)
        ↓
    shader.useProgram()
        ↓
    shader.setMat4()
        ↓
    shader.setVec3()
        ↓
    mesh.draw()
        ↓
    glDrawElements()

Current Features:
    OpenGL 3.3 Core Profile
    GLFW window creation
    GLAD initialization
    Shader loading from files
    Mesh rendering using VAO/VBO/EBO
    Object transformations
    Uniform object color
    Per-vertex color support
    Fullscreen mode
    Keyboard input handling


Future Goals:
    Camera system
    Scene management
    Material system
    Texture support
    STL file loading
    Lighting
    Thermal simulation visualization
    Heat distribution rendering
    Multiple models per scene

Dependencies:
    OpenGL
    GLFW
    GLAD
    GLM