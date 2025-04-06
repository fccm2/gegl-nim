import ../src/gegl

gegl_nim_init()

let n = gegl_nim_node_new()

let load = gegl_nim_node_png_load(n, "input.png")
let save = gegl_nim_node_png_save(n, "output.png")

let blur = gegl_nim_node_gaussian_blur(n, 2.0, 2.0)

gegl_nim_node_connect_to(load, blur)
gegl_nim_node_connect_to(blur, save)
gegl_nim_node_process(save)

gegl_nim_node_unref(n)
gegl_nim_exit()

