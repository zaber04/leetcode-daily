function longestCommonPrefix(strs: string[]): string {
    const len = strs.length;

    if (!len) {
        return "";
    }

    if (len == 1) {
        return strs[0];
    }

    let pref = strs[0];

    for (var i = 1; i < len; i++) {
        while (!strs[i].startsWith(pref)) {
            pref = pref.slice(0, -1);
        }

        if (pref == "") {
            return "";
        }
    }

    return pref;
};