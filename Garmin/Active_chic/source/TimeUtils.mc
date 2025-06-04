module MathUtils {

    function min(a, b) {
        return (a < b) ? a : b;
    } // min

    function max(a, b) {
        return (a > b) ? a : b;
    } // max

    function floor(val) {
        var intVal = val.toNumber();
        if (intVal == val || val >= 0) {
            return intVal;
        } else {
            return intVal - 1;
        }
    } // floor

    function ceil(val) {
        var intVal = val.toNumber();
        if (intVal == val || val <= 0) {
            return intVal;
        } else {
            return intVal + 1;
        }
    } // ceil

    function nextDivisible(val, n) {
        var intVal = ceil(val);
        if (intVal % n == 0) {
            return intVal;
        } else {
            return intVal + (n - (intVal % n));
        }
    } // nextDivisible

} // module MathUtils