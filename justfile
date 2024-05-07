default: init

# lists available tasks
@list:
    just --list

# init project
init:
    qmk setup
    qmk compile --compiledb -j0

# compile
dev:
    qmk compile -j0

# open the project in the browser
open:
    open .

# start a console
console:
    cp boardsource_unicorne_iovis.uf2 /Volumes/RPI-RP2

# # run tests
# test:
#     rspec
#
# # Open the DB
# db:
#     pgcli $DATABASE_URL
