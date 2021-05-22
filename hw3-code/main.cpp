#include <iostream>
#include "sym_tables.hpp"

int main() {

    string x("x");
    string y("y");
    string w("w");
    string z("z");
    string f("f");
    string str_name("name");
    string str_type("type");
    SymbolTable st = SymbolTable();
    StrPairVec v1 = StrPairVec();
    v1.push_back(StrPair("BOOL", "arg1"));
    v1.push_back(StrPair("STRING", "arg2"));
    StrPairVec v2 = StrPairVec();
    v2.push_back(StrPair("BOOL", "arg1"));
    v2.push_back(StrPair("STRING", "arg2"));

    bool b = v1==v2;

    st.open_scope();
    st.add_func_symbol(w, str_type, v1);
    st.open_scope();
    st.add_func_args(v1);
    st.add_var_symbol(y, str_type);
    st.close_scope();
    st.add_func_symbol(f, str_type, v2);
    st.open_scope();
    st.add_func_args(v2);
    st.add_var_symbol(z, str_type);
    st.close_scope();


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
