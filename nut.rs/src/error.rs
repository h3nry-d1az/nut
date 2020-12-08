pub struct NutError {
    msg: String,
    code: i32,
}
// NutError implementation

impl NutError {
    fn new(msg: String, code: i32) -> NutError {
        let e = NutError {
            msg: msg,
            code: code,
        };

        ErrCache[ErrCacheIndex] = &mut e;

        return e;
    }
    // NutError constructor

    fn new_null() -> NutError {
        return NutError {
            msg: String::new(),
            code: 0
        };
    }
    // Null error constructor

    fn is_null(&mut self) -> bool {
        if self.msg == String::new() && self.code == 0 {
            return true;
        }
        
        return false;
    }
    // Is null?

    fn check() -> NutError {
        let e: NutError;

        for err in ErrCache.iter() {
            e = &mut ErrCache[ErrCacheIndex];
            ErrCache[ErrCacheIndex] = NutError::new_null();
            ErrCacheIndex += 1;
            return e;
        }

        return NutError::new_null();
    }
}