#version 330 core

in vec3 v_color;
in vec2 v_tex_coords;
in float v_tex_index;

out vec4 frag_color;

uniform sampler2DArray u_texture_array;

void main() {
	if (v_tex_index < 0.0) {
		frag_color = vec4(v_color, 1.0);
	} else {
		vec4 tex_color = texture(u_texture_array, vec3(v_tex_coords, v_tex_index));

		frag_color = tex_color * vec4(v_color, 1.0);

		if (frag_color.a < 0.1)
			discard;
	}
}
