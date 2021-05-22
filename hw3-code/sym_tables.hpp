//
// Created by yaniv on 15/05/2021.
//

#ifndef HW3_CODE_SYM_TABLES_HPP
#define HW3_CODE_SYM_TABLES_HPP

#include <stack>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>

#include "hw3-output.hpp"

extern int yylineno;

typedef pair<string, string> StrPair;
typedef vector<string> StrVec;
typedef vector<StrPair> StrPairVec;

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return is_base_of<Base, T>::value;
}

class Symbol {
public:
    string name;
    string type;
    int offset;
    Symbol(const string& name, const string& type, int offset) : name(name), type(type), offset(offset) {}
    virtual void print();
};

class VarSymbol : public Symbol {
public:
    VarSymbol(const string& name, const string& type, int offset) : Symbol(name, type, offset) {}
    void print() override {
        output::printID(name, offset, type);
    }
};

class FuncSymbol : public Symbol {
public:
    StrVec args_type;
    string return_type;
    FuncSymbol(const string& name, const string& return_type, StrVec& args_type) :
                Symbol(name, "FUNC", 0), return_type(return_type), args_type(args_type) {};
    void print() override {
        output::printID(name, offset, output::makeFunctionType(type, args_type));
    }
};

typedef vector<Symbol*> SymVec;

class Table {
public:
    SymVec symbols = SymVec();
    Table* parent = nullptr;
    Table() = default;
    explicit Table(Table* parent) : parent(parent) {}

    void pop() {
        symbols.pop_back();
    }
    Symbol& top() {
        return *symbols.back();
    }
    void push(Symbol* symbol) {
        symbols.push_back(symbol);
    }
    ~Table() {
        for(Symbol* sym: symbols) {
            delete sym;
        }
    }
};

typedef vector<Table*> TableVec;

class SymbolTable {
public:
    stack<int> offset_stack;
    TableVec tables_stack;

    SymbolTable() {
        offset_stack = stack<int>();
        tables_stack = TableVec();
        open_first_scope();

        StrPairVec print_args = StrPairVec();
        print_args.push_back(StrPair("STRING", "arg"));
        add_func_symbol("print", "VOID", print_args);

        StrPairVec printi_args = StrPairVec();
        printi_args.push_back(StrPair("INT", "arg"));
        add_func_symbol("printi", "VOID", printi_args);
    }
    Symbol* search_symbol(const string& name, bool is_func) {
        for (auto table_it = tables_stack.end(); table_it != tables_stack.begin(); table_it--) {
            for (auto symbol_it = (*table_it)->symbols.end(); symbol_it != (*table_it)->symbols.begin(); symbol_it--) {
                if(is_func) {
                    if ((*symbol_it)->name == name && (*symbol_it)->type == "FUNC") {
                        return (*symbol_it);
                    }
                }
                else {
                    if ((*symbol_it)->name == name && (*symbol_it)->type != "FUNC") {
                        return (*symbol_it);
                    }
                }
            }
        }
        return nullptr;
    }
    void open_scope() {
        auto* t = new Table(tables_stack.back());
        tables_stack.push_back(t);
        offset_stack.push(offset_stack.top());
    }
    void open_first_scope() {
        auto* t = new Table(nullptr);
        tables_stack.push_back(t);
        offset_stack.push(0);
    }
    void close_scope() {
        output::endScope();
        for (auto symbol : tables_stack.back()->symbols) {
            symbol->print();
        }
        delete tables_stack.back();
        tables_stack.pop_back();
        offset_stack.pop();
    }
    void close_global_scope() {
        auto main_symbol = search_symbol("main", true);
        FuncSymbol* main_func_symbol = (FuncSymbol*) main_symbol;
        if(main_symbol == nullptr || main_func_symbol->return_type != "VOID"
            || main_func_symbol->args_type.size() != 0) {
            output::errorMainMissing();
            exit(0);
        }
        close_scope();
    }
    void add_var_symbol(const string& name, const string& type) {
        // TODO Maybe check if name==byte and then its value
        check_name_exists(name, false);
        auto* s = new VarSymbol(name, type, offset_stack.top());
        tables_stack.back()->push(s);
        offset_stack.top() += 1;
    }
	void add_func_symbol(const string& name, const string& return_type, StrPairVec& args) {
        check_name_exists(name, true);
        StrVec args_type = StrVec();
        for(auto arg : args) {
            check_name_exists(arg.second, false);
            args_type.push_back(arg.first);
        }
        auto* f = new FuncSymbol(name, return_type, args_type);
        tables_stack.back()->push(f);
	}
	void check_name_exists(const string& name, bool is_func) {
        if(search_symbol(name, is_func) != nullptr) {
            output::errorDef(yylineno ,name);
            exit(0);
        }
    }




};


#endif //HW3_CODE_SYM_TABLES_HPP
