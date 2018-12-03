#version 330 core

//material variables
uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

//light variables
uniform vec3 uLightPos_vs;
uniform vec3 uLightIntensity;

//texture variables
uniform sampler2D uEarthTexture;
uniform sampler2D uCloudTexture;

//position du fragment sur l'écran
in  vec4 vPosition_vs;
//normal du fragment
in  vec4 vFragNormal;
//coordonée u, v du fragment
in  vec2 vFragTexCoords;

out vec3 fFragColor;


vec3 blinnPhong() {
	vec3 fragLightVec = uLightPos_vs - vec3(vPosition_vs);

	vec3 Li = uLightIntensity / (length(fragLightVec) * length(fragLightVec));
	vec3 wi = normalize(fragLightVec);
	vec3 wo = normalize(vec3(- vPosition_vs));
	vec3 halfVector = 0.5 * (wo + wi);
	vec3 N = vec3(vFragNormal);
	return 
		Li * (
			uKd * (dot(wi, N))
			+ uKs * pow(dot(halfVector, N), uShininess)
		);
}

void main() {	
	fFragColor = 
		blinnPhong() * (
		      texture(uEarthTexture, vFragTexCoords).xyz
			+ texture(uCloudTexture, vFragTexCoords).xyz
	    );

	//fFragColor = normalize(vFragNormal.xyz);
};
