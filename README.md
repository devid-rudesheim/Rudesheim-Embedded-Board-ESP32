# Rudesheim-Embedded-Board-ESP32

Rudesheim layer 2: Board interface implementation for ESP32.

`Esp32` inherits from `Arduino` in
[Rudesheim-Embedded-Board-Arduino](https://github.com/devid-rudesheim/Rudesheim-Embedded-Board-Arduino)
(`Board` → `Arduino` → `Esp32`), currently without overriding anything —
ESP32 uses nothing beyond standard Arduino API calls today, but the
class exists as the place to add ESP32-specific behavior later.

For install/uninstall instructions and the overall dependency graph, see
[Rudesheim-Embedded](https://github.com/devid-rudesheim/Rudesheim-Embedded#install).
Use this as the `lib_deps` URL for ESP32 targets:

```
https://github.com/devid-rudesheim/Rudesheim-Embedded-Board-ESP32.git#v0.0.1
```
