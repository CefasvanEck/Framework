#version 120

// Interpolated values from the vertex shader
varying vec2 UV;

// Values that stay constant for the whole mesh.
uniform sampler2D textureSampler;
uniform int test;

uniform vec3[8] lightPosition;
uniform vec3[8] lightColour;
uniform vec3[8] lightAttenuation;

void main()
{
	vec4 color = texture2D( textureSampler, UV );

	color.x = 0;
	color.y = 0;
	color.z = 0;
	
	// Output color = color of the texture at the specified UV
	gl_FragColor = color;
}
