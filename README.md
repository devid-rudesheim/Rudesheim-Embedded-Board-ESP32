# Rudesheim-Embedded-Board-ESP32

Rudesheim layer 2: Board interface implementation for ESP32.

Pulls in [Rudesheim-Embedded-Base](https://github.com/devid-rudesheim/Rudesheim-Embedded-Base)
and [Rudesheim-Embedded-Foundation](https://github.com/devid-rudesheim/Rudesheim-Embedded-Foundation)
automatically as declared dependencies.

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
