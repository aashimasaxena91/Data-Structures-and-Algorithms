class Solution {
public:

    unordered_map<string, string> mp;
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCHEFGHIJKLMNOPQRSTUVWXYZ";
    int num=0;
    // Encodes a URL to a shortened URL.
    
    string getCode(){
        string c="";
        for(int i=0;i<6;i++){
            c+=chars[rand()%62];
        }
        c= "http://tinyurl.com/" + c;
        return c;
    }
    
    string encode(string longUrl) {
       string code = getCode();
        mp[code] = longUrl;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));