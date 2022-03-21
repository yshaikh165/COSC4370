
#version 330 core
out vec4 color;

in vec3 FragPos;  
in vec3 Normal;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    //TODO:
    vec3 var;
    float str;
    str = 0.1f;
    var = str * lightColor;

    float var3;
    vec3 normal;
    normal = normalize(Normal);
    vec3 var2;
    var2 = normalize(lightPos - FragPos);

    var3 = max(dot(normal, var2), 0.0);
    vec3 var4;
    var4 = var3 * lightColor;

    vec3 rdir;
    rdir = reflect(-var2, normal);  
    vec3 vdir;
    vdir = normalize(viewPos - FragPos);

    float sc;
    sc = pow(max(dot(vdir, rdir), 0.0), 32);

    float spec_str;
    spec_str = 0.5f;

    vec3 sclr;
    sclr = spec_str * sc * lightColor;  

    vec3 total;
    total = (var + var4 + sclr) * objectColor;
    color = vec4(total, 1.0f);
} 