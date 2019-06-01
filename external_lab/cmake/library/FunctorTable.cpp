#include "FunctorTable.hpp"
#include <cstring>

FunctorTable::FunctorTable()
{
}

void FunctorTable::Register(int type, Func func)
{
    if (m_funcs.find(type) != m_funcs.end()) {
        throw std::runtime_error(("FunctorTable::Register with already registered type " + std::to_string(type)).c_str());
    }

    m_funcs[type] = func;
}

void FunctorTable::Call(int type)
{
    auto func_it = m_funcs.find(type);
    if (func_it != m_funcs.end()) {
        (func_it->second)();
    }
    else {
        throw std::runtime_error(("FunctorTable::Call with unregistered type " + std::to_string(type)).c_str());
    }
}
