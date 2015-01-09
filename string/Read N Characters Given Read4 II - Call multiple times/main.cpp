/* example test cases and the output 
 * Input: 	"ab", [read(1),read(2)]
   Output: 	["a",""] ---> using Read 4 I
   Expected: 	["a","b"]
*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution 
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) 
    {
        int readLen=0;
        int readByte=0;
        while(!q.empty() && readLen<n)
        {
            buf[readLen++]=q.front();
            q.pop();
        }
        while(readLen+4<=n)
        {
            readByte=read4(buf+readLen);
            readLen+=readByte;
            if(readByte<4) // which means that all available bytes being read
                return readLen;
        }
        if(readLen==n)
            return readLen;
            
        // deal with the case that after reading 4 byte, the remaining byte for the length less than 4
        char remain[4]; // not necessary allocate on heap
        int actualReadByte=read4(remain);
        readByte=min(actualReadByte, n-readLen); // important, not attaching all the actual read byte
        for(int i=0; i<readByte; i++)
            buf[readLen++]=remain[i];
        
        for(int i=readByte; i<actualReadByte; i++)
            q.push(remain[i]);
        return readLen;
    }
    
private:
    queue<char> q;
};
