function romanToInt(str: string): number {
	var res = 0;
    var stLen = str.length;

	const valueMap = {
		'I' : 1,
		'V' : 5,
		'X' : 10,
		'L' : 50,
		'C' : 100,
		'D' : 500,
		'M' : 1000
	}

	for (var i = 0; i < stLen; i++)
	{
		var s1 = valueMap[str.charAt(i)];

		if (i + 1 < stLen) {
			var s2 = valueMap[str.charAt(i+1)];

			if (s1 >= s2) {
				res = res + s1;
			} else {
				res = res + s2 - s1;
				i++;
			}
		} else {
			res = res + s1;
		}
	}

	return res;
};