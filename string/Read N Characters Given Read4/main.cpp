// reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-read-n-characters-given-read4.html

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
        while(readLen+4<=n)
        {
            readByte=read4(buf+readLen); // to update the array starting position!!
            readLen+=readByte;
            if(readByte<4) // which means that all available bytes being read
                return readLen;
        }

            
        // deal with the case that after reading 4 byte, the remaining byte for the length less than 4
        char remain[4]; // not necessary allocate on heap
        readByte=min(read4(remain), n-readLen); // important, not attaching all the actual read byte
        for(int i=0; i<readByte; i++)
            buf[readLen++]=remain[i];
        return readLen;
    }
};
