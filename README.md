# Rudesheim-Embedded-Board-ESP32

Rudesheim layer 2: Board interface implementation for ESP32.

This is a thin, architecture-constrained (`espressif32`) package with no
source of its own — the actual implementation lives in
[Rudesheim-Embedded-Board-Arduino](https://github.com/devid-rudesheim/Rudesheim-Embedded-Board-Arduino),
since ESP32 uses nothing beyond standard Arduino API calls. It pulls in
Base, Foundation, and Board-Arduino automatically as declared dependencies.

## Install

Add it to `lib_deps` in `platformio.ini`:

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
lib_deps =
    https://github.com/devid-rudesheim/Rudesheim-Embedded-Board-ESP32.git#v0.0.1
```

Then fetch it:

```sh
pio pkg install -e esp32dev
```

Or install directly by URL without editing `platformio.ini`:

```sh
pio pkg install -e esp32dev -l "https://github.com/devid-rudesheim/Rudesheim-Embedded-Board-ESP32.git#v0.0.1"
```

## Uninstall

```sh
pio pkg uninstall -e esp32dev -l "Rudesheim-Embedded-Board-ESP32"
```

Removes Base and Foundation along with it, as long as nothing else in the
environment still depends on them.
