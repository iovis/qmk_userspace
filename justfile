default: flash

# lists available tasks
@list:
    just --list

# init project and clean
init:
    git stash
    git pull
    git stash pop

setup:
    qmk setup -H ../qmk_firmware --yes

alias dev := compile

compile: setup
    qmk compile --compiledb -j0 -kb boardsource/unicorne
    fish -ic pause_if_err

flash:
    cp boardsource_unicorne_iovis.uf2 /Volumes/RPI-RP2

vsetup:
    @ # gh repo clone zsa/qmk_firmware zsa_firmware -- -b firmware24
    qmk setup -H ../zsa_firmware --yes

vcompile: vsetup
    qmk compile --compiledb -j0 -kb zsa/voyager
    fish -ic pause_if_err

vflash:
    qmk flash -kb zsa/voyager

open:
    gh repo view --web

console:
    # Flash with `CONSOLE_ENABLE = yes`
    qmk console -n -t

clean:
    qmk clean -a
