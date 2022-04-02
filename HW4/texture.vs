
#version 330 core
layout (location = 0) in vec3 position;
layout(location = 1) in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//I used stackoverflow to help me. Here it the link to the website: 
//https://stackoverflow.com/questions/48266344/model-view-and-projection-matrix-do-not-want-to-work-well-for-opengl-glsl


void main()
{
    gl_Position = (projection * view * model) * (vec4(position, 1.0));
    UV = vec2(vertexUV.x, 1-vertexUV.y);    
}
