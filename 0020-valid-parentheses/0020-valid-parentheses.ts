function isValid(s: string): boolean {
    // must be even number
    if (s.length % 2) {
        return false;
    }

    let stk = [];

    const opposite = {
        ')' : '(',
        '}' : '{',
        ']' : '['
    };

    for (let i = 0, arlen = s.length; i < arlen; i++) {
        let x = s[i];
 
        if ('([{'.includes(x)) {
            stk.push(x);
            continue;
        }

        let check = stk.pop();
        // not opening bracket means closing bracket. so stack should not be
        // need same type oppening bracket
        if (!check || (check != opposite[x])) {
            return false;
        }
    }

    return (stk.length == 0);
};