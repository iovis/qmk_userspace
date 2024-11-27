qmk_firmware := quote(justfile_directory() / "../qmk_firmware/")
zsa_firmware := quote(justfile_directory() / "../zsa_firmware/")

alias dev := compile

default: init

# lists available tasks
@list:
    just --list

# init project and clean
init:
    git stash
    git pull
    git stash pop || true

setup firmware="qmk":
    @ # gh repo clone zsa/qmk_firmware zsa_firmware -- -b firmware24
    cd {{ quote(justfile_directory() / "../" + firmware + "_firmware/") }} && git pull
    qmk setup -H {{ quote(justfile_directory() / "../" + firmware + "_firmware/") }} --yes
    qmk config user.keyboard={{ if firmware == "qmk" { "boardsource/unicorne" } else { "zsa/voyager" } }}
    qmk compile --compiledb -j0

compile:
    qmk lint
    qmk compile -j0
    fish -ic pause_if_err

flash:
    # cp boardsource_unicorne_iovis.uf2 /Volumes/RPI-RP2
    qmk flash

open:
    gh repo view --web

console:
    # Flash with `CONSOLE_ENABLE = yes`
    qmk console -t

clean:
    qmk clean -a
