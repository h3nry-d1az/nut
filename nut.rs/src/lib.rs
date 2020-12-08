// This file contains the
// nut kernel wrapper for
// rust developers.
//
// If you want to make an O.S.
// in rust, you should use the
// nut kernel with the rust wrapper

#![no_std]
// Don't use std crate

pub mod error;

pub extern "C" {
    fn halt();
    fn panic(msg: String);
    // abort.h functions
}
// Please call these functions
// inside an 'unsafe {}' code block