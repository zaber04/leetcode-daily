function checkStraightLine(coordinates: number[][]): boolean {
    const len = coordinates.length;

    if (len < 3) {
        return true;
    }

    const p1 = coordinates[0];
    const p2 = coordinates[1];

    const slope = (p2[0] == p1[0]) ?  'INF' : (p2[1] - p1[1])*1.0/(p2[0] - p1[0]);

    for (let i = 1; i < len - 1; i++) {
        var slp = (coordinates[i+1][0] == coordinates[i][0]) ? 'INF' : (coordinates[i+1][1] - coordinates[i][1])*1.0/(coordinates[i+1][0] - coordinates[i][0]);
        
        if (slp != slope) {
            return false;
        }
    }

    return true
};