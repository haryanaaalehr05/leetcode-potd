class Solution {
public String replaceWords(List<String> dictionary, String sentence) {
        Set<String> rootSet = new HashSet<>(dictionary);
        StringBuilder result = new StringBuilder();
        
        for (String word : sentence.split(" ")) {
            String root = getRoot(word, rootSet);
            result.append(root).append(" ");
        }
        
        return result.toString().trim();
    }
    
    private String getRoot(String word, Set<String> rootSet) {
        for (int i = 1; i <= word.length(); i++) {
            String prefix = word.substring(0, i);
            if (rootSet.contains(prefix)) {
                return prefix;
            }
        }
        return word;
    }
};