# meta2back

> interception-tools plugin for converting left-meta (Win) to a back-button

A plugin for [interception-tools](https://gitlab.com/interception/linux/tools) to convert a key press (left-meta/Windows-key on my mouse) to a another button (back button) press.

# Installing

requires meson, ninja, and a compiler to build.

```
meson setup builddir
cd builddir
ninja
sudo cp meta2back /usr/local/bin/
```

Then add to your interception-tools pipeline.
