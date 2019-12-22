void hex_str2bytes(const string& str, u_char * out){
    const char h[] = "0123456789abcdef";
    
    u_char l,r;
    for(size_t i = 0; i < str.size(); ++i, ++i) {
        for(size_t j=0; j < sizeof(h); ++j) {
            if (h[j] == str[i]) l = j;
            if (h[j] == str[i+1]) r = j;
        }

        *(out++) = (l << 4) + r;
    }
}

string byte2hex_str(u_char * src, int len)
{
    const char h[] = "0123456789abcdef";
    
    string out;
    u_char l, r;
    for(int i = 0; i < len; ++i) {
        l = (src[i] >> 4); // div 8
        r = (src[i] << 4); r = (r >> 4); // mod 8       
        out.push_back( h[l] );
        out.push_back( h[r] );
    }
    
    return out;    
}
