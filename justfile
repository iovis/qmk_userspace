default: flash

# lists available tasks
@list:
    just --list

# init project and clean
init:
    git stash
    git pull
    git stash pop
    qmk setup

setup:
    qmk setup
    qmk compile --compiledb -j0

open:
    gh repo view --web

console:
    # Flash with `CONSOLE_ENABLE = yes`
    qmk console -n -t

flash:
    cp boardsource_unicorne_iovis.uf2 /Volumes/RPI-RP2

clean:
    qmk clean -a

alias dev := compile

compile:
    qmk compile -j0
    fish -ic pause_if_err
