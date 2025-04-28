qmk_firmware := quote(justfile_directory() / "../qmk_firmware/")
zsa_firmware := quote(justfile_directory() / "../zsa_firmware/")

# Fix LIBUSB_ACCESS_ERROR (udev rules)
# https://github.com/zsa/wally/wiki/Linux-install#2-create-a-udev-rule-file

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

update_community_modules:
    mkdir -p modules
    git submodule add --force https://github.com/getreuer/qmk-modules.git modules/getreuer
    git submodule update --init --recursive

# just setup boardsource/unicorne
setup keyboard: update_community_modules
    @ # gh repo clone zsa/qmk_firmware zsa_firmware -- -b firmware25
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
