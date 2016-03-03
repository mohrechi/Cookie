function processData(input) {
    "use strict";
    let pressure = (gravity) => (mass) => (height) => gravity * mass * height;
    let m = input[0];
    let g = input[1];
    let h = input[2];

    let accelerationDueToGravity = pressure(g);
    let particleMass = accelerationDueToGravity(m);
    let particleHeight = particleMass(h);

    let totalPressure = particleHeight;

    console.log(totalPressure);
}
