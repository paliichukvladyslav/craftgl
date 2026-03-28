project(
  'craftgl',
  ['cpp', 'c'],
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)

glfw_dep = dependency('glfw3', required: true)
opengl_dep = dependency('opengl', required: true)

subdir('src')
