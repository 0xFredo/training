const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;

fn mainErrorImmutability() {
    let x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is: {}", x);
}

fn mainOkMutable() {
    let mut x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is: {}", x);
}

fn mainOkShadowing() {
    let x = 5;

    let x = x + 1;

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {}", x);
    }

    println!("The value of x is: {}", x);
}

fn mainOkShadowing() {
    let spaces = "   ";
    let spaces = spaces.len();
}

fn mainErrorMutateVarType() {
    let mut spaces = "   ";
    spaces = spaces.len();
}

fn mainOkTypeAnnotation() {
    let guess: u32 = "42".parse().expect("Not a number!");
}

fn mainOkFloating() {
    let x = 2.0; // f64

    let y: f32 = 3.0; // f32
}

fn mainOkOperators() {
    // addition
    let sum = 5 + 10;

    // subtraction
    let difference = 95.5 - 4.3;

    // multiplication
    let product = 4 * 30;

    // division
    let quotient = 56.7 / 32.2;
    let floored = 2 / 3; // Results in 0

    // remainder
    let remainder = 43 % 5;
}

fn mainOkBool() {
    let t = true;

    let f: bool = false; // with explicit type annotation
}

fn mainOkChars() {
    let c = 'z';
    let z = 'ℤ';
    let heart_eyed_cat = '😻';
}

fn mainOkTuple() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);
}

fn mainOkTupleDestructuring() {
    let tup = (500, 6.4, 1);

    let (x, y, z) = tup;

    println!("The value of y is: {}", y);
}

fn mainOkTupleIndexAccess() {
    let x: (i32, f64, u8) = (500, 6.4, 1);

    let five_hundred = x.0;

    let six_point_four = x.1;

    let one = x.2;
}

fn mainOkArray() {
    

fn mainOkArray() {
    let a1 = [1, 2, 3, 4, 5];

    let months = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    ];
    let a: [i32; 5] = [1, 2, 3, 4, 5];
    let b = [3; 5];
}

fn mainArrayIndexAcces() {
    let a = [1, 2, 3, 4, 5];

    let first = a[0];
    let second = a[1];
}

use std::io;

fn mainPanicsInsertingIndexOutOfBound() {
    let a = [1, 2, 3, 4, 5];

    println!("Please enter an array index.");

    let mut index = String::new();

    io::stdin()
        .read_line(&mut index)
        .expect("Failed to read line");

    let index: usize = index
        .trim()
        .parse()
        .expect("Index entered was not a number");

    let element = a[index];

    println!(
        "The value of the element at index {} is: {}",
        index, element
    );
}

