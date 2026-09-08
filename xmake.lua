add_rules("mode.debug", "mode.release")

set_languages("c++23")

add_requires("sfml 3.x", {configs = {graphics = true, window = true, system = true}})

target("shimera")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("sfml")
