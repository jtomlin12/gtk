#!/bin/bash

# need suppressions or else gtk's "one-off" allocations will pollute valgrind output with leaks
# https://developer.gnome.org/documentation/tools/valgrind.html

G_DEBUG=gc-friendly:resident-modules G_SLICE=always-malloc valgrind \
    --tool=memcheck \
    --leak-check=full \
    --show-leak-kinds=definite \
    --gen-suppressions=all \
    --suppressions=/usr/share/gtk-3.0/valgrind/gtk.supp \
    --suppressions=/usr/share/glib-2.0/valgrind/glib.supp \
    --suppressions=custom.supp \
    ./build/gtk_app
