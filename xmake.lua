add_rules("mode.debug", "mode.release")

add_requires("sfml 3.x", "glew", "glm")

target("shimera_atp_test")
    set_kind("binary")
    set_languages("c++23")
    add_files("src/*.cpp")
    add_packages("sfml", "glew", "glm")

    -- Add the static version of Shimera

    set_rundir("$(builddir)/$(plat)/$(arch)/$(mode)")
