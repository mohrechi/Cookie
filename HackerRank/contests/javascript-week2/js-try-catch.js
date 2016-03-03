function processData(my_string) {
    try {
        var r = my_string.split('').reverse().join('');
        console.log('Reversed string is : ' + r);
    } catch (err) {
        console.log('Error : ' + err.message);
    } finally {
        console.log('Type of my_string is : ' + typeof(my_string));
    }
}