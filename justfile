alias flash := console
alias compile := dev

default: console

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
console:
    cp boardsource_unicorne_iovis.uf2 /Volumes/RPI-RP2

# compile
dev:
    #!/usr/bin/env fish
    qmk compile -j0
    pause_if_err
