fn main() -> () {
    cc::Build::new()
               .file("../kernel/nut/nut.c")
               .compile("nut.so");

    println!("cargo:rustc-link-lib=nut.so");
} //nut.rs build script