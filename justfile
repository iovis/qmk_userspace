alias console := flash
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
    open .

# flash the device
flash:
    cp boardsource_unicorne_iovis.uf2 /Volumes/RPI-RP2

# compile
compile:
    #!/usr/bin/env fish
    qmk compile -j0
    pause_if_err
