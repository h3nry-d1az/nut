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
pub mod keys;

pub extern "C" {
    fn halt();
    fn panic(msg: String);
    // abort.h functions

    fn Log(msg: String, fore_color: u8, back_color: u8);
    // log.h functions

    fn switch_endian16(nb: u16) -> u16;
    fn switch_endian32(nb: u32) -> u32;
    // network.h functions

    fn digits(num: i32);
    fn ItoA(num: i32, number: String);
    fn sleep(timer_count: u32);
    // utils.h functions

    fn set_color(fore: u8, back: u8);
    // basics.h functions

    fn inb(port: u16) -> u8;
    fn outb(port: u16, data: u8);
    fn charin() -> char;
    fn strin() -> String;
    fn newline();
    fn charout(character: char, fore_color: u8, back_color: u8);
    fn strout(string: String, fore_color: u8, back_color: u8);
    fn gotox(x: u16);
    fn gotoy(y: u16);
    fn gotoxy(x: u16, y: u16);
    fn centered_strout(string: String, fore_color: u8, back_color: u8);
    fn intout(num: i32, fore_color: u8, back_color: u8);
    fn clear_screen(fore_color: u8, back_color: u8);
    fn puts(s: String);
    fn putc(c: char);
    fn puti(i: i32);
    //fn printf(string: String, ...);
    // io.h functions
}
// Please call these functions
// inside an 'unsafe {}' code block
