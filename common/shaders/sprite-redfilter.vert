#version 400 core

// Input vertex data, different for all executions of this shader.
in vec3 vertexPosition;
in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

uniform mat4 viewMatrix;
uniform mat4 transformationMatrix;
uniform mat4 modelViewMatrix;

uniform vec3[8] lightPosition;
out vec3[8] toLightVector;


void main()
{
	// Output position of the vertex, in clip space : MVP * position
	gl_Position =  MVP * vec4(vertexPosition,1);

	vec4 worldPosition = transformationMatrix * vec4(vertexPosition ,1);
	vec4 positionRelativeToCam = viewMatrix * worldPosition;

	vec3 surfaceNormal = (modelViewMatrix * vec4(1,1,1,0.0)).xyz;
	vec3 norm = normalize(surfaceNormal);
	vec3 tang = normalize((modelViewMatrix * vec4(1,1,1,0)).xyz);
	vec3 bitang = normalize(cross(norm, tang));
	
	mat3 toTangentSpace = mat3(tang.x, bitang.x, norm.x,tang.y, bitang.y, norm.y,tang.z, bitang.z, norm.z);

	for(int i=0;i<8;i++)
    {
		toLightVector[i] = toTangentSpace * (lightPosition[i] - positionRelativeToCam.xyz);
	}

	// UV of the vertex. No special space for this one.
	UV = vertexUV;
}
