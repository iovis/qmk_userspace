qmk_firmware := quote(justfile_directory() / "../qmk_firmware/")
zsa_firmware := quote(justfile_directory() / "../zsa_firmware/")

alias dev := compile

default: init

run: compile flash

# lists available tasks
@list:
    just --list

# init project and clean
init:
    git stash
    git pull
    git stash pop || true

# setup boardsource/unicorne
setup keyboard:
    @ # gh repo clone zsa/qmk_firmware zsa_firmware -- -b firmware24
    qmk setup -H {{ if parent_directory(keyboard) == "zsa" { zsa_firmware } else { qmk_firmware } }} --yes
    qmk config user.keyboard={{ keyboard }}
    qmk config user.keymap=iovis
    qmk compile --compiledb -j0

compile:
    qmk lint
    qmk compile -j0
    fish -ic pause_if_err

flash:
    @ # cp boardsource_unicorne_iovis.uf2 /Volumes/RPI-RP2
    qmk flash

open:
    gh repo view --web

console:
    # Flash with `CONSOLE_ENABLE = yes`
    qmk console -t

clean:
    qmk clean -a
