set(headers RenderJob.h RenderMode.h Renderer.h)

set(sources RenderJob.cpp RenderMode.cpp Renderer.cpp)

add_library(camotics-render OBJECT "${headers}" "${sources}")
