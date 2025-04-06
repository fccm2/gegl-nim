import ../src/gegl

gegl_nim_init()

let n = gegl_nim_node_new()

let load = gegl_nim_node_png_load(n, "input.png")
let save = gegl_nim_node_png_save(n, "output.png")

let edge = gegl_nim_node_edge_sobel(n)

gegl_nim_node_connect_to(load, edge)
gegl_nim_node_connect_to(edge, save)
gegl_nim_node_process(save)

gegl_nim_node_unref(n)
gegl_nim_exit()

