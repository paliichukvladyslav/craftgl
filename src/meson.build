glad_src = files(
  '../external/src/glad.c'
)

glad_inc = include_directories('../external/include')
proj_inc = include_directories('include')

sources = files(
  'main.cpp',
  'App.cpp',
  'InputHandler.cpp',
  'Shader.cpp',
  'Mesh.cpp',
  'World.cpp',
  'Renderer.cpp'
)

executable(
  'craftgl',
  sources,
  glad_src,
  include_directories : [glad_inc, proj_inc],
  dependencies : [glfw_dep, opengl_dep]
)
