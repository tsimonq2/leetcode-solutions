#!/usr/bin/env python3

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # Compile the regex pattern
        r = re.compile(p)
        # Return if the entire string matches the pattern
        return bool(r.fullmatch(s))
