const maxNumber = 100000;

function objectPropertyNumber() {
    console.time('objectPropertyNumberSet');
    const obj = {};
    for (let i = 0; i < maxNumber; i++) {
        obj[i] = i;
    }
    console.timeEnd('objectPropertyNumberSet');

    const newObj = {};
    console.time('objectPropertyNumberGet');
    Object.keys(obj).forEach(key => newObj[key] = obj[key]);
    console.timeEnd('objectPropertyNumberGet');
}

function objectPropertyString() {
    console.time('objectPropertyStringSet');
    const obj = {};
    for (let i = 0; i < maxNumber; i++) {
        obj[`objectPropertyString-${i}`] = i;
    }
    console.timeEnd('objectPropertyStringSet');

    const newObj = {};
    console.time('objectPropertyStringGet');
    Object.keys(obj).forEach(key => newObj[key] = obj[key]);
    console.timeEnd('objectPropertyStringGet');
}

function arrayIndex() {
    console.time('arrayIndexSet');
    const arr = [];
    for (let i = 0; i < maxNumber; i++) {
        arr[i] = i;
    }
    console.timeEnd('arrayIndexSet');

    console.time('arrayIndexGet');
    const newArr = [];
    for (let i = 0; i < maxNumber; i++) {
        newArr[i] = arr[i];
    }
    console.timeEnd('arrayIndexGet');
}

function arrayPropertyString() {
    console.time('arrayPropertyStringSet');
    const arr = [];
    for (let i = 0; i < maxNumber; i++) {
        arr[`objectPropertyString-${i}`] = i;
    }
    console.timeEnd('arrayPropertyStringSet');

    console.time('arrayPropertyStringGet');
    const newArr = [];
    for (let i = 0; i < maxNumber; i++) {
        newArr[`objectPropertyString-${i}`] = arr[`objectPropertyString-${i}`]
    }
    console.timeEnd('arrayPropertyStringGet');
}

objectPropertyNumber();
objectPropertyString();

arrayIndex();
arrayPropertyString();
