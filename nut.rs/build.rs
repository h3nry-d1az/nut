fn main() -> () {
    cc::Build::new()
               .file("../kernel/nut/nut.h")
               .compile("nut.o");

    println!("cargo:rustc-link-lib=nut.o");
} //nut.rs build script