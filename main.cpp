#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

static const GLfloat clear_color[] = { 0.169f, 0.236f, 0.313f, 1.0f };

int main(void)
{
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window;
	window = glfwCreateWindow(640, 480, "gl-sandbox", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glClearBufferfv(GL_COLOR, 0, clear_color);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
