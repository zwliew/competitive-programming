class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hangle = 0.5 * (60 * hour + minutes)
        mangle = 6 * minutes
        d = abs(hangle - mangle)
        if d > 180:
            return 360 - d
        return d