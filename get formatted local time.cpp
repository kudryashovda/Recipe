string ltime() {
    time_t now = time(0);
    string s(30, '\0');
    strftime(&s[0], s.size(), "%H:%M:%S %d.%m.%Y ", localtime(&now));    
    
    return s;
}
