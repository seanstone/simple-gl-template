#include <iostream>
#include <gl_2_1.h>
#include <GLFW/glfw3.h>

GLFWwindow* Window;

int initWindow()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	Window = glfwCreateWindow(800, 600, "SimpleGL", NULL, NULL);
	if( Window == NULL ){ std::cout << "Failed to initialize GLFW Window\n"; glfwTerminate(); return -1; }
    glfwMakeContextCurrent(Window);

    // Ensure we can capture the escape key being pressed
	glfwSetInputMode(Window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetCursorPos(Window, 800/2, 600/2);

	return 1;
}

int main()
{
	if(!glfwInit()) {std::cout << "Failed to initialize GLFW\n"; return 0;} // Initialise GLFW
	std::cout << "GLFW initialized\n";
	if(!initWindow()) {std::cout << "Failed to initialize GLFW Window\n"; return 0;} // Initialise GLFW Window
	std::cout << "GLFW window created\n";
	if(ogl_LoadFunctions() == ogl_LOAD_FAILED) { std::cout << "Failed to load OpenGL functions\n"; return 0;}
	std::cout << "OpenGL functions loaded\n";

	std::cout << "\n";

	// Get version info
	const GLubyte* Renderer = glGetString(GL_RENDERER);
	const GLubyte* Version  = glGetString(GL_VERSION);
	printf("Renderer: %s\n", Renderer);
	printf("OpenGL version %s\n\n", Version);

	do
    {
		glClearColor(0, 0, 0.1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(Window); glfwPollEvents();
    }
    while(glfwGetKey(Window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(Window) == 0);
}
