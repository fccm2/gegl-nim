#include <gegl.h>

void gegl_nim_init() {
  gegl_init(NULL, NULL);
}

void gegl_nim_exit() {
  gegl_exit();
}

GeglNode * gegl_nim_node_new() {
  GeglNode *node = gegl_node_new();
  return node;
}

void gegl_nim_node_unref(GeglNode* node) {
  g_object_unref(node);
}

void gegl_nim_node_connect_to(GeglNode* n1, GeglNode* n2) {
  gegl_node_connect_to(n1, "output", n2, "input");
}

void gegl_nim_node_connect_to2(GeglNode* n1, GeglNode* n2) {
  gegl_node_connect_to(n1, "output", n2, "aux");
}

void gegl_nim_node_process(GeglNode* node) {
  gegl_node_process(node);
}

GeglNode * gegl_nim_node_png_load(GeglNode* node, char *s) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:png-load",
    "path", s,
    NULL);
  return child;
}

GeglNode * gegl_nim_node_png_save(GeglNode* node, char *s) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:png-save",
    "path", s,
    NULL);
  return child;
}

GeglNode * gegl_nim_node_jpg_load(GeglNode* node, char *s) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:jpg-load",
    "path", s,
    NULL);
  return child;
}

GeglNode * gegl_nim_node_jpg_save(GeglNode* node, char *s) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:jpg-save",
    "path", s,
    NULL);
  return child;
}

GeglNode * gegl_nim_node_svg_load(GeglNode* node, char *s) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:svg-load",
    "path", s,
    NULL);
  return child;
}

GeglNode * gegl_nim_node_gaussian_blur(GeglNode* node, double x, double y) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:gaussian-blur",
    "std-dev-x", x,
    "std-dev-y", y,
    NULL);
  return child;
}

GeglNode * gegl_nim_node_edge_sobel(GeglNode* node) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:edge-sobel",
    NULL);
  return child;
}

GeglNode * gegl_nim_node_brightness_contrast(GeglNode* node, double b, double c) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:brightness-contrast",
    "brightness", b,
    "contrast", c,
    NULL);
  return child;
}

GeglNode * gegl_nim_node_brightness(GeglNode* node, double b) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:brightness-contrast",
    "brightness", b,
    NULL);
  return child;
}

GeglNode * gegl_nim_node_contrast(GeglNode* node, double c) {
  GeglNode *child = gegl_node_new_child(node,
    "operation", "gegl:brightness-contrast",
    "contrast", c,
    NULL);
  return child;
}

GeglNode * gegl_nim_node_compose(GeglNode* node, int c) {
  gchar *compose_op = NULL;
  switch (c)
  { case 0: compose_op = "gegl:multiply"; break;
    case 1: compose_op = "gegl:difference"; break;
    case 2: compose_op = "gegl:screen"; break;
    case 3: compose_op = "gegl:overlay"; break;
    case 4: compose_op = "gegl:subtract"; break;
    case 5: compose_op = "gegl:exclusion"; break;
    case 6: compose_op = "gegl:add"; break;
    case 7: compose_op = "gegl:divide"; break;
    case 8: compose_op = "gegl:color-burn"; break;
    case 9: compose_op = "gegl:color-dodge"; break;
    case 10: compose_op = "gegl:hard-light"; break;
    case 11: compose_op = "gegl:soft-light"; break;
    case 12: compose_op = "gegl:src-atop"; break;
    case 13: compose_op = "gegl:lighten"; break;
    default: ;
  }
  GeglNode *child = gegl_node_new_child(node,
    "operation", compose_op,
    NULL);
  return child;
}

