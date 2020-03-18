#version 120

// Interpolated values from the vertex shader
varying vec2 UV;

// Values that stay constant for the whole mesh.
uniform sampler2D textureSampler;

void main()
{
	vec4 color = texture2D( textureSampler, UV );
	color.x += 0.3;
	// Output color = color of the texture at the specified UV
	gl_FragColor = color;
}
