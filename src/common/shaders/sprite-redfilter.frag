#version 120

// Interpolated values from the vertex shader
varying vec2 UV;

// Values that stay constant for the whole mesh.
uniform sampler2D textureSampler;
uniform int test;

void main()
{
	vec4 color = texture2D( textureSampler, UV );
	color.x += 0.3;

	if(test == 1)
	{
		color.y += 0.8;
	}
	// Output color = color of the texture at the specified UV
	gl_FragColor = color;
}
