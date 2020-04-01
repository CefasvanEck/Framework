//This file was added by Cefas

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <string>
#include <iostream>



class ShaderProgram
{
public:
	ShaderProgram();
	virtual ~ShaderProgram();

	GLuint getshaderProgramID();

	void deleteShader();

	void useShaderProgram(GLuint idShaderProgram);

	void setShaderID(GLuint idShaderProgram);

	GLuint loadShaders(const std::string& vertex_file_path, const std::string& fragment_file_path);

private:

	GLuint shaderProgramID;

protected:

};

#endif /* SHADERPROGRAM_H */