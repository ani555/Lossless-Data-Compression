#ifndef BITCHAR_H
#define BITCHAR_H
#include<string>
#define ul unsigned long
using namespace std;
class bitChar{
public:
    unsigned char* c;
    ul shift_count;
    string BITS;

    bitChar()
    {
        shift_count = 0;
        c = (unsigned char*)calloc(1, sizeof(char));
    }

    ~bitChar()
    {
        if(c)
            free(c);
    }
    public:
    	string readByBits(ifstream& inf)
    {
   		string s="";
		inf.seekg(0, std::ios::end);
		size_t size = inf.tellg();
		std::string buffer(size, ' ');
		inf.seekg(0);
		inf.read(&buffer[0], size); 
		for(int i=0;i<buffer.length();i++)
			{
				s+=getBits(buffer[i]);
			}
        return s;
    }
    
    void setBITS(string X)
    {
        BITS = X;
    }

    ul insertBits(ofstream& outf)
    {
        ul total = 0;
        while(BITS.length())
        {
            if(BITS[0] == '1')
                *c |= 1;
            *c <<= 1;
            ++shift_count;
            ++total;
            BITS.erase(0, 1);

            if(shift_count == 7 )
            {
                if(BITS.size()>0)
                {
                    if(BITS[0] == '1')
                        *c |= 1;
                    ++total;
                    BITS.erase(0, 1);
                }

                writeBits(outf);
                shift_count = 0;
                free(c);
                c = (unsigned char*)calloc(1, sizeof(char));
            }
        }

        if(shift_count > 0)
        {
            *c <<= (7 - shift_count);
            writeBits(outf);
            free(c);
            c = (unsigned char*)calloc(1, sizeof(char));
        }
        outf.close();
        return total;
    }

    string getBits(unsigned char X)
    {
        stringstream itoa;
        for(unsigned s = 7; s > 0 ; s--)
        {
            itoa << ((X >> s) & 1);
        }

        itoa << (X&1) ;
        return itoa.str();
    }

    void writeBits(ofstream& outf)
    {
        outf << *c;
    }

};
#endif
