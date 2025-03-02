class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        str_list = []

        def formHappyStrings(i: int, curr_str: List[chr]):
            if i == n:
                str_list.append("".join(curr_str))
                return
            if ((i >= 1 and curr_str[i - 1] != "a") or (i == 0)) and len(str_list) < k:
                curr_str[i] = "a"
                formHappyStrings(i + 1, curr_str)
            if (i >= 1 and curr_str[i - 1] != "b" or (i == 0)) and len(str_list) < k:
                curr_str[i] = "b"
                formHappyStrings(i + 1, curr_str)
            if (i >= 1 and curr_str[i - 1] != "c" or (i == 0)) and len(str_list) < k:
                curr_str[i] = "c"
                formHappyStrings(i + 1, curr_str)
            return

        formHappyStrings(0, ["a" for i in range(n)])
        return str_list[k - 1] if len(str_list) == k else ""
        