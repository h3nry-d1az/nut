pub struct NutError {
    msg: String,
    code: i32,
}
// NutError implementation


pub struct Errors {
	cache: [NutError; 32],
	cachei: usize,
}

impl Errors {
	fn new() -> Errors {
		return Errors {
			cache: [NutError::new_null(); 32],
			cachei: 0,
		}
	}

	fn check(&mut self) -> NutError {
		let e: NutError;
		for error in self.cache.iter() {
			e = self.cache[self.cachei];
			self.cache[self.cachei] = NutError::new_null();
			return e;
		}

		return NutError::new_null();
  }
}
// Error collection struct

impl NutError {
    fn new(msg: String, code: i32, errors: Errors) -> NutError {
        let e = NutError {
            msg: msg,
            code: code,
        };

      	errors.cache[errors.cachei] = &mut e;

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
}