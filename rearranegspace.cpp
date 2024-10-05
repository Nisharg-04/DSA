class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        int length = text.size();
        
        // Count the total number of spaces in the input string
        for (char c : text) {
            if (c == ' ') spaces++;
        }
        
        // Split the words by spaces
        vector<string> words;
        int i = 0;
        while (i < length) {
            while (i < length && text[i] == ' ') i++;  // Skip leading spaces
            if (i >= length) break;
            int start = i;
            while (i < length && text[i] != ' ') i++;  // Find the end of the word
            words.push_back(text.substr(start, i - start));  // Extract the word
        }
        
        int wordCount = words.size();
        
        // If there's only one word, return the word followed by all spaces
        if (wordCount == 1) {
            return words[0] + string(spaces, ' ');
        }
        
        // Calculate the number of spaces between words and the number of trailing spaces
        int spacesBetweenWords = spaces / (wordCount - 1);
        int trailingSpaces = spaces % (wordCount - 1);
        
        // Form the result string with evenly distributed spaces between words
        string result;
        for (int j = 0; j < wordCount; j++) {
            if (j > 0) {
                result += string(spacesBetweenWords, ' ');
            }
            result += words[j];
        }
        
        // Add trailing spaces at the end
        result += string(trailingSpaces, ' ');
        
        return result;
    }
};