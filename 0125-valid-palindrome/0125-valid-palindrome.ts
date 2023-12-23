function isPalindrome(s: string): boolean {
    s = s.toLowerCase().replace(/[^A-Za-z0-9]/g, '')
    const rev = s.split('')

    for(let i = 0; i < (rev.length) / 2 + 1; i++) {
        if (rev[i] != rev[rev.length - i - 1]) {
            return false
        }
    }

    return true
};