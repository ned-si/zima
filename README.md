# zima

My QMK keymap for the [splitkb Zima](https://splitkb.com/products/zima) macropad.

It is cloned inside my
[qmk-userspace](https://github.com/ned-si/qmk-userspace) checkout, at
`keyboards/splitkb/zima/keymaps/nedsi` (git-ignored there, so the userspace always
builds whatever this clone has checked out).

It is standalone: `rules.mk` sets `USER_NAME := nedsi_none` so the shared
`users/nedsi` code is not built in. The encoder steps through the layers; the
OLED shows the active one.

## Build and flash

From a machine set up as described in the qmk-userspace README:

```sh
qmk compile -kb splitkb/zima -km nedsi
qmk flash   -kb splitkb/zima -km nedsi
```

Bootloader: press the reset button on the controller.
