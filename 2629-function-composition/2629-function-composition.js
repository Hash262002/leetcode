/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    var len=functions.length;
    return function(x) {
        var value=x;
        while(len>0){
            value=functions[len-1](value);
            len--;
        }
        return value;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */