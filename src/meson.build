glad_src = files(
  '../external/src/glad.c'
)

imgui_dir = '../external/imgui'

glad_inc = include_directories('../external/include')
proj_inc = include_directories('include')
imgui_inc = include_directories(imgui_dir, imgui_dir / 'backends')

imgui_src = files(
  imgui_dir / 'imgui.cpp',
  imgui_dir / 'imgui_draw.cpp',
  imgui_dir / 'imgui_tables.cpp',
  imgui_dir / 'imgui_widgets.cpp',
  imgui_dir / 'imgui_demo.cpp',
  
  imgui_dir / 'backends/imgui_impl_glfw.cpp',
  imgui_dir / 'backends/imgui_impl_opengl3.cpp'
)

sources = files(
  'main.cpp',
  'App.cpp',
  'InputHandler.cpp',
  'Shader.cpp',
  'Mesh.cpp',
  'World.cpp',
  'Renderer.cpp',
  'UI.cpp',
  'Image.cpp',
  'TextureArray.cpp',
  'MeshFactory.cpp'
)

executable(
  'craftgl',
  sources,
  glad_src,
  imgui_src,
  include_directories : [glad_inc, proj_inc, imgui_inc],
  dependencies : [glfw_dep, opengl_dep]
)
