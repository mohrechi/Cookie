function myFilter(my_array, callback) {
    var filtered_array = [];
    my_array.forEach(function (elem) {
        if (callback(elem)) {
            filtered_array.push(elem);
        }
    });
    return filtered_array;
}

function processData(inputArray) {
    console.log(myFilter(inputArray, function (elem) {
        return elem % 2 === 0;
    }));
}
