TStrtingList ts[20];
ts[0] = name;
ts[1] = time;
ts[2] = power;
ts[3] = "0";
....
ts[19] = "0";

string print_string(TStringList &ts) {
  string s = "";
  for (auto it: ts) s += it;
  
  return s;
}

void tokenize_string(string s, TStringList &ts) {
  ts = delimText(s, '\t');
}

void copy_block(TStringList &ts) {
  transfer to page2;
}
