add_rules("mode.debug", "mode.release")

if is_plat("windows") then
    set_toolchains("msvc")
end

set_languages("c++23")

add_requires("sfml 3.x", {configs = {graphics = true, window = true, system = true}})
add_requires("glew")

target("shimera")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("sfml", "glew")
