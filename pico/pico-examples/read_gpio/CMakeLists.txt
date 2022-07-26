add_executable(read_gpio
               read_gpio.c
               )

# pull in common dependencies
target_link_libraries(read_gpio pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(read_gpio)

# add url via pico_set_program_url
example_auto_set_url(read_gpio)
