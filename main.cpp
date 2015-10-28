#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

static void setup(void);
static void render(void);
static void init_shader_prog(void);

static const GLfloat clear_color[] = { 0.169f, 0.236f, 0.313f, 1.0f };

static GLuint program;
static const char * vs_source[] =
{
	"#version 330 core				\n"
	"						\n"
	"void main(void)				\n"
	"{						\n"
	"	gl_Position = vec4(0.0, 0.0, 0.0, 1.0);	\n"
	"}						\n"
};
static const char * fs_source[] =
{
	"#version 330 core				\n"
	"						\n"
	"out vec4 color;				\n"
	"						\n"
	"void main(void)				\n"
	"{						\n"
	"	color = vec4(1.0, 1.0, 1.0, 1.0);	\n"
	"}						\n"
};

static GLuint vao;

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

	setup();

	while (!glfwWindowShouldClose(window)) {
		render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

static void setup(void)
{
	init_shader_prog();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

static void render(void)
{
	glClearBufferfv(GL_COLOR, 0, clear_color);
	glDrawArrays(GL_POINTS, 0, 1);
}

static void init_shader_prog(void)
{
	program = glCreateProgram();

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, vs_source, NULL);
	glCompileShader(vs);

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, fs_source, NULL);
	glCompileShader(fs);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glUseProgram(program);
}
