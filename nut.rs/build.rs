fn main() -> () {
    cc::Build::new()
               .file("nut.c")
               .include("../kernel/nut/nut.h")
               .compile("nut.o");

    println!("cargo:rustc-link-lib=nut.o");
} //nut.rs build script