#pragma once


#include <tools/tinyjson.h>

template <typename T>
inline void loadCmp(const char* path) {}

unsigned int getTemplateIndex(json_t const* json, const char* name);

#include <load/loader.tpp>