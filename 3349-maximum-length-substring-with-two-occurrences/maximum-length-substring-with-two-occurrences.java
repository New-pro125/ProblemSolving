class Solution {
    public int maximumLengthSubstring(String s) {
        Map<Character,Integer> freq = new HashMap<>();
        int length = 0;
        int i = 0, j = 0;
        while(j < s.length()){
            freq.put(s.charAt(j),freq.getOrDefault(s.charAt(j), 0) + 1);
            while(i < j && freq.get(s.charAt(j)) > 2){
                freq.put(s.charAt(i), freq.getOrDefault(s.charAt(i), 0) - 1);
                i++;
            }
            j++;
            length = Math.max(length, j - i);
        }
        return length;
    }
}