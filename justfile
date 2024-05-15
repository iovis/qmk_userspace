alias dev := compile

default: flash

# lists available tasks
@list:
    just --list

# init project and clean
init:
    qmk setup
    qmk compile --compiledb -j0

open:
    qmk docs -b

# Flash with `CONSOLE_ENABLE = yes`
console:
    qmk console

flash:
    cp boardsource_unicorne_iovis.uf2 /Volumes/RPI-RP2

clean:
    qmk clean -a

# compile
compile:
    #!/usr/bin/env fish
    qmk compile -j0
    pause_if_err
