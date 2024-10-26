alias dev := compile

default: init

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
    qmk compile --compiledb -j0 -kb boardsource/unicorne

compile:
    qmk lint -kb boardsource/unicorne
    qmk compile -j0 -kb boardsource/unicorne
    fish -ic pause_if_err

flash:
    # cp boardsource_unicorne_iovis.uf2 /Volumes/RPI-RP2
    qmk flash -kb boardsource/unicorne

vsetup:
    @ # gh repo clone zsa/qmk_firmware zsa_firmware -- -b firmware24
    qmk setup -H ../zsa_firmware --yes
    qmk compile --compiledb -j0 -kb zsa/voyager

vcompile:
    qmk lint -kb zsa/voyager
    qmk compile -j0 -kb zsa/voyager
    fish -ic pause_if_err

vflash:
    qmk flash -kb zsa/voyager

open:
    gh repo view --web

console:
    # Flash with `CONSOLE_ENABLE = yes`
    qmk console -t

clean:
    qmk clean -a
