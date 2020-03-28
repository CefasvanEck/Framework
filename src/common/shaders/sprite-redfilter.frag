#version 120

// Interpolated values from the vertex shader
in vec2 UV;

// Values that stay constant for the whole mesh.
uniform sampler2D textureSampler;

uniform int maxLights;

in vec3 toLightVector[8];
uniform vec3[8] lightColour;
uniform vec3[8] lightAttenuation;

float calculateLightAttenuation(int i)
{
	float distance = length(toLightVector[i]);
	return lightAttenuation[i].x + ((lightAttenuation[i].y * distance) / 100000) + (lightAttenuation[i].z * distance * distance);
}

void main()
{
	vec4 color = texture2D(textureSampler, UV);

	// Output color = color of the texture at the specified UV with the sun: 1 is full sun and 0 is no light or midnight
	vec4 finalColor = vec4(lightColour[0], 1) / calculateLightAttenuation(0);

	//Adds the lights when the sun is not at his brightest 
	for(int i = 1; i < maxLights;++i)
	{
		finalColor += (vec4(lightColour[i], 1)) / calculateLightAttenuation(i);
	}

	gl_FragColor = finalColor * color;
}