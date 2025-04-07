{.compile: "gegl_nim.c".}

{.passC: "`pkg-config --cflags gegl-0.4`".}
{.passL: "`pkg-config --libs gegl-0.4`".}

type
  node* = pointer

# C Functions

proc gegl_nim_init*() {.importc, cdecl.}
proc gegl_nim_exit*() {.importc, cdecl.}

proc gegl_nim_node_new*(): node {.importc, cdecl.}
proc gegl_nim_node_unref*(node: node) {.importc, cdecl.}

proc gegl_nim_node_connect_to*(n1: node, n2: node) {.importc, cdecl.}
proc gegl_nim_node_connect_to2*(n1: node, n2: node) {.importc, cdecl.}

proc gegl_nim_node_process*(node: node) {.importc, cdecl.}

proc gegl_nim_node_png_load*(node: node, s: cstring): node {.importc, cdecl.}
proc gegl_nim_node_png_save*(node: node, s: cstring): node {.importc, cdecl.}

proc gegl_nim_node_jpg_load*(node: node, s: cstring): node {.importc, cdecl.}
proc gegl_nim_node_jpg_save*(node: node, s: cstring): node {.importc, cdecl.}

proc gegl_nim_node_svg_load*(node: node, s: cstring): node {.importc, cdecl.}

proc gegl_nim_node_gaussian_blur*(node: node, x: cdouble, y: cdouble): node {.importc, cdecl.}
proc gegl_nim_node_edge_sobel*(node: node): node {.importc, cdecl.}

proc gegl_nim_node_brightness_contrast*(node: node, b: cdouble, c: cdouble): node {.importc, cdecl.}
proc gegl_nim_node_brightness*(node: node, b: cdouble): node {.importc, cdecl.}
proc gegl_nim_node_contrast*(node: node, c: cdouble): node {.importc, cdecl.}

type
  compositor* {.size: sizeof(cint).} = enum
    multiply
    difference
    screen
    overlay
    subtract
    exclusion

proc gegl_nim_node_compose*(node: node, c: compositor): node {.importc, cdecl.}

