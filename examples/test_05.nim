import ../src/gegl

gegl_nim_init()

let n = gegl_nim_node_new()

let layer1 = gegl_nim_node_svg_load(n, "layer1.svg")
let layer2 = gegl_nim_node_svg_load(n, "layer2.svg")

let save = gegl_nim_node_png_save(n, "output.png")

let compose = gegl_nim_node_compose(n, multiply)

gegl_nim_node_connect_to(layer1, compose)
gegl_nim_node_connect_to2(layer2, compose)

gegl_nim_node_connect_to(compose, save)

gegl_nim_node_process(save)

gegl_nim_node_unref(n)
gegl_nim_exit()

