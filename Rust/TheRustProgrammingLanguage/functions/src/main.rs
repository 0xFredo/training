fn mainOk() {
    another_function(5);
}

fn another_function(x: i32) {
    println!("The value of x is: {}", x);
}

fn mainOk() {
    print_labeled_measurement(5, 'h');
}

fn print_labeled_measurement(value: i32, unit_label: char) {
    println!("The measurement is: {}{}", value, unit_label);
}


fn mainOkStatement() {
    let y = 6;
}

fn mainErrorStatement() {
    let x = (let y = 6);
}

fn mainOkExpression() {
    let y = {
        let x = 3;
        x + 1
    };

    println!("The value of y is: {}", y);
}

fn fiveOkReturn() -> i32 {
    5
}

fn mainOkPrint() {
    let x = five();

    println!("The value of x is: {}", x);
}

fn mainOkReturnExpression() {
    let x = plus_one(5);

    println!("The value of x is: {}", x);
}

fn plus_one(x: i32) -> i32 {
    x + 1
}

fn mainErrorReturnStatement() {
    let x = plus_oneError(5);

    println!("The value of x is: {}", x);
}

fn plus_oneError(x: i32) -> i32 {
    x + 1;
}


