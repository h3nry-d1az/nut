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

    fn Log(msg: String, fore_color: u8, back_color: u8);
    // log.h functions

    fn switch_endian16(nb: u16) -> u16;
    fn switch_endian32(nb: u32) -> u32;
    // network.h functions
}
// Please call these functions
// inside an 'unsafe {}' code block
