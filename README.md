# meta2back

> interception-tools plugin for converting left-meta (Win) to a back-button

A plugin for [interception-tools](https://gitlab.com/interception/linux/tools) to convert a key press (left-meta/Windows-key on my mouse) to a another button (back button) press.

# Install

## Build

requires meson, ninja, and a compiler to build.

```
meson setup builddir
cd builddir
ninja
sudo cp meta2back /usr/local/bin/
```

## Configure

Then add to your interception-tools pipeline. Reference file [meta2back.yaml](./meta2back.yaml) is configured for a Microsoft Sculpt mouse:

```
# set up a mux called 'mouseback'
- CMD: mux -c mouseback
# intercept the mouse, add the mux, and output it
- JOB: "intercept mux -o mouseback | mux -i mouseback | uinput -d $DEVNODE"
  DEVICE:
    NAME: Microsoft Sculpt Comfort Mouse
# read the mouse's keyboard, convert meta2back, and inject into the mouseback mux.
- JOB: "intercept -g $DEVNODE | meta2back | mux -o mouseback"
  DEVICE:
    NAME: Microsoft Sculpt Comfort Mouse Keyboard
    EVENTS:
      EV_KEY: [KEY_LEFTMETA]
```

# Explanation

Mice don't have "Windows" keys, so this mouse presents as a mouse and keyboard. We capture the mouse-keyboard, remap the Meta/Windows key to a button, then emit that button into the mouse's mouse output, as button 4 (typically "side" or "back").
