add_rules("mode.debug", "mode.release")

if is_plat("windows") then
    set_toolchains("msvc")
end

add_requires("raylib", "glew")

target("raylib_template")
    set_kind("binary")
    set_languages("c++23")
    add_files("src/*.cpp")
    add_packages("raylib", "glew")