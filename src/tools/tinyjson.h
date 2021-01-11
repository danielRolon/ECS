/* Esta cebecera defne funciones para trabajar mas comodo con tiny-json */

#ifndef TINYJSON_INCLUDED
#define TINYJSON_INCLUDED

#include <tiny-json/tiny-json.h>

// Carga un archivo y retorna un json_t
json_t const* loadJson(const char* path);

// Chequea una propiedad
void checkProperty(json_t const* property, unsigned int type);

// Imprime una propiedad
void printProperty(json_t const* property);

// Devuelve una propiedad y la chequea
json_t const* getPropertyCheck(json_t const* json, const char* name, unsigned int type);

// Devuelve un hijo y lo chequea
json_t const* getChildCheck(json_t const* json, unsigned int type);

// Devuelve un hermano y lo chequea
json_t const* getSiblingCheck(json_t const* json, unsigned int type);

// Imprime un objeto o un array
void dump( json_t const* json );

#endif //TINYJSON_INCLUDED