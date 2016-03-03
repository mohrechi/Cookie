function processData(my_height) {
    try {
        if (isNaN(my_height)) {
            throw new Error('notANumberError');
        }
        if (my_height > 10) {
            throw new Error('hugeHeightError');
        }
        if (my_height < 4) {
            throw new Error('tinyHeightError');
        }
        console.log(my_height);
    } catch (err) {
        console.log(err.message);
    }
}
