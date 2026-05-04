#!/bin/env bash

xxd -i vertex.glsl > ./include/shaders/vertex_shader.h
xxd -i fragment.glsl > ./include/shaders/fragment_shader.h

echo done
