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

#include "hw3_output.hpp"
extern int yylineno;

typedef pair<string, string> StrPair;
typedef vector<string> StrVec;
typedef vector<StrPair> StrPairVec;
typedef vector<Symbol*> SymVec;
typedef vector<Table*> TableVec;

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return is_base_of<Base, T>::value;
}

class Symbol {
public:
    string name;
    string type;
    int offset;
    Symbol(string& name, string& type, int offset) : name(name), type(type), offset(offset) {}
};

class VarSymbol : public Symbol {
public:
    VarSymbol(string& name, string& type, int offset) : Symbol(name, type, offset) {}
};

class FuncSymbol : public Symbol {
public:
    StrPairVec args;
    FuncSymbol(string& name, StrVec& args_type, string& return_type) :
                Symbol(name, return_type, 0), args_type(args_type) {};
};

class Table {
public:
    SymVec symbols = SymVec();
    Table* parent = nullptr;
    Table() = default;
    explicit Table(Table* parent) : parent(parent) {}

    Symbol* pop() {
        symbols.pop_back();
    }
    Symbol* top() {
        symbols.back();
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
    Symbol* search_symbol(string& name) {
        for (auto & table_it = tables_stack.end(); table_it != tables_stack.begin(); table_it--) {
            for (auto & symbol_it = (*table_it)->end(); symbol_it != tables_stack.begin(); symbol_it--) {
                if((*symbol_it)->name==name) {
                    return symbol;
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
        for (Symbol* symbol : tables_stack.back()) {
            if (VarSymbol *v = dynamic_cast<VarSymbol *>symbol) {
                output::printID(v->name, v->offset, v->type);
            } else
            if (FuncSymbol *vf = dynamic_cast<FuncSymbol *>table_it)
                output::printID(f->name, f->offset, output::makeFunctionType(f->type, f->args_type));
            else{
                assert(false);
            }
        }
        delete tables_stack.back();
        tables_stack.pop_back();
        offset_stack.pop();
    }
    void close_global_scope() {
        auto main_symbol = search_symbol("main");
        if(main_symbol == nullptr) {
            output::errorMainMissing();
            exit(0);
        }
//        if(main_symbol->type != "")
    }
    void add_var_symbol(string& name, string& type) {
        // TODO Maybe check if name==byte and then its value
        check_name_exists(name);
        auto* s = new VarSymbol(name, type, offset_stack.top());
        tables_stack.back()->push(s);
        offset_stack.top() += 1;
    }
	void add_func_symbol(string& name, string& return_type, StrPairVec& args) {
        check_name_exists(name);
        StrVec args_type = StrVec();
        for(auto arg : args) {
            check_name_exists(arg.second);
            args_type.push_back(arg.first)
        }
        auto* f = new FuncSymbol(name, return_type, args_type);
        tables_stack.back()->push(f);
	}
	void check_name_exists(string& name) {
        if(search_symbol(name) != nullptr) {
            output::errorDef(yylineno ,name);
            exit(0);
        }
    }




};


#endif //HW3_CODE_SYM_TABLES_HPP
